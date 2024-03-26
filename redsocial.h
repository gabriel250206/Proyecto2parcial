#include "usuarios.h"
#include "publicaciones.h"

using namespace std;

class RedSocial{

    private:
        vector<Usuario*> usuarios;
        vector<UsuarioPremium*> usuarioPremium;
        vector<Publicacion*>publicaciones;
        vector<PublicacionPremium*>publicacionesPremium;
    public:
        string nombre;
        int numeroDeUsuarios;
        int numeroDePublicaciones; /// se modifica en interfaz

        void agregarUsuario(Usuario* nuevo);
        void mostrarUsuarios();
        void mostrarPublicaciones();
        Usuario* getUsuario(int id);
        Usuario* getUsuariopos(int pos);




};