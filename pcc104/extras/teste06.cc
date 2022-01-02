/********************************************************************/
// Programa para gerar permutações com vetores e listas
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM
/********************************************************************/
// Bibliotecas
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){

  // Parâmetros do programa
  int N;
  
  // Vetor e lista pra permutar
  vector<int> V = {1, 5, 3};
  list<char> L = {'B', 'A', 'C'};

  cout << "Vetor:" << endl;
  // Permutando o vetor - Antes deve-se ordenar
  sort(V.begin(), V.end()); // ordenando
  // Permutando
  do{
    cout << V[0] << " " << V[1] << " " << V[2] << endl;
  } while ( next_permutation(V.begin(),V.end()) );

  cout << "\nLista:" << endl;
  // Permutando a lista - Antes deve-se ordenar
  L.sort(); // ordenando
  // Permutando, com auxilio do iterator
  list<char>::iterator it;  // Iterator
  do{
    for (it = L.begin(); it != L.end(); ++it){ cout << *it << " "; }
    cout << endl;
  } while ( next_permutation(L.begin(),L.end()) );

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste06.cc -o saida
