#include <bits/stdc++.h>
#include "rlutil.h"

using namespace std;
using namespace rlutil;
class Usuario
{
public:
    string nombre;
};

void data()
{
    cout << getId;
}
void publ(){};
void ami(){};
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
        if (mod > Usuarios.size())
            mod = 0;
        if (mod < 0)
            mod = Usuarios.size();
        for (int i = 0; i < Usuarios.size(); i++)
        {
            if (mod == i)
                cout << ">";
            cout << Usuarios[i].nombre << '\n';
        }
        if (mod == Usuarios.size())
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
                if (mod == Usuarios.size())
                    return 0;
                Usuario a = &Usuarios[mod];
                else opciones();
            }
        }
    }
}

int main()
{
    hidecursor();
    setColor(89);
    setColor(BLACK);
    Tittle();
    cout << "Presiona cualquier tecla para iniciar \n";
    anykey();

    if (!menuk())
        return 0;

    return 0;
}
