
#pragma once 
class RedSocial;    
class Usuario;
#include <iostream>
using namespace std;

class Mision{
    protected:
        int valor;
        int progreso;
        int progresoTotal;
        bool complete;
    public:
        string nombre;
        string tipo;
        Mision();
        // Mision(string nombre,int valor);
        // Mision(string nombre);
        void completada(Usuario* usuario);
        void avanzaProgreso();
        void mostrarProgreso();
        int getProgreso();
        int getProgresoTotal();
        


};

class MisionAmigos:public Mision{
    public:
    MisionAmigos();
    //MisionAmigos(string nombre,int valor);
    //MisionAmigos(string nombre);
    
};

class MisionPublicacion:public Mision{
    public:
    MisionPublicacion();
    //MisionAmigos(string nombre,int valor);
    //MisionAmigos(string nombre);
    
};
