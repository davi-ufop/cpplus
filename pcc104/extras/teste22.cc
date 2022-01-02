/********************************************************************/
// Programa para criar uma lista encadeada por recursividade
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM DEPRO
/********************************************************************/
// Bibliotecas
#include <iostream>
#include <cstdlib>

// Prefixo
using namespace std;

// Parâmetro Global - Limite dos valores das chaves: [0..K]
const int L=80;

// Criando a estrutura para os elementos da lista
struct Elemento{
  int chave;          // Chave
  Elemento *ponte;    // Ponteiro pra apontar o próximo elemento
};

// Método para inserir Elementos na lista
void inserEs(Elemento *F, int c){
  if (F->chave != L){
   Elemento *NF;       // Elemento PONTE     
   F->chave = c++;     // Chave SIMPLES
   NF = F+1;           // Elemento posterior
   F->ponte = NF;      // Ponteiro apontando para o próximo
   F++;                // Passando para o próximo elemento
   inserEs(F, c);      // Recursividade
  }
}

// Método para mostrar os elementos
void showEs(Elemento *F, int c){
  if (F->chave != L){  // Apresentando os Elementos:
    cout << "\nElemento " << c << ":\n";
    cout << "Chave de E[" << c << "] = " << F->chave << endl;
    cout << "Ponte de E[" << c << "] = " << F->ponte << endl;
	F++;    // Próximo Elemento
    c++;    // Contagem respectiva
	showEs(F, c);
  }
}

// Busca por um elemento chave - K
int buscaEk(Elemento *F, int k){
  int c=1;   // Contador - Indica o Elemento K
  while (F->chave != k){   // Condição de encontro 
    F++;   // Próximo Elemento
    c++;   // Contando
  }
  return c;
}

// Função Principal
int main(){
  // Parâmetros e variáveis
  int N, K;

  // Elementos necessários:
  Elemento *E;

  // Entrada de dados - Tamanho da Lista
  cout << "Digite o tamanho da instância: ";
  cin >> N;

  // Alocamento de memória:
  E = (struct Elemento *)malloc(N*sizeof(*E));

  // Ajustando a calda da Lista - Limite dos processos recursivos 
  E += N;         // Translado até o N-ésimo Elemento
  E->chave = L;   // Atribuição da chave de controle
  E -= N;         // Translado ao Elemento inicial - HEAD
  
  // Processo de inserção recursivo
  inserEs(E, 1);

  // Processo de apresentação recursivo
  showEs(E, 1);

  // Buscando o elemento K
  cout << "\nDigite o valor de uma chave: ";
  cin >> K;
  int I = buscaEk(E, K);   // Método de busca
  // Resultado:
  cout << "Esta chave está no " << I << "° Elemento!" << endl; 

  return 0;
}
/********************************************************************/
// FIM - Para compilar digite: g++ teste22.cc -o saida
