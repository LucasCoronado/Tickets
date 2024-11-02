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

	void ListarTodos(std::string fileName);
    void ListarXId(std::string fileName);

	int generarNuevoId(std::string fileName);


private:

	Usuario _usuario;

};

