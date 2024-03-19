#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Publicacion;
class Usuario{
private:
    long id;
public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario> amigos;
    vector<Publicacion> publicaciones;

    Usuario::Usuario();
    Usuario::Usuario(int nombre, long id);

};