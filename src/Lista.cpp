#include "Lista.hpp"


Lista::Lista() {

}

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
     produtos.push_back(prod);
}

void Lista::ExcluirProduto(int cod){
     for(unsigned int i = 0; i < produtos.size(); i++){
          if(cod == produtos[i].GetCodBarras()){
               string nome = produtos[i].GetNome();
               produtos.erase(produtos.begin() + i);
               cout << "Produto " << nome << "(" << cod << ") excluido com sucesso!\n" << endl;
               break;
          }
     }
     //cout << "Produto nao encontrado!" << endl;
}

bool Lista::ExisteProduto(int cod){
     bool existe = false;
     for(unsigned int i = 0; i <= produtos.size() || existe; i++){
          for(unsigned int j = 0; j < produtos.size() || existe; j++){
               if((int) cod == produtos[j].GetCodBarras()){
                    existe = true;
                    return existe;
               }
          }
     }
     return existe;
}

int Lista::RetornaIdProduto(int cod){
     bool existe = false;
     for(unsigned int i = 0; i <= produtos.size() || existe; i++){
          for(unsigned int j = 0; j < produtos.size() || existe; j++){
               if((int) cod == produtos[j].GetCodBarras()){
                    existe = true;
                    return j;
               }
          }
     }
     //return existe;
}

void Lista::MostrarTodos() const{
     cout << "(Id)-- Cod Barras - Nome - Preço - Marca - Quantidade" << endl;
     for(unsigned int i = 0; i < produtos.size(); i++){
          cout << "(" << i << "): " << produtos[i].GetCodBarras();
          cout << " - " << produtos[i].GetNome();
          cout << " - " << produtos[i].GetPreco();
          cout << " - " << produtos[i].GetMarca();
          cout << " - " << produtos[i].quantidade << endl;
     }
}

