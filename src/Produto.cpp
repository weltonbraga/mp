#include "Produto.hpp"

Produto::Produto(int codBarras, string nome, float preco, string marca, int qtd)
          : quantidade(qtd)
          , codBarras(codBarras)
          , nome(nome)
          , preco(preco)
          , marca(marca) {

}

Produto::~Produto(){

}

int Produto::GetCodBarras(void) const{
     return codBarras;
}

string Produto::GetNome(void) const{
     return nome;
}

void Produto::SetNome(string novoNome){
     nome = novoNome;
}

float Produto::GetPreco(void) const{
     return preco;
}

void Produto::SetPreco(float novoPreco){
     preco = novoPreco;
}

string Produto::GetMarca(void) const{
     return marca;
}

void Produto::SetMarca(string novaMarca){
     marca = novaMarca;
}

