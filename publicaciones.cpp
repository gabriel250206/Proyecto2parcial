#include "publicaciones.h"

void Publicacion:: mostrarPublicacion(){cout<<"fecha: "<<this->fecha<<endl<<" contenido: "<<this->contenido<<endl<<"usuario: "<<this->usuario->nombre;}

Publicacion::Publicacion(Usuario* usuario, string fecha, string contenido){
    this->usuario=usuario;
    this->fecha=fecha;
    this->contenido=contenido;
}