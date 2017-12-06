#include "GerenteBD.hpp"

//#define DEBUG
#ifdef DEBUG
	#define DEBUG_PRINT(x) do{cout << x << endl;}while(0)
#else
	#define DEBUG_PRINT(x) 
#endif

GerenteBD::GerenteBD()
{
	DEBUG_PRINT("GerenteDB::() - inicio");
	nomeBD = "usuarios";
	string buffer;
	ifstream f_usuarios(nomeBD + ".json");
	getline(f_usuarios, buffer);
	usuariosBD = json::parse(buffer);
	f_usuarios.close();
	DEBUG_PRINT("GerenteDB::() - fim");
}

void GerenteBD::Run(){
	GerenteBD gBD;
	Usuario uLogado;
	string uLogin;
	string uSenha;
	cout << "Insira o login: ";
	cin >> uLogin;
	if ( gBD.ExisteUsuario( uLogin ) ) { //usuario cadastrado
		cout << "Insira sua senha: " << endl;
		do{
            getline(cin, uSenha);
        }while(uSenha == "");
		
		if (gBD.ChecaSenha(uLogin, uSenha)) {
			uLogado = gBD.RetornaUsuario(uLogin);
			cout << "Bem-vindo, " << uLogado.GetNome() << endl ; 
		} else {
			cout << "Senha inválida." << endl;
		}
	} else {
		cout << "Usuario não cadastrado." << endl;
		string uResposta;
		while (true)
		{
			cout << "Cadastrar novo usuario? S/N: ";
			cin >> uResposta;
			if (uResposta == "s" || uResposta == "S") {
				uLogado = gBD.NovoUsuario( uLogin );
				break;
			}
			else {
				break;
			}
		}
	} 
}


bool GerenteBD::ExisteUsuario(string _login) {
	auto resultado = usuariosBD.find( _login);
	bool encontrado = (resultado != usuariosBD.end());
	if (encontrado)
		return true;
	return false;
}

bool GerenteBD::ChecaSenha(string _login, string _senha){
	string senhaSalva = usuariosBD[_login]["senha"];
	if (_senha == senhaSalva)
		return true;
	return false;
}

Usuario GerenteBD::RetornaUsuario( string _login ){
	Usuario usuario;
	usuario.SetSenha(usuariosBD[_login]["senha"]);
	usuario.SetNome(usuariosBD[_login]["nome"]);
	usuario.SetLogin(_login);
	return usuario;
}

Usuario GerenteBD::NovoUsuario(string _login){
	Usuario usuario;
	string nome;
	string senha;
	cout << "Nome: ";
	do{
		getline(cin, nome);
    }while(nome == "");
	cout << "Senha: ";
	do{
		getline(cin, senha);
    }while(senha == "");
	usuario.SetLogin(_login);
	usuario.SetNome(nome);
	usuario.SetSenha(senha);
	
	std::map<string, string> c_map { {"senha", senha}, {"nome", nome} };
	json j_map(c_map);
	usuariosBD[_login]= j_map;
	
	return usuario;
}

GerenteBD::~GerenteBD(){
	DEBUG_PRINT("GerenteDB:: ~ () - inicio");
	ofstream f_usuarios;
	f_usuarios.open(nomeBD + ".json", std::ofstream::out);
	f_usuarios << usuariosBD.dump();
	f_usuarios.close();
	
	DEBUG_PRINT("showBD: " << usuariosBD.dump(2));
	DEBUG_PRINT("GerenteDB:: ~ () - fim");
}