/********************************************************************/
// Ordenando uma lista encadeada ... com Bubble Sort
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO - DECOM 
/********************************************************************/
// Biblioteca
#include <iostream>
#include <ctime>

// Prefixos
using namespace std;

//Tamanho da lista
const int N=5;  

// Definindo o objeto: Elemento(chave, endereço do próximo elemento)
class Elemento{
  public:
    int chave;          // Valor chave
    Elemento *prox;     // Endereço hexadecimal na RAM
};

// Função principal
int main(){
  // Semente randômica
  srand(time(0));

  // Definindo um arranjo de elementos:
  Elemento A[N];

  // Inserindo as chaves dos elementos da lista
  for (int i=0; i<N; ++i){
	A[i].chave = rand()%100;  // Atribuição do valor chave: [0-99]
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

  // Ordenando a lista encadeada -> bubble sort:
  for (int i=0; i<N; ++i)
    for (int j=N-1; i<j; --j)
      if (A[j].chave < A[j-1].chave){ 
        A[j].chave = A[j].chave + A[j-1].chave;
        A[j-1].chave = A[j].chave - A[j-1].chave;	
        A[j].chave = A[j].chave - A[j-1].chave;	
	  }

  // Loop Condição Circular: E1->E2->E3->E4...EN->E1
  cout << "\n\tLista Ordenada:\n" << endl;
  for (int j=0; j<N; ++j){ // N elementos 
	cout << j+1 << "º elemento: Chave = " << A[j].chave << endl;
    cout << j+1 << "º elemento: Posição = " << &A[j] << endl;
	cout << "A posição do próximo = " << A[j].prox << endl;
	cout << endl; // Salto estético
  }
  
  cout << "\nFIM\n\n"; 
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste15.cc -o saida
