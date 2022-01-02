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
    Node(int V){
      VL = V;
      RE = NULL;
      RD = NULL;	
  }
};

// Método para Inserir os Nós
Node* Insere(Node *Raiz, Node *Ramo){
  if (Raiz == NULL) {return Ramo;}
  if (Raiz->VL > Ramo->VL){
    Raiz->RE = Insere(Raiz->RE, Ramo);  
  } else {
    Raiz->RD = Insere(Raiz->RD, Ramo);
  }
  return Raiz;
}

// Método para Ler a árvore PRE-Order
void PROrder(Node *Raiz){
  if(Raiz){
    cout << Raiz->VL << " ";
    PROrder(Raiz->RE);
    PROrder(Raiz->RD);
  }
}

// Método para Ler a árvore IN-Order
void INOrder(Node *Raiz){
  if(Raiz){
    INOrder(Raiz->RE);
    cout << Raiz->VL << " ";
    INOrder(Raiz->RD);
  }
}

// Método para Ler a árvore POS-Order
void PSOrder(Node *Raiz){
  if(Raiz){
    PSOrder(Raiz->RE);
    PSOrder(Raiz->RD);
    cout << Raiz->VL << " ";
  }
}

// Função principal
int main(){
  // Parâmetros e variáveis
  const int N=5;    // Qtdade de Nós
  int K;    // Variável para valores

  // Criando o nó Raiz
  cout << "Digite o valor da raiz: ";
  cin >> K;
  Node *R = new Node(K);
 
  // Inserindos outros nós
  for (int i=0; i<N; ++i){
    cout << "Digite o valor do nó " << i+1 << ": ";
	cin >> K;
	Node *B = new Node(K);
    R = Insere(R, B);
  }
  
  cout << "\nResultados:" << endl;
  // Apresentando os nós: PRE-Order
  cout << "PRE-Order: ";
  PROrder(R);
  cout << endl;
  // Apresentando os nós: IN-Order
  cout << "IN-Order: ";
  INOrder(R);
  cout << endl;
  // Apresentando os nós: POS-Order
  cout << "POS-Order: ";
  PSOrder(R);
  cout << endl;

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste28.cc -o saida
