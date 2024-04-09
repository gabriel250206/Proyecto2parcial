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

void edus(Usuario* pUser){
    string lll="+´+´´+", uio="'0989}+"  ; 
    int edd=-1; 
    p:
    system("cls");
    cout << " presione 1 para cambiar el nombre\n";
    cout << " presione 2 para cambiar la edad\n";
    cout << " presione 3 para cambiar la nacionaldad\n";
    cout << " presione 4 para volver\n";
    int h ; 
    
    cin>> h;
    if(h == 1 ){
         system("cls");
        cout<< "Escriba el nombre ";
        cin>>lll;
        goto p;
    }
    if(h == 2 ){
        system("cls");
        cout<< "Escriba la edad ";
        cin>>edd;
        goto p;
    }
    if(h == 3 ){
        system("cls");
        cout<< "Escriba la nacionalidad ";
        cin>>uio;
        goto p;
    }
    if(h == 4 ){
        if (lll != "+´+´´+"){
            cout << "confirme el cambio de nombre de "<< pUser->nombre << " a "<< lll<<endl;
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
            cout << "confirme el cambio de nacionalidad de "<< pUser->nacionalidad << " a "<< uio<<endl;
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
            cout << "confirme el cambio de edad de "<< pUser->edad << " a "<< edd <<endl;
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
void misiones(Usuario* pUser){
    int mod=0;
    Mision* pMision=nullptr;
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
                    cout<<"funciona";
                    pMision= new MisionAmigos();
                    cout<<"funciona";
                    pUser->selectMision(pMision);
                    cout<<"funciona";
                    return;
                }
                if(mod==1){
                    cout<<"funciona";
                    pMision= new MisionPublicacion();
                    cout<<"funciona";
                    pUser->selectMision(pMision);
                    cout<<"funciona";
                    return;
                }
                if(mod==2){
                    return;
                }
            }
        }
    }
}
void data(Usuario* pUser)
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
void publ(Usuario* pUser){
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
                    pUser->crearPublicacion(&P);
                }
                
                return;
            }
        }

        
    }

}
void ami(Usuario *pUser){
    system("cls");
    int mod=0;
    while(1){
        cls();
        
        for(int i=0;i<pUser->amigos.size();i++){
            cout<<pUser->amigos[i]->nombre<<endl;
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
                    pUser->agregarAmigo(nuevoUser);
                }
                cout<<"sale"<<endl;
                return;
            }
        }

        
    }
}

void opciones(Usuario* pUser)
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
                    data(pUser);
                if (mod == 1)
                    
                    publ(pUser);
                if (mod == 2)
                    ami(pUser);
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
        // cout<<"Usuarios: "<<P.numeroDeUsuarios<<endl;
        // cout<<"Publicaciones: "<<P.numeroDePublicaciones<<endl;
        // P.mostrarPublicaciones();
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
                    if(mod==P.numeroDeUsuarios||mod==P.numeroDeUsuarios+1){
                        cls();
                        P.newUser(mod,P.numeroDeUsuarios);
                        goto inicio;
                        
                    }
                    
                    if(mod==P.numeroDeUsuarios+2){
                        P.mostrarPublicaciones();
                        msleep(1000);
                    }
                    else{
                    pUser = P.getUsuariopos(mod);
                    opciones(pUser);
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
