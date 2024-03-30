#include "publicaciones.h"
#include "usuarios.h"
#include <vector>
#include <string>
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
        std::string nombre;
        int numeroDeUsuarios=0;
        int numeroDePublicaciones=0; /// se modifica en interfaz
        void eliminarUsuario(int pos);
        void agregarUsuario(Usuario* nuevo);
        void mostrarUsuarios();
        void mostrarPublicaciones();
        Usuario* getUsuario(int id);
        Usuario* getUsuariopos(int pos);

        RedSocial(std::string nombre);
        RedSocial(std::string nombre,vector<Usuario*>usuarios);
        RedSocial(std::string nombre,vector<Usuario*>usuarios,vector<vector<Publicacion*>>publicaciones);

};