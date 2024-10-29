#include "Cliente.h"
using namespace std;

Cliente::Cliente(string nombre, string apellido, string user, string passw, string fileName):Usuario(nombre, apellido, user, passw, fileName)
{
}

Cliente::Cliente():Usuario()
{
}

Cliente::~Cliente()
{
	//dtor
}


void Cliente::cargarCliente(string fileName){

	cargarUsuario(fileName);
	setPermiso("Cliente");

}
