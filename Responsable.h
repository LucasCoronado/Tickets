#pragma once
#include <iostream>
#include "Usuario.h"


class Responsable: public Usuario
{
public:
	Responsable(std::string nombre, std::string apellido, std::string user, std::string passw, std::string fileName);
	Responsable();
	~Responsable();

	void cargarResponsable(std::string fileName);
	//int setIdMasUno(std::string fileName);
private:

    };


