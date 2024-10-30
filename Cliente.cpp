#include "Cliente.h"
using namespace std;

Cliente::Cliente(string nombre, string apellido, string user, string passw, string fileName):Usuario(nombre, apellido, user, passw, fileName)
{
}

Cliente::Cliente():Usuario()
{
	setFileName("clientes.dat");
}

Cliente::~Cliente()
{
	//dtor
}


void Cliente::cargarCliente(string fileName){

	cout<<"REGISTRO DE CLIENTE"<<endl;
	cargarUsuario(fileName);
	setPermiso("Cliente");

}
