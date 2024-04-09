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

int RedSocial::getNum(){
    return this->usuarioss.size();
}
int RedSocial::getNumP(){
    return this->publicacioness.size();
}
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
       publicacioness[i]->mostrarPublicacion();
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

void RedSocial::nuevaP(Publicacion* nueva){
    publicacioness.push_back(nueva);
}
RedSocial::RedSocial(std::string nombre){
    this->nombre=nombre;
}
RedSocial::RedSocial(string nombre,vector<Usuario*>usuarios){
    this->nombre=nombre;
    this->usuarioss=usuarios;
}
RedSocial::RedSocial(string nombre,vector<Usuario*>usuarios,vector<Publicacion*>publicaciones){
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
    
    int mod=0;
    while(1){
        cls();
        cout<<"que clan quieres ver?"<<endl;
        if(mod>4){
            mod=0;
        }
        if(mod<0){
            mod=4;
        }
        for(int i=0;i<4;i++){
            if(mod==i){
                cout<<">";
            }
            cout<<"nacion del "<<clan[i]->getName()<<endl;
        }
        if(mod==4)cout<<">";
        cout<<"volver";
        if(kbhit){
            int k=getkey();
            if(k==14){
                mod--;
            }
            if(k==15){
                mod++;
            }
            if(k==1){
                if(mod<4){
                    int modos=0;
                    while(1){
                        cls();
                        clan[mod]->getParticipantes();
                        cout<<endl<<"deseas agregar participantes?"<<endl;
                        
                        if(modos>1){
                            modos==0;
                        }
                        if(modos<0){
                            modos==1;
                        }
                        if(modos==0)
                            cout<<">";
                        cout<<" si"<<endl;
                        if(modos==1)
                            cout<<">";
                        cout<<" nio"<<endl;

                        if(kbhit){
                            int k=getkey();
                            if(k==14){
                                modos--;
                            }
                            if(k==15){
                                modos++;
                            }
                            if(k==1){
                                if(modos==1)return;
                                else{
                                    cout<<endl<<"escribe su id"<<endl;
                                    int idea;
                                    cin>>idea;
                                    
                                    Usuario* pUsuario=this->getUsuario(idea);
                                    if(pUsuario->clanOrg()=="lobo solitario"&& pUsuario->getClan()=="lobo solitario"){
                                        pUsuario->setClan(clan[mod]->getName());
                                        clan[mod]->nuevoParticipante(pUsuario);
                                        
                                    }
                                    else{
                                        if(pUsuario->clanOrg()!="avatar")cout<<"ya tienes un clan, rata traicionera"<<endl;
                                        
                                    }
                                    if(pUsuario->clanOrg()=="avatar")
                                    {
                                        msleep(1000);
                                        cout<<endl<<"el avatar puede estar en cualquier clan que desee, disfruta tu estancia"<<endl;
                                        pUsuario->setClan(clan[mod]->getName());
                                        clan[mod]->nuevoParticipante(pUsuario);
                                    }
                                    
                                }
                            }


                        
                        }
                    }
                    
                    
                }
                if(mod==4){
                    return;
                }
            }
        }
        
    }
}