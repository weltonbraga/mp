#include "Produto.hpp"

Produto::Produto(int _codBarras, string _nome, float _preco, string _marca, int _qtd)
          : quantidade(_qtd)
          , codBarras(_codBarras)
          , nome(_nome)
          , preco(_preco)
          , marca(_marca) {

}

Produto::~Produto(){

}

int Produto::GetCodBarras(void) const{
     return codBarras;
}

string Produto::GetNome(void) const{
     return nome;
}

void Produto::SetNome(string _nome){
     nome = _nome;
}

float Produto::GetPreco(void) const{
     return preco;
}

void Produto::SetPreco(float _preco){
     preco = _preco;
}

string Produto::GetMarca(void) const{
     return marca;
}

void Produto::SetMarca(string _marca){
     marca = _marca;
}

