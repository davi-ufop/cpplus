/********************************************************************/
// Programa pra somar números randômicos, criados com srand()/rand()
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO & DECOM
/********************************************************************/
// Bibliotecas
#include <iostream>   // Biblioteca para realizar in e out
#include <ctime>      // Biblioteca pra usar o tempo em srand() 

// Prefixos
using namespace std;

// Variável global
int VN[]={};

// Método para criar os números randômicos
void NumsRands(int N);

// Método para somar os números randômicos
int SomaNums(int N);

// Método para mostrar os números criados
void ShowNums(int N){
  cout << "( ";   // Frescura
  for (int k=0; k<N; ++k)
    cout << VN[k] << " ";  // Mostra cada elmento k
  cout << ")\n";    // Fim da frescura
}

// Função principal
int main(){
  // Semente randômica
  srand(time(0));

  // Variáveis 
  int Q, R;
 
  // Entrada
  cout << "Digite a quantidade de números: ";
  cin >> Q;

  // Criando os números
  NumsRands(Q);

  // Mostrando os números
  ShowNums(Q);

  // Somando os números
  R = SomaNums(Q);

  // Resposta 
  cout << "A soma dos números = " << R << endl;

  return 0;
}

// Método para criar os números randômicos
void NumsRands(int N){
  // Limite dos números randômicos
  int L=100;
  // Criando os números randômicos
  for (int i=0; i<N; ++i)
    VN[i] = rand()%L;  // Gerando N elementos randômicos
}

// Método para somar os números randômicos
int SomaNums(int N){
  int S=0; // Variável pra armazenar a soma de N elementos
  for (int i=0; i<N; ++i){
    S += VN[i];  // Soma dos elementos
  }
  return S;
}
/********************************************************************/
// FIM - Pra compilar, vide prog01.cc
