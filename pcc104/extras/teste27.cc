/********************************************************************/
// Programa para construir uma árvore simples com Classe em C++
// Davi C. Neves - UFOP, DEPRO, DECOM - Novembro de XXI
/********************************************************************/
// Bibliotecas
#include <iostream>

// Prefixo STD
using namespace std;

// Classe para os Nós
class Node {
  public:
    int VL;     // Valor do Nó
    Node *RE;   // Ramificação Esquerda
	Node *RD;   // Ramificação Direita
	// Construtor
    Node(int N){
      VL = N;
      RE = NULL;
      RD = NULL;	
  }
};

// Função principal
int main(){
  // Criando o nó Raiz
  Node R = Node(4);
 
  // Inserindos outros nós
  Node Ramo1 = Node(3);   // Nó 1
  R.RE = &Ramo1;
  Node Ramo2 = Node(2);   // Nó 2
  (*R.RE).RE = &Ramo2;
  Node Ramo3 = Node(6);   // Nó 3
  R.RD = &Ramo3;
  Node Ramo4 = Node(5);   // Nó 4
  (*R.RD).RE = &Ramo4;
  Node Ramo5 = Node(7);   // Nó 5
  (*R.RD).RD = &Ramo5;
  
  // Buscando os nós: IN-Order
  cout << (*(*R.RE).RE).VL << endl;
  cout << (*R.RE).VL << endl;
  cout << R.VL << endl;
  cout << (*(*R.RD).RE).VL << endl;
  cout << (*R.RD).VL << endl;
  cout << (*(*R.RD).RD).VL << endl;

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste27.cc -o saida
