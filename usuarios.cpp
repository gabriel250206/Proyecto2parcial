#include <iostream>
#include <string>
#include <vector>
#include "usuarios.h"
using namespace std;

Usuario::Usuario(){
    this-> nombre="nulo";
    this-> edad=0;
    this-> nacionalidad="wakanda";
    this->id=00000;
}

Usuario::Usuario(int nombre, int edad, string nacionalidad, long id){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad=nacionalidad;
    this->id=id;
}