
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
        //vector<UsuarioPremium*> usuarioPremium;
        vector<Publicacion*> publicacioness;
        //vector<PublicacionPremium*>publicacionesPremium;
    public:
        string nombre;
        int numeroDeUsuarios;
        int numeroDePublicaciones=0; 
        void eliminarUsuario(int pos,vector<Clan*>tribu);
        void agregarUsuario(Usuario* nuevo);
        void mostrarUsuarios();
        void mostrarPublicaciones();
        Usuario* getUsuario(int id);
        Usuario* getUsuariopos(int pos);
        void newUser(int mod);
        void mostrarClanes(vector<Clan*>clanes);
        void nuevaP(Publicacion* publicacion);
        int getNum();
        int getNumP();
        void data(Usuario* pUser);
        void edus(Usuario* pUser);
        void opciones(Usuario* pUser);
        void ami(Usuario* pUser);
        void publ(Usuario* pUser);
        void misiones(Usuario* pUser);

        RedSocial(std::string nombre);
        RedSocial(std::string nombre,vector<Usuario*>usuarios);
        RedSocial(std::string nombre,vector<Usuario*>usuarios,vector<Publicacion*>publicaciones);



};