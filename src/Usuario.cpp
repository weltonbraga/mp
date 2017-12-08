#include "Usuario.hpp"

Usuario::Usuario() {

}

Usuario::Usuario(string login, string nome) {
	this->nome = nome;
	this->login = login;
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

void Usuario::SetNome(string nome) {
	this->nome = nome;
}

void Usuario::SetLogin(string login) {
	this->login = login;
}

void Usuario::SetSenha(string senha) {
	this->senha = senha;
}