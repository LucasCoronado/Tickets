#include "Menu.h"
using namespace std;

void Menu::ejecutar()
{
	int usuario = -1;
	int opcion = -1;

	while (opcion != 9)
	{
		cout << "INICIAR SESION" << endl;
		cout << "1 - CLIENTE" << endl;
		cout << "2 - RESPONSABLE" << endl;
		cout << "3 - ADMIN" << endl;
		cout << "0 - CERRAR PROGRAMA" << endl;
		cout << endl <<"INGRESE OPCION: ";
		cin >> usuario;

		if (usuario == 1)
		{
			fileName = "clientes.dat";
		}
		else if (usuario == 2 || usuario == 3)
		{
			fileName = "responsables.dat";
		}
		else if (usuario == 0)
		{
			return;
		}

		cin.ignore();

		UsuarioManager userMan;
		Usuario usuarioActivo = logIn(fileName);

		if (usuarioActivo.getPermiso() == "Cliente")
		{
			menuCliente(usuarioActivo);
		}
		else if (usuarioActivo.getPermiso() == "Responsable")
		{
			menuResponsable(usuarioActivo);
		}
		else if (usuarioActivo.getPermiso() == "Admin")
		{
			menuAdmin(usuarioActivo);
		}
	}
}


Usuario Menu::logIn(const string& fileName)
{
	UsuarioArchivo uArch;
	Usuario usuario;
	string user, passw;
	bool userCheck{}, passwCheck{};

	while (!userCheck || !passwCheck)
	{
		system("cls");
		cout << "INGRESAR NOMBRE DE USUARIO: ";
		cin >> user;

		userCheck = uArch.validarUser(user, fileName);
		if (!userCheck)
		{
			cout << "EL USUARIO NO EXISTE" << endl;
			system("pause");
		}
		else
		{
			cout << "INGRESAR CONTRASENA: ";
			cin >> passw;

			passwCheck = uArch.validarPass(passw, fileName);
			if (!passwCheck)
			{
				cout << "LA CONTRASENA ES INCORRECTA" << endl << endl;
				system("pause");
			}
		}
	}

	system("cls");
	return usuario = usuario.getUsuario(fileName, user);
}

void Menu::menuCliente(Usuario& usuarioActivo)
{
	int opcion = -1;

	while (opcion != 0)
	{
		cout << "Hola " << usuarioActivo.getUser() << endl;
		cout << "TENES: " << ticketAr.cantidadTicketsPorUsuario(usuarioActivo, "En progreso") << " TICKETS EN CURSO" << endl;
		cout << "TENES: " << ticketAr.cantidadTicketsPorUsuario(usuarioActivo, "En revision") << " TICKETS ESPERANDO TU REVISION" << endl;
		cout << "1 - CARGAR TICKET" << endl;
		cout << "2 - VER TODOS LOS TICKETS" << endl;
		cout << "3 - TERMINAR TICKETS" << endl;
		cout << "0 - CERRAR SESION" << endl;
		cout << "9 - CERRAR PROGRAMA" << endl;
		cout << endl <<"INGRESE OPCION: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			ticketMan.cargarTicket(usuarioActivo);
			break;
		case 2:
		{
			int e;
			cout << "1 - PENDIENTES" << endl;
			cout << "2 - EN PROGRESO" << endl;
			cout << "3 - EN REVISION" << endl;
			cout << "4 - CERRADOS" << endl;
			cout << endl <<"INGRESE OPCION: ";
			cin >> e;
			ticketMan.mostrarOrdenadosPorPrioridad(usuarioActivo.getId(), e);
			break;
		}
		case 3:
		{
			int id, op = 3;
			cout << "INGRESAR ID: ";
			cin >> id;

			int pos = ticketAr.buscar(id);
			ticket = ticketAr.leer(pos);

			if (ticket.getCliente() == usuarioActivo.getId() && ticket.getEstado() == "En revision")
			{
				ticketMan.mostrarTicket(ticket);
				cout << "EL TICKET ESTA RESUELTO ?" << endl;
				cout << "1 - SI / 2 - NO" << endl;
				cin >> op;
			}
			else
			{
				cout << "EL NUMERO DE ID NO CORRESPONDE A UN TICKET TUYO O AUN NO SE HA MANDADO A REVISION" << endl;
			}

			if (op == 1)
			{
				ticketMan.cambiarEstado(ticket, "Cerrado", pos);
			}
			else if (op == 2)
			{
				ticketMan.cambiarEstado(ticket, "Pendiente", pos);
			}
			break;
		}
		case 9:
			exit(0);
		}
		system("pause");
		system("cls");
	}
}

