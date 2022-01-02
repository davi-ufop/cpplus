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
  
  // Nós da árvore
  NodeTree N1, N2, N3, N4, N5, N6, N7, N8, N9;
  
  // Vetor para as chaves dos nós
  vector<int> VC = {4, 2, 1, 3, 7, 5, 6, 8};

  // Arranjo para identificar os nós
  char VI[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
  
  // Vetor para os nós -> variáveis
  vector<NodeTree> VN = {N1, N2, N3, N4, N5, N6, N7, N8};
 
  // Definindo identidades e chaves dos nós
  VN = chavesIDs(VI, VC, VN);

  // Conferindo o resultado
  showKIDs(VN);

  // Inserindo os nós na árvore
  VN = insereNos(VN, VC);

  // Folhas à direita:
  cout << "Folhas à direita: { ";
  while ( !VN[0].folhasD.empty() ){
    cout <<  VN[0].folhasD.front() << " ";
    VN[0].folhasD.pop_front();
  }
  cout << "}\n";
  
  // Folhas à esquerda:
  cout << "Folhas à esquerda: { ";
  while ( !VN[0].folhasE.empty() ){
    cout <<  VN[0].folhasE.front() << " ";
    VN[0].folhasE.pop_front();
  }
  cout << "}\n";

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste05.cc -o saida
