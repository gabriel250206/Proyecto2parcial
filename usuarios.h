
#ifndef usuarios.h
#define usuarios.h
#include <string>
#include <vector>
#include "publicaciones.h"
using namespace std;

int contId=00000;

class Usuario{
private:
    int id;
public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario*> amigos;
    //map<id, usuario*> amigos;
    vector<Publicacion*> publicacioness;

    Usuario(string nombre);
    Usuario(string nombre, int edad);
    Usuario(string nombre, int edad, string nacionalidad);


    int getId();
    void mostrar();
    void mostrarPublicaciones();
    virtual void agregarAmigo(Usuario* nuevoAmigo);
    virtual void crearPublicacion();
    Usuario* getAmigo(int id);


};

class UsuarioPremium: public Usuario{
    public:
    void crearPublicacion();
    vector <PublicacionPremium*> publicacion;
};

#endif // usuarios





