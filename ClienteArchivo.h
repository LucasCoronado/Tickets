#pragma once
#include "Cliente.h"


class ClienteArchivo
{
    public:
        ClienteArchivo();
        ~ClienteArchivo();

        bool guardar(const Cliente &registro);
        int buscar(int codigo);

        void leerTodos();
        //int setId(std::string fileName);

    private:
        int getCantidad();
        std::string _fileName;
};
