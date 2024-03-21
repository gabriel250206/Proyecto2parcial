#pragma once "usuarios.h"

#include "usuarios.h"

long idp=00000;

class Publicacion{
    private:
        int id;
    public:
        string fecha;
        string contenido;
        Usuario* usuario;

        virtual void mostrarPublicacion();
        Publicacion();
        Publicacion(Usuario* usuario, string fecha, string contenido);
};

class PublicacionPremium: public Publicacion{
    public:
    vector<Usuario*>etiquetas;
    void mostrarPublicacion();


    PublicacionPremium(Usuario* usuario, string fecha, string contenido, vector<UsuarioPremium*>etiquetas);


};