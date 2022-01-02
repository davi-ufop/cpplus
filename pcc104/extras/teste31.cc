/********************************************************************/
// Programa para manipular matrizes e listas em C++ com estruturas
// Davi Neves - UFOP, DEPRO, DECOM - Novembro de XXI
/********************************************************************/
// Bibliotecas
#include <iostream>
#include <list>
#include <vector>

// Prefixo
using namespace std;

// Método para apresentar uma lista 
// void mostreL(list<int> Li) {
void mostreL(list<char> Li) {
  for (auto v : Li){
    cout << v << " ";
  }
  cout << endl;
}

// Método para apresentar uma matriz
// void mostreM(vector<vector<int>> Mij) {
void mostreM(vector<vector<char>> Mij) {
  for (int i=0; i<Mij.size(); i++){
    cout << "| ";
    for (int j=0; j<Mij[i].size(); j++){
      cout << Mij[i][j] << " ";
	}
	cout << "|" << endl;
  }
}

// Função Principal
int main(){
  // Definindo a lista:	
  //list<int> L = {1, 2, 3, 4};
  list<char> L = {'a', 'b', 'c', 'd'};
  // Mostrando a lista definida
  cout << "Lista: ";
  mostreL(L);

  // Definindo a matriz:
  //vector<vector<int>> M = {{1, 2}, {3, 4}};
  vector<vector<char>> M = {{'a', 'b'}, {'c', 'd'}};
  // Mostrando a matriz definida:
  cout << "\nMatriz:\n";
  mostreM(M);

  // Trocando o elemento M22
  cout << "\nDigite o novo valor de M22: ";
  cin >> M[1][1];
  // Pronto!
  cout << "\nMatriz:\n";
  mostreM(M);

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste31.cc -o saida
