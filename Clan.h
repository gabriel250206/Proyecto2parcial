#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Usuario;

class Clan{
    private: 
        string nombre;
    public:
        vector<Usuario*> participantes;

    Clan(string nombre);
    void nuevoParticipante(Usuario* usuario);
    string getName();
    void getParticipantes();

};

