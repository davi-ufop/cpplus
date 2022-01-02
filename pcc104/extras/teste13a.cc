/********************************************************************/
// Analisando o uso de STRUCT pra construir uma lista encadeada
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO - DECOM 
/********************************************************************/
// Biblioteca
#include <iostream>

// Prefixos
using namespace std;

// Definindo o objeto: Elemento(chave, endereço do próximo elemento)
struct Elemento{
  int chave;                 // Valor chave
  struct Elemento *prox;     // Endereço hexadecimal na RAM
};

// Função principal
int main(){
  //Tamanho da lista
  int N=4;  
  
  // Definindo um novo tipo de dado, baseado em struct
  typedef struct Elemento cell;  // cell é um novo tipo de dado
  
  // Definindo um arranjo de células:
  cell A[N];

  // Inserindo as chaves dos elementos da lista
  for (int i=0; i<N; ++i){
    cout << "Digite a " << i+1 << "ª chave: "; 
	cin >> A[i].chave;    // Atribuição do valor chave
  }

  // Inserindo o endereço do próximo elemento
  int N1 = N-1;
  A[N1].prox = &A[0];       // Condição circular 
  for (int i=0; i<N1; ++i){ // Varredura pela lista
    A[i].prox = &A[i+1];    // Atribuição proposta
  }

  // Testando com o Elemento teste: T
  cell *T;
  // Escolha o elemento
  int k;
  cout << "Qual elemento você deseja visitar: "; 
  cin >> k;
  k--;  // Correção para a forma que será apresentado
  // Associando elementos
  T = &A[k];

  // Resultado:
  cout << "\nResultado:\n";
  cout << "Chave do " << k+1 << "º elemento = " << T->chave << endl;
  cout << "Posição do " << k+1 << "º elemento = " << &A[k] << endl;
  cout << "Posição do " << k+2 << "º elemento = " << T->prox << endl;
  cout << "Posição do " << k+2 << "º elemento = " << &A[k+1] << endl;

  // Loop Condição Circular
  cout << "\nCircular:\n" << endl;
  for (int j=0; j<N; ++j){
    cout << j+1 << "º elemento: Posição = " << &A[j] << endl;
	cout << "Posição do próximo = " << A[j].prox << endl;
	cout << endl; // Salto estético
  }

  return 0;
}
/********************************************************************/
// DIGITE: diff teste11.cc teste13A.cc
/********************************************************************/
// FIM - Para compilar: g++ teste13A.cc -o saida
