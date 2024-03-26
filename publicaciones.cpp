#include "publicaciones.h"
#include "usuarios.h"
#include <iostream> 
using namespace std;
void Publicacion:: mostrarPublicacion(){cout<<"fecha: "<<this->fecha<<endl<<" contenido: "<<this->contenido<<endl<<"usuario: "<<this->usuario->nombre;}

Publicacion::Publicacion(Usuario* usuario){
    this->usuario=usuario;
    this->fecha="NA";
    this->contenido="NA";
    this->id=idp++;
}
Publicacion::Publicacion(Usuario* usuario, string fecha, string contenido){
    this->usuario=usuario;
    this->fecha=fecha;
    this->contenido=contenido;
    this->id=idp++;
}
void PublicacionPremium:: mostrarPublicacion(){
    cout<<"fecha: "<<this->fecha<<endl<<" contenido: "<<this->contenido<<endl<<"usuario: "<<this->usuario->nombre;
    for(int i=0;i<etiquetas.size();i++){
        cout<<this->etiquetas[i]->nombre<<endl;
    }
}

PublicacionPremium::PublicacionPremium(Usuario* usuario, string fecha, string contenido, vector<UsuarioPremium*>etiquetas){
    this->usuario=usuario;
    this->fecha=fecha;
    this->contenido=contenido;
    for(int i=0;i<etiquetas.size();i++){
        this->etiquetas[i]=etiquetas[i];
    }
}