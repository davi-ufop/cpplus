/********************************************************************/
// Programa pra imprimir 1/2 pirâmide com letras. Matriz triangular!
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

  // Letras
  char Ma[] = "ABCDEFGHIJKLMNOP";  // Maiúsculas para linhas
  char Mi[] = "abcdefghijklmnop";  // Minúsculas para colunas

  // Entrada -> Instância
  cout << "Digite a ordem da matriz ( < 26 ): ";
  cin >> N;

  cout << "\nMatriz AaBb:\n";
  // Construindo a matriz
  int i=0;   // Índice da linha
  while (i < N) {    // Limitando o número de linhas < N
    ++i;  // Índice da próxima linha
    cout << "| ";     // Frescura
    for (int j=0; j<i; ++j){  // Colunas
      cout << Ma[i-1] << Mi[j] << " ";   // Letras dos elementos
    }
    cout << endl;    // Próxima linha
  }

  cout << "\nMatriz ABC:\n";
  // Outra matriz -> Copia de StudyTonight
  int p=0;
  while (p < N) { // Limite de linhas
    char c = 'A';
    ++p;  // Índice da próxima linha
    cout << "|";  // Frescura
    for (int q=0; q<p; ++q){ // Colunas
      cout << c << " ";  // Letra respectiva à coluna
      c++;  // NOTE QUE PODEMOS ACRESCER LETRAS TAMBÉM!!! 
    }
    cout << endl;  // Próxima linha
  }

  return 0;
}
// FIM - Pra compilar, vide prog01.cc
