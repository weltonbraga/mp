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
	int op;
	do{
		system("cls | clear");
		cout << "\n(1) Acrescentar produto" << endl;
		cout << "(2) Alterar produto" << endl;
		cout << "(3) Excluir produto" << endl;
		cout << "(4) Salvar lista" << endl;
		cout << "(5) Finalizar compra." << endl;
		cout << "(6) Sair do menu." << endl;
		scanf("%d", &op);
		switch(op){
			case 1:
				{int cod, i = 0;
				do{
					cod = i;
					i++;
				} while(uLogado.GetListaAberta().ExisteProduto(cod));
				cout << "Insira o nome: ";
				std::cin.clear();
				std::cin.sync();
				string _nome;
				cin >> _nome;
				cout << "Insira o preco: ";
				float _preco;
				scanf("%f.2", &_preco);
				cout << "Insira a marca: ";
				std::cin.clear();
				std::cin.sync();
				string _marca;
				cin >> _marca;
				cout << "Insira a quantidade: ";
				int qtd;
				scanf("%d", &qtd);
				Produto* prod;
				prod = new Produto(cod, _nome, _preco, _marca, qtd);
				uLogado.GetListaAberta().AdicionarProduto(*prod);}
				break;

			case 2:
				int op2;
				do{
					cout << "\n(1) Alterar nome" << endl;
					cout << "(2) Alterar preco" << endl;
					cout << "(3) Alterar marca" << endl;
					cout << "(4) Alterar quantidade" << endl;
					cout << "(5) Terminar alteracao\n" << endl;
					scanf("%d", &op2);
					switch(op2){
						case 1:
							cout << "Escolha o produto: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{int cod;
							if(uLogado.GetListaAberta().ExisteProduto(cod)){
								scanf("%d", &cod);
								cout << "Digite o nome: ";
								string nome;
								std::cin.clear();
								std::cin.sync();
								uResposta.clear();
								cin >> uResposta;
								uLogado.GetListaAberta().produtos[cod]->SetNome(nome);
								cout << "Dados alterados com sucesso!" << endl;
							}}
							break;

						case 2:
							cout << "Escolha o produto: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{int cod;
							scanf("%d", &cod);
							if(uLogado.GetListaAberta().ExisteProduto(cod)){
								cout << "Digite o preco";
								float preco;
								scanf("%f.2", &preco);
								uLogado.GetListaAberta().produtos[cod]->SetPreco(preco);
								cout << "Dados alterados com sucesso!" << endl;
							}}
							break;

						case 3:
							cout << "Escolha o produto: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{int cod;
							scanf("%d", &cod);
							if(uLogado.GetListaAberta().ExisteProduto(cod)){
								int qtd;
								scanf("%d", &qtd);
								cout << "Digite a quantidade";
								uLogado.GetListaAberta().produtos[cod]->SetPreco(qtd);
								cout << "Dados alterados com sucesso!" << endl;
							}}
							break;

						case 4:
							cout << "Escolha o produto: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{int cod;
							scanf("%d", &cod);
							if(uLogado.GetListaAberta().ExisteProduto(cod)){
								cout << "Digite a marca: ";
								string marca;
								std::cin.clear();
								std::cin.sync();
								uResposta.clear();
								cin >> uResposta;
								uLogado.GetListaAberta().produtos[cod]->SetMarca(marca);
								cout << "Dados alterados com sucesso!" << endl;
							}}
							break;	

						default:
							system("cls | clear");
							break;			
					}
				} while(op2 < 5);
				break;

			case 3:
				cout << "Escolha o produto: " << endl;
				uLogado.GetListaAberta().MostrarTodos();
				{int cod;
				scanf("%d", &cod);
				if(uLogado.GetListaAberta().ExisteProduto(cod)){
					cout << "COD_BARRAS: " << uLogado.GetListaAberta().produtos[cod]->GetCodBarras() << endl;
					cout << "NOME: " << uLogado.GetListaAberta().produtos[cod]->GetNome() << endl;
					cout << "PRECO: " << uLogado.GetListaAberta().produtos[cod]->GetPreco() << endl;
					cout << "MARCA: " << uLogado.GetListaAberta().produtos[cod]->GetMarca() << endl;
					cout << "QUANTIDADE: " << uLogado.GetListaAberta().produtos[cod]->quantidade << endl;
					cout << "\nDeseja mesmo escluir o produto? (S/N)" << endl;
					std::cin.clear();
					std::cin.sync();
					uResposta.clear();
					cin >> uResposta;
					if(uResposta[0] == 's' || uResposta[0] == 'S'){
						uLogado.GetListaAberta().ExcluirProduto(cod);
					}
					else{
						cout << "Produto nao excluido." << endl;
					}
				}}
				break;

			case 4:
				uLogado.SalvarLista(&uLogado.GetListaAberta());
				cout << "Lista salva com sucesso!" << endl;
				break;

			case 5:
				cout << "Compra finalizada." << endl;
				break;

			case 6:
				op = 6;
				break;
		}
	} while(op < 6);
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