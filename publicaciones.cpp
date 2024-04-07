#include "publicaciones.h"
#include "usuarios.h"
#include <iostream> 
using namespace std;
void Publicacion:: mostrarPublicacion(){cout<<"fecha: "<<this->fecha<<endl<<" contenido: "<<this->contenido<<endl<<"usuario: "<<this->usuario->nombre<<endl<<"id: "<<this->id<<endl;}

Publicacion::Publicacion(){
    this->usuario=nullptr;
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

int Publicacion::getId(){return this->id;} /// no se si se necesite en algun momento

void Publicacion::incrementId(){
    this->id=idp++;
}

void PublicacionPremium:: mostrarPublicacion(){
    Publicacion::mostrarPublicacion();
    for(int i=0;i<etiquetas.size();i++){
        cout<<this->etiquetas[i]->nombre<<endl;
    }
}



PublicacionPremium::PublicacionPremium(Usuario* usuario, string fecha, string contenido, vector<UsuarioPremium*>etiquetas):Publicacion(usuario, fecha,contenido){
    incrementId();
    for(int i=0;i<etiquetas.size();i++){
        this->etiquetas[i]=etiquetas[i];
    }
}