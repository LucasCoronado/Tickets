#pragma once
#include <iostream>
#include "Usuario.h"

class Cliente: public Usuario
{
    public:
        Cliente(std::string nombre, std::string apellido, std::string user, std::string passw);
        Cliente();
        ~Cliente();

   private:

       int maxTicketsCreados = 10;
};
