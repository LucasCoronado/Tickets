#include <iostream>
#include "Usuario.h"
#include "UsuarioArchivo.h"
#include "UsuarioManager.h"
#include "Ticket.h"
#include "TicketArchivo.h"
#include "TicketManager.h"
using namespace std;

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
	userMan.leerTodos(fileName);
	system("pause");

	Usuario usActivo;
	usActivo = logIn(fileName);

	TicketManager ticketMan;
	TicketArchivo ticketAr;
	int opcion = 3;

	//userMan.cargarUsuario(fileName);

	if(usActivo.getPermiso()=="Cliente")
	{
		while(opcion!=0)
		{

			userMan.mostrarUsuario(usActivo);
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
				ticketMan.buscarPorIdUsuario(usActivo.getId(),"CLIENTE");
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
		while(opcion!=0)
		{

			cout<<"1 - VER TICKETS ASIGNADOS"<<endl;
			cout<<"2 - VER TICKET POR ID"<<endl;
			cout<<"0 - CERRAR PROGRAMA"<<endl;
			cin>>opcion;

			switch(opcion)
			{

			case 1:
			{
				ticketMan.buscarPorIdUsuario(usActivo.getId(),"RESPONSABLE");
				break;
			}
			case 2:
			{
				int id;
				cout<<"INGRESAR ID: ";
				cin>>id;

				Ticket ticket;
				ticket = ticketAr.leer(id-1);
				if(ticket.getResponsable() == usActivo.getId()){
					ticketMan.mostrarTicket(ticket);
				}else{
					cout<<"EL NUMERO DE ID NO CORRESPONDE A UN TICKET TUYO";
				}
				break;
			}
			}
			system("pause");
			system("cls");
		}
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
