#pragma once
#include "Ticket.h"

class TicketArchivo
{
public:
	TicketArchivo();
	virtual ~TicketArchivo();

	int getCantidad();
	bool guardar(const Ticket &registro);
	Ticket leer(int pos);

	int buscar(int id);
	bool cambiarEstado(Ticket ticket,std::string estado, int pos);


	private:
	std::string _fileName;
};

