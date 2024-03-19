#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Publicacion{
    
};

long contId=00000;

class Usuario{
private:
    long id;
public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario> amigos;
    vector<Publicacion> publicaciones;

    Usuario::Usuario(string nombre);
    Usuario::Usuario(string nombre, int edad);
    Usuario::Usuario(string nombre, int edad, string nacionalidad);


    int getId();
    void mostrar();
    void mostrarPublicaciones();
    void agregarAmigos(Usuario* nuevoAmigo);
    void crearPublicacion();
    Usuario* getAmigo(int id);


};

class UsuarioPremium: public Usuario{

};

