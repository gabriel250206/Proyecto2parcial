#include <iostream>
#include <string>
#include <vector>
#include "publicaciones.h"

//#include<map>
#include "usuarios.h"
using namespace std;

Usuario::Usuario(string nombre){
    this-> nombre="nulo";
    this-> edad=0;
    this-> nacionalidad="wakanda";
    this->id=contId++;
}
Usuario::Usuario(string nombre,int edad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad="wakanda";
    this->id=contId++;
}

Usuario::Usuario(string nombre, int edad, string nacionalidad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad=nacionalidad;
    this->id=contId++;
    
}

int Usuario:: getId(){return this->id;};

void Usuario:: mostrar(){cout<<"nombre: "<<this->nombre<<endl<<"edad: "<<this->edad<<endl<<"nacionalidad: "<<this->nacionalidad<<endl<<"id: "<<this->id;}

void Usuario:: mostrarPublicaciones(){
    for(int i=0;i<this->publicaciones.size();i++){
        publicaciones[i]->mostrarPublicacion();
    }
}
void Usuario:: agregarAmigo(Usuario* nuevoAmigo){
    amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
}

Usuario* Usuario::getAmigo(int id){
    for(int i=0;i<amigos.size();i++){
        if(amigos[i]->id==this->id){ 
            return amigos[i];  
        }
    }
    return nullptr;
}

// void Usuario:: agregarAmigo(Usuario* nuevoAmigo){
//     amigos[nuevoAmigo->id] =nuevoAmigo;
//     nuevoAmigo->amigos[this->id]=this;
// }

 void Usuario:: crearPublicacion(Publicacion* nueva){
    publicaciones.push_back(nueva);
}

void UsuarioPremium:: crearPublicacion(Publicacion* nueva){
    
}