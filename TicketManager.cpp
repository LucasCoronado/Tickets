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
	int prioridad,dia,mes,anio,limite;

	cin.ignore();
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
	cout<<"FECHA"<<endl;
	cout<<"DIA: ";
	cin>>dia;
	fecha.setDia(dia);
	cout<<"MES: ";
	cin>>mes;
	fecha.setMes(mes);
	cout<<"ANIO: ";
	cin>>anio;
	fecha.setAnio(anio);

	while(fecha.verificarFecha(dia,mes,anio) == false)
	{
		cout<<"FECHA NO VALIDA"<<endl;
		cout<<"--------------"<<endl;
		cout<<"FECHA"<<endl;
		cout<<"DIA: ";
		cin>>dia;
		fecha.setDia(dia);
		cout<<"MES: ";
		cin>>mes;
		fecha.setMes(mes);
		cout<<"ANIO: ";
		cin>>anio;
		fecha.setAnio(anio);
	}

	_ticket.setFechaCreacion(fecha);

	cout<<"LIMITE DE TIEMPO EN DIAS: ";
	cin>>limite;
	fecha.agregarDias(limite);
	_ticket.setFechaLimite(fecha);

	_ticket.setEstado("Pendiente");
	_ticket.setId(generarNuevoId());
	_ticket.setCliente(usuario.getId());

	UsuarioArchivo usAr("responsables.dat");
	_ticket.setResponsable(usAr.asignarResponsable());

	_ticketArch.guardar(_ticket);


}

void TicketManager::mostrarTicket(Ticket ticket)
{
	UsuarioArchivo cliente("clientes.dat");
	UsuarioArchivo resp("responsables.dat");
	cout<<"TICKET #"<<_ticket.getId()<<endl<<endl;

	cout<<"Titulo: "<<_ticket.getTitulo()<<endl;
	cout<<"Descripcion: "<<_ticket.getDescripcion()<<endl;
	cout<<"Prioridad: "<<_ticket.getPrioridad()<<endl;
	cout<<"Estado: "<<_ticket.getEstado()<<endl;
	cout<<"Cliente: "<<cliente.leer(_ticket.getCliente()).getUser()<<endl;
	cout<<"Responsable Asignado: "<<resp.leer(_ticket.getResponsable()).getUser()<<endl;
	cout<<"Fecha de Creacion: "<<_ticket.getFechaCreacion().toString()<<endl;
	cout<<"Fecha Limite: "<<_ticket.getFechaLimite().toString()<<endl;
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

void TicketManager::buscarPorIdUsuario(int idUser)
{

	int i, cantidadRegistros = _ticketArch.getCantidad();
	for(i=0; i<cantidadRegistros; i++)
	{
		_ticket = _ticketArch.leer(i);
		if (_ticket.getCliente() == idUser)
		{
		 mostrarTicket(_ticket);
		 cout<<endl;
		}
	}

}

void TicketManager::mostrarOrdenadosPorPrioridad(int idUser){

	for(int i=0;i<_ticketArch.getCantidad();i++){

		_ticket = _ticketArch.leer(i);
		if(_ticket.getPrioridad()=="ALTA" && _ticket.getCliente() == idUser){
			mostrarTicket(_ticket);
			cout<<endl;
		}
	}
	for(int i=0;i<_ticketArch.getCantidad();i++){

		_ticket = _ticketArch.leer(i);
		if(_ticket.getPrioridad()=="MEDIA" && _ticket.getCliente() == idUser){
			mostrarTicket(_ticket);
			cout<<endl;
		}
	}for(int i=0;i<_ticketArch.getCantidad();i++){

		_ticket = _ticketArch.leer(i);
		if(_ticket.getPrioridad()=="BAJA" && _ticket.getCliente() == idUser){
			mostrarTicket(_ticket);
			cout<<endl;
		}
	}

}
