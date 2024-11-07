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
	bool modificarTicket(Ticket ticket, int pos);
	int cantidadTicketsPorUsuario(Usuario usuario);

	private:
	std::string _fileName;
};

