#include <bits/stdc++.h>
#include "rlutil.h"
#include "usuarios.h"
using namespace std;
using namespace rlutil;
vector<Usuario> Usuarios;
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
            cout << Usuarios[i].nombre;
        }
        if (kbhit)
        {
            int k = getkey();
            if (k == 14)
                mod--;
            if (k == 15)
                mod++;
            if (k == 1)
            {
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
