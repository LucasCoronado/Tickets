#include "ResponsableArchivo.h"
#include <iostream>
using namespace std;

ResponsableArchivo::ResponsableArchivo()
{
	_fileName = "responsables.dat";
}

ResponsableArchivo::~ResponsableArchivo()
{
	//dtor
}


bool ResponsableArchivo::guardar(const Responsable &registro)
{

	FILE *pFile;
	bool result;

	pFile = fopen(_fileName.c_str(),"ab");

	if(pFile == nullptr)
	{
		return false;
	}
	Responsable copiaRegistro = registro;

	copiaRegistro.setId(copiaRegistro.setIdMasUno(_fileName.c_str()));

	copiaRegistro.mostrarUsuario();
	result = fwrite(&copiaRegistro, sizeof(Responsable), 1,pFile) == 1;

	fclose(pFile);

	return result;

}

int ResponsableArchivo::getCantidad()
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

	return total / sizeof(Responsable);

}

void ResponsableArchivo::leerTodos()
{
	Responsable regR;
	FILE *pFile;

	pFile = fopen(_fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		cout<<"No se pudo abrir el archivo"<<endl;
		return;
	}

	while(fread(&regR, sizeof(Responsable),1, pFile)==1)
	{

		regR.mostrarUsuario();
		cout << endl;
	}

	fclose(pFile);

}


