/********************************************************************/
// Programa para construir listas de adjacência, usadas em GRAFOS
// Davi Neves - UFOP, DEPRO, DECOM - Novembro de XXI
/********************************************************************/
// Bibliotecas
#include <iostream>
#include <list>

// Prefixo
using namespace std;

// Método para criar a Lista das Listas
list<list<int>> crieListaG(int N) {
  // Parâmetros e variáveis
  int NI, NA;
  list<list<int>> LE;
  // Entrada de dados
  for (int i=0; i<N; i++) {
    cout << "\nDigite o número de elos do Nó " << i+1 << ": ";
	cin >> NI;   // Usado no loop seguinte
	for (int j=0; j<NI; j++) { // Adicionando os elos do nó i+1
      list<int> LJ;            // Lista de cada elo J
	  LJ.push_back(i+1);       // O nó referência do elo J
      cout << "Digite o " << j+1 << "º nó adjacente à " << i+1 << ": ";
	  cin >> NA;               // O nó adjacente do elo J
	  LJ.push_back(NA);
	  // Adicionando a lista LJ na Lista das Listas: LE 
	  LE.push_back(LJ);
	} // Pronto, em cada passo desse loop LJ reinicia -> zera
  }
  // Resultado
  return LE;
}

// Método para apresentar a Lista das Listas - Lista de Elos
void mostreLE(list<list<int>> LE) {
  list<list<int>>::iterator it;  // Usando iterator
  cout << "{ ";  // Lista Principal - Início
  // Loop sobre a Lista das Listas
  for (it=LE.begin(); it!=LE.end(); it++){
    list<int> LJ = *it;  // Lista J
	cout << "{ "; // Início de LJ
    cout << LJ.front() << ", ";  // Elemento referência
    cout << LJ.back();           // Elemento Adjacente
	cout << " }, ";  // Fim de LJ
  }
  cout << "}" << endl; // Fim da Lista das Listas
}
/********************************************************************/
