#ifndef __USUARIO__
#define __USUARIO__

#include <iostream>
#include <string>

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

public:
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

};

#endif // !__USUARIO__
