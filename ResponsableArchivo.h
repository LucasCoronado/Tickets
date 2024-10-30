#pragma once
#include "Responsable.h"


class ResponsableArchivo
{
public:
	ResponsableArchivo();
	~ResponsableArchivo();

	bool guardar(const Responsable &registro);
	int buscar(int codigo);

	void leerTodos();
	//int setId(std::string fileName);

private:
	std::string _fileName;
	int getCantidad();
};

