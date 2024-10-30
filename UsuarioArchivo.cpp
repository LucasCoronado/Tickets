#include "UsuarioArchivo.h"
#include <iostream>
using namespace std;

UsuarioArchivo::UsuarioArchivo()
{
    //ctor
}

UsuarioArchivo::~UsuarioArchivo()
{
    //dtor
}


bool UsuarioArchivo::guardar(const Usuario &registro, string fileName)
{

	FILE *pFile;
	bool result;

	pFile = fopen(fileName.c_str(),"ab");

	if(pFile == nullptr)
	{
		return false;
	}

	Usuario copiaRegistro = registro;

	copiaRegistro.setId(copiaRegistro.setIdMasUno(fileName.c_str()));

	copiaRegistro.mostrarUsuario();
	result = fwrite(&copiaRegistro, sizeof(Usuario), 1,pFile) == 1;

	fclose(pFile);

	return result;

}

void UsuarioArchivo::leerTodos(string fileName)
{
	Usuario reg;
	FILE *pFile;
	pFile = fopen(fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		cout<<"No se pudo abrir el archivo"<<endl;
		return;
	}

	while(fread(&reg, sizeof(reg),1, pFile)==1){

		reg.mostrarUsuario();
		cout << endl;
	}

	fclose(pFile);
}

int UsuarioArchivo::getCantidad(string fileName)
{

	int total;
	FILE *pFile;
	pFile = fopen(fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		return 0;
	}

	fseek(pFile, 0,SEEK_END);
	total = ftell(pFile);

	fclose(pFile);

	return total / sizeof(Usuario);

}
