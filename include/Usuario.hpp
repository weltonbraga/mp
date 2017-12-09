#ifndef __USUARIO__
#define __USUARIO__

#include <iostream>
#include <string>
#include <vector>
#include "Lista.hpp"

using std::string; 

/*!
*	\brief Representa a instância do usuario que utiliza o sistema.
*	
*	Contém as informações do usuário.
*/
class Usuario {
private:
	/*!
	*	\brief Nome do usuário.
	*/
	string nome;

	/*!
	*	Login do usuário.
	*/
	string login;
	/*!
	*	\brief Senha do usuário.
	*/
	string senha;
	Lista* listaAberta;/**< Lista que está sendo manipulada pelo usuário*/

public:
	std::vector<Lista*> listas;/**< Vetor de listas salvas pelo usuário.*/

	
	/*!
	*	\brief Construtor padrão
	*/
	Usuario();
	
	/*!
	*	\brief Construtor alternativo.
	*	\param nome Nome do usuario.
	*	\param login Login do usuario
	*/
	Usuario(string login, string nome);

	/*!
	*	\brief Construtor de cópia.
	*	\param usuario Usuário a ser copiado.
	*/
	Usuario(const Usuario &user);

	/*!
	*	\brief Getter do atributo nome.
	*/
	string GetNome();
	
	/*!
	*	\brief Getter do atributo login.
	*/
	string GetLogin();

	/*!
	*	\brief Getter do atributo senha.
	*/
	string GetSenha();

	/*!
	*	\brief Getter do atributo listaAberta.
	*/
	Lista& GetListaAberta();

	/*!
	*	\brief Setter do atributo nome.
	*	\param nome Nome designado para instancia.
	*/
	void SetNome(string nome);

	/*!
	*	\brief Setter do atributo login.
	*	\param login Login designada para instância.
	*/
	void SetLogin(string login);

	/*!
	*	\brief Setter do atributo senha.
	*	\param senha Senha designada para instância.
	*/
	void SetSenha(string senha);

	/**
		\brief Registra a lista de compras
		\param Ponteiro para a lista a ser salva

		Salva uma lista de compras existente no vetor de listas.
	*/
	void SalvarLista(Lista*);

	/**
		\brief Abre uma lista de compras
		\param Ponteiro para a lista a ser aberta

		Abre uma lista de compras existente do vetor de listas.
	*/
	void AbrirLista(Lista*);

	/**
		\brief Cria uma nova lista de compras
		\param nome Parâmetro opcional. Nome da lista.

		Cria uma lista de compras e a acrescenta ao vetor de listas.
	*/
	void CriarLista(string _nome = "(lista sem nome)");
};

#endif // !__USUARIO__
