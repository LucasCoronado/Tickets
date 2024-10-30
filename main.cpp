#include <iostream>
#include "Cliente.h"
#include "Responsable.h"
#include "UsuarioArchivo.h"
#include "Ticket.h"
#include "TicketArchivo.h"
using namespace std;


void cargarCliente();
void listarClientes();
void cargarResponsable();
void listarResponsables();
void cargarTicket();

int main()
{
	/*int usuario = 3;
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
	}  */

   cargarTicket();

	return 0;
}

void cargarCliente()
{
	Cliente c1;
	UsuarioArchivo cArch;

	c1.cargarCliente("clientes.dat");

	if(cArch.guardar(c1))
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

	if(rArch.guardar(r1))
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

void cargarTicket(){

	Ticket t1;
	TicketArchivo tArch;

	t1.cargarTicket();

	if(tArch.guardar(t1))
	{
		cout << "Creacion de Ticket existoso"<<endl;
	}
	else
	{
		cout << "No se pudo crear el Ticket" << endl;
	}


}

