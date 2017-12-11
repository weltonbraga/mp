// WINDOWS
#ifdef _WIN32
	#include <windows.h>
	
//LINUX
#elif __linux__
	#include <unistd.h>
	
#else
	#error "Unknown compiler"
	
#endif

#include "json.hpp"
#include "Usuario.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>

using json = nlohmann::json;
using namespace std;

class GerenteBD {
private:
	string nomeBD;
	json usuariosBD;
public:
		/*!
	*	\brief Construtor padrão
	*
	*	Na construção da instância de \c GerenteBD é feita a leitura
	*	dos arquivos com registros de usuários.
	*/
	GerenteBD();
	/*!
	*	\brief Destrutor.
	*
	*	Salva os dados da memória no arquivo com registros de usuários.
	*/
	virtual ~GerenteBD();

	/*!
	*	\brief Verifica a existencia de usuário.
	*	\param _login Login do usuário.
	*	\return true caso o login exista no banco.
	*/
	bool ExisteUsuario(string _login);
	/*!
	*	\brief Verifica se o login confere com a senha.
	*	\param _login Login do usuario.
	*	\param _senha Senha a ser testada.
	*	\return retorna true apenas se o login existe e está associada à senha.
	*/
	bool ChecaSenha(string _login, string _senha);
	
	Usuario RetornaUsuario( string _login );
	Usuario NovoUsuario( string _login);
	static void Run();
	static void LimpaTela();
	void SalvaListas(Usuario& uLogado);
	void MenuListas(Usuario& uLogado);
	void CarregaListas(Usuario& uLogado);
	
	static vector<Lista> json_para_vector( json& entrada);
};