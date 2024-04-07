#include <iostream>
#include <string>
#include <vector>
#include "usuarios.h"
#include "publicaciones.h"
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
}
Usuario::Usuario(string nombre,int edad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad="wakanda";
    this->clan="lobo solitario";
    this->id=contId++;
    this->xp=0;
}

Usuario::Usuario(string nombre, int edad, string nacionalidad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad=nacionalidad;
    this->clan="lobo solitario";
    this->id=contId++;
    this->xp=0;
    
}

int Usuario:: getId(){return this->id;};

void Usuario:: mostrar(){cout<<"Su tribu es es: "<<this->clan<<endl<<"nombre: "<<this->nombre<<endl<<"edad: "<<this->edad<<endl<<"nacionalidad: "<<this->nacionalidad<<endl<<"id: "<<this->id<<endl<<"xp: "<<this->xp<<endl<<endl;}

void Usuario:: mostrarPublicaciones(){
    for(int i=0;i<this->publicacioness.size();i++){
        publicacioness[i]->mostrarPublicacion();
        cout<<endl;
    }
}
void Usuario:: agregarAmigo(Usuario* nuevoAmigo){
    amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
    if(this->mision->tipo=="amigos"){
        this->mision->avanzaProgreso();
        if(this->mision->getProgreso()==this->mision->getProgresoTotal()){
            this->mision=nullptr;
            this->mision->completada(this);
        }
    }
    if(nuevoAmigo->mision->tipo=="amigos"){
        this->mision->avanzaProgreso();
        if(nuevoAmigo->mision->getProgreso()==nuevoAmigo->mision->getProgresoTotal()){
            nuevoAmigo->mision=nullptr;
            nuevoAmigo->mision->completada(nuevoAmigo);
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

 void Usuario:: crearPublicacion(){
    Publicacion* nueva=new Publicacion();
    cout<<"escribe la fecha y el contenido"<<endl;
    cin>>nueva->fecha>>nueva->contenido;
    nueva->usuario=this;
    publicacioness.push_back(nueva);
}


string Usuario::getClan(){return this->clan;}

void Usuario::setClan(string clan){
    this->clan=clan;
}

void Usuario::selectMision(){
    cout<<"Que mision deseas hacer?"<<endl;
    int k=0;
    while(1){

        if(k<0){
            k=1;
        }
        if(k>1){
            k=0;
        }

        if(k==0){
            cout<<">mision de amigos"<<endl;
            cout<<"mision de hacer una publicacion"<<endl;
        }
        if(k==1){
            cout<<"mision de amigos"<<endl;
            cout<<">mision de hacer una publicacion"<<endl;
        }


        if(kbhit()){
            int eleccion=getkey();
            if(eleccion==14){
                k--;
            }
            if(eleccion==15){
                k++;
            }
            if(eleccion==1){
                if(k==0){
                    mision= new MisionAmigos();
                }
                if(k==1){
                    mision=new MisionPublicacion();
                }
            }
            


        }
    }
}



//----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------




UsuarioPremium::UsuarioPremium(string nombre):Usuario(nombre){
    setClan("Avatar");
}
UsuarioPremium::UsuarioPremium(string nombre,int edad):Usuario(nombre,edad){
    setClan("Avatar");
}

UsuarioPremium::UsuarioPremium(string nombre, int edad, string nacionalidad):Usuario(nombre,edad,nacionalidad){
    setClan("Avatar");
    
}










void UsuarioPremium:: crearPublicacion(){
    PublicacionPremium* nueva= new PublicacionPremium();
    cout<<"escribe la fecha y el contenido"<<endl;
    cin>>nueva->fecha>>nueva->contenido;
    nueva->usuario=this;
    cout<<"cuantos amigos seran?"<<endl;
    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        int ide;
        cout<<"inserta su id"<<endl;
        cin>>ide;
        nueva->etiquetas.push_back(getAmigo(ide));

    }
    this->publicacionPremium.push_back(nueva);
}