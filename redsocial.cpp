#include "redsocial.h"
#include "publicaciones.h"
#include "usuarios.h"
#include <iostream>
using namespace std;
class Publicacion;
class PublicacionPremium;
class Usuario;
class UsuarioPremium;
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


RedSocial::RedSocial(std::string nombre){
    this->nombre=nombre;
}
RedSocial::RedSocial(string nombre,vector<Usuario*>usuarios){
    this->nombre=nombre;
    this->usuarioss=usuarios;
}
RedSocial::RedSocial(string nombre,vector<Usuario*>usuarios,vector<vector<Publicacion*>>publicaciones){
    this->nombre=nombre;
    this->usuarioss=usuarios;
    this->publicacioness=publicaciones;
}