void Menu::menuResponsable(Usuario& usuarioActivo)
{
	int opcion = -1;

	while (opcion != 0)
	{
		cout << "TENES: " << ticketAr.cantidadTicketsPorUsuario(usuarioActivo, "Pendiente") << " TICKETS PENDIENTES DE APERTURA" << endl;
		cout << "TENES: " << ticketAr.cantidadTicketsPorUsuario(usuarioActivo, "En progreso") << " TICKETS EN PROGRESO" << endl;
		cout << "TENES: " << ticketAr.cantidadTicketsPorUsuario(usuarioActivo, "En revision") << " TICKETS ESPERANDO APROBACION" << endl;
		cout << "1 - VER TICKETS ASIGNADOS" << endl;
		cout << "2 - CAMBIAR ESTADO DE TICKET" << endl;
		cout << "0 - CERRAR SESION" << endl;
		cout << "9 - CERRAR PROGRAMA" << endl;
		cout << endl <<"INGRESE OPCION: ";
		cin >> opcion;

		switch (opcion)
		{

		case 1:
		{
			int e;
			cout << "1 - PENDIENTES" << endl;
			cout << "2 - EN PROGRESO" << endl;
			cout << "3 - EN REVISION" << endl;
			cout << "4 - CERRADOS" << endl;
			cout << endl <<"INGRESE OPCION: ";
			cin >> e;

			ticketMan.mostrarOrdenadosPorPrioridad(usuarioActivo.getId(), e);
			break;
		}
		case 2:
		{
			int id, op = 3;
			cout << "INGRESAR ID: ";
			cin >> id;
			int pos = ticketAr.buscar(id);
			ticket = ticketAr.leer(pos);

			if (ticket.getResponsable() == usuarioActivo.getId())
			{
				if (ticket.getEstado() == "Pendiente")
				{
					ticketMan.mostrarTicket(ticket);
					cout << "DESEA INICIAR A TRABAJAR EN EL TICKET ?" << endl;
					cout << "1 - SI / 2 - NO" << endl;
					cin >> op;
					if (op == 1)
					{
						ticketMan.cambiarEstado(ticket, "En progreso", pos);
					}
				}
				else if (ticket.getEstado() == "En progreso")
				{
					ticketMan.mostrarTicket(ticket);
					cout << "DESEA MANDAR A REVISION EL TICKET ?" << endl;
					cout << "1 - SI / 2 - NO" << endl;
					cin >> op;
					if (op == 1)
					{
						string acciones;
						cin.ignore();
						cout << "INDICAR ACCIONES REALIZADAS: ";
						getline(cin, acciones);
						ticket.setAcciones(acciones);
						ticketMan.cambiarEstado(ticket, "En revision", pos);
					}
				}
			}
			else
			{
				cout << "EL NUMERO DE ID NO CORRESPONDE A UN TICKET TUYO" << endl;
			}
			break;
		}
		case 9:
			exit(0);
		}
		system("pause");
		system("cls");
	}
}

