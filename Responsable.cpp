#include "Responsable.h"
using namespace std;

Responsable::Responsable(string nombre, string apellido, string user, string passw, string fileName):Usuario(nombre, apellido, user, passw, fileName)
{
	//ctor
}

Responsable::Responsable():Usuario()
{
	setFileName("responsables.dat");
}

Responsable::~Responsable()
{
	//dtor
}

void Responsable::cargarResponsable(string fileName){

	cout<<"REGISTRO DE RESPONSABLE"<<endl;
	cargarUsuario(fileName);
	setPermiso("Responsable");

}
