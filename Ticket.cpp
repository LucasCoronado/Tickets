#include "Ticket.h"
#include <iostream>
#include <cstring>
using namespace std;

Ticket::Ticket()
{
	setId(-1);
	setTitulo("Titulo generico");
	setDescripcion("Descripcion generica");
	setPrioridad(1);
	setEstado("Pendiente");
	setCliente(-1);
	setResponsable(-1);
	setFechaCreacion(_fechaCreacion);
	setFechaLimite(_fechaLimite);
}

Ticket::~Ticket()
{
	//dtor
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
string Ticket::getAcciones()
{
	return _acciones;
}
string Ticket::getPrioridad()
{
	return _prioridad;
}
string Ticket::getEstado()
{
	return _estado;
}
int Ticket::getCliente()
{
	return _idCliente;
}
int Ticket::getResponsable()
{
	return _idResponsable;
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
void Ticket::setAcciones(string acciones)
{
	if(acciones.size() < 100)
	{
		strcpy(_acciones, acciones.c_str());
	}
}
bool Ticket::setPrioridad(int prioridad)
{
	switch(prioridad)
	{

	case 1:
	{
		strcpy(_prioridad, "ALTA");
		break;
	}
	case 2:
	{
		strcpy(_prioridad, "MEDIA");
		break;
	}
	case 3:
	{
		strcpy(_prioridad, "BAJA");
		break;
	}
	default:{
		return false;
	}
	}
	return true;

}
void Ticket::setEstado(string estado)
{
	if(estado.size() < 30)
	{
		strcpy(_estado, estado.c_str());
	}
}
void Ticket::setCliente(int idCliente)
{
	_idCliente = idCliente;
}
void Ticket::setResponsable(int idResponsable)
{
	_idResponsable = idResponsable;
}

void Ticket::setFechaCreacion(Fecha fechaCreacion)
{
	_fechaCreacion = fechaCreacion;
}
void Ticket::setFechaLimite(Fecha fechaLimite)
{
	_fechaLimite = fechaLimite;
}

int Ticket::diasRestantes(){
	int dias;
	Fecha f;

	dias = f.diasHasta(_fechaLimite);

	return dias;
}
