#include <iostream>
#include "Usuario.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "Responsable.h"
#include "ResponsableArchivo.h"
using namespace std;


void cargarCliente();
void listarClientes();
void cargarResponsable();
void listarResponsables();

int main()
{
    //cargarCliente();

    //listarClientes();

	cargarResponsable();
	listarResponsables();
	return 0;
}

void cargarCliente()
{
	Cliente c1;
	ClienteArchivo cArch;

	c1.cargarCliente("clientes.dat");

	if(cArch.guardar(c1))
	{
		cout << "Registro de cliente existoso"<<endl;
	}
	else
	{
		cout << "No se pudo registrar el cliente" << endl;
	}

	system("pause");
}

void listarClientes(){

    ClienteArchivo cArch;
    cArch.leerTodos();

    system("pause");
}

void cargarResponsable()
{
	Responsable r1;
	ResponsableArchivo rArch;

	r1.cargarResponsable("responsables.dat");

	if(rArch.guardar(r1))
	{
		cout << "Registro de Responsable existoso"<<endl;
	}
	else
	{
		cout << "No se pudo registrar el Responsable" << endl;
	}

	system("pause");
}

void listarResponsables(){

    ResponsableArchivo cArch;
    cArch.leerTodos();

    system("pause");
}
