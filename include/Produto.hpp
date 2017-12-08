#ifndef __PRODUTO_HPP__
#define __PRODUTO_HPP__

#include <string>

using std::string;

/**
	\brief Classe que instancia um item.
	
	Especifica quais métodos um produto deve ter para conseguir ser manipulado corretamente pelo sistema.
*/

class Produto{
     public:
          /**
			\brief Construtor
               \param codBarras Chave primária do produto.
               \param nome Nome do produto.
               \param preco Preco médio do produto.
               \param marca Marca do produto.
               \param qtd Parâmetro opcional. Quantidade desse produto na lista, por padrão é 0.

			Inicializa as variáveis protegidas.
		*/
          Produto(int codBarras, string nome, float preco, string marca, int qtd = 0);
          /**
			\brief Destrutor

               Destrutor padrão.
          */
          ~Produto();
          /** brief Obtém o número do código de barras
           * \return int Inteiro correspondente ao número do código de barras
           * 
           * Retorna o número do código de barras
          */
          int GetCodBarras(void) const;
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
          /** brief Obtém o preço do produto
           * \return float Número correspondente ao preço
           * 
           * Retorna o número decimal correspondente ao preço do produto
          */
          float GetPreco(void) const;
          /** brief Redefine o preço do produto
           * \param float Número correspondente ao novo preço
           * 
           * Redefine o número decimal recebido como sendo o novo preço do produto
          */
          void SetPreco(float novoPreco);
          /** brief Obtém a marca do produto
           * \return string String contendo a marca do produto
           * 
           * Retorna uma string contendo a marca do produto
          */
          string GetMarca(void) const;
          /** brief Redefine a marca do produto
           * \param string String correspondente à nova marca
           * 
           * Redefine a marca recebida como sendo a nova marca do produto
          */
          void SetMarca(string novaMarca);

          int quantidade;/**< Quantidade do produto na lista*/

     private:
          int codBarras;/**< Chave primária do produto. Número referente ao código de barras*/
          string nome;/**< Nome do produto*/
          float preco;/**< Preço médio do produto*/
          string marca;/**< Marca do produto*/

};

#endif //__PRODUTO_HPP__

