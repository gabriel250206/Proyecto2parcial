#include <iostream>
#include <string>
#include <vector>
#include "usuarios.h"
#include "publicaciones.h"
#include "RedSocial.h"
using namespace rlutil;

using namespace std;
class Publicacion;
class PublicacionPremium;
Usuario::Usuario(string nombre){
    this-> nombre=nombre;
    this-> edad=0;
    this-> nacionalidad="wakanda";
    this->clan="lobo solitario";
    this->id=contId++;
    this->xp=0;
    this->origen="lobo solitario";
}
Usuario::Usuario(string nombre,int edad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad="wakanda";
    this->clan="lobo solitario";
    this->id=contId++;
    this->xp=0;
    this->origen="lobo solitario";
}

Usuario::Usuario(string nombre, int edad, string nacionalidad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad=nacionalidad;
    this->clan="lobo solitario";
    this->id=contId++;
    this->xp=0;
    this->origen="lobo solitario";
    
}

int Usuario:: getId(){return this->id;};

void Usuario::mostrarAmigos(){
    for(int i=0;i<amigos.size();i++){
        cout<<amigos[i]<<endl;
    }
}

void Usuario:: mostrar(){cout<<"Su tribu es es: "<<this->clan<<endl<<"nombre: "<<this->nombre<<endl<<"edad: "<<this->edad<<endl<<"nacionalidad: "<<this->nacionalidad<<endl<<"id: "<<this->id<<endl<<"xp: "<<this->xp<<endl<<endl;}

void Usuario:: mostrarPublicaciones(){
    for(int i=0;i<this->publicacioness.size();i++){
        publicacioness[i]->mostrarPublicacion();
        cout<<endl;
    }
}
void Usuario:: agregarAmigo(Usuario* nuevoAmigo){
    cout<<"entra"<<endl;
    amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
    cout<<"agrega"<<endl;
    if(this->mision!=nullptr){
        if(this->mision->tipo=="amigos"){
            cout<<"entra"<<endl;
        this->mision->avanzaProgreso();
            cout<<"puso"<<endl;
        if(this->mision->getProgreso()==this->mision->getProgresoTotal()){
            this->mision=nullptr;
            this->mision->completada(this);
        }
    }
    }
    if(nuevoAmigo->mision!=nullptr){
        if(nuevoAmigo->mision->tipo=="amigos"){
            cout<<"entra"<<endl;
        this->mision->avanzaProgreso();
            cout<<"puso"<<endl;
        if(nuevoAmigo->mision->getProgreso()==nuevoAmigo->mision->getProgresoTotal()){
            nuevoAmigo->mision=nullptr;
            nuevoAmigo->mision->completada(nuevoAmigo);
        }
    }
    }
    
    
}

Usuario* Usuario::getAmigo(int id){
    for(int i=0;i<amigos.size();i++){
        if(amigos[i]->id==this->id){ 
            return amigos[i];  
        }
    }
    return nullptr;
}


int Usuario::getXp(){return this->xp;}

void Usuario::increaseXp(int xp){
    this->xp=this->xp+xp;
}

// void Usuario:: agregarAmigo(Usuario* nuevoAmigo){
//     amigos[nuevoAmigo->id] =nuevoAmigo;
//     nuevoAmigo->amigos[this->id]=this;
// }

 void Usuario:: crearPublicacion(RedSocial* red){
    Publicacion* nueva=new Publicacion();
    cout<<"escribe la fecha y el contenido"<<endl;
    cin>>nueva->fecha>>nueva->contenido;
    nueva->usuario=this;
    publicacioness.push_back(nueva);
    red->nuevaP(nueva);
    

}


string Usuario::getClan(){return this->clan;}

 void Usuario::setClan(string clan){
         this->clan=clan;
}

void Usuario::selectMision(Mision* pMision){
    this->mision=pMision;
}

string Usuario::clanOrg(){
    return this->origen;
}

// void Usuario::setClan(string nombre){
//     this->clan=nombre;
// }

//----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------




UsuarioPremium::UsuarioPremium(string nombre):Usuario(nombre){
    setClan("Avatar");
    this->origen="avatar";
}
UsuarioPremium::UsuarioPremium(string nombre,int edad):Usuario(nombre,edad){
    setClan("Avatar");
    this->origen="avatar";
}

UsuarioPremium::UsuarioPremium(string nombre, int edad, string nacionalidad):Usuario(nombre,edad,nacionalidad){
    setClan("Avatar");
    this->origen="avatar";
    
}










// void UsuarioPremium:: crearPublicacion(){
//     PublicacionPremium* nueva= new PublicacionPremium();
//     cout<<"escribe la fecha y el contenido"<<endl;
//     cin>>nueva->fecha>>nueva->contenido;
//     nueva->usuario=this;
//     cout<<"cuantos amigos seran?"<<endl;
//     int x;
//     cin>>x;
//     for(int i=0;i<x;i++){
//         int ide;
//         cout<<"inserta su id"<<endl;
//         cin>>ide;
//         nueva->etiquetas.push_back(getAmigo(ide));

//     }
//     this->publicacionPremium.push_back(nueva);
// }