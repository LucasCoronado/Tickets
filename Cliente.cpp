#include "Cliente.h"
using namespace std;

Cliente::Cliente(string nombre, string apellido, string user, string passw):Usuario(nombre, apellido, user, passw)
{
}

Cliente::Cliente():Usuario()
{
}

Cliente::~Cliente()
{
	//dtor
}
