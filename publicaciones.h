#pragma once "usuarios.h"

#include "usuarios.h"


class Publicacion{
    private:
        int id;
    public:
        string fecha;
        string contenido;
        Usuario* usuario;

        virtual void mostrarPublicacion();

        Publicacion(Usuario* usuario, string fecha, string contenido);
};

class PublicacionPremium: public Publicacion{
    public:
    vector<string*>etiquetas;
    void mostrarPublicacion();


};