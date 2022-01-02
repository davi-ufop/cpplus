/********************************************************************/
// Programa para construir um grafo a partir da matriz de adjacência
// Davi Neves - UFOP, DEPRO, DECOM - Novembro de XXI
/********************************************************************/
// Bibliotecas
#include <iostream>
#include <vector>
#include <ctime>

// Prefixo
using namespace std;

// Parâmetro Global - Limite para valores randômico < L
const int L = 2;  // Os elementos da matriz são 0 ou 1

// Método para criar uma matriz adjacente aleatória
vector<vector<int>> crieM(const int N) {
  vector<vector<int>> Mij;         // Variável para a Matriz
  // Para evitar ERRO de segmentação
  Mij.resize(N, vector<int>(N));   // Reescalonando o tamanho
  // Construindo a matriz definindo as linhas
  for (int i=0; i<N; ++i) {      // Linha i
    for (int j=i+1; j<N; ++j) {  // Colunas i+1
      Mij[i][j] = rand()%L;      // Elementos referentes a linha i
	  Mij[j][i] = Mij[i][j];     // Elementos referentes a coluna i
    }
    Mij[i][i] = 0;   // Diagonal principal
  }
  return Mij;
}

// Método para apresentar uma matriz
void mostreM(vector<vector<int>> Mij) {
  for (int i=0; i<Mij.size(); i++) {       // Variando a linha i
    cout << i+1 << " | ";    // Início da linha
    for (int j=0; j<Mij[i].size(); j++) {  // Imprime colunas de i
      cout << Mij[i][j] << " ";
	}
	cout << "|" << endl;   // Fim da linha
  }
}

// Método para mostrar o GRAFO a partir de A
void mostreGdeA(vector<vector<int>> Mij) {
  for (int i=0; i<Mij.size(); i++) {
    cout << i+1 << " <--> ";    // Nó referencial
    for (int j=0; j<Mij[i].size(); j++) {
      if (Mij[i][j] != 0) { cout << j+1 << " "; }  // Nós Adjacentes
	}
	cout << endl;
  }
}

// Estrutura de Dados Pertinente -> Nós
struct Nos {
  int ID;  // Índice dos nós
  vector<int> VAD;  // Vetor para os vértices adjacentes
};

// Classe GRAFO
class Grafo {
  private:
    int K=0;  // Ordem do GRAFO
  public:
    vector<Nos> Noh;   // Vetor para listar os Nós
    // Construtor do objeto GRAFO usando a matriz Adjacente
    Grafo(vector<vector<int>> MA) {      // Entrada: Matriz Adjacente
      for (int i=0; i<MA.size(); i++) {  // Adicionando os índices
        Noh.push_back(Nos());            // Iniciando o vetor de Nós
        Noh[i].ID = i+1;                 
        for (int j=0; j<MA[i].size(); j++) {  // Vetor dos adjacentes 
          if(MA[i][j] != 0) {                 
            Noh[i].VAD.push_back(j+1);        // j+1 = índice dos Nós 
			K++;                              // Ordem do GRAFO
		  }
	    }
      }
	  cout << "\nOrdem do GRAFO = " << K/2 << endl;
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
	int NV = GR.Noh[i].VAD.size();
    for	(int j=0; j<NV; j++) {
      cout << GR.Noh[i].VAD[j] << " ";  // Nós adjacentes (ligados)
    }
	cout << endl;
  }
}

// Função principal
int main() {
  // Variáveis
  int N;

  // Semente randômica
  srand(time(0));

  // Quanto nós terá o GRAFO?
  cout << "Digite o número de nós do grafo: ";
  cin >> N;

  // Criando a matriz de Adjacência
  vector<vector<int>> A;
  A = crieM(N);

  // Apresentando a matriz adjacente A
  cout << "\nMatriz Adjacente:\n";
  mostreM(A);

  // Mostrando o GRAFO a partir de A
  cout << "\nGRAFO a partir de A:\n";
  mostreGdeA(A);

  // Criando o GRAFO a partir de A
  Grafo G = Grafo(A);

  // Mostrando os Nós de GRAFO
  mostreNdeG(G, N);

  // Mostrando os Elos de GRAFO
  cout << "Elos:\n";
  mostreEdeG(G, N);

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste32.cc -o saida
