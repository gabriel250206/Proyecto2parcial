#include "Clan.h"
#include "usuarios.h"
#include "rlutil.h"
using namespace rlutil;
Clan::Clan(string nombre){
    this->nombre=nombre;
}

void Clan::nuevoParticipante(Usuario* usuario){
    this->participantes.push_back(usuario);
    usuario->setClan(this->nombre);
}
string Clan::getName(){
    return this->nombre;
}
void Clan::getParticipantes(){
    system("cls");
    for(int i=0;i<participantes.size();i++){
        cout<<participantes[i]->nombre<<endl;
    }
    if(participantes.size()==0){
        cout<<"no hay miembros";
    }

}
void Clan::quitaParticipante(Usuario* pUsuario){
   
    for(int i=0;i<this->participantes.size();i++){
        
        if(participantes[i]->nombre==pUsuario->nombre){
            
            this->participantes.erase(participantes.begin()+i);
            
        }
    }
    
    
}