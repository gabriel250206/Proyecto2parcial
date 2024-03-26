#include "usuarios.h"
#include "publicaciones.h"
#include <vector>
using namespace std;

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




};