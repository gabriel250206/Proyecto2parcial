#include <bits/stdc++.h>
#include "rlutil.h"
#include "redsocial.h"

using namespace std;
using namespace rlutil;
RedSocial P;
Usuario *a;
void editar(){}
void data()
{
    a->mostrar();
    int mod = 0;
    while (1)
    {
        system("cls");
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
void publ(){}
void ami(){}

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
                a = P.getUsuariopos(mod);
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
