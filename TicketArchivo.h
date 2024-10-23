#pragma once
#include "Ticket.h"

class TicketArchivo
{
    public:
        TicketArchivo();
        virtual ~TicketArchivo();

         bool guardar(const Ticket &registro);
        int buscar(int codigo);

        bool leerTodos(Ticket registros[], int cantidad);
        Ticket leer(int pos);

    private:
        std::string _fileName;
        int getCantidad();
};

