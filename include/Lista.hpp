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
          /**
			\brief Construtor
               \param nome Parâmetro opcional. Nome do produto.

			Inicializa as variáveis protegidas.
		*/
          Lista(string nome = "(lista sem nome)");
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
          void AdicionarProduto(Produto);
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
          void SetNome(string novoNome);
          std::vector<Produto> produtos;

     private:
          string nome;
};

#endif // __LISTA_HPP__

