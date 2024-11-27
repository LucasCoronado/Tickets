#include "UsuarioArchivo.h"
#include <iostream>
using namespace std;

UsuarioArchivo::UsuarioArchivo(string fileName)
{
	_fileName = fileName;
}

UsuarioArchivo::UsuarioArchivo()
{

}

UsuarioArchivo::~UsuarioArchivo()
{
	//dtor
}

int UsuarioArchivo::getCantidad()
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

	return total / sizeof(Usuario);
}


bool UsuarioArchivo::guardar(const Usuario &registro)
{
	FILE *pFile;
	bool result;

	pFile = fopen(_fileName.c_str(),"ab");

	if(pFile == nullptr)
	{
		return false;
	}

	result = fwrite(&registro, sizeof(Usuario), 1,pFile) == 1;

	fclose(pFile);

	return result;

}
Usuario UsuarioArchivo::leer(int pos)
{
	Usuario usuario;

	FILE *pFile = fopen(_fileName.c_str(), "rb");

	if (pFile == nullptr)
	{
		return usuario;
	}
	fseek(pFile, pos * sizeof(Usuario), SEEK_SET);

	fread(&usuario, sizeof(Usuario), 1, pFile);
	fclose(pFile);
	return usuario;

}

int UsuarioArchivo::buscar(int id)
{
	int i, cantidadRegistros = getCantidad();
	Usuario usuario;

	for(i=0; i<cantidadRegistros; i++)
	{
		usuario = leer(i);
		if (usuario.getId() == id)
		{
			return i;
		}
	}
	return -1;
}


int UsuarioArchivo::buscarPorUser(string user)
{
	int i, cantidadRegistros = getCantidad();
	Usuario usuario;

	for(i=0; i<cantidadRegistros; i++)
	{
		usuario = leer(i);
		if (usuario.getUser() == user)
		{
			return i;
		}
	}
	return -1;
}


bool UsuarioArchivo::validarUser(string user, string fileName)
{
	Usuario registro;

	FILE *pFile;

	pFile = fopen(fileName.c_str(),"rb");

	if(pFile == nullptr)
	{
		return false;
	}

	while(fread(&registro,sizeof(Usuario),1,pFile)==1)
	{
		if(registro.getUser() == user)
		{
			fclose(pFile);
			return true;
		}
	}

	fclose(pFile);
	return false;

}

bool UsuarioArchivo::validarPass(string passw, string fileName)
{
	Usuario registro;
	FILE *pFile;

	pFile = fopen(fileName.c_str(),"rb");

	if(pFile == nullptr)
	{

		return false;
	}

	while(fread(&registro,sizeof(Usuario),1,pFile)==1)
	{
		if(registro.getPassw() == passw)
		{
			fclose(pFile);
			return true;
		}
	}

	fclose(pFile);
	return false;

}


