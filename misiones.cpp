#include "misiones.h"
#include "usuarios.h"
Mision::Mision(){
    this->nombre="Mision sin nombre";
    this->valor=50;
    this->complete=false;
    this->progreso=0;
    this->progresoTotal=3;
    this->tipo="sin tipo";
}
// Mision::Mision(string nombre){
//     this->nombre=nombre;
//     this->valor=50;
//     this->complete=false;
//     this->progreso=0;
//     this->progresoTotal=3;
// }
// Mision::Mision(string nombre, int valor){
//     this->nombre=nombre;
//     this->valor=valor;
//     this->complete=false;
//     this->progreso=0;
//     this->progresoTotal=3;
// }

void Mision::completada(Usuario* usuario){
    
    usuario->increaseXp(this->valor);

}
void Mision::avanzaProgreso(){
    this->progreso++;
}

void Mision::mostrarProgreso(){

    cout<<this->nombre<<endl<<"Progreso: "<<this->progreso<<"/"<<this->progresoTotal;
}

int Mision::getProgreso(){
    return this->progreso;
}
int Mision::getProgresoTotal(){
    return this->progresoTotal;
}

MisionAmigos::MisionAmigos():Mision(){
    nombre="Agrega a 3 amigos";
    tipo="Amigos";

}

MisionPublicacion::MisionPublicacion():Mision(){
    nombre="Haz una publicacion";
    tipo="publicacion";
    valor=100;
    progresoTotal=1;

}