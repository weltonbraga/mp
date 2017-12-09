#include "Usuario.hpp"

Usuario::Usuario() {

}

Usuario::Usuario(string login, string nome) {
	this->nome = nome;
	this->login = login;
	listaAberta = nullptr;
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
	return *listaAberta;
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
	Lista* lista = new Lista(_nome);
	AbrirLista(lista);
}

void Usuario::SalvarLista(Lista* lista){
	listas.push_back(lista);
}

void Usuario::AbrirLista(Lista* lista){
	listaAberta = lista;
}

