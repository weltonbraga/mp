#include "GerenteBD.hpp"

//#define DEBUG
#ifdef DEBUG
	#define DEBUG_PRINT(x) do{cout << x << endl;}while(0)
#else
	#define DEBUG_PRINT(x) 
#endif

GerenteBD::GerenteBD()
{
	DEBUG_PRINT("GerenteBD::() - inicio");
	nomeBD = "usuarios";
	string buffer;
	ifstream f_usuarios(nomeBD + ".json");
	if (f_usuarios.is_open() ){
		getline(f_usuarios, buffer);
		usuariosBD = json::parse(buffer);
		f_usuarios.close();
	} else {
		DEBUG_PRINT("Falha ao abrir o arquivo - fim");
	}
	DEBUG_PRINT("GerenteBD::() - fim");
}

GerenteBD::~GerenteBD(){


	DEBUG_PRINT("GerenteBD:: ~ () - inicio");
	ofstream f_usuarios;
	f_usuarios.open(nomeBD + ".json", std::ofstream::out);
	f_usuarios << usuariosBD.dump();
	f_usuarios.close();


	
	DEBUG_PRINT("showBD: " << usuariosBD.dump(2));
	DEBUG_PRINT("GerenteBD:: ~ () - fim");
}

void GerenteBD::CarregaListas(Usuario& usuario){
	json todas_listas = usuariosBD[usuario.GetLogin()]["listas"];
	usuario.listas = GerenteBD::json_para_vector(todas_listas);
}

void GerenteBD::LimpaTela(){
	#ifdef _WIN32
	system("cls");
	#elif __linux__
	system("clear");
	#endif 
}

