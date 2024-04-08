#include "Clan.h"
#include "usuarios.h"

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