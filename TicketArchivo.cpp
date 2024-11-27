#include "TicketArchivo.h"
#include <iostream>
using namespace std;

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

Ticket TicketArchivo::leer(int pos)
{
	Ticket ticket;

	FILE *pFile = fopen(_fileName.c_str(), "rb");

	if(pFile == nullptr)
	{
		return ticket;
	}
	fseek(pFile,pos * sizeof(Ticket), SEEK_SET);

	fread(&ticket, sizeof(Ticket), 1, pFile);
	fclose(pFile);
	return ticket;

}

int TicketArchivo::buscar(int id)
{
	int i, cantidadRegistros = getCantidad();
	Ticket ticket;

	for(i=0; i<cantidadRegistros; i++)
	{
		ticket = leer(i);
		if (ticket.getId() == id)
		{
			return i;
		}
	}
	return -1;
}

bool TicketArchivo::modificarTicket(Ticket ticket, int pos)
{

	FILE *pFile;
	pFile=fopen(_fileName.c_str(),"rb+");

	if(pFile ==nullptr)
	{
		return false;
	}
	fseek(pFile,pos*sizeof(Ticket),SEEK_SET);

	bool escribio=fwrite(&ticket,sizeof(Ticket),1,pFile)==1;
	fclose(pFile);
	return escribio;
}

int TicketArchivo::cantidadTicketsPorUsuario(Usuario usuario, string estado)
{

	int cant=0;
	Ticket ticket;
	FILE *pFile;
	pFile=fopen(_fileName.c_str(),"rb");

	if(pFile==nullptr)
	{
		return -1;
	}
	while(fread(&ticket,sizeof(Ticket),1,pFile)==1)
	{
		if(ticket.getEstado() == estado){
	 if(usuario.getPermiso() == "Cliente"){
		if(ticket.getCliente() == usuario.getId()){
			cant++;
		}
	 }else if(usuario.getPermiso() == "Responsable"){
		if(ticket.getResponsable() == usuario.getId()){
			cant++;
		}
	 }
		}
	}
	fclose(pFile);
	return cant;

}


