/********************************************************************/
// Programa pra imprimir meia pirâmide com N°s. Matriz triangular!
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO & DECOM
/********************************************************************/
// Bibliotecas
#include <iostream>   // Biblioteca para realizar in e out

// Prefixos
using namespace std;

// Função principal
int main(){
  // Parâmetros
  int N; // Ordem da matriz

  // Entrada -> Instância
  cout << "Digite a ordem da matriz: ";
  cin >> N;

  // Construindo a matriz
  int i=0;   // Índice da linha
  while (i < N) {    // Limitando o número de linhas < N
    ++i;  // Índice da próxima linha
    cout << "| ";     // Frescura
    for (int j=0; j<i; ++j){
      cout << i << j+1 << " ";   // Número dos elementos
    }
    cout << endl;    // Próxima linha
  }

  return 0;
}
/********************************************************************/
// É interessante observar que a complexidade é de N(N+1)/2
// Portanto se você escolher N=4 a matriz terá 10 elementos
// Da mesma forma, para N=6 haverá 21 operações de impressão
/********************************************************************/
// FIM - Pra compilar, vide prog01.cc
