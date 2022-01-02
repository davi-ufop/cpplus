// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema da mochila com programação dinâmica e função memória
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Nov./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <cstdlib>     // Biblioteca padrão de C++ -> STRINGS
#include <vector>      // Vector pra armazenar dados
#include <ctime>       // Tempo para semente randômica

// Prefixos -> Namespaces
using namespace std;

// Variável Global - Contador de operações
int C = 0;

// Parâmetros Globais - Dados de Entrada 
vector<int> W = {2, 1, 3, 2};        // Pesos dos produtos
vector<int> V = {12, 10, 20, 15};    // Valores dos produtos

// Método pra apresentar os elementos do vetor X
void showVec(vector<int> X, string NomeX, int n){
  cout << NomeX << " = (";
	for (int i=0; i<n-1; ++i){ cout << X[i] << " "; }
  cout << X[n-1] << ")\n";	
}

// Método pra apresentar os elementos da matriz A
void showMat(vector<vector<int>> A, string NomeA, int n, int m){
  cout << NomeA << ":\n";
	for (int i=0; i<n; ++i){
    cout << "\t| ";
    for (int j=0; j<m; ++j){ cout << A[i][j] << " "; }
    cout << "|\n";
  }	
}

// Método para determinar o maior valor dentre dois inteiros
int maxVal(int P, int Q){
  if (P > Q) { return P; } else { return Q; }
}

// Método para aplicar condições iniciais em A - Vide Anany
vector<vector<int>> CI(vector<vector<int>> A, int n, int m){
	for (int i=1; i<n; ++i){ A[i][0] = 0; C++;}  // Primeira Linha
  for (int j=0; j<m; ++j){ A[0][j] = 0; C++;}  // Primeira Coluna
	return A;
}

// Método pra atribuir os valores conforme a fórmula de recorrência:
vector<vector<int>> AV(vector<vector<int>> A, int n, int m){
  for (int i=1; i<n; ++i){
    for (int j=1; j<m; ++j){
      if (j-W[i-1] >= 0){
        C++;  // Comtando operações básicas | Recorrência - Anany
        A[i][j] = maxVal(A[i-1][j], A[i-1][j-W[i-1]] + V[i-1]);
      } else {
        C++;  // Comtando operações básicas | Recorrência - Anany
        A[i][j] = A[i-1][j];
      }
    }
  }
  return A;
}

// Função principal
int main(){
  // Parâmetros e variáveis do processo
  int N = W.size() + 1;   // N° de Linhas - Quantidade de produtos
  int M;  // Limite para o peso na mochila - N° de Colunas
	cout << "Digite o limite para o peso, Wmax: ";
	cin >> M;
	M++; // Correção porque a contagem começa em 0 e não em 1 

	// Matriz para armazenar dados -> Tabela da programação dinâmica! 
  vector<vector<int>> F(N, vector<int>(M));   // Matriz F

  // Atribuindo as Condições Iniciais -> Programação dinâmica!
  F = CI(F, N, M);

	// Atribuindo os valores de acordo com a fórmula de recorrência
  F = AV(F, N, M);

	// Resultados do problema
	showVec(W, "W", N-1);
	showVec(V, "V", N-1);
  showMat(F, "Matriz F", N, M);

	// Pronto
  cout << "Foram realizadas " << C << " operações básicas!\n";
	return 0;
}
// **************************************************************** //
// FIM
// Para compilar: g++ prog.cc -o saida
