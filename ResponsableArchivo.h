#pragma once
#include "Responsable.h"


class ResponsableArchivo
{
public:
	ResponsableArchivo();
	~ResponsableArchivo();

	bool guardar(const Responsable &registro);
	int buscar(int codigo);

	bool leerTodos(Responsable registros[], int cantidad);

private:
	std::string _fileName;
	int getCantidad();
};

