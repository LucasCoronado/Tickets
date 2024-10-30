#pragma once
#include <iostream>
#include "Usuario.h"


class Cliente: public Usuario
{
public:
	Cliente(std::string nombre, std::string apellido, std::string user, std::string passw, std::string fileName);
	Cliente();
	~Cliente();

	void cargarCliente(std::string fileName);
private:
};
