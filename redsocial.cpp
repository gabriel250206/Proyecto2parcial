#include "redsocial.h"
#include <iostream>
using namespace std;
void RedSocial::agregarUsuario(Usuario* nuevo){
    usuarioss.push_back(nuevo);
    this->numeroDeUsuarios++;
    
}
void RedSocial::eliminarUsuario(int pos){
    usuarioss.erase(usuarioss.begin()+pos);
    this->numeroDeUsuarios--;
    
}
void RedSocial::mostrarUsuarios(){
    for(int i=0;i<usuarioss.size();i++)
        cout<<usuarioss[i]<<endl;
}

void RedSocial::mostrarPublicaciones(){
    
}

Usuario* RedSocial:: getUsuario(int id){
    for(int i=0;i<usuarioss.size();i++){
        if(usuarioss[i]->getId()==id){
            return usuarioss[i];
        }
    }
    return nullptr;
}
Usuario* RedSocial:: getUsuariopos(int pos){
    return usuarioss[pos];
}