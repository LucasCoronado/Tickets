#include <iostream>
#include "Usuario.h"
#include "Cliente.h"
//#include "ClienteArchivo.h"
#include "Responsable.h"
//#include "ResponsableArchivo.h"
#include "UsuarioArchivo.h"
using namespace std;


void cargarCliente();
void listarClientes();
void cargarResponsable();
void listarResponsables();

int main()
{
	int usuario = 3;
	while(usuario != 0){
	cout<<"CARGA DE USUARIO"<<endl<<endl;

	cout<<"1 - Cliente"<<endl;
	cout<<"2 - Responsable"<<endl;

	cin>>usuario;
	cin.ignore();

	switch(usuario)
	{
	case 1:
		cargarCliente();
		listarClientes();
		break;
	case 2:
		cargarResponsable();
		listarResponsables();
	}
	}

	return 0;
}

void cargarCliente()
{
	Cliente c1;
	UsuarioArchivo cArch;

	c1.cargarCliente("clientes.dat");

	if(cArch.guardar(c1,"clientes.dat"))
	{
		cout << "Registro de cliente existoso"<<endl;
	}
	else
	{
		cout << "No se pudo registrar el cliente" << endl;
	}

	system("pause");
}

void listarClientes()
{

	UsuarioArchivo cArch;
	cArch.leerTodos("clientes.dat");

	system("pause");
}

void cargarResponsable()
{
	Responsable r1;
	UsuarioArchivo rArch;

	r1.cargarResponsable("responsables.dat");

	if(rArch.guardar(r1, "responsables.dat"))
	{
		cout << "Registro de Responsable existoso"<<endl;
	}
	else
	{
		cout << "No se pudo registrar el Responsable" << endl;
	}

	system("pause");
}

void listarResponsables()
{

	UsuarioArchivo cArch;
	cArch.leerTodos("responsables.dat");

	system("pause");
}
