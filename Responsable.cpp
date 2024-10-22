#include "Responsable.h"
using namespace std;

Responsable::Responsable(string nombre, string apellido, string user, string passw):Usuario(nombre, apellido, user, passw)
{
	//ctor
}

Responsable::Responsable():Usuario()
{
}

Responsable::~Responsable()
{
	//dtor
}
