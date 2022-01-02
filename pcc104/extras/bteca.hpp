/********************************************************************/
// Minha biblioteca, para auxiliar na criação de dados de entrada
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM
// USADA NOS PROGRAMAS 1, 2 e 3
/********************************************************************/
// Importando bibliotecas
#include <iostream>
#include <ctime>
#include <vector>
#include <list>

// Sufixos - Namespaces
using namespace std;

// Criando um vetor qualquer
template <typename nome1>
vector<nome1> gerVec(int N, int L){
  // Semente randômica
  srand(time(0));
  // Vetor de números randômicos - tipo=nome1
  vector<nome1> VR;
  // Adicionando os elementos randômicos ao vetor
  for (int i=0; i<N; ++i) { VR.push_back( (nome1)(rand()%L) ); }
  // Retorno da função
  return VR;
}

// Apresentando um vetor qualquer
template <typename tipo1>
void showVec(tipo1 VS){
  // Tamanho do vetor
  const int NS = VS.size();
  // Mostrando os elementos na tela
  cout << "( ";
  for (int i=0; i<NS; ++i){ cout << VS[i] << " "; }
  cout << ")" << endl;
}

// Criando uma lista qualquer
template <typename nome2>
list<nome2> gerLis(int N, int L){
  // Lista para armazenar N valores randômicos 
  list<nome2> LR;
  // Inserindo os elementos randômicos
  for (int i=0; i<N; ++i) { LR.push_back( (nome2)(rand()%L) ); }
  // Retorno da função
  return LR;
}

// Apresentando uma lista
template <typename tipo2>
void showLis(tipo2 LS){
  tipo2 LP( LS );
  // Mostrando os elementos da lista usando a ordem de filas
  cout << "{ ";
  while ( !LP.empty() ){        // Até esvaziar LP
    cout << LP.front() << " ";  // FIFO 
    LP.pop_front();             // FIFO
  }
  cout << "}" << endl; 
}

