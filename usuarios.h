
#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>
#include <vector>
using namespace std;

static int contId=00000;
class Publicacion;
class PublicacionPremium;

class Usuario{
private:
    int id;
    int xp;
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
    int getXp();
    void increaseXp(int xp);
    


};

class UsuarioPremium: public Usuario{
    public:
    vector <PublicacionPremium*> publicacionPremium;
    void crearPublicacion();
    
};

#endif // USUARIOS_H





