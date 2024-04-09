
#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>
#include <vector>
#include "misiones.h"
#include "rlutil.h"
using namespace std;

static int contId=1;
class Publicacion;
class PublicacionPremium; 
class Mision;
class RedSocial;

class Usuario{
private:
    int id;
    int xp;
    string clan;
protected:
    string origen;
public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario*> amigos;
    //map<id, usuario*> amigos;
    vector<Publicacion*> publicacioness;
    Mision* mision=nullptr;


    Usuario(string nombre);
    Usuario(string nombre, int edad);
    Usuario(string nombre, int edad, string nacionalidad);


    int getId();
    string getClan();
    void setClan(string clan);
    void mostrar();
    void mostrarPublicaciones();
    void mostrarAmigos();
    virtual void agregarAmigo(Usuario* nuevoAmigo);
    virtual void crearPublicacion(RedSocial* red);
    Usuario* getAmigo(int id);
    int getXp();
    void increaseXp(int xp);
    void selectMision(Mision* pMision);
    string clanOrg();
    
    


};

class UsuarioPremium: public Usuario{
    public:
    UsuarioPremium(string nombre);
    UsuarioPremium(string nombre, int edad);
    UsuarioPremium(string nombre, int edad, string nacionalidad);
    // vector <PublicacionPremium*> publicacionPremium;
    // void crearPublicacion();
    
};

#endif // USUARIOS_H