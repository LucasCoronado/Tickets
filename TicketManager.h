#pragma once
#include "Ticket.h"
#include "TicketArchivo.h"
#include "UsuarioArchivo.h"


class TicketManager
{
public:
	TicketManager();
	virtual ~TicketManager();

	void mostrarTicket(Ticket ticket);
	void cargarTicket(Usuario usuario);

	void leerTodos();
	int generarNuevoId();


	void buscarPorIdUsuario(int idUser);
    void mostrarOrdenadosPorPrioridad(int idUser);

private:
    Ticket _ticket;
    TicketArchivo _ticketArch;
};

