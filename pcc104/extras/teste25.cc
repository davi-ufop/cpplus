/********************************************************************/
// Programa para criar uma Arvore Binária, com recursividade
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM DEPRO
/********************************************************************/
// Biblioteca
#include <iostream>

// Prefixo
using namespace std;

// Estrutura de um Nó da árvore
struct Noh {   
  int Valor;        // Valor chave
  struct Noh *RE;   // Ramo à esquerda
  struct Noh *RD;   // Ramo à direita
  // Método interno para construir o respectivo Nó
  Noh(int V){     // Entrada do Valor chave V
    Valor = V;    // Atribuição do valor V
    RE = NULL;    // Definição primária para o ramo à esquerda
    RD = NULL;    // Definição primária para o ramo à direita
  }
};

// Método externo pra Inserir o dado Nó S na árvore com raiz R
Noh* inseRe(Noh *R, Noh *S){       // Entrada
  if (R == NULL){ return S; }      // Conclusão da recursividade
  if (S->Valor < R->Valor){        // Condição: Vai pra esquerda  
    R->RE = inseRe(R->RE, S);      // O RE torna-se Raiz - Recursivo
  } else {                         // Condição: Vai pra direita
    R->RD = inseRe(R->RD, S);      // O RD torna-se Raiz - Recursivo
  }                                
  return R;                        // Quando RE ou RD for NULL: FIM
}                                  // Resultado: caminho desde a Raiz

// PRE-Order
void PreOrder(Noh *RZ){
  if (RZ){
    cout << RZ->Valor << " ";
    PreOrder(RZ->RE);
    PreOrder(RZ->RD);
  }
}

// IN-Order
void InOrder(Noh *RZ){
  if (RZ){
    InOrder(RZ->RE);
    cout << RZ->Valor << " ";
    InOrder(RZ->RD);
  }
}

// POST-Order
void PostOrder(Noh *RZ){
  if (RZ){
    PostOrder(RZ->RE);
    PostOrder(RZ->RD);
    cout << RZ->Valor << " ";
  }
}

// Função Principal
int main(){
  // Parâmetros e Variáveis do processo
  const int N=5;      // Tamanho da árvore - Número de nós
  int W, R;           // Variáveis

  // Definindo o Valor da Raiz
  cout << "\nDigite o valor da Raiz: ";
  cin >> R;   // Valor da Raiz
  struct Noh *Raiz = new Noh(R);  // Comando pra criar a Raiz
                                  // O comando 'new' aloca a RAM  
  // Processo de inserção dos Ramos                   
  // Dica: Digite 3 Maiores e 2 Menores que a Raiz -> Resultado L55
  for (int i=0; i<N; ++i){  // Siga a dica, evite erro de segmentação
    cout << "Digite o valor do Ramo " << i+1 << ": ";
    cin >> W;   // Valor o i-ésimo Ramo
    struct Noh *Ramo = new Noh(W);  // Comando pra criar o Ramo
    Raiz = inseRe(Raiz, Ramo);      // Processo recursivo pra definir  
  }                                 // o caminho do i-ésimo Ramo

  // PRE ORDER
  cout << "\n\tPreOrder\n";
  PreOrder(Raiz);
  cout << endl;

  // IN ORDER
  cout << "\n\tInOrder\n";
  InOrder(Raiz);
  cout << endl;

  // POST ORDER
  cout << "\n\tPostOrder\n";
  PostOrder(Raiz);
  cout << endl;

  return 0;
}
/********************************************************************/
// FIM - Para compilar digite: g++ teste23.cc -o saida
