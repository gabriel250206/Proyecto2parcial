#include <iostream>
#include <vector>
#include <string>
#include "rlutil.h"
#include "redsocial.h"
#include "publicaciones.h"
#include "usuarios.h"
#include "Clan.h"
using namespace std;
using namespace rlutil;
RedSocial P{"Clans"};
Usuario *pUsuario;

void editar(){}
void misiones(Usuario* pUsuario){
    int mod=0;
    Mision* pMision;
    while(1){
        cls();
        if(mod>3){
            mod=0;
        }
        if(mod<0){
            mod=3;
        }
        if(mod==0){
            cout<<">";
        }
        cout<<"mision de amigo"<<endl;
        if(mod==1){
            cout<<">";
        }
        cout<<"mision de publicacion"<<endl;
        if(mod==2)
            cout<<">";
        cout<<"salir"<<endl;
        if(kbhit){
            int k=getkey();
            if(k==14){
                mod--;
            }
            if(k==15){
                mod++;
            }
            if(k==1){
                if(mod==0){
                    pMision= new MisionAmigos;
                    pUsuario->selectMision(pMision);
                }
                if(mod==1){

                }
                if(mod==2){
                    return;
                }
            }
        }
    }
}
void data()
{
    
    int mod = 0;
    while (1)
    {
        system("cls");
        pUsuario->mostrar();
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
                    editar();
                if (mod == 1)
                    return;
            }
        }
    }



}
void publ(){

    system("cls");
    int mod=0;
    while(1){
        cls();
        pUsuario->mostrarPublicaciones();
        
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
                    pUsuario->crearPublicacion();
                }
                
                return;
            }
        }

        
    }

}
void ami(){
    system("cls");
    int mod=0;
    while(1){
        cls();
        
        for(int i=0;i<pUsuario->amigos.size();i++){
            cout<<pUsuario->amigos[i]->nombre<<endl;
        }
      
        if(mod==0){
            cout<<">agregar amigo"<<endl;
            cout<<"volver"<<endl;
        }
        if(mod==1){
            cout<<"agregar amigo"<<endl;
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
                    cout<<"escribe su id"<<endl;
                    int id;
                    cin>>id;
                    Usuario* nuevoUser=P.getUsuario(id);
                    pUsuario->agregarAmigo(nuevoUser);
                }
                cout<<"sale"<<endl;
                return;
            }
        }

        
    }
}

void opciones(Usuario* pUsuario)
{
    int mod = 0;
    while (1)
    {
        system("cls");
        if (mod > 4)
            mod = 0;
        if (mod < 0)
            mod = 4;
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
        cout << "agregar mision\n";
        if (mod == 4)
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
                    data();
                if (mod == 1)
                    publ();
                if (mod == 2)
                    ami();
                if (mod==3)
                    misiones(pUsuario);
                if (mod == 4)
                    return;
            }
        }
    }
}

void Tittle()
{
    cout << "titulo : ) \n";
    return;
}
bool menuk()
{
    Clan agua("agua");
    Clan fuego("fuego");
    Clan tierra("tierra");
    Clan aire("aire");
    vector<Clan*>tribus;
    tribus.push_back(&agua);
    tribus.push_back(&fuego);
    tribus.push_back(&tierra);
    tribus.push_back(&aire);
    int mod = 0;
    while (1)
    {
        hidecursor();
        system("cls");
        if (mod > P.numeroDeUsuarios+3)
            mod = 0;
        if (mod < 0)
            mod = P.numeroDeUsuarios+3;
        for (int i = 0; i < P.numeroDeUsuarios; i++)
        {
            if (mod == i)
                cout << ">";
            cout << P.getUsuariopos(i)->nombre<< '\n';
        }
        if (mod == P.numeroDeUsuarios)
            cout << ">";
        cout << "Agregar usuarios"<<endl;
        if(mod==P.numeroDeUsuarios+1)
            cout<<">";
        cout<<"Agregar usuario premium"<<endl;
        if(mod==P.numeroDeUsuarios+2)
            cout<<">";
        cout<<"mostrar clanes"<<endl;
        if(mod==P.numeroDeUsuarios+3)
            cout<<">";
        cout<<"Salir";
        if (kbhit)
        {
            int k = getkey();
            if (k == 14)
                mod--;
            if (k == 15)
                mod++;
            if (k == 1)
            {
                if (mod == P.numeroDeUsuarios+3)return 0;
                else{
                    if(mod==P.numeroDeUsuarios){
                        cls();
                        P.newUser(mod,P.numeroDeUsuarios);
                        
                    }
                    if(mod==P.numeroDeUsuarios+1){
                        cls();
                        P.newUser(mod,P.numeroDeUsuarios);
                        
                    }
                    if(mod==P.numeroDeUsuarios+2){
                       
                        P.mostrarClanes(tribus);
                    }
                    else{
                    pUsuario = P.getUsuariopos(mod);
                    opciones(pUsuario);
                }
                
                }
            }
        }
    }
}
int main()
{   
    Usuario Alberto("Alberto" , 16 , "mexicano");
    Usuario Gabriel("Gabriel" , 18 , "mexicano");
    UsuarioPremium LanaDelRey("Lana del rey",21,"oaxaca");
    P.agregarUsuario(&Alberto);
    P.agregarUsuario(&Gabriel);
    P.agregarUsuario(&LanaDelRey);

    

    hidecursor();
    setColor(89);
    setColor(BLACK);
    Tittle();
    cout << "Presiona cualquier tecla para iniciar \n";
    anykey();
    if (!menuk())
        return 0;
    
}
