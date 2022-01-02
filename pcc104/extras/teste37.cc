/*************************************************************************/
// Programa para construir um GRAFO usando as estruturas map e vector
// Davi Neves - UFOP, DEPRO, DECOM - Novembro de XXI
/*************************************************************************/
// Bibliotecas
#include <iostream>
#include <vector>
#include <map>

// Prefixo
using namespace std;

// Construindo o objeto GRAFO
class GRAFO{
   private:
     char C;    // Variável para os nós adjacentes
	 int D;     // Variável para o grau dos nós
   public:
	 map<char, vector<char>> Noh;    // Estrutura dos Nós
	 // Construtor do GRAFO
	 GRAFO(char L){  // Entrada/Ativação do construtor
       for (char c='A'; c<L; c++){ // Construção dos nós adjacentes
	     cout << "\nQual é o grau do nó " << c << "?\n";
	     cin >> D;
	       for (int i=0; i<D; i++){ // Inserção de cada nó adjacente 
             cout << "Digite o " << i+1 << "º nó adjacente à " << c << ": ";
	         cin >> C;
	         Noh[c].push_back(C);  // Inserção
	       }
       }
	 }
	 // Método para apresentar o GRAFO
	 void MostreG(char L){
       for (char c='A'; c<L; c++){ // Varredura pelos nós referências
        cout << "Nó " << c << " <--> ";
	    D = Noh[c].size();  // Grau de cada nó referência
		for (int i=0; i<D; i++) {    // Varredura pelo vetor
          cout << Noh[c][i] << " ";  // de nós adjacentes
	    }
	    cout << endl;  // Salta para o próximo nó referência
       }
	 }
};

// Função Principal 
int main(){
  // Variáveis de entrada
  int N;
  char L='A';

  // Entrada - Definindo a instância
  cout << "Digite o número de nós: ";
  cin >> N;
  L+=N;

  // Construindo o GRAFO
  GRAFO G = GRAFO(L);

  // Mostrando o GRAFO
  cout << "\nResultado: \n";
  G.MostreG(L);

  return 0;
}
/*************************************************************************/
// FIM -> Para compilar: g++ teste37.cc -o saida
