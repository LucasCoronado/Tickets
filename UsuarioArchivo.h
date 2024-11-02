#pragma once
#include "Usuario.h"

class UsuarioArchivo
{
    public:
        UsuarioArchivo(std::string fileName);
        UsuarioArchivo();
        virtual ~UsuarioArchivo();

        int getCantidad();
        bool guardar(const Usuario &registro);
        Usuario leer(int id);
        int buscar(int id);

        bool validarUser(std::string user, Usuario &registro);
        bool validarPass(std::string passw, Usuario &registro);



    private:

        std::string _fileName;
};


