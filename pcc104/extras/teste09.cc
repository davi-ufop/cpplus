/********************************************************************/
// Programa que demonstra como podemos usar uma função ponteiro
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO - DECOM 
/********************************************************************/
// Biblioteca
#include <iostream>
#include <ctime>

// Prefixos
using namespace std;

// Variável global - Ordem da matriz
const int N=4;

// Método para apresentar a matriz M
void showM( int M[N][N] ){
  for (int i=0; i<N; ++i){        // Varredura em colunas
    cout << "| ";
    for (int j=0; j<N; ++j){      // Varredura em linhas
      cout << M[i][j] << " ";     // Cada elemento de M
    }
    cout << "|" << endl;
  }
}

// Método que vai associar a matriz M ao ponteiro P(->Q)
int * pontQM(int M[N][N] ){     
  // Mostrando a matriz para podermos conferir o resultado
  cout << "\nMatriz M:" << endl;
  showM( M );
  // Ponteiro que vai apontar para o primeiro elemento de M
  int *P;
  // Basta apontar o ponteiro para o primeiro elemento de M
  P = &M[0][0];   // Na RAM: P -> M[0][0] .. P+N -> M[1][0]
  return P;       // P+1 -> M[0][1] .. P+N+1 -> M[1][1] 
}                 // Entendeu? Então pronto! 

// Método para apresentar os vetores colunas
void showColumns(int* Q){  
  // Parâmetro de controle
  int *C;
  // Controle
  C = Q;  // Para auxiliar a varredura sobre as linhas
  for (int j=0; j<N; ++j){    // Varredura de Colunas
    cout << "( ";
    for (int i=0; i<N; ++i){  // Varredura de Linhas
      cout << *Q << " "; // Imprimindo o dado apontado por Q
      Q += N;   // Próxima linha, Mesma coluna
    }
    cout << ") -> C" << j+1 << endl;  // Fim da coluna i+1
	Q = C+j;  // Voltando pra 1ª linha na j-ésima coluna
	Q++;      // Ou seja, nesta etapa Q = Q+1
  }
}

// Função Principal
int main(){
  // Semente randômica
  srand(time(0));
  
  // Matriz M que deve ser contsruída
  int M[N][N];
  // Construindo a matriz M:
  for (int i=0; i<N; ++i)     // Colunas
    for (int j=0; j<N; ++j)   // Linhas
      M[i][j] = rand()%10;    // Elementos: [0,9]

  // Ponteiro que apontará para matriz
  int *Q;

  // Decompondo: M -> Q
  Q = pontQM( M ); 

  // Resultado Parcial
  cout << "\nResultado Parcial:\n";
  cout << "M[0][0] = " << *Q << endl; 
  cout << "&M[0][0] = " << Q << endl;

  // Resultado Completo
  cout << "\nResultado Completo:\n";
  showColumns( Q ); 

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste09.cc -o saida
