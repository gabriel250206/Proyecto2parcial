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
    while(1){
        cls();
        pUsuario->mostrarPublicaciones();
        
        
        
        int mod=0;
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
                    pUsuario->agregarAmigo(P.getUsuario(id));
                    cout<<"agrega"<<endl;
                }
                cout<<"sale"<<endl;
                return;
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
        if (mod > P.numeroDeUsuarios)
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
        cout << "Salir";
        if (kbhit)
        {
            int k = getkey();
            if (k == 14)
                mod--;
            if (k == 15)
                mod++;
            if (k == 1)
            {
                if (mod == P.numeroDeUsuarios)return 0;
                else{
                pUsuario = P.getUsuariopos(mod);
                opciones();
                }
            }
        }
    }
}
int main()
{   
    Usuario Alberto("Alberto" , 16 , "mexicano");
    Usuario Gabriel("Gabriel" , 18 , "mexicano");
    P.agregarUsuario(&Alberto);
    P.agregarUsuario(&Gabriel);
    hidecursor();
    setColor(89);
    setColor(BLACK);
    Tittle();
    cout << "Presiona cualquier tecla para iniciar \n";
    anykey();
    if (!menuk())
        return 0;
    
}
