#include "Usuario.hpp"
//#define DEBUG
#ifdef DEBUG
	#define DEBUG_PRINT(x) do{cout << x << endl;}while(0)
#else
	#define DEBUG_PRINT(x) 
#endif

Usuario::Usuario() {

}
//(string _nome) : nome (_nome) {
Usuario::Usuario(string login, string nome) {
	this->nome = nome;
	this->login = login;
	//listaAberta = Lista();
}

Usuario::Usuario(const Usuario &usuario) {
	this->nome = usuario.nome;
	this->login = usuario.login;
}

string Usuario::GetNome() {
	return nome;
}

string Usuario::GetLogin() {
	return login;
}

string Usuario::GetSenha() {
	return senha;
}

Lista& Usuario::GetListaAberta(){
	return listaAberta;
}

void Usuario::SetNome(string nome) {
	this->nome = nome;
}

void Usuario::SetLogin(string login) {
	this->login = login;
}

void Usuario::SetSenha(string senha) {
	this->senha = senha;
}

void Usuario::CriarLista(string _nome){
	Lista lista(_nome);
	listas.push_back(lista);
	listaAberta=listas.back();
}

void Usuario::SalvarLista(Lista& lista){
	DEBUG_PRINT("		SalvarLista:"<< lista.GetNome());
	listas.push_back(lista);
	DEBUG_PRINT("		SalvarLista FIM");
}

void Usuario::AbrirLista(unsigned int n){
	listaAberta = listas[n];
	listas.erase(listas.begin()+n);
}

