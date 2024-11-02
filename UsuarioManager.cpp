#include "UsuarioManager.h"
#include <iostream>
using namespace std;

UsuarioManager::UsuarioManager()
{
	//ctor
}

UsuarioManager::~UsuarioManager()
{
	//dtor
}

void UsuarioManager::cargarUsuario(string fileName)
{
	string nombre, apellido, user, passw;
	UsuarioArchivo uArchivo(fileName);

	cout << "Nombre: ";
	getline(cin, nombre);
	_usuario.setNombre(nombre);

	cout << "Apellido: ";
	getline(cin, apellido);
	_usuario.setApellido(apellido);

	cout << "Username: ";
	cin >> user;

	while(uArchivo.validarUser(user,_usuario)==false){

		cout<<"El nombre de usuario ya existe"<<endl;
		cin >> user;
	}
	_usuario.setUser(user);

	cout << "Contrasena: ";
	cin >> passw;
	while(_usuario.setPassw(passw)==false)
	{
		cout << "La contrasena debe tener un minimo de 5 caracteres"<<endl;
		cout << "Contrasena: ";
		cin >> passw;
	};

	if(fileName == "clientes.dat")
	{
		_usuario.setPermiso("Cliente");
	}
	else
	{
		_usuario.setPermiso("Responsable");
	}

	_usuario.setId(generarNuevoId(fileName));

	uArchivo.guardar(_usuario);
}

void UsuarioManager::mostrarUsuario(Usuario usuario)
{

	cout << "---------------------------" << endl;
	cout << "Nombre: " << usuario.getNombre() << endl;
	cout << "Apellido: " << usuario.getApellido() << endl;
	cout << "User: " <<usuario.getUser() << endl;
	cout << "Contrasena: " <<usuario.getPassw() << endl;
	cout << "Id: " << usuario.getId() << endl;
	cout << "Tipo de Usuario: " << usuario.getPermiso() <<endl;
}

void UsuarioManager::ListarTodos(string fileName)
{
	UsuarioArchivo uArchivo(fileName);

	int cantidadRegistros = uArchivo.getCantidad();

	for (int i = 0; i<cantidadRegistros; i++)
	{
		_usuario = uArchivo.leer(i);
		mostrarUsuario(_usuario);
		cout << endl;
	}
}

void UsuarioManager::ListarXId(string fileName)
{
	UsuarioArchivo uArchivo(fileName);
	int id;

	cout << "Ingrese el ID: ";
	cin >> id;

	int posicion = uArchivo.buscar(id);
	if (posicion >= 0)
	{
		Usuario reg = uArchivo.leer(posicion);
		mostrarUsuario(reg);
	}
	else
	{
		cout << "No existe el registro con ID #" << id << endl;
	}
}

int UsuarioManager::generarNuevoId(string fileName)
{

	UsuarioArchivo uArchivo(fileName);

	return uArchivo.getCantidad() + 1;
}


