#pragma once
#include <string>

class Fecha
{
public:
	Fecha(int dia, int mes, int anio);
	Fecha();
	virtual ~Fecha();

	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);

	int getDia();
	int getMes();
	int getAnio();
	void agregarDias(int num);
	std::string toString();

private:

	int _dia;
	int _mes;
	int _anio;
	int vDias[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

	bool verificarFecha(int dia, int mes, int anio);
	void setFechaDefault();
	void agregarDia(int &dia);
	void restarDia(int &dia);
	bool esBisiesto();

};
