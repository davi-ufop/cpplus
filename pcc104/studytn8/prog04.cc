/********************************************************************/
// Programa para imprimir uma matriz triangular reversa com números
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO & DECOM
/********************************************************************/
// Bibliotecas
#include <iostream>   // Biblioteca para realizar in e out

// Prefixos
using namespace std;

// Função principal
int main(){
  // Ordem da matriz
  int N;

  // Entrada de dados
  cout << "Digite a ordem da matriz: ";
  cin >> N;

  // Matriz triangular reversa à do prog02.cc
  cout << "\nMatriz reversa:\n";
  int i=0, n=1;    // Condição inicial
  while ( i<N ){   // Limite para as linhas 
    ++i; // Próxima linha	
	cout << "| ";  // Frescura
    for (int j=0; j<=N-i; ++j){ // Varrendo colunas
      cout << n << " ";  // Número dos elementos
	  n++;  // Valor do próximo elemento
    }
    cout << endl;  // Próxima linha
  }

  return 0;
}
// FIM - Pra compilar, vide prog01.cc
