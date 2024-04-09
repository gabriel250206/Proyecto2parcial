#include "redsocial.h"
#include "publicaciones.h"
#include "usuarios.h"
#include "clan.h"
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
void RedSocial::eliminarUsuario(int pos, vector<Clan*>tribu){
    if(usuarioss[pos]->getClan()!="lobo solitario"){
        for(int i=0;i<4;i++){
            if(usuarioss[pos]->getClan().compare(tribu[i]->getName())==0){
                tribu[i]->quitaParticipante(usuarioss[pos]);
                break;
            }
        }
    }
    usuarioss.erase(usuarioss.begin()+pos);
    this->numeroDeUsuarios--;
    
    
}
void RedSocial::mostrarUsuarios(){
   
    int mod=0;
    while(1){
        cls();
        if(mod<0){
            mod=usuarioss.size()+1;
        }
        if(mod>usuarioss.size()+1){
            mod=0;
        }
        
        
        for(int i=0;i<usuarioss.size();i++){
            if(mod==i)std::cout<<">";
            std::cout<<usuarioss[i]->nombre<<endl;
        }
        
        if(mod==usuarioss.size())std::cout<<">";
        std::cout<<"volver"<<endl;

    
        if(kbhit){
            int k=getkey();
            if(k==14) mod--;
            if(k==15)mod++;
            if(k==1){
                if(mod==usuarioss.size())return;
                else{
                    Usuario* pUsuario=usuarioss[mod];
                    this->opciones(pUsuario);
                }
            }
        }
    }
    
        

}

