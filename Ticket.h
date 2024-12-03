#pragma once
#include "Usuario.h"
#include "Fecha.h"


class Ticket
{
public:
	Ticket();
	~Ticket();

	int getId();
	std::string getTitulo();
	std::string getDescripcion();
	std::string getAcciones();
	std::string getPrioridad();
	std::string getEstado();
	int getCliente();
	int getResponsable();
	Fecha getFechaCreacion();
	Fecha getFechaLimite();

	void setId(int id);
	void setTitulo(std::string titulo);
	void setDescripcion(std::string descripcion);
	void setAcciones(std::string descripcion);
	bool setPrioridad(int prioridad);
	void setEstado(std::string estado);
	void setCliente(int idCliente);
	void setResponsable(int idResponsable);
	void setFechaCreacion(Fecha fechaCreacion);
	void setFechaLimite(Fecha fechaLimite);
	int diasRestantes();

private:

	int _id;
	char _titulo[20];
	char _descripcion[100];
	char _acciones[100];
	char _prioridad[10];  // Puede ser "Alta", "Media", "Baja"
	char _estado[15];     // Puede ser "Pendiente", "En Progreso","Resuelto", "Cerrado"
	int _idCliente;
	int _idResponsable;
	Fecha _fechaCreacion;
	Fecha _fechaLimite;
};
