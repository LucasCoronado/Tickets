#include "ResponsableArchivo.h"


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

	result = fwrite(&registro, sizeof(Responsable), 1,pFile) == 1;

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

bool ResponsableArchivo::leerTodos(Responsable registros[], int cantidad)
{
	FILE *pFile;
	bool result;

	pFile = fopen(_fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		return false;
	}

	result = (fread(registros, sizeof(Responsable), cantidad, pFile) == cantidad);

	fclose(pFile);

	return result;
}
