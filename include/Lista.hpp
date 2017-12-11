#ifndef __LISTA_HPP__
#define __LISTA_HPP__

#include "Produto.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
	\brief Classe que instancia uma lista de compras vazia.
	
	Especifica quais métodos a lista deve ter para conseguir ser manipulada corretamente pelo usuário.
*/

class Lista{
     public:
          Lista();
          /**
			\brief Construtor
               \param nome Parâmetro opcional. Nome do produto.

			Inicializa as variáveis protegidas.
		*/
          Lista(string _nome);

          /**
			\brief Destrutor

               Destrutor padrão.
          */
          ~Lista();

          /** brief Adiciona um produto
           * \param Produto Produto a ser acrescentado à lista
           * 
           * Adiciona um produto à lista de compras
          */
          void AdicionarProduto(Produto&);

          /** brief Exclui um produto
           * \param int Código de barras do produto a ser excluído da lista
           * 
           * Exclui um produto da lista de compras
          */
          void ExcluirProduto(int);

          /** brief Obtém o nome do produto
           * \return string String contendo o nome do produto
           * 
           * Retorna uma string contendo o nome do produto
          */
          string GetNome(void) const;

          /** brief Redefine o nome do produto
           * \param string String correspondente ao novo nome
           * 
           * Redefine o nome recebido como sendo o novo nome do produto
          */
          void SetNome(string _nome);

          /** brief Verifica existência do produto na lista
           * \param int Código de barras do produto
           * \return bool True se existir, false caso contrário.
           * 
           * Verifica a existência de um produto, pelo código de barras, nesta lista.
          */
          bool ExisteProduto(int cod);

          /** brief Lista todos os produtos
           * 
           * Exibe os produtos desta lista
          */
          void MostrarTodos() const;
          int RetornaIdProduto(int cod);
          std::vector<Produto> produtos;/**< Vetor de produtos cadastrados nesta lista*/

     private:
          string nome;
};

#endif // __LISTA_HPP__

