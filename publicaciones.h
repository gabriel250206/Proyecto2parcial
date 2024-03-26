
#ifndef publicaciones.h
#define publicaciones.h
#include "usuarios.h"
#include <string>
#include <vector>
using namespace std ;
int idp=00000;

class Publicacion{
    private:
        int id;
    public:
        string fecha;
        string contenido;
        Usuario* usuario;

        void mostrarPublicacion();
        Publicacion(Usuario *usuario);
        Publicacion(Usuario *usuario, string fecha, string contenido);
};

class PublicacionPremium: public Publicacion{
    public:
    vector<Usuario*>etiquetas;
    void mostrarPublicacion();
    PublicacionPremium(Usuario* usuario, string fecha, string contenido, vector<UsuarioPremium*>etiquetas);
    
};
#endif // publicaciones