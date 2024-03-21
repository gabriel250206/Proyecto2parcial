#pragma once "usuarios.h"

#include "usuarios.h"


class Publicacion{
    private:
        int id;
    public:
        string fecha;
        string contenido;
        Usuario* usuario;

        void mostrarPublicacion();

        Publicacion(Usuario* usuario, string fecha, string contenido);
};