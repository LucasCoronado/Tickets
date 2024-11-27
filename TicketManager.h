#pragma once
#include "Ticket.h"
#include "TicketArchivo.h"
#include "UsuarioArchivo.h"
#include "UsuarioManager.h"

class TicketManager
{
public:
	TicketManager();
	virtual ~TicketManager();

	void mostrarTicket(Ticket ticket);
	void cargarTicket(Usuario usuario);

	void leerTodos();
	int generarNuevoId();


	void buscarPorIdUsuario(int idUser, std::string tipoUser);
	void mostrarSegunPrioridad(int idUser, std::string prioridad, int e);
    void mostrarOrdenadosPorPrioridad(int idUser, int e);
    void cambiarEstado(Ticket ticket, std::string estado, int pos);

private:
    Ticket _ticket;
    TicketArchivo _ticketArch;
};

