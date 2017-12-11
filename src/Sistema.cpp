#include "Sistema.hpp"

//#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(x) do{cout << x << endl;}while(0)
#else
#define DEBUG_PRINT(x)  
#endif

void Sistema::Run() {
	while (true) {
		if (!EfetuaLogin())
			break;
		if (uLogado.GetLogin() != "") {
			NavegaConta();
		}
	}
}

bool Sistema::Sair(){
	string opcao;
	while(true) {
	    cout << "Escolha opcao desejada: " << endl;
		cout << "(1) - Logar" << endl;
		cout << "(2) - Finalizar programa" << endl;
		cin >> opcao;

		if ( opcao == "1"){
			DEBUG_PRINT("Opcao " << opcao);
			return false;
		}else if (opcao == "2"){
			DEBUG_PRINT("Opcao " << opcao);
			cout << "Até logo!" << endl; 
			return true;
		}else{
			cout << "Opcao inválida!" << endl; 
		}
	}
}

bool Sistema::EfetuaLogin(){
	string uLogin;
	string uSenha;
	string uResposta;

	if ( Sair() ){
		return false;
	}
	

	cout << "Insira o login: ";
	cin >> uLogin;
	if ( gBD.ExisteUsuario( uLogin ) ) { //usuario cadastrado
		cout << "Insira sua senha: ";
		do{
            getline(cin, uSenha);
        }while(uSenha == "");
		
		if (gBD.ChecaSenha(uLogin, uSenha)) {
			uLogado = gBD.RetornaUsuario(uLogin);
			GerenteBD::LimpaTela();
			cout << "Bem-vindo, " << uLogado.GetNome() << endl ;
			
		} else {
			cout << "Senha inválida." << endl;
		}
	} else {
		cout << "Usuario não cadastrado." << endl;
		
		while (true)
		{
			cout << "Cadastrar novo usuario? S/N: ";
			cin >> uResposta;
			if (uResposta == "s" || uResposta == "S") {
				uLogado = gBD.NovoUsuario( uLogin );
				break;
			} else if(uResposta != "n" && uResposta != "N") {
				cout << "Opção inválida." << endl;
			} else{
				break;
			}
			DEBUG_PRINT("r: ("<< uResposta  << ")");
		}
	}
	return true; 
}

void Sistema::NavegaConta() {
	bool stay = true;
	while (stay) {
		//_Cabecalho();
		int opcao;
		cout << "Escolha opcao desejada: " << endl;
		cout << "(1) - Gerenciar Listas" << endl;
		cout << "(2) - Logout" << endl;
		cin >> opcao;
		switch (opcao) {
		case 1:
			DEBUG_PRINT("Opcao " << opcao);
			GerenciarListas();
			break;
		case 2:
			DEBUG_PRINT("Opcao " << opcao);

			stay = false;
			uLogado = Usuario();
			break;
		default:
			cout << "Opcao invalida!" << endl;
			//_OpcaoInvalida();
		}
	}
}
void Sistema::GerenciarListas( ){
	DEBUG_PRINT("Opcao Gerenciar Listas Inicio");
	gBD.CarregaListas(uLogado);
	gBD.MenuListas(uLogado);
	gBD.SalvaListas(uLogado);
	DEBUG_PRINT("Opcao Gerenciar Listas Fim");
}

