#include <iostream>
#include "Usuario.h"
#include "UsuarioArchivo.h"
#include "UsuarioManager.h"
#include "Ticket.h"
#include "TicketArchivo.h"
#include "TicketManager.h"
using namespace std;


void cargarTicket();
void listarTickets();

Usuario logIn(string fileName);

int main()
{
	int usuario = 3;
	string fileName;

	cout<<"INICIAR SESION"<<endl;
	cout<<"1 - CLIENTE"<<endl;
	cout<<"2 - RESPONSABLE"<<endl;
	cout<<"0 - CERRAR PROGRAMA"<<endl;
	cin>>usuario;

	if(usuario == 1)
	{
		fileName = "clientes.dat";
	}
	else if(usuario == 2)
	{
		fileName = "responsables.dat";
	}

	cin.ignore();

	UsuarioManager userMan;
	Usuario usActivo;
	usActivo = logIn(fileName);
	TicketManager ticketMan;
	int opcion = 3;

	if(usActivo.getPermiso()=="Cliente")
	{
		while(opcion!=0)
		{
			cout<<"1 - CARGAR TICKET"<<endl;
			cout<<"2 - VER TODOS LOS TICKETS"<<endl;
			/// TODO cout<<"3 - VER TICKETS ESPERANDO REVISION"<<endl;
			cout<<"0 - CERRAR PROGRAMA"<<endl;
			cin>>opcion;

			switch(opcion)
			{

			case 1:
			{
				ticketMan.cargarTicket(usActivo);
				break;
			}

			case 2:
			{
				ticketMan.buscarPorIdUsuario(usActivo.getId());
				cout<<"----------------"<<endl;
				break;
			}
			}

			system("pause");
			system("cls");
		}
	}
	else if(usActivo.getPermiso()=="Responsable")
	{

	}
	else if(usActivo.getPermiso()=="Admin")
	{
		//userMan.cargarUsuario(fileName);
		//ticketMan.leerTodos();
	}


	return 0;
}

Usuario logIn(string fileName)
{
	UsuarioArchivo uArch;
	Usuario usuario;
	string user, passw;

	bool userCheck{},passwCheck{};
	while(!userCheck || !passwCheck)
	{
		system("cls");
		cout<<"INGRESAR NOMBRE DE USUARIO: ";
		cin>> user;

		userCheck = uArch.validarUser(user,fileName);
		if(!userCheck)
		{
			cout<<"EL USUARIO NO EXISTE"<<endl;
			system("pause");
		}
		else
		{
			cout<<"INGRESAR CONTRASENA: ";
			cin>> passw;

			passwCheck = uArch.validarPass(passw,fileName);

			if(!passwCheck)
			{
				cout<<"LA CONTRASENA ES INCORRECTA"<<endl<<endl;
				system("pause");

			}
		}
	}


	system("cls");
	return usuario = usuario.getUsuario(fileName,user);
}