void GerenteBD::MenuListas(Usuario& uLogado){
	GerenteBD gBD;
	unsigned int cod_lista_atual;
	//Usuario uLogado;
	//string uLogin;
	//string uSenha;
	string uResposta;
	if(uLogado.listas.size() == 0){
		uResposta.clear();
		uResposta[0] = 'n';
		cout << "Você ainda não tem listas" << endl;
		DEBUG_PRINT ("\n\nZERO\n\n");
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
			cout << "(" << i << ")" << uLogado.listas[i].GetNome() << endl;
		}
		scanf("%u", &cod_lista_atual);
		uLogado.AbrirLista(cod_lista_atual);
		GerenteBD::LimpaTela();
	}
	else{
		cout << "(1) - Deseja cadastrar uma nova lista?"
		<< endl << "(2) - Cancelar " << endl ;
		//std::cin.clear(); // unset failbit
   		//std::cin.sync();
		//uResposta.clear();
		cin >> uResposta;
		if ( uResposta == "1"){
		//if(uResposta[0] == 's' || uResposta[0] == 'S'){
			cout << "Digite o nome da lista: ";
			string novaLista;
			//std::cin.clear(); // unset failbit
   			//std::cin.sync();
			do{
				getline(cin, novaLista);
			}while(novaLista == "");
			uLogado.CriarLista(novaLista);
			cout << "Lista criada com sucesso.\n\nQue tal acrescentar alguns itens?" << endl;
		} else if (uResposta == "2") {
			return;
		}else{
			cout << "Opcao inválida!" << endl; 
		}
	}
	cout << "Lista: " << uLogado.GetListaAberta().GetNome() << endl;
	//uLogado.GetListaAberta().MostrarTodos();
	/*for(unsigned int i = 0; i < uLogado.GetListaAberta().produtos.size(); i++){
		cout << " -------------------- " << endl;
		cout << "Item: "<< uLogado.GetListaAberta().produtos[i].GetNome() << endl;
		cout << "Codigo de Barras: "<< uLogado.GetListaAberta().produtos[i].GetCodBarras() << endl;
		cout << "Unidades: "<< uLogado.GetListaAberta().produtos[i].quantidade << endl;
		cout << "Valor unitário: "<<uLogado.GetListaAberta().produtos[i].GetPreco() << endl;
		cout << "Marca: " << uLogado.GetListaAberta().produtos[i].GetMarca() << endl;
	}*/
	int op;
	do{
		//GerenteBD::LimpaTela();
		uLogado.GetListaAberta().MostrarTodos();
		cout << "\n(1) Acrescentar produto" << endl;
		cout << "(2) Alterar produto" << endl;
		cout << "(3) Excluir produto" << endl;
		cout << "(4) Finalizar compra." << endl;
		cout << "(5) Sair do menu." << endl;
		scanf("%d", &op);
		switch(op){
			case 1:
				{
				cout << "Insira o codigo de barras: ";
				int cod;
				cin >> cod;
				if (uLogado.GetListaAberta().ExisteProduto(cod)) {
					int id = uLogado.GetListaAberta().RetornaIdProduto(cod);
					uLogado.GetListaAberta().produtos[id].quantidade += 1;
					cout << "\nProduto adicionado!\n" << endl
					DEBUG_PRINT("q: " << uLogado.GetListaAberta().produtos[id].quantidade);
					break;
				}
				/*
				{
					int cod, i = 0;
				do{
					cod = i;
					i++;
				} while(uLogado.GetListaAberta().ExisteProduto(cod));
				*/
				cout << "Insira o nome: ";
				std::cin.clear();
				std::cin.sync();
				string _nome;
				do{
					getline(cin, _nome);
				}while(_nome == "");
				cout << "Insira o preco: ";
				double _preco;
				cin >> _preco;
				cout << "Insira a marca: ";
				std::cin.clear();
				std::cin.sync();
				string _marca;
				do{
					getline(cin, _marca);
				}while(_marca == "");

				//cin >> _marca;
				cout << "Insira a quantidade: ";
				int qtd;
				scanf("%d", &qtd);
				Produto prod(cod, _nome, _preco, _marca, qtd);
				uLogado.GetListaAberta().AdicionarProduto(prod);
				}
				break;

			case 2:
				int op2;
				do{
					cout << "\n(1) Alterar nome" << endl;
					cout << "(2) Alterar preco" << endl;
					cout << "(3) Alterar quantidade" << endl;
					cout << "(4) Alterar marca" << endl;
					cout << "(5) Terminar alteracao\n" << endl;
					scanf("%d", &op2);
					switch(op2){
						case 1:
							cout << "Escolha o COD BARRAS do produto: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{
								int cod;
								scanf("%d", &cod);
								
								if(uLogado.GetListaAberta().ExisteProduto(cod)){
									
									cout << "Digite o nome: ";
									string nome;
									std::cin.clear();
									std::cin.sync();
									uResposta.clear();
									do{
										getline(cin, nome);
									}while(nome == "");
									int id = uLogado.GetListaAberta().RetornaIdProduto(cod);
									uLogado.GetListaAberta().produtos[id].SetNome(nome);
									cout << "\nDados alterados com sucesso!" << endl;
								}else {
									cout << "\nCodigo de barras não existe.\n" << endl;
								}
							}
							break;

						case 2:
							cout << "Escolha o COD BARRAS do produto:: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{
								int cod;
								scanf("%d", &cod);
								if(uLogado.GetListaAberta().ExisteProduto(cod)){
									cout << "Digite o preco: ";
									double preco;
									//scanf("%f.2", &preco);
									cin >> preco;
									int id = uLogado.GetListaAberta().RetornaIdProduto(cod);
									uLogado.GetListaAberta().produtos[id].SetPreco(preco);
									cout << "\nDados alterados com sucesso!" << endl;
								}else {
									cout << "\nCodigo de barras não existe.\n" << endl;
								}
							}
							break;

						case 3:
							cout << "Escolha o COD BARRAS do produto:: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{
								int cod;
								scanf("%d", &cod);
								if(uLogado.GetListaAberta().ExisteProduto(cod)){
									int qtd;
									cout << "Digite a quantidade: ";
									scanf("%d", &qtd);
									int id = uLogado.GetListaAberta().RetornaIdProduto(cod);
									uLogado.GetListaAberta().produtos[id].quantidade = qtd;

									cout << "\nDados alterados com sucesso!" << endl;
								}else {
									cout << "\nCodigo de barras não existe.\n" << endl;
								}
							}
							break;

						case 4:
							cout << "Escolha o COD BARRAS produto: " << endl;
							uLogado.GetListaAberta().MostrarTodos();
							{
								int cod;
								scanf("%d", &cod);
								if(uLogado.GetListaAberta().ExisteProduto(cod)){
									cout << "Digite a marca: ";
									string marca;
									//std::cin.clear();
									//std::cin.sync();
									uResposta.clear();
									do{
										getline(cin, marca);
									}while(marca == "");
									int id = uLogado.GetListaAberta().RetornaIdProduto(cod);
									uLogado.GetListaAberta().produtos[id].SetMarca(marca);
									cout << "Dados alterados com sucesso!" << endl;
								} else {
									cout << "\nCodigo de barras não existe.\n" << endl;
								}
							}
							break;	

						default:
							GerenteBD::LimpaTela();
							cout << "Opção inválida" << endl;
							break;			
					}
				} while(op2 < 5);
				break;

			case 3:
				cout << "Escolha o COD BARRAS do produto: " << endl;
				uLogado.GetListaAberta().MostrarTodos();
				{int cod;
				scanf("%d", &cod);
				if(uLogado.GetListaAberta().ExisteProduto(cod)){
					int id = uLogado.GetListaAberta().RetornaIdProduto(cod);
					cout << "COD_BARRAS: " << uLogado.GetListaAberta().produtos[id].GetCodBarras() << endl;
					cout << "NOME: " << uLogado.GetListaAberta().produtos[id].GetNome() << endl;
					cout << "PRECO: " << uLogado.GetListaAberta().produtos[id].GetPreco() << endl;
					cout << "MARCA: " << uLogado.GetListaAberta().produtos[id].GetMarca() << endl;
					cout << "QUANTIDADE: " << uLogado.GetListaAberta().produtos[id].quantidade << endl;
					cout << "\nDeseja mesmo excluir o produto? (S/N)" << endl;
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
				}else {
					cout << "\nCodigo de barras não existe.\n" << endl;
				}
			}
				break;

			

			case 4:
				cout << "Compra finalizada." << endl;
				break;

			case 5:
				DEBUG_PRINT(" SAINDO:   SalvarLista ...");
				uLogado.SalvarLista(uLogado.GetListaAberta());
				DEBUG_PRINT(" SAINDO:    SalvarLista FIM");
				//op = 6;
				break;
		}
	} while(op < 5);
}
void GerenteBD::SalvaListas(Usuario& uLogado){
	DEBUG_PRINT("GerenteBD::SalvaListasUsuario - inicio");

	json j_l_todos_produtos;
	json j_l_todas_listas;

	for (std::vector<Lista>::iterator v_l = uLogado.listas.begin() ; v_l != uLogado.listas.end(); ++v_l){
		for (std::vector<Produto>::iterator p = (*v_l).produtos.begin() ; p != (*v_l).produtos.end(); ++p){
			json produto_atual
							{
								{"codBarras", (*p).GetCodBarras()},
								{"nome", (*p).GetNome()}, 
								{"quantidade", (*p).quantidade}, 
								{"preco", (*p).GetPreco()},
								{"marca", (*p).GetMarca()}
							};
			j_l_todos_produtos.push_back( produto_atual );
		}
	
		json lista_atual {
				{"nome" , (*v_l).GetNome()},
				{"produtos", j_l_todos_produtos}
			};
		j_l_todos_produtos.clear();

		j_l_todas_listas.push_back(lista_atual);
	}
	usuariosBD[uLogado.GetLogin()]["listas"]= j_l_todas_listas;
	DEBUG_PRINT("GerenteBD::SalvaListasUsuario - FIM");
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
	
	json dados { {"senha", senha}, {"nome", nome} , {"listas", {}} };
	usuariosBD[_login]= dados;
	
	return usuario;
}

vector<Lista> GerenteBD::json_para_vector( json& entrada) {
	DEBUG_PRINT("static vector<Lista> json_para_vector( json& entrada) inicio");
	vector<Lista> l_final;
	for(auto&& lista : entrada) {
		DEBUG_PRINT( "lista[nome]: "<< lista["nome"] );
		string nome = lista["nome"];
		Lista l(nome);
		for(auto&& produto : lista["produtos"]) {
			DEBUG_PRINT( "produto: "<< produto );
			int codBarras = produto["codBarras"];
			string marca = produto["marca"];
			string nome = produto["nome"];
			double preco = produto["preco"];
			int qtd = produto["quantidade"];
			Produto p (codBarras, nome, preco, marca, qtd );
			l.AdicionarProduto(p);
		}
		l_final.push_back(l);
	}
	DEBUG_PRINT("static vector<Lista> json_para_vector( json& entrada) fim");
	return l_final;
}