void RedSocial::mostrarPublicaciones(){
    cls();
    for(int i=0;i<publicacioness.size();i++){
       publicacioness[i]->mostrarPublicacion();
       std::cout<<endl;
    }
    if(publicacioness.size()==0)std::cout<<"Chale, no hay publicaciones"<<endl;
    while(1){
        
        std::cout<<">volver"<<endl;
        if(kbhit){
            int k=getkey();
            if(k==1)return;

        }
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

void RedSocial:: newUser(int mod5){
    std::cout<<"escribe su nombre"<<endl;
    msleep(1000);
    string nombre;
    cin>>nombre;
    int amod=0;
    while(1){
        cls();
        std::cout<<endl<<"tiene nacionalidad?"<<endl;
        if(amod==0){
            std::cout<<">si"<<endl<<"no"<<endl;
        }
        if(amod==1){
            
            std::cout<<"si"<<endl<<">no"<<endl;
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
                    std::cout<<"escribe la edad"<<endl;
                    int edad;
                    cin>>edad;
                    std::cout<<"escribe la nacionalidad"<<endl;
                    string nacionalidad;
                    cin>>nacionalidad;
                    if(mod5==0){
                        Usuario* pNuevo= new Usuario(nombre,edad,nacionalidad);
                        this->agregarUsuario(pNuevo);
                        return;
                    }
                    if(mod5==1){
                        UsuarioPremium* pNuevo= new UsuarioPremium(nombre,edad,nacionalidad);
                        this->agregarUsuario(pNuevo);
                        return;
                    }
                    

                }
                if(amod==1){
                    int mod2=0;
                    while(1){
                        
                        cls();
                        std::cout<<"tiene edad?"<<endl;
                        if(mod2==0){
                            std::cout<<">si"<<endl<<"no"<<endl;
                        }
                        if(mod2==1){
            
                             std::cout<<"si"<<endl<<">no"<<endl;
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
                                
                                std::cout<<"escribe la edad"<<endl;
                                int edad;
                                cin>>edad;
                                if(mod5==0){
                                    Usuario* pNuevo=new Usuario(nombre,edad);
                                    this->agregarUsuario(pNuevo);
                                    return;
                                }
                                if(mod5==1){
                                    UsuarioPremium* pNuevo=new UsuarioPremium(nombre,edad);
                                    this->agregarUsuario(pNuevo);
                                    return;
                                }
                            }
                            if(mod2==1){
                                if(mod5==0){
                                    Usuario* pNuevo=new Usuario(nombre);
                                    this->agregarUsuario(pNuevo);
                                    return;
                                }
                                if(mod5==1){
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
        std::cout<<"que clan quieres ver?"<<endl;
        if(mod>4){
            mod=0;
        }
        if(mod<0){
            mod=4;
        }
        for(int i=0;i<4;i++){
            if(mod==i){
                std::cout<<">";
            }
            std::cout<<"nacion del "<<clan[i]->getName()<<endl;
        }
        if(mod==4)std::cout<<">";
        std::cout<<"volver";
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
                        std::cout<<endl<<"deseas agregar participantes?"<<endl;
                        
                        if(modos>1){
                            modos==0;
                        }
                        if(modos<0){
                            modos==1;
                        }
                        if(modos==0)
                            std::cout<<">";
                        std::cout<<" si"<<endl;
                        if(modos==1)
                            std::cout<<">";
                        std::cout<<" nio"<<endl;

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
                                    std::cout<<endl<<"escribe su id"<<endl;
                                    int idea;
                                    cin>>idea;


                                    bool existe=false;
                                    for(int i=0;i<this->getNum();i++){
                                        if(this->getUsuariopos(i)->getId()==idea){
                                        existe=true;
                                        }
                                    }

                                    if(existe==true){
                                        Usuario* pUsuario=this->getUsuario(idea);
                                    if(pUsuario->getClan()=="lobo solitario"){
                                        pUsuario->setClan(clan[mod]->getName());
                                        clan[mod]->nuevoParticipante(pUsuario);
                                        
                                    }
                                    else{
                                        if(pUsuario->clanOrg()!="avatar"){
                                            std::cout<<endl<<"ya tiene un clan"<<endl;
                                        }
                                        msleep(1000);
                                    }
                                    if(pUsuario->clanOrg()=="avatar")
                                    {
                                        
                                        std::cout<<endl<<"el avatar puede estar en cualquier clan que desee, disfruta tu estancia"<<endl;
                                        pUsuario->setClan(clan[mod]->getName());
                                        clan[mod]->nuevoParticipante(pUsuario);
                                        msleep(3000);
                                    }
                                    }else{
                                        cout<<"no existe ese usuario"<<endl;
                                        msleep(3000);
                                        return;
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

void RedSocial::edus(Usuario* pUser){



    string lll="+´+´´+", uio="'0989}+"  ; 
    int edd=-1; 
    p:
    system("cls");
    std::cout << " presione 1 para cambiar el nombre\n";
    std::cout << " presione 2 para cambiar la edad\n";
    std::cout << " presione 3 para cambiar la nacionaldad\n";
    std::cout << " presione 4 para volver\n";
    int h ; 
    
    cin>> h;
    if(h == 1 ){
         system("cls");
        std::cout<< "Escriba el nombre ";
        cin>>lll;
        goto p;
    }
    if(h == 2 ){
        system("cls");
        std::cout<< "Escriba la edad ";
        cin>>edd;
        goto p;
    }
    if(h == 3 ){
        system("cls");
        std::cout<< "Escriba la nacionalidad ";
        cin>>uio;
        goto p;
    }
    if(h == 4 ){
        if (lll != "+´+´´+"){
            std::cout << "confirme el cambio de nombre de "<< pUser->nombre << " a "<< lll<<endl;
            if (kbhit)
            {
                int k = getkey();
                if (k == 1)
            {
                pUser-> nombre = lll; 
            } 
            }
        }
         if (uio != "'0989}+"){
            std::cout << "confirme el cambio de nacionalidad de "<< pUser->nacionalidad << " a "<< uio<<endl;
            if (kbhit)
            {
                int k = getkey();
                if (k == 1)
            {
                pUser-> nacionalidad = uio; 
            } 
            }
        }
        if (edd > 0){
            std::cout << "confirme el cambio de edad de "<< pUser->edad << " a "<< edd <<endl;
            if (kbhit)
            {
                int k = getkey();
                if (k == 1)
            {
                pUser-> edad = edd; 
            } 
            }
     
        }return; 
    }

}

void RedSocial::ami(Usuario *pUser){
    system("cls");
    int mod=0;
    while(1){
        cls();
        
        if(mod>pUser->amigos.size()+1){
            mod==0;
        }
        if(mod<0){
            mod==pUser->amigos.size()+1;
        }
        for(int i=0;i<pUser->amigos.size();i++){
            if(mod==i)std::cout<<">";
            std::cout<<pUser->amigos[i]->nombre<<endl;
        }
      
        if(mod==pUser->amigos.size()){
            cout<<">";
        }
        std::cout<<"agregar amigo"<<endl;
        if(mod==pUser->amigos.size()+1){
            std::cout<<">";
        }
        std::cout<<"volver"<<endl;
        if(kbhit){
            int k=getkey();
            
            if(k==14){
                mod--;
                
            }
            if(k==15){
                mod++;
                
            }
            if(k==1){
                if(mod<pUser->amigos.size()){
                    Usuario* amix=pUser->amigos[mod];
                    opciones(amix);
                }
                if(mod==pUser->amigos.size()){
                    std::cout<<"escribe su id"<<endl;
                    int id;
                    cin>>id;
                    Usuario* nuevoUser=this->getUsuario(id);
                    pUser->agregarAmigo(nuevoUser);
                }
                
                return;
            }
        }
            
            
    }

        
}


void RedSocial::publ(Usuario* pUser){
    system("cls");
    int mod=0;
    while(1){
        
        cls();
        pUser->mostrarPublicaciones();
        
        if(mod==0){
            cout<<">crear publicacion"<<endl;
            cout<<"volver"<<endl;
        }
        if(mod==1){
            cout<<"crear publicacion"<<endl;
            cout<<">volver"<<endl;
        }
        if(kbhit){
            int k=getkey();
            
            if(k==14){
                mod--;
                if(mod<0){
                mod=1;
        }
            }
            if(k==15){
                mod++;
                if(mod>1){
                mod=0;
                }
            }
            if(k==1){
                if(mod==0){
                    pUser->crearPublicacion(this);
                }
                
                return;
            }
        }

        
    }

}


// void RedSocial::misiones(Usuario* pUser){
//     int mod=0;
//     Mision* pMision=nullptr;
//     while(1){
//         cls();
//         if(mod>3){
//             mod=0;
//         }
//         if(mod<0){
//             mod=3;
//         }
//         if(mod==0){
//             cout<<">";
//         }
//         cout<<"mision de amigo"<<endl;
//         if(mod==1){
//             cout<<">";
//         }
//         cout<<"mision de publicacion"<<endl;
//         if(mod==2)
//             cout<<">";
//         cout<<"salir"<<endl;
//         if(kbhit){
//             int k=getkey();
//             if(k==14){
//                 mod--;
//             }
//             if(k==15){
//                 mod++;
//             }
//             if(k==1){
//                 if(mod==0){
//                     cout<<"funciona";
//                     pMision= new MisionAmigos();
//                     cout<<"funciona";
//                     pUser->selectMision(pMision);
//                     cout<<"funciona";
//                     return;
//                 }
//                 if(mod==1){
//                     cout<<"funciona";
//                     pMision= new MisionPublicacion();
//                     cout<<"funciona";
//                     pUser->selectMision(pMision);
//                     cout<<"funciona";
//                     return;
//                 }
//                 if(mod==2){
//                     return;
//                 }
//             }
//         }
//     }
// }




void RedSocial::opciones(Usuario* pUser)
{
    int mod = 0;
    while (1)
    {
        system("cls");
        if (mod > 3)
            mod = 0;
        if (mod < 0)
            mod = 3;
        if (mod == 0)
            cout << ">";
        cout << "datos\n";
        if (mod == 1)
            cout << ">";
        cout << "publicaciones\n";
        if (mod == 2)
            cout << ">";
        cout << "amigos\n";
        if (mod == 3)
            cout << ">";
        cout << "volver\n";
        
        
        if (kbhit)
        {
            int k = getkey();
            if (k == 14)
                mod--;
            if (k == 15)
                mod++;
            if (k == 1)
            {
                if (mod == 0)
                    this->data(pUser);
                if (mod == 1)
                    
                    this->publ(pUser);
                if (mod == 2)
                    this->ami(pUser);
                if (mod==3)
                    return;
                
            }
        }
    }
}



void RedSocial::data(Usuario* pUser)
{
    
    int mod = 0;
    while (1)
    {
        system("cls");
        pUser->mostrar();
        if (mod > 1)
            mod = 0;
        if (mod < 0)
            mod = 1;
        if (mod == 0)
            cout << ">";
        cout << "editar\n";
        if (mod == 1)
            cout << ">";
        cout << "volver\n";
        if (kbhit)
        {
            int k = getkey();
            if (k == 14)
                mod--;
            if (k == 15)
                mod++;
            if (k == 1)
            {
                if (mod == 0)
                    edus(pUser);
                if (mod == 1)
                    return;
            }
        }
    }



}