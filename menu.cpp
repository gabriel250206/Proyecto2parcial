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


void Tittle()
{
cout<<"  _______           _______ _________ _______  _______ \n";
cout<<" (  ___  )|\\     /|(  ___  )\\";cout<<"__   __/(  ___  )(  ____ )\n";
cout<<" | (   ) || )   ( || (   ) |   ) (   | (   ) || (    )|\n";
cout<<" | (___) || |   | || (___) |   | |   | (___) || (____)|\n";
cout<<" |  ___  |( (   ) )|  ___  |   | |   |  ___  ||     __)\n";
cout<<" | (   ) | \\ \\_/ / | (   ) |   | |   | (   ) || (\\ (   \n";
cout<<" | )   ( |  \\   /  | )   ( |   | |   | )   ( || ) \\ \\__\n";
cout<<" |/     \\|   \\_/   |/     \\|   )_(   |/     \\||/   \\__/\n";
cout<<endl<<endl<<"la leyenda de pmp"<<endl;
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
        Usuario* pUser;
        hidecursor();
        inicio:
        system("cls");
        P.numeroDeUsuarios=P.getNum();
        P.numeroDePublicaciones=P.getNumP();
        cout<<"Usuarios: "<<P.numeroDeUsuarios<<endl;
        cout<<"Publicaciones: "<<P.numeroDePublicaciones<<endl;
        // P.mostrarPublicaciones();
        if (mod > 6)
            mod = 0;
        if (mod < 0)
            mod = 6;
        if (mod == 0)
            cout << ">";
        cout << "Agregar usuarios"<<endl;
        if(mod==1)
            cout<<">";
        cout<<"Agregar usuario premium"<<endl;
        if(mod==2)
            cout<<">";
        cout<<"Mostrar clanes"<<endl;
        if(mod==3)
            cout<<">";
        cout<<"Todos los usuarios"<<endl;
        if(mod==4)
            cout<<">";
        cout<<"Todas las publicaciones"<<endl;
        if(mod==5)
            cout<<">";
        cout<<"Eliminar usuario"<<endl;
        if(mod==6)
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
                if (mod == 6)return 0;
                else{
                    if(mod==0||mod==1){
                        cls();
                        P.newUser(mod);
                        goto inicio;
                        
                    }
                    
                    if(mod==2){
                        msleep(1000);
                        P.mostrarClanes(tribus);
                        
                    }
                    if(mod==3){
                        P.mostrarUsuarios();
                    }
                    if(mod==4){
                        P.mostrarPublicaciones();
                    }
                    if(mod==5){
                        cls();
                        cout<<"introduce su id"<<endl;
                        int idea;
                        cin>>idea;
                        if(idea>0&&idea<P.getNum()){
                            P.eliminarUsuario(idea-1,tribus);
                        }else{
                            cout<<"no existe ese usuario"<<endl;
                            msleep(3000);
                        }
                        
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
