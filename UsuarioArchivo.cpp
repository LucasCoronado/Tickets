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


bool UsuarioArchivo::guardar(const Usuario &registro)
{


	Usuario copiaRegistro = registro;
    string fileName = copiaRegistro.getFileName();

	copiaRegistro.setId(copiaRegistro.setIdMasUno(fileName.c_str()));

	FILE *pFile;
	bool result;

	pFile = fopen(fileName.c_str(),"ab");

	if(pFile == nullptr)
	{
		return false;
	}


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


bool UsuarioArchivo::validarUser(string user, Usuario &registro){

	string fileName = registro.getFileName();
	FILE *pFile;

	pFile = fopen(fileName.c_str(),"rb");

	if(pFile == nullptr){

		return false;
	}

	while(fread(&registro,sizeof(Usuario),1,pFile)==1){
		if(registro.getUser() == user){
			fclose(pFile);
			return true;
		}
	}

	fclose(pFile);
	return false;

}

bool UsuarioArchivo::validarPass(string passw, Usuario &registro){

	string fileName = registro.getFileName();
	FILE *pFile;

	pFile = fopen(fileName.c_str(),"rb");

	if(pFile == nullptr){

		return false;
	}

	while(fread(&registro,sizeof(Usuario),1,pFile)==1){
		if(registro.getPassw() == passw){
			fclose(pFile);
			return true;
		}
	}

	fclose(pFile);
	return false;

}

