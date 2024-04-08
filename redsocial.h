
#include <vector>
#include <string>
using namespace std;
class Publicacion;
class PublicacionPremium;
class Usuario;
class UsuarioPremium;
class Clan;
class RedSocial{

    private:
        vector<Usuario*> usuarioss;
        vector<UsuarioPremium*> usuarioPremium;
        vector<vector<Publicacion*> >publicacioness;/// hacerlo vector de vectores como lo tenia beto
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
        void newUser(int mod, int numero);
        void mostrarClanes(vector<Clan*>clanes);
        

RedSocial(std::string nombre);
        RedSocial(std::string nombre,vector<Usuario*>usuarios);
        RedSocial(std::string nombre,vector<Usuario*>usuarios,vector<vector<Publicacion*>>publicaciones);



};