// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de ordenação por inserção
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Set./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <locale>      // Gramática Local
#include <time.h>      // Tempo/Datas
#include <list>        // Listas -> Vide ref. C++

// Prefixos -> Namespaces
using namespace std;

// Parâmetros e Variáveis globais
const int N=15;         // Tamanho da instância - Número de produtos
const int L=5*N;        // Limite para o número randômicos: cinco vezes N

class Lista {  // Nossa classe para listas
  public:  // Publicando nossos objetos e métodos
    int elementos[N];  // Arranjo para armazenar elementos da lista
    // Algoritmo de Ordenação por Inserção
    void Ordena() {    
      for ( int i=1; i<N; ++i ) {  // Varredura nos N elementos adjacentes
        int v = elementos[i];   // Salvando o elemento pivô
		int j = i-1;        // Elemento precedente ao pivô
        while ( j >= 0 && elementos[j] > v ) {  // Analisando elementos precedentes
          elementos[j+1] = elementos[j];    // Troca entre elementos conforme análise
          j -= 1;    // Iteração para a varredura
        }
        elementos[j+1] = v; // Conclusão da troca iniciada
      }
    }
    // Função para imprimir a lista criada
    void Imprime() {
      cout << "Lista: \n ( "; 
      for ( int i=0; i<N; ++i ) {
        cout << elementos[i] << " ";  // Impressão dos elementos
      }
      cout << ")\n" << endl;
    }
};	

// Função Principal
int main() {
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");

  // Semente Temporal para Números Randômicos
  srand(time(0));

  // Definindo Listas de acordo com nossa classe
  Lista L1;

  // Definindo uma Lista usando STL
  list<int> L2;

  // Construindo listas randômicas - Instância
  for ( int i=0; i<N; ++i ) {
    int elemento_i = rand()%L;   // Elemento randômico
    L1.elementos[i] = elemento_i;  // Adicionando elementos na nossa lista
	L2.push_back(elemento_i);   // Adicionando elementos na lista L2 -> Fila
  }

  // Executando a ordenação por inserção
  L1.Imprime();  // Imprime a elementos original
  cout << "Ordenando ...\n";
  L1.Ordena();   // Ordenando por Inserção 
  cout << "Pronto, elementos ordenados por inserção!\n";
  L1.Imprime();  // Imprime a elementos ordenada

  // Ordenando a Lista L2 - Via STL
  L2.sort();  // Comando de ordenação
  cout << "Ordenamento via STL - <list>.\nLista L2:\n ( ";
  while ( !L2.empty() ) { // Imprimindo todos os elementos
    cout << L2.front() << " ";  // Dinâmica FIFO em L2
    L2.pop_front(); // Esvaziando a lista L2
  }
  cout << ")" << endl;

  // FIM do programa principal
  return 0;
}     
//FIM
// Para compilar: g++ prog.cc -o saida
