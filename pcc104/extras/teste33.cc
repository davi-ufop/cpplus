/********************************************************************/
// Programa para construir um grafo a partir de listas de adjacência
// Davi Neves - UFOP, DEPRO, DECOM - Novembro de XXI
/********************************************************************/
// Bibliotecas
#include <vector>
#include "blista.hpp"

// Prefixo
using namespace std;

// Estrutura de Dados - Nós
struct Nos {
  int ID;
  list<int> LAD;
};

// Classe para o GRAFO usando a Lista de Elos
class Grafo {
  public:
    vector<Nos> Noh;   // Vetor dos nós do GRAFO
    // Construtor do GRAFO
	Grafo(list<list<int>> LE, int NL){
	  for (int i=0; i<NL; i++) {
        Noh.push_back(Nos());  // Para iniciar a construção
		Noh[i].ID = i+1;       // Índice do Nó referencial
        list<list<int>>::iterator it;  // Iterator em LE
	    for (it=LE.begin(); it!=LE.end(); it++){ // Varrendo LE
          list<int> LI = *it;   // Captando uma das Lista -> LI
		  if (LI.front() == i+1){             // Construindo a
		    Noh[i].LAD.push_back(LI.back());  // lista de adjacentes
          }
        }
      }
    }
};

// Método para Mostrar os Nós do GRAFO GR
void mostreNdeG(Grafo GR, int N) {
  cout << "\nNós: ";
  for (int i=0; i<N; i++){
    cout << GR.Noh[i].ID << " ";  // Índices dos Nós
  } 
  cout << "\n" << endl;
}

// Método para Mostrar os elos do GRAFO
void mostreEdeG(Grafo GR, int N) {
  for (int i=0; i<N; i++) {
    cout << "Nó " << GR.Noh[i].ID << " <--> ";  // Nó referencial
	for (int v : GR.Noh[i].LAD){ 
	  cout << v << " ";  // Nós adjacentes
    }
	cout << endl;
  }
}

// Função Principal
int main() {
  // Parâmetros e Variáveis
  int N;
  list<list<int>> LL;
  
  // Entrada de Dados
  cout << "\n\t\tDADOS DE ENTRADA\n";
  cout << "Digite o número de nós do grafo: ";
  cin >> N;

  // Criando a Lista de Listas - Lista de Elos
  LL = crieListaG(N);

  // Mostrando a Lista de Elos
  cout << "\nLista de Elos: \n";
  mostreLE(LL);
  
  // Criando o GRAFO a partir da LE -> LL
  Grafo G = Grafo(LL, N);

  // Mostrando os Nós de GRAFO
  mostreNdeG(G, N);

  // Mostrando os Elos de GRAFO
  cout << "Elos:\n";
  mostreEdeG(G, N);
  
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste33.cc -o saida
