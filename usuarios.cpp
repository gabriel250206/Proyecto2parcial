#include <iostream>
#include <string>
#include <vector>
#include "usuarios.h"
using namespace std;

Usuario::Usuario(string nombre){
    this-> nombre="nulo";
    this-> edad=0;
    this-> nacionalidad="wakanda";
    this->id=contId;
  
    
}
Usuario::Usuario(string nombre,int edad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad="wakanda";
    this->id=contId;
    
   
}

Usuario::Usuario(string nombre, int edad, string nacionalidad){
    this-> nombre=nombre;
    this-> edad=edad;
    this-> nacionalidad=nacionalidad;
    this->id=contId++;
    
}