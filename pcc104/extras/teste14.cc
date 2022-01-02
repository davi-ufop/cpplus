/********************************************************************/
// Programa que realiza uma busca em uma lista encadeada
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO - DECOM 
/********************************************************************/
// Biblioteca
#include <iostream>
#include <ctime>

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
  cout << "\nCircular:\n" << endl;
  for (int j=0; j<N; ++j){ // N elementos 
    cout << j+1 << "º elemento: Chave = " << A[j].chave << endl;
    cout << j+1 << "º elemento: Posição = " << &A[j] << endl;
	cout << "A posição do próximo = " << A[j].prox << endl;
	cout << endl; // Salto estético
  }

  // Busca pelo elemento K:
  int k, i=0;
  Elemento *K, EK;
  cout << "Digite o valor da chave: ";
  cin >> k;
  while (A[i].chave != k){ ++i; }
  K = &(A[i]);
  EK = A[i];

  // Resultado:
  cout << "\nResultado:\n";
  cout << "Chave do elemento K = " << K->chave << endl;
  cout << "A[" << i+1 << "].chave = " << A[i].chave << endl;
  cout << "Posição do elemento K+1 = " << K->prox << endl;
  cout << "A[" << i+1 << "].prox = " << A[i].prox << endl;

  // Brincando:
  cout << "\nBrincando:\n";
  cout << "K->prox->chave = " << K->prox->chave;
  cout << "\nK->prox->prox->chave = " << K->prox->prox->chave;

  // Testando
  cout << "\nTestando:\n";
  cout << "EK.prox.chave = " << (*EK.prox).chave;
  cout << "\nEK.prox.prox.chave = " << (*(*EK.prox).prox).chave;


  cout << "\nFIM\n\n"; 
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste14.cc -o saida
