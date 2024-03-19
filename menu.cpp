#include <bits/stdc++.h>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
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
        if (mod > 3)
            mod = 0;
        if (mod < 0)
            mod = 3;

        if (mod == 0)
            cout << ">";
        cout << "opcion 1\n";
        if (mod == 1)
            cout << ">";
        cout << "opcion 2\n";
        if (mod == 2)
            cout << ">";
        cout << "opcion 3\n";
        if (mod == 3)
            cout << ">";
        cout << "Salir\n";
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
                    return 1;
                if (mod == 1)
                    if (mod == 2)
                        if (mod == 3)
                            return 0;
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
