#include "TicketArchivo.h"

TicketArchivo::TicketArchivo()
{
	_fileName = "tickets.dat";
}

TicketArchivo::~TicketArchivo()
{
	//dtor
}

bool TicketArchivo::guardar(const Ticket &registro)
{

	FILE *pFile;
	bool result;

	pFile = fopen(_fileName.c_str(),"ab");

	if(pFile == nullptr)
	{
		return false;
	}

	result = fwrite(&registro, sizeof(Ticket), 1,pFile) == 1;

	fclose(pFile);

	return result;

}

int TicketArchivo::getCantidad()
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

	return total / sizeof(Ticket);

}

bool TicketArchivo::leerTodos(Ticket registros[], int cantidad)
{
	FILE *pFile;
	bool result;

	pFile = fopen(_fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		return false;
	}

	result = fread(registros, sizeof(Ticket), cantidad, pFile) == cantidad;

	fclose(pFile);

	return result;
}

Ticket TicketArchivo::leer(int pos){

     FILE *pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == NULL){
        return Ticket();
    }
    Ticket ticket;
    fseek(pFile, sizeof(Ticket) * pos, SEEK_SET);

    fread(&ticket, sizeof(Ticket), 1, pFile);
    fclose(pFile);
    return ticket;

}