void Menu::menuAdmin(Usuario& usuarioActivo)
{

	int opcion = -1;

	while(opcion!=0)
	{
		cout<<"1 - VER CLIENTES"<<endl;
		cout<<"2 - VER RESPONSABLES"<<endl;
		cout<<"3 - VER TICKETS POR CLIENTE"<<endl;
		cout<<"4 - VER TICKETS POR RESPONSABLE"<<endl;
		cout<<"5 - VER TICKETS ABIERTOS"<<endl;
		cout<<"6 - VER TICKETS CERRADOS"<<endl;
		cout<<"7 - CARGAR NUEVO USUARIO"<<endl;
		cout<<"8 - BUSCAR USUARIO"<<endl;
		cout<<"0 - CERRAR SESION"<<endl;
		cout<<"9 - CERRAR PROGRAMA"<<endl;
		cout << endl <<"INGRESE OPCION: ";
		cin>>opcion;

		switch(opcion)
		{

		case 1:
		{
			userMan.leerTodos("clientes.dat");
			system("pause");
			break;
		}
		case 2:
		{
			userMan.leerTodos("responsables.dat");
			system("pause");
			break;
		}
		case 3:
		{
			int idUser;
			cout<<"ID USUARIO: ";
			cin>>idUser;
			ticketMan.buscarPorIdUsuario(idUser, "CLIENTE");
			system("pause");
			break;
		}
		case 4:
		{
			int idUser;
			cout<<"ID USUARIO: ";
			cin>>idUser;
			ticketMan.buscarPorIdUsuario(idUser, "RESPONSABLE");
			system("pause");
			break;
		}
		case 5:
		{
			int e;
			cout<<"1 - EN PROGRESO"<<endl;
			cout<<"2 - EN REVISION"<<endl;
			cout << endl <<"INGRESE OPCION: ";
			cin>>e;

			UsuarioArchivo userAr("clientes.dat");
			for(int i=1; i<userAr.getCantidad(); i++)
			{
				ticketMan.mostrarOrdenadosPorPrioridad(i,e+1);
				system("pause");
			}
			system("pause");
			break;
		}
		case 6:
		{
			UsuarioArchivo userAr("clientes.dat");
			for(int i=1; i<userAr.getCantidad(); i++)
			{
				ticketMan.mostrarOrdenadosPorPrioridad(i,4);
			}
			system("pause");
			break;
		}
		case 7:
		{
			int u;
			cout<<"1 - CARGAR CLIENTE"<<endl;
			cout<<"2 - CARGAR RESPONSABLE"<<endl;
			cout << endl <<"INGRESE OPCION: ";
			cin >>u;

			if(u==1)
			{
				fileName = "clientes.dat";
			}
			else if(u == 2)
			{
				fileName = "responsables.dat";
			}
			cin.ignore();
			userMan.cargarUsuario(fileName);
			break;
		}
		case 8:
		{
			string username;
			int u;
			cout<<"1 - BUSCAR CLIENTE"<<endl;
			cout<<"2 - BUSCAR RESPONSABLE"<<endl;
			cout << endl <<"INGRESE OPCION: ";
			cin >>u;

			if(u==1)
			{
				fileName = "clientes.dat";
			}
			else if(u == 2)
			{
				fileName = "responsables.dat";
			}
			UsuarioArchivo userAr(fileName);
			cout<<"1 - BUSCAR POR ID"<<endl;
			cout<<"2 - BUSCAR POR NOMBRE DE USUARIO"<<endl;
			cout << endl <<"INGRESE OPCION: ";
			cin>>u;

			if(u==1)
			{
				cout<<"INGRESAR ID: ";
				cin>>u;
			}
			else if(u==2)
			{

				cout<<"INGRESAR NOMBRE DE USUARIO: "<<endl;
				cin>>username;
				u = userAr.buscarPorUser(username) +1;
			}

			Usuario us = userAr.leer(u-1);
			userMan.mostrarUsuario(us);

			cout<<"TIENE "<<ticketAr.cantidadTicketsPorUsuario(us,"Pendiente")<<" TICKETS PENDIENTES DE APERTURA"<<endl;
			cout<<"TIENE "<<ticketAr.cantidadTicketsPorUsuario(us,"En progreso")<<" TICKETS EN PROGRESO"<<endl;
			cout<<"TIENE "<<ticketAr.cantidadTicketsPorUsuario(us,"En revision")<<" TICKETS ESPERANDO APROBACION"<<endl;
			cout<<"TIENE "<<ticketAr.cantidadTicketsPorUsuario(us,"Cerrado")<<" TICKETS CERRADOS"<<endl;


			system("pause");
			break;
		}
		case 9:
		{
			exit(0);
		}
		}

		system("cls");
	}

}

