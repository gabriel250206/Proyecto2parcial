#include "publicaciones.h"
#include "usuarios.h"
#include <vector>
using namespace std;
class Publicacion;
class PublicacionPremium;
class Usuario;
class UsuarioPremium;
class RedSocial{

    private:
        vector<Usuario*> usuarioss;
        vector<UsuarioPremium*> usuarioPremium;
        vector<vector<Publicacion*>> publicacioness;
        vector<PublicacionPremium*>publicacionesPremium;
    public:
        string nombre;
        int numeroDeUsuarios=0;
        int numeroDePublicaciones=0; /// se modifica en interfaz
        void eliminarUsuario(int pos);
        void agregarUsuario(Usuario* nuevo);
        void mostrarUsuarios();
        void mostrarPublicaciones();
        Usuario* getUsuario(int id);
        Usuario* getUsuariopos(int pos);

        RedSocial(string nombre){
            this->nombre=nombre;
        }
        RedSocial(string nombre,vector<Usuario*>usuarios){
            this->nombre=nombre;
            this->usuarioss=usuarios;
        }
        RedSocial(string nombre,vector<Usuario*>usuarios,vector<vector<Publicacion*>>publicaciones){
            this->nombre=nombre;
            this->usuarioss=usuarios;
            this->publicacioness=publicaciones;
        }

};