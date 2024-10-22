#include "Ticket.h"
#include <iostream>
#include <cstring>
using namespace std;

Ticket::Ticket()
{
	setId(-1);
	setTitulo("Titulo generico");
	setDescripcion("Descripcion generica");
	setPrioridad("Alta");
	setEstado("Pendiente");
	setCliente(_cliente);
	setResponsable(_responsable);
	setFechaCreacion(_fechaCreacion);
	setFechaLimite(_fechaLimite);
}

Ticket::~Ticket()
{
	//dtor
}

void Ticket::mostrarTicket(){

    cout<<"TICKET #"<<getId()<<endl<<endl;

    cout<<"Titulo: "<<getTitulo()<<endl;
    cout<<"Descripcion: "<<getDescripcion()<<endl;
    cout<<"Prioridad: "<<getPrioridad()<<endl;
    cout<<"Estado: "<<getEstado()<<endl;
    cout<<"Cliente: "<<getCliente().getUser()<<endl;
    cout<<"Responsable Asignado: "<<getResponsable().getUser()<<endl;
    cout<<"Fecha de Creacion: "<<getFechaCreacion().toString()<<endl;
    cout<<"Fecha Limite: "<<getFechaLimite().toString()<<endl;
}

int Ticket::getId()
{
	return _id;
}
string Ticket::getTitulo()
{
	return _titulo;
}
string Ticket::getDescripcion()
{
	return _descripcion;
}
string Ticket::getPrioridad()
{
	return _prioridad;
}
string Ticket::getEstado()
{
	return _estado;
}
Cliente Ticket::getCliente()
{
	return _cliente;
}
Responsable Ticket::getResponsable()
{
	return _responsable;
}

Fecha Ticket::getFechaCreacion()
{
	return _fechaCreacion;
}

Fecha Ticket::getFechaLimite()
{
	return _fechaLimite;
}


void Ticket::setId(int id)
{
	_id = id;
}
void Ticket::setTitulo(string titulo)
{
	if(titulo.size() < 20)
	{
		strcpy(_titulo, titulo.c_str());
	}
}
void Ticket::setDescripcion(string descripcion)
{
	if(descripcion.size() < 100)
	{
		strcpy(_descripcion, descripcion.c_str());
	}
}
void Ticket::setPrioridad(string prioridad)
{
	if(prioridad.size() < 30)
	{
		strcpy(_prioridad, prioridad.c_str());
	}
}
void Ticket::setEstado(string estado)
{
	if(estado.size() < 30)
	{
		strcpy(_estado, estado.c_str());
	}
}
void Ticket::setCliente(Cliente cliente)
{
	_cliente = cliente;
}
void Ticket::setResponsable(Responsable responsable)
{
	_responsable = responsable;
}
void Ticket::setFechaCreacion(Fecha fechaCreacion)
{
	_fechaCreacion = fechaCreacion;
}
void Ticket::setFechaLimite(Fecha fechaLimite)
{
	_fechaLimite = fechaLimite;
}
