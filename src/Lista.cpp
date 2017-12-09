#include "Lista.hpp"

Lista::Lista(string _nome) : nome (_nome) {

}

Lista::~Lista(){

}

string Lista::GetNome(void) const{
     return nome;
}

void Lista::SetNome(string _nome){
     nome = _nome;
}

void Lista::AdicionarProduto(Produto& prod){
     produtos.push_back(&prod);
}

void Lista::ExcluirProduto(int cod){
     for(unsigned int i = 0; i < produtos.size(); i++){
          if(cod == produtos[i]->GetCodBarras()){
               string nome = produtos[i]->GetNome();
               produtos.erase(produtos.begin() + i);
               cout << "Produto " << nome << "(" << cod << ") excluido com sucesso" << endl;
               break;
          }
     }
     cout << "Produto nao encontrado!" << endl;
}

