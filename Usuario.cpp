#include "Usuario.h"
#include <cstring>
using namespace std;


Usuario::Usuario()
{
	setNombre("Juan");
	setApellido("Perez");
	setUser("JuanP");
	setPassw("12345678");
}

Usuario::Usuario(string nombre, string apellido, string user, string passw)
{

	setNombre(nombre);
	setApellido(apellido);
	setUser(user);
	setPassw(passw);

}

Usuario::~Usuario()
{
	//dtor
}


string Usuario::getNombre()
{
	return _nombre;
}
string Usuario::getApellido()
{
	return _apellido;
}
string Usuario::getUser()
{
	return _user;
}
string Usuario::getPassw()
{
	return _passw;
}

string Usuario::getPermiso(){
    return _permiso;
}

void Usuario::setNombre(string nombre)
{
	if(nombre.size() < 30)
	{
		strcpy(_nombre, nombre.c_str());
	}
}
void Usuario::setApellido(string apellido)
{
	if(apellido.size() < 30)
	{
		strcpy(_apellido, apellido.c_str());
	}
}
void Usuario::setUser(string user)
{
	if(user.size() < 30)
	{
		strcpy(_user, user.c_str());
	}
}
bool Usuario::setPassw(string passw)
{

	if(passw.size() < 30 && passw.size() > 8)
	{
		strcpy(_passw, passw.c_str());
		return true;
	}
	return false;
}

void Usuario::setPermiso(string permiso){

    if(permiso.size() < 30)
	{
		strcpy(_permiso, permiso.c_str());
	}
}
