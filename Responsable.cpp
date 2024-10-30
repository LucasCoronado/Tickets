#include "Responsable.h"
using namespace std;

Responsable::Responsable(string nombre, string apellido, string user, string passw, string fileName):Usuario(nombre, apellido, user, passw, fileName)
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

void Responsable::cargarResponsable(string fileName){

	cargarUsuario(fileName);
	setPermiso("Responsable");

}

/*int Responsable::setIdMasUno(string fileName){

	Responsable registro;
	FILE *pFile;

	pFile = fopen(fileName.c_str(),"rb");

	if(pFile == nullptr){

		return -1;
	}

	fseek(pFile,-sizeof(Responsable),SEEK_END);

	fread(&registro,sizeof(Responsable),1,pFile);

	int i = registro.getId() + 1;

	return i;

}
*/
