// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de gerar subconjuntos a partir de um conjunto
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Set./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <locale>    // Gramática Local
#include <time.h>    // Tempo pra semente randômica
#include <list>      // Para usar a estrutura de listas
#include <vector>    // Para usar a classe vector

// Prefixos -> Namespaces
using namespace std;

// Variáveis e parâmetros globais
int N=17;
vector<int> V(N,0);
list<int> L;

// Método para gerar a instância de entrada
void Instance(){
  // Gerando número randômicos
  for ( int i=0; i<N; ++i ) { L.push_back(rand()%100); }
  L.sort();  // Ordenando os valores da lista
  int c=0;   // Parâmetro de controle do vetor V
  while ( !L.empty() ) {  // Convertendo a lista L num vetor V
    V[c] = L.front();     // Primeiro termo - FIFO
    L.pop_front();        // Esvaziando a lista L
	c++;                  // Novo índice c
  }
  // Resultado - Imprimindo a instância 
  cout << "Instância criada:\n";
  cout << "( ";
  for (int i=0; i<N; ++i){cout << V[i] << " ";}  // Elementos
  cout << ")\n";
}

// Função para busca binária
int BuscaBin(vector<int> W, int Key);

// Função principal
int main() {
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");
  // Sementa randômica
  srand(time(0));
  // Instância de entrada
  Instance();
  // Entrada do termo chave
  int K;
  cout << "Digite o termo chave: ";
  cin >> K;
  // Buscando o Índice
  int I = BuscaBin(V, K);
  // Resultado
  cout << "O índice do termo chave = " << I << ".\n"; 
  cout << "Logo, de acordo com a busca binária, ";
  cout << "V[" << I << "] = " << V[I] << endl;
  // Pronto!
  return 0;
}

int BuscaBin(vector<int> W, int Key){
  // Parâmetros do livro 
  int l = 0;  // Índice do primeiro elemento
  int r = N-1;  // Índice do último elemento
  int m, Wm;  // Parâmetros de controle
  // Varredura de busca
  while ( l <= r ) {
    m = (l+r)/2;   // Índice do elemento médio
	Wm = W[m];
    if ( Wm > Key ) {  // Varredura Inferior
      r = m-1;  // Novo limite superior
    } else if ( Wm < Key ) {  // Varredura Superior
      l = m+1;  // Novo limite inferior  
    } else {  // Igualdade Wm = Key
      return m;  // Índice correto da chave Key
    }
  }
  return -1;  // Deu zebra!
}

//FIM
// Para compilar: g++ prog.cc -o saida
