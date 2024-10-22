#pragma once
#include <iostream>
#include "Usuario.h"


class Responsable: public Usuario
{
public:
	Responsable(std::string nombre, std::string apellido, std::string user, std::string passw);
	Responsable();
	~Responsable();

private:

    int maxTicketsAsignados = 5;
};


