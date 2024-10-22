#pragma once
#include <iostream>


class Usuario
{
public:
	Usuario();
	Usuario(std::string nombre, std::string apellido, std::string user, std::string passw);

	~Usuario();

	std::string getNombre();
	std::string getApellido();
	std::string getUser();
	std::string getPassw();
	std::string getPermiso();

	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setUser(std::string user);
	bool setPassw(std::string passw);
	void setPermiso(std::string permiso);

	bool autenticarLogin(std::string user, std::string passw, std::string permiso);

protected:

	char _nombre[30];
	char _apellido[30];
	char _user[30];
	char _passw[30];

	char _permiso[30];  // Puede ser "Cliente","Responsable","Admin"

private:
};

