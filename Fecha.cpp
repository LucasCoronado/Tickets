#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio)
{
	if(verificarFecha(dia,mes,anio))
	{

		_dia = dia;
		_mes=mes;
		_anio=anio;
	}
	else
	{
		setFechaDefault();
	}
	if(esBisiesto())
	{
		vDias[1]=29;
	}
}

Fecha::Fecha()
{
	setFechaDefault();
}

Fecha::~Fecha()
{
	//dtor
}

void Fecha::setDia(int dia)
{
	_dia = dia;
}
void Fecha::setMes(int mes)
{
	_mes=mes;
}
void Fecha::setAnio(int anio)
{
	_anio=anio;
}

int Fecha::getDia()
{
	return _dia;
}
int Fecha::getMes()
{
	return _mes;
}
int Fecha::getAnio()
{
	return _anio;
}

bool Fecha::verificarFecha(int dia, int mes, int anio)
{

	if(vDias[mes-1]>=dia && anio > 0)
	{
		return true;
	}

	return false;
}

void Fecha::setFechaDefault()
{

	_dia=1;
	_mes=1;
	_anio=2023;
}

bool Fecha::esBisiesto()
{

	if ((_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Fecha::agregarDia(int &dia)
{

	if(_dia == vDias[_mes-1])
	{
		if(_mes!= 12)
		{
			_mes+=1;
		}
		if(_mes == 12)
		{

			_mes = 1;
			_anio +=1;
		}
		_dia = 1;
	}
	else
	{
		_dia ++;
	}




}
void Fecha::restarDia(int &dia)
{
	if(_dia == 1)
	{

		if(_mes!=1)
		{
			_mes-=1;
		}
		else if(_mes==1)
		{
			_anio-=1;
			_mes = 12;
		}
		_dia = vDias[_mes-1];
	}
	else
	{
		_dia--;
	}
}

void Fecha::agregarDias(int num)
{

	if(num>0)
	{
		for(int i=0; i<num; i++)
		{
			agregarDia(_dia);
		}
	}
	else if(num<0)
	{
		num = num *-1;
		for(int i=0; i<num; i++)
		{
			restarDia(_dia);
		}
	}

}

std::string Fecha::toString(){


	std::string dia = std::to_string(_dia);
	std::string mes = std::to_string(_mes);
	std::string anio = std::to_string(_anio);

	std::string fechaF= dia+"/"+mes+"/"+anio;
	return fechaF;
}
