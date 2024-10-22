#pragma once
#include "Cliente.h"


class ClienteArchivo
{
    public:
        ClienteArchivo();
        ~ClienteArchivo();

        bool guardar(const Cliente &registro);
        int buscar(int codigo);

        bool leerTodos(Cliente registros[], int cantidad);

    private:
        std::string _fileName;
        int getCantidad();
};
