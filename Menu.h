#pragma once

#include <iostream>
#include "Usuario.h"
#include "UsuarioManager.h"
#include "UsuarioArchivo.h"
#include "Ticket.h"
#include "TicketArchivo.h"
#include "TicketManager.h"

class Menu
{
public:
	void ejecutar();

private:
	Usuario logIn(const std::string& fileName);
	void menuCliente(Usuario& usuarioActivo);
    void menuResponsable(Usuario& usuarioActivo);
    void menuAdmin(Usuario& usuarioActivo);

    TicketManager ticketMan;
    TicketArchivo ticketAr;
    Ticket ticket;
    UsuarioManager userMan;
    void validarInt(int &i, int opIn, int opFin);
    std::string fileName;
};
