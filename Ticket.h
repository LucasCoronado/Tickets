#pragma once
#include "Cliente.h"
#include "Responsable.h"
#include "Fecha.h"



class Ticket
{
public:
	Ticket();
	~Ticket();

	int getId();
	std::string getTitulo();
	std::string getDescripcion();
	std::string getPrioridad();
	std::string getEstado();
	Cliente getCliente();
	Responsable getResponsable();
	Fecha getFechaCreacion();
	Fecha getFechaLimite();

	void setId(int id);
	void setTitulo(std::string titulo);
	void setDescripcion(std::string descripcion);
	void setPrioridad(std::string prioridad);
	void setEstado(std::string estado);
	void setCliente(Cliente cliente);
	void setResponsable(Responsable responsable);
	void setFechaCreacion(Fecha fechaCreacion);
	void setFechaLimite(Fecha fechaLimite);

	void mostrarTicket();

private:

	int _id;
	char _titulo[20];
	char _descripcion[100];
	char _prioridad[10];  // Puede ser "Alta", "Media", "Baja"
	char _estado[15];     // Puede ser "Pendiente", "En Progreso","Resuelto", "Cerrado"
	Cliente _cliente;
	Responsable _responsable;
	Fecha _fechaCreacion;
	Fecha _fechaLimite;
};
