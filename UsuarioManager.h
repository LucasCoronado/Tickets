#pragma once
#include "Usuario.h"
#include "UsuarioArchivo.h"


class UsuarioManager
{
public:
	UsuarioManager();
	virtual ~UsuarioManager();

	void cargarUsuario(std::string fileName);
	void mostrarUsuario(Usuario usuario);

	void leerTodos(std::string fileName);
    void leerPorId(std::string fileName);

	int generarNuevoId(std::string fileName);



private:

	Usuario _usuario;

};

