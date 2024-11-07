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
	// /*
	int usuario = -1;
	int opcion = -1;
	string fileName;
	while(opcion!=9)
	{
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
		}else{
			return 0;
		}

		cin.ignore();

		UsuarioManager userMan;
		//userMan.leerTodos(fileName);
		//system("pause");

		Usuario usActivo;
		usActivo = logIn(fileName);

		Ticket ticket;
		TicketManager ticketMan;
		TicketArchivo ticketAr;


		//userMan.cargarUsuario(fileName);
		opcion = -1;
		if(usActivo.getPermiso()=="Cliente")
		{
			while(opcion!=0)
			{

				cout<<"Hola "<<usActivo.getUser()<<endl;
				cout<<"TENES: "<<ticketAr.cantidadTicketsPorUsuario(usActivo)<<" TICKETS CREADOS"<<endl;
				cout<<"1 - CARGAR TICKET"<<endl;
				cout<<"2 - VER TODOS LOS TICKETS"<<endl;
				cout<<"3 - TERMINAR TICKETS"<<endl;
				cout<<"0 - CERRAR SESION"<<endl;
				cout<<"9 - CERRAR PROGRAMA"<<endl;
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
				case 3:
				{
					int id,op = 3;
					cout<<"INGRESAR ID: ";
					cin>>id;

					int pos = ticketAr.buscar(id);
					ticket = ticketAr.leer(pos);

					if(ticket.getCliente() == usActivo.getId() && ticket.getEstado() == "En revision")
					{
						ticketMan.mostrarTicket(ticket);
						cout<<"EL TICKET ESTA RESUELTO ?"<<endl;
						cout<<"1 - SI / 2 - NO"<<endl;
						cin>>op;
					}
					else
					{
						cout<<"EL NUMERO DE ID NO CORRESPONDE A UN TICKET TUYO O AUN NO SE HA MANDADO A REVISION"<<endl;
					}


					if(op==1)
					{
						ticketMan.cambiarEstado(ticket, "Cerrado", pos);
					}
					else if(op==2)
					{
						ticketMan.cambiarEstado(ticket, "Pendiente", pos);
					}
				}
				case 9:{
					return 0;
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
				cout<<"TENES: "<<ticketAr.cantidadTicketsPorUsuario(usActivo)<<" TICKETS ASIGNADOS"<<endl;
				cout<<"1 - VER TICKETS ASIGNADOS"<<endl;
				cout<<"2 - CAMBIAR ESTADO DE TICKET"<<endl;
				cout<<"0 - CERRAR SESION"<<endl;
				cout<<"9 - CERRAR PROGRAMA"<<endl;
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
					int id,op = 3;
					cout<<"INGRESAR ID: ";
					cin>>id;

					int pos = ticketAr.buscar(id);
					ticket = ticketAr.leer(pos);

					if(ticket.getResponsable() == usActivo.getId())
					{
						if(ticket.getEstado()=="Pendiente")
						{
							ticketMan.mostrarTicket(ticket);
							cout<<"DESEA INICIAR A TRABAJAR EN EL TICKET ?"<<endl;
							cout<<"1 - SI / 2 - NO"<<endl;
							cin>>op;
							if(op==1)
							{
								ticketMan.cambiarEstado(ticket, "En progreso", pos);
							}
						}
						else if(ticket.getEstado()=="En progreso")
						{
							ticketMan.mostrarTicket(ticket);
							cout<<"DESEA MANDAR A REVISION EL TICKET ?"<<endl;
							cout<<"1 - SI / 2 - NO"<<endl;
							cin>>op;
							if(op==1)
							{
								string acciones;
								cin.ignore();
								cout<<"INDICAR ACCIONES REALIZADAS: ";
								getline(cin,acciones);
								ticket.setAcciones(acciones);
								ticketMan.cambiarEstado(ticket, "En revision", pos);
							}
						}
					}
					else
					{
						cout<<"EL NUMERO DE ID NO CORRESPONDE A UN TICKET TUYO"<<endl;

					}
					break;
				}
				case 9:{
					return 0;
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
	}
// */
	/*
	TicketManager ticketMan;
	ticketMan.leerTodos();
	 */
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
