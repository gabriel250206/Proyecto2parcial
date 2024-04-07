#include <iostream>
#include <vector>
#include <string>
#include "rlutil.h"
#include "redsocial.h"
#include "publicaciones.h"
#include "usuarios.h"
using namespace std;
using namespace rlutil;
RedSocial P{"Clans"};
Usuario *pUsuario;
void editar(){}

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
void newUser(){
    cout<<"escribe su nombre"<<endl;
    string nombre;
    cin>>nombre;
    int mod=0;
    while(1){
        cls();
        cout<<endl<<"tiene nacionalidad?"<<endl;
        if(mod==0){
            cout<<">si"<<endl<<"no"<<endl;
        }
        if(mod==1){
            
            cout<<"si"<<endl<<">no"<<endl;
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
                    cout<<"escribe la edad"<<endl;
                    int edad;
                    cin>>edad;
                    cout<<"escribe la nacionalidad"<<endl;
                    string nacionalidad;
                    cin>>nacionalidad;
                    Usuario* pNuevo= new Usuario(nombre,edad,nacionalidad);
                    P.agregarUsuario(pNuevo);
                    return;

                }
                if(mod==1){
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
                                Usuario* pNuevo=new Usuario(nombre,edad);
                                P.agregarUsuario(pNuevo);
                                return;
                            }
                            if(mod2==1){
                                Usuario* pNuevo=new Usuario(nombre);
                                P.agregarUsuario(pNuevo);
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
void opciones()
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
                    data();
                if (mod == 1)
                    publ();
                if (mod == 2)
                    ami();
                if (mod == 3)
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
    int mod = 0;
    while (1)
    {
        hidecursor();
        system("cls");
        if (mod > P.numeroDeUsuarios+1)
            mod = 0;
        if (mod < 0)
            mod = P.numeroDeUsuarios;
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
                if (mod == P.numeroDeUsuarios+1)return 0;
                else{
                    if(mod==P.numeroDeUsuarios){
                        cls();
                        newUser();
                    }
                    else{
                    pUsuario = P.getUsuariopos(mod);
                    opciones();
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
    Usuario LanaDelRey("Lana del rey",21,"oaxaca");
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
