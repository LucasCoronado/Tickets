#include "Usuario.h"
#include <cstring>
using namespace std;


Usuario::Usuario()
{
	_id = -1;
	setNombre("Juan");
	setApellido("Perez");
	setUser("JuanP");
	setPassw("12345678");
}

Usuario::Usuario(string nombre, string apellido, string user, string passw, string fileName)
{

	setId(-1);
	setNombre(nombre);
	setApellido(apellido);
	setUser(user);
	setPassw(passw);

}

Usuario::~Usuario()
{
	//dtor
}


int Usuario::getId()
{
	return _id;
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

string Usuario::getPermiso()
{
	return _permiso;
}

string Usuario::getFileName()
{
	return _fileName;
}

void Usuario::setId(int id)
{
	_id = id;
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

	if(passw.size() < 30 && passw.size() > 4)
	{
		strcpy(_passw, passw.c_str());
		return true;
	}
	return false;
}

void Usuario::setPermiso(string permiso)
{

	if(permiso.size() < 30)
	{
		strcpy(_permiso, permiso.c_str());
	}
}

void Usuario::setFileName(string fileName)
{

	if(fileName.size() < 20)
	{
		strcpy(_fileName, fileName.c_str());
	}
}


Usuario Usuario::getUsuario(Usuario registro,string user){

	string fileName = registro.getFileName();

	FILE *pFile;

	pFile = fopen(fileName.c_str(),"rb");

	if(pFile == nullptr){

		return registro;
	}

	while(fread(&registro,sizeof(Usuario),1,pFile)==1){
		if(registro.getUser() == user){
			fclose(pFile);
			return registro;
		}
	}

	fclose(pFile);
	exit(-1);

}
