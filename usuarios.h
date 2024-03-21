#include <iostream>
#include <string>
#include <vector>
#include "publicaciones.h"
using namespace std;

long contId=00000;

class Usuario{
private:
    long id;
public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario*> amigos;
    //map<id, usuario*> amigos;
    vector<Publicacion*> publicaciones;

    Usuario::Usuario(string nombre);
    Usuario::Usuario(string nombre, int edad);
    Usuario::Usuario(string nombre, int edad, string nacionalidad);


    int getId();
    void mostrar();
    void mostrarPublicaciones();
    void agregarAmigo(Usuario* nuevoAmigo);
    void crearPublicacion();
    Usuario* getAmigo(int id);


};

class UsuarioPremium: public Usuario{

};

