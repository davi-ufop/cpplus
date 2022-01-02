/********************************************************************/
// Programa para testar a biblioteca de dados não sequenciais
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM
/********************************************************************/
// Importando a biblioteca de dados não sequenciais
#include "bdnsql.hpp"

// Programa principal
int main(){
  // Mensagem inicial
  cout << "\tPrograma executado:\n" << endl;
  
  // Lista para as chaves
  int LC[8] = {4, 2, 1, 3, 7, 5, 6, 8};

  // Nós da árvore
  NodeTree N1, N2, N3, N4, N5, N6, N7, N8;

  // Lista das variáveis
  list<NodeTree> LN = {N1, N2, N3, N4, N5, N6, N7, N8};
  list<NodeTree>::iterator ik, ij;
 
  // Adicionando as chaves
  int k=0;
  for (ik = LN.begin(); ik != LN.end(); ++ik){
    NodeTree& noh = *ik;
    noh.chave = LC[k];
	k++;
  }

  NodeTree N9;
  N9.chave = 9;
  LN.push_back(N9);

  // Conferindo a operação anterior
  int j=1;
  for (ij = LN.begin(); ij != LN.end(); ++ij){
    cout << "N" << j << " chave = " << ij->chave << endl;
    j++;
  }

  cout << "\n\nN1.chave = " << N1.chave << endl;
  cout << "N9.chave = " << N9.chave << endl;

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste04.cc -o saida
