/********************************************************************/
// Inserindo elemento K em uma lista encadeada ordenada - ARRAY
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO - DECOM 
/********************************************************************/
// Biblioteca
#include <iostream>
#include <cmath>

// Prefixos
using namespace std;

//Tamanho da lista
const int N=7;  

// Definindo o objeto: Elemento(chave, endereço do próximo elemento)
class Elemento{
  public:
    int chave;          // Valor chave
    Elemento *prox;     // Endereço hexadecimal na RAM
};

// Função principal
int main(){
  // Definindo um arranjo de elementos:
  Elemento A[N+1];

  // Inserindo as chaves dos elementos da lista
  for (int i=0; i<N; ++i){
	A[i].chave = pow(2, i);  // Atribuição da chave: n^i
  }

  // Inserindo o endereço do próximo elemento
  int N1 = N-1;
  A[N1].prox = &(A[0]);       // Condição circular 
  for (int i=0; i<N1; ++i){   // Varredura pela lista
    A[i].prox = &(A[i+1]);    // Atribuição proposta
  }

  // Loop Condição Circular: E1->E2->E3->E4...EN->E1
  cout << "\n\tLista Original:\n" << endl;
  for (int j=0; j<N; ++j){ // N elementos 
	cout << j+1 << "º elemento: Chave = " << A[j].chave << endl;
    cout << j+1 << "º elemento: Posição = " << &A[j] << endl;
	cout << "A posição do próximo = " << A[j].prox << endl;
	cout << endl; // Salto estético
  }

  // Definindo o elemento K
  int k;
  cout << "Digite a chave de K: ";
  cin >> k; 

  // Buscando a posição de K
  int p = 0;
  while (A[p].chave < k){ p++; }
  cout << "A posição de inserção = " << p+1 << endl;

  // Inserindo o elemento com a chave k
  int NK = N;
  for (int j=NK; j>=p; --j){ A[j+1].chave = A[j].chave; }
  A[p].chave = k;
  
  // Loop Condição Circular: E1->E2->E3->E4...EN->E1
  cout << "\n\tLista Ampliada:\n" << endl;
  for (int j=0; j<=N; ++j){ // N elementos 
	cout << j+1 << "º elemento: Chave = " << A[j].chave << endl;
    cout << j+1 << "º elemento: Posição = " << &A[j] << endl;
	cout << "A posição do próximo = " << A[j].prox << endl;
	cout << endl; // Salto estético
  }

  cout << "\nFIM\n\n"; 
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste16.cc -o saida
