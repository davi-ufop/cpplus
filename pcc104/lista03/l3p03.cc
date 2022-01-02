// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de permutação Lexicográfica
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Set./XXI
// **************************************************************** //
// Importando as bibliotecas:
#include <iostream>    // Entradas/Saídas
#include <locale>      // Gramática Local
#include <time.h>      // Tempo/Datas
#include <list>        // Listas -> Vide ref. C++

// Prefixos -> Namespaces
using namespace std;

// Parâmetros e Variáveis globais
const int N=6;        // Tamanho da instância - Número de produtos
const int L=100*N;    // Limite para o número randômicos: cem vezes N

class Lista {  // Nossa classe para listas
  private:  // Variáveis privadas
    int A[N];  // Variável para armazenar N dados
  public:   // Métodos públicos
	// Criando os elementos desta lista
    void Make() {
      list<int> Li;  // Lista - STL <list>
      for ( int i=0; i<N; ++i ) { Li.push_back(rand()%L); }  // Elementos
	  Li.sort();     // Ordenando os elementos randômicos
	  int j = 0;     // Índice para o Arranjo: A[j]
	  while ( !Li.empty() ) {   // Colocando os elementos em A[N]
        A[j] = Li.front();      // Primeiro elemento da lista -> FIFO
        Li.pop_front();         // Retirando o elemento da lista
        j += 1;                 // Novo índice
      }
	}
    void Show() {   // Apresentando a lista
      cout << "( ";  
      for ( int i=0; i<N; ++i ){
        cout << A[i] << " ";     // Elementos separados por espaço
      }
      cout << ")" << endl;
	}
	void NewPermute();
};

// Função Principal
int main() {
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");
  // Semente Temporal para Números Randômicos
  srand(time(0));
  
  // Listas conforme definimos
  Lista L1;

  // Criando os elementos da Lista
  L1.Make();

  // Mostrando os elementos da Lista
  cout << "\nLista Inicial:" << endl;
  L1.Show();

  // Sete Permutações Lexicográficas
  for ( int P=1; P<=7; P++ ) {
    cout << "\nPermutação " << P << ":" << endl;
    L1.NewPermute();  // Realiza a permutação
    L1.Show();        // Mostra o resultado da permutação
  }
  
  return 0;
}

// Método externo para a Lista
void Lista::NewPermute() {
  // Encontrando o maior índice i, tal que: A[I-1] < A[I]
  int I = 0;  // Valor inicial e em seguida a varredura
  for (int i=0; i<(N-1); ++i) { if (A[i] < A[i+1]) { I = i; } }  
  cout << "Elemento A[I] = " << I << endl;  // Resultado 
  // Encontrando o maior índice j, tal que: A[J] > A[I]
  int J = I+1;  // Primeiro valor pra J
  while (A[J] > A[I] && J < N){ J += 1;}  // Busca conforme estabelecido
  J -= 1;  // Ajuste necessário
  cout << "Elemento A[J] = " << J << endl; 
  // Troca dos elementos > A[i]
  int Aj = A[J];  // Salvando o elemento A[j]
  A[J] = A[I];    // Novo valor de A[j]
  A[I] = Aj;      // Novo valor de A[i]
  // Revertendo a ordem de A[I+1] até A[N-1]
  int nu = N-1; // Índice relativo aos elementos adjacentes
  int np = I+1; // Índice relativo aos elementos precedentes
  while (nu > np) {  // Trocando os valores > A[I]
    int AN = A[nu];  // Salvando o valor adjacente 
	A[nu] = A[np];   // Novo valor para A[nu]
	A[np] = AN;      // Novo valor para A[np]
	nu -= 1;    // Novo índice nu
	np += 1;    // Novo índice np
  }
}

//FIM
// Para compilar: g++ prog.cc -o saida
