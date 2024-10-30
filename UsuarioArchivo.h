#pragma once
#include "Usuario.h"

class UsuarioArchivo
{
    public:
        UsuarioArchivo();
        virtual ~UsuarioArchivo();

        bool guardar(const Usuario &registro, std::string fileName);
        void leerTodos(std::string fileName);
        int getCantidad(std::string fileName);

    private:
};


