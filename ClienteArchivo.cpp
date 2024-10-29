#include "ClienteArchivo.h"
#include <iostream>
using namespace std;

ClienteArchivo::ClienteArchivo()
{
   _fileName = "clientes.dat";
}

ClienteArchivo::~ClienteArchivo()
{
	//dtor
}

bool ClienteArchivo::guardar(const Cliente &registro)
{

	FILE *pFile;
	bool result;

	pFile = fopen(_fileName.c_str(),"ab");

	if(pFile == nullptr)
	{
		return false;
	}

	result = fwrite(&registro, sizeof(Cliente), 1,pFile) == 1;

	fclose(pFile);

	return result;

}

int ClienteArchivo::getCantidad()
{

	int total;
	FILE *pFile;
	pFile = fopen(_fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		return 0;
	}

	fseek(pFile, 0,SEEK_END);
	total = ftell(pFile);

	fclose(pFile);

	return total / sizeof(Cliente);

}

void ClienteArchivo::leerTodos()
{
	Cliente regC;
	FILE *pFile;
	pFile = fopen(_fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		cout<<"No se pudo abrir el archivo"<<endl;
		return;
	}

	while(fread(&regC, sizeof(Cliente),1, pFile)==1){

		regC.mostrarUsuario();
		cout << endl;
	}

	fclose(pFile);
}
