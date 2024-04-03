
#ifndef PUBLICACIONES_H
#define PUBLICACIONES_H
#include <string>
#include <vector>
#include "usuarios.h"
using namespace std ;
static int idp=00000;

class Publicacion{
    private:
        int id;
    public:
        string fecha;
        string contenido;
        Usuario* usuario=nullptr;

        virtual void mostrarPublicacion();
        Publicacion();
        Publicacion(Usuario* usuario, string fecha, string contenido);
        int getId();
        void incrementId();
};

class PublicacionPremium: public Publicacion{
    public:
    vector<Usuario*>etiquetas;
    void mostrarPublicacion();
    PublicacionPremium(Usuario* usuario, string fecha, string contenido, vector<UsuarioPremium*>etiquetas);
    
};
#endif // PUBLICACIONES_H