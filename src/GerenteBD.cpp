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
	string uResposta;
	cout << "Insira o login: ";
	std::cin.clear(); // unset failbit
   	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.sync();
	cin >> uLogin;
	if ( gBD.ExisteUsuario( uLogin ) ) { //usuario cadastrado
		cout << "Insira sua senha: " << endl;
		do{
			std::cin.clear(); // unset failbit
			std::cin.sync();
			getline(cin, uSenha);
			if (gBD.ChecaSenha(uLogin, uSenha)) {
				uLogado = gBD.RetornaUsuario(uLogin);
			} else {
				cout << "Senha inválida." << endl;
			}
		}while(uSenha == "" || !gBD.ChecaSenha(uLogin, uSenha));

	} else {
		cout << "Usuario não cadastrado." << endl;
		while (true)
		{
			cout << "Cadastrar novo usuario? S/N: ";
			std::cin.clear(); // unset failbit
   			std::cin.sync();
			uResposta.clear();
			cin >> uResposta;
			if (uResposta[0] == 's' || uResposta[0] == 'S') {
				uLogado = gBD.NovoUsuario( uLogin );
				break;
			}
			else {
				break;
			}
		}
	}
	cout << "Bem vindo, " << uLogado.GetNome() << "!\n" << endl;
	if(uLogado.listas.size() == 0){
		uResposta.clear();
		uResposta[0] = 'n';
	}
	else{
		cout << "Voce tem " << uLogado.listas.size() << " listas salvas. Deseja restaurar alguma? (S/N)";
		std::cin.clear(); // unset failbit
   		std::cin.sync();
		uResposta.clear();
		cin >> uResposta;
	}
	if(uResposta[0] == 's' || uResposta[0] == 'S'){
		cout << "Digite o numero da lista que deseja abrir:" << endl;
		for(unsigned int i = 0; i < uLogado.listas.size(); i++){
			cout << "(" << i << ")" << uLogado.listas[i]->GetNome() << endl;
		}
		unsigned int n;
		scanf("%u", &n);
		uLogado.AbrirLista(uLogado.listas[n]);
	}
	else{
		cout << "Deseja cadastrar uma nova lista? (Se nao, saira do programa) (S/N)";
		std::cin.clear(); // unset failbit
   		std::cin.sync();
		uResposta.clear();
		cin >> uResposta;
		if(uResposta[0] == 's' || uResposta[0] == 'S'){
			cout << "Digite o nome da lista: ";
			string novaLista;
			std::cin.clear(); // unset failbit
   			std::cin.sync();
			cin >> novaLista;
			uLogado.CriarLista(novaLista);
			cout << "Lista criada com sucesso. Que tal acrescentar alguns itens?" << endl;
		}
		else{
			exit(0);
		}
	}
	cout << "Lista " << uLogado.GetListaAberta().GetNome() << endl;
	for(unsigned int i = 0; i < uLogado.GetListaAberta().produtos.size(); i++){
		cout << uLogado.GetListaAberta().produtos[i]->GetNome() << endl;
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