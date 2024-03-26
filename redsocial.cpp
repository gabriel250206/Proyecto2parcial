#include "redsocial.h"

void RedSocial::agregarUsuario(Usuario* nuevo){
    usuarios.push_back(nuevo);
    this->numeroDeUsuarios++;
}
void RedSocial::mostrarUsuarios(){
    for(int i=0;i<usuarios.size();i++)
        cout<<usuarios[i]<<endl;
}

void RedSocial::mostrarPublicaciones(){
    for(int i=0;i<publicaciones.size();i++){
        cout<<publicaciones[i]<<endl;
    }
}

Usuario* RedSocial:: getUsuario(int id){
    for(int i=0;i<usuarios.size();i++){
        if(usuarios[i]->getId()==id){
            return usuarios[i];
        }
    }
    return nullptr;
}
Usuario* RedSocial:: getUsuariopos(int pos){
    return usuarios[pos];
}