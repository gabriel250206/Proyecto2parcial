#include "redsocial.h"
#include "publicaciones.h"
#include "usuarios.h"
#include "clan.h"
#include <iostream>
using namespace std;
using namespace rlutil;
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
    for(int i=0;i<publicacioness.size();i++){
        for(int j=0;j<publicacioness[i].size();j++)cout<<publicacioness[i][i]<<endl;
    }
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

void RedSocial:: newUser(int mod5,int numero){
    cout<<"escribe su nombre"<<endl;
    string nombre;
    cin>>nombre;
    int amod=0;
    while(1){
        cls();
        cout<<endl<<"tiene nacionalidad?"<<endl;
        if(amod==0){
            cout<<">si"<<endl<<"no"<<endl;
        }
        if(amod==1){
            
            cout<<"si"<<endl<<">no"<<endl;
        }
        if(kbhit){
            int k=getkey();
            if(k==14){
                amod--;
                if(amod<0){
                    amod=1;
                }
            }
            if(k==15){
                amod++;
                if(amod>1){
                    amod=0;
                }
            }
            if(k==1){
                if(amod==0){
                    cout<<"escribe la edad"<<endl;
                    int edad;
                    cin>>edad;
                    cout<<"escribe la nacionalidad"<<endl;
                    string nacionalidad;
                    cin>>nacionalidad;
                    if(mod5==numero){
                        Usuario* pNuevo= new Usuario(nombre,edad,nacionalidad);
                        this->agregarUsuario(pNuevo);
                        return;
                    }
                    if(mod5==numero+1){
                        UsuarioPremium* pNuevo= new UsuarioPremium(nombre,edad,nacionalidad);
                        this->agregarUsuario(pNuevo);
                        return;
                    }
                    

                }
                if(amod==1){
                    int mod2=0;
                    while(1){
                        
                        cls();
                        cout<<"tiene edad?"<<endl;
                        if(mod2==0){
                            cout<<">si"<<endl<<"no"<<endl;
                        }
                        if(mod2==1){
            
                             cout<<"si"<<endl<<">no"<<endl;
                        }
                        if(kbhit){
                            int k=getkey();
                            if(k==14){
                                mod2--;
                                if(mod2<0){
                                    mod2=1;
                                }
                            }
                        if(k==15){
                            mod2++;
                            if(mod2>1){
                               mod2=0;
                            }
                        }
                        if(k==1){
                            if(mod2==0){
                                
                                cout<<"escribe la edad"<<endl;
                                int edad;
                                cin>>edad;
                                if(mod5==numero){
                                    Usuario* pNuevo=new Usuario(nombre,edad);
                                    this->agregarUsuario(pNuevo);
                                    return;
                                }
                                if(mod5==numero+1){
                                    UsuarioPremium* pNuevo=new UsuarioPremium(nombre,edad);
                                    this->agregarUsuario(pNuevo);
                                    return;
                                }
                            }
                            if(mod2==1){
                                if(mod5==numero){
                                    Usuario* pNuevo=new Usuario(nombre);
                                    this->agregarUsuario(pNuevo);
                                    return;
                                }
                                if(mod5==numero+1){
                                    UsuarioPremium* pNuevo=new UsuarioPremium(nombre);
                                    this->agregarUsuario(pNuevo);
                                    return;
                                }
                                
                            }
                        }
                        }
                    }
                }
            }
        }
    }
}

void RedSocial::mostrarClanes(vector<Clan*>clan){
    cls();
    for(int i=0;i<4;i++){
        cout<<"nacion del "<<clan[i]->getName()<<endl;
    }
}