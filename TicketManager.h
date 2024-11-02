#pragma once
#include "Ticket.h"
#include "TicketArchivo.h"


class TicketManager
{
public:
	TicketManager();
	virtual ~TicketManager();

	void mostrarTicket(Ticket ticket);
	void cargarTicket(Usuario usuario);

	void leerTodos();
	int generarNuevoId();

private:
    Ticket _ticket;
    TicketArchivo _ticketArch;
};

