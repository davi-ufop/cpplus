/********************************************************************/
// Programa para demonstrar como criar uma lista encadeada SIMPLES
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM DEPRO
/********************************************************************/
// Bibliotecas
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Criando a estrutura para os elementos da lista
struct Elemento{
  int chave;          // Chave
  Elemento *ponte;    // Ponteiro pra apontar o próximo elemento
};

// Função principal
int main(){
  // Tamanho da lista
  const int N = 7;

  // Elemento de Busca
  int K = 5;   // Variável

  // Definindo as entidades
  Elemento *E, *NE, *B;

  // Alocando a memória RAM
  E = (struct Elemento *)malloc(N*sizeof(*E));

  // Construindo sete Elementos:
  // Definindo o Elemento E1
  E->chave = 1;   // Chave de E1
  NE = E+1;       // Apontando pra E2
  E->ponte = NE;  // Atribuição respectiva
  // Iteração para criar os demais
  for (int i=1; i<N; ++i){
    E++;               // Passando pra E2 ... E7
	E->chave = i+1;    // Chave de E2 ... E7 -> [2..7]
	NE = E+1;          // Apontando pra E3 ... E8?
	E->ponte = NE;     // Atribuição respectiva
  }
  // Condição cíclica, ou seja, fazendo E7->E1 e não E8!
  NE = E-N;        // Apontando pra E1!
  E->ponte = NE;   // Atribuição

  // Conferindo o resultado: Chaves = 7,6,5,4,3,2,1
  for (int i=N; i>0; --i){
    cout << "Chave de E[" << i << "] = " << E->chave;
	cout << " -> E[" << i+1 << "] = " << E->ponte << endl;
    E--;
  }	

  // Fazendo a busca da posição do elemento 5
  cout << "\nBusca pelo 5° elemento: CAPITÃO PLANETA!\n";
  K=K-1;  // E4 que aponta pra E5!
  for (int i=0; i<K; ++i){ E++; }  // Viajando até E4
  cout << "E->chave = " << E->chave << endl;    // E4.chave 
  cout << "Posição de E[5] = " << E->ponte << endl; // Pronto!

  return 0;
}
/********************************************************************/
// FIM - Para compilar digite: g++ teste20.cc -o saida
