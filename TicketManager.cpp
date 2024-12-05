#include "TicketManager.h"
#include <iostream>
using namespace std;

TicketManager::TicketManager()
{
	//ctor
}

TicketManager::~TicketManager()
{
	//dtor
}


void TicketManager::cargarTicket(Usuario usuario)
{

	string titulo,descripcion;
	int prioridad,limite;

	cout<<"TITULO: ";
	getline(cin, titulo);
	_ticket.setTitulo(titulo);

	cout<<"DESCRIPCION: ";
	getline(cin, descripcion);
	_ticket.setDescripcion(descripcion);

	cout<<"PRIORIDAD: "<<endl;
	cout<<"1-ALTA / 2-MEDIA / 3-BAJA"<<endl;
	cin>>prioridad;

	while(_ticket.setPrioridad(prioridad) == false)
	{

		cout<<"VALOR NO TOLERADO"<<endl;
		cout<<"PRIORIDAD: "<<endl;
		cout<<"1-ALTA / 2-MEDIA / 3-BAJA"<<endl;
		cin>>prioridad;
	}

	Fecha fecha;
	fecha.setFechaActual();

	_ticket.setFechaCreacion(fecha);

	cout<<"LIMITE DE TIEMPO EN DIAS: ";
	cin>>limite;
	fecha.agregarDias(limite);
	_ticket.setFechaLimite(fecha);

	_ticket.setEstado("Pendiente");
	_ticket.setId(generarNuevoId());

	_ticket.setCliente(usuario.getId());

	UsuarioManager usMan;
	_ticket.setResponsable(usMan.asignarResponsable());

	_ticketArch.guardar(_ticket);
	cin.ignore();

}

void TicketManager::mostrarTicket(Ticket ticket)
{
	UsuarioArchivo cliente("clientes.dat");
	UsuarioArchivo resp("responsables.dat");
	cout<<"TICKET #"<<ticket.getId()<<endl<<endl;

	cout<<"Titulo: "<<ticket.getTitulo()<<endl;
	cout<<"Descripcion: "<<ticket.getDescripcion()<<endl;
	cout<<"Prioridad: "<<ticket.getPrioridad()<<endl;
	cout<<"Estado: "<<ticket.getEstado()<<endl;
	cout<<"Cliente: "<<cliente.leer(ticket.getCliente()-1).getUser()<<endl;
	cout<<"Responsable Asignado: "<<resp.leer(ticket.getResponsable()-1).getUser()<<endl;
	cout<<"Fecha de Creacion: "<<ticket.getFechaCreacion().toString()<<endl;
	cout<<"Fecha Limite: "<<ticket.getFechaLimite().toString()<<endl;

	Fecha fecha;

	cout<<"Falta: "<<fecha.diasHasta(ticket.getFechaLimite())<<" dias para la fecha limite."<<endl;
	//cout<<"Falta: "<<ticket.diasRestantes()<<" dias para la fecha limite."<<endl;

	if(ticket.getEstado()=="En revision" || ticket.getEstado()=="Cerrado"){
		cout<<"Acciones tomadas: "<<ticket.getAcciones()<<endl;
	}

}

void TicketManager::leerTodos()
{
	int cantidadRegistros = _ticketArch.getCantidad();

	for(int i=0; i<cantidadRegistros; i++)
	{
		_ticket = _ticketArch.leer(i);
		mostrarTicket(_ticket);
		cout<<endl;
	}
}

int TicketManager::generarNuevoId()
{
	return _ticketArch.getCantidad() + 1;
}


void TicketManager::buscarPorIdUsuario(int idUser, string tipoUser)
{
	int i, cantidadRegistros = _ticketArch.getCantidad();
	for(i=0; i<cantidadRegistros; i++)
	{
		_ticket = _ticketArch.leer(i);
		if(tipoUser == "CLIENTE")
		{
			if (_ticket.getCliente() == idUser)
			{
				mostrarTicket(_ticket);
				cout<<endl;
			}
		}
		if(tipoUser == "RESPONSABLE")
		{
			if (_ticket.getResponsable() == idUser)
			{
				mostrarTicket(_ticket);
				cout<<endl;
			}
		}

	}

}

void TicketManager::mostrarSegunPrioridad(int idUser, string prioridad,int e){

string estado[4] = {"Pendiente","En progreso","En revision","Cerrado"};
for(int i=0; i<_ticketArch.getCantidad(); i++)
	{

		_ticket = _ticketArch.leer(i);
		if(_ticket.getPrioridad()==prioridad && (_ticket.getCliente() == idUser || _ticket.getResponsable() == idUser) && _ticket.getEstado() == estado[e-1])
		{
			mostrarTicket(_ticket);
			cout<<endl;
			c++;
		}
	}
}

void TicketManager::mostrarOrdenadosPorPrioridad(int idUser,int e)
{
	system("cls");
	mostrarSegunPrioridad(idUser, "ALTA", e);
	mostrarSegunPrioridad(idUser, "MEDIA",e);
	mostrarSegunPrioridad(idUser, "BAJA",e);
}

void TicketManager::cambiarEstado(Ticket ticket, string estado, int pos)
{

	ticket.setEstado(estado);

	if(_ticketArch.modificarTicket(ticket,pos))
	{
		cout<<"El nuevo estado del ticket es: "<< estado <<endl ;
	}
	else
	{
		cout<<"No se pudo actualizar el estado"<<endl;
	}

}



