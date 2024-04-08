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