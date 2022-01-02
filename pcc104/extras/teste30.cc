/********************************************************************/
// Programa para construir um GRAFO simples com classes em C++
// Davi Neves - UFOP, DECOM, DEPRO - Novembro de XXI
/********************************************************************/
// Bibliotecas
#include <iostream>
#include <vector>

// Prefixo
using namespace std;
 
// Estrutura de dados para Elos
struct Elo {
    int orig;   // Nó Origem do ELO
	int dest;   // Nó Destino do ELO
};
 
// Classe para o objeto GRAFO
class Grafo {
  public:
    // Matriz (vetor de vetores) para armazenar
	// lista de nós adjacentes
    vector<vector<int>> listAdj;
    // Construtor do GRAFO
    Grafo(vector<Elo> const &elos, int N) {
      // Reestruturando a lista de adjacência
	  // para o tamanho adequado: N
      listAdj.resize(N);
      // Adicionando os elos ao GRAFO
      for (auto &elo: elos) {
        // Adicionando os nós no final 
        listAdj[elo.orig].push_back(elo.dest);
        // Se o GRAFO for direcional ative a linha:
        // listAdj[elo.dest].push_back(elo.orig);
      }
    }
};
 
// Método para apresentar o GRAFO
void mostraG(Grafo const &grafo, int N) {
  // Imprimindo o índice do vértice atual
  for (int i = 0; i < N; i++) {
    cout << i << " ——> ";
    // Imprimindo os vizinhos deste vértice
    for (int v: grafo.listAdj[i]) {
      cout << v << " ";
    }
	// Saltando de linha para o próximo vértice
    cout << endl;
  }
}
 
// Programa Principal
int main() {
  // Número de Nós do GRAFO 
  int N = 6;
  
  // Instância de entrada conforme elaboramos
  vector<Elo> elos = { { 0, 1 }, { 1, 2 }, { 2, 0 }, 
             { 2, 1 }, { 3, 2 }, { 4, 5 }, { 5, 4 } };
 
  // Construindo o GRAFO
  Grafo grafo(elos, N);
 
  // Apresentando o GRAFO
  mostraG(grafo, N);
 
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste30.cc -o saida
