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
	///CARGA DE USUARIO

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
	}else if(usuario == 2){
		fileName = "responsables.dat";
	}

	cin.ignore();

	UsuarioManager userMan;

	userMan.cargarUsuario(fileName);
	//userMan.ListarTodos(fileName);
	//userMan.ListarXId(fileName);



	//UsuarioManager userMan;
	/*userMan.leerTodos(fileName);
	Usuario usActivo;
	system("pause");

	usActivo = logIn(fileName);

	TicketManager ticketMan;

	ticketMan.cargarTicket(usActivo);
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
