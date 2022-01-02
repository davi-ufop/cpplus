// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema da Mediana de um conjunto desordenado
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Out./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <locale>    // Gramática Local
#include <time.h>    // Tempo para sementes randômicas
#include <vector>    // Vetores

// Prefixos -> Namespaces
using namespace std;

// Variáveis globais
const int N=11;      // Tamanho da instância - IMPAR
const int N2=N/2;    // Número de elementos menores <  mediana   
vector<int> V;       // Vetor para o conjunto arbitrário

// Criando o vetor arbitrário
void crieV(){              // criando os Elementos       
  for (int i=0; i<N; ++i){ V.push_back(rand()%50); } 
}

// Mostrando o vetor
void showV(vector<int> X){
  const int L = X.size();
  cout << "( ";            // mostrando os Elementos
  for (int i=0; i<L; ++i){ cout << X[i] << " "; }
  cout << ")" << endl;
}

// Contando o Nº de elementos menores que k
int numMenores(int Vk){ // Entrada: elemento k de V
  int C=0;    // Contador de valores menores 
  for (int i=0; i<N; ++i){  // Varredura por todos elementos de V
    if (V[i] < Vk){  // Comparando elementos
      C++;   // Contagem para Vi < Vk
    }
  }
  return C;  // Valor da contagem
}

// Buscando a mediana
int findMed(){  // Método para buscar a mediana
  int Nk=0;   // Valor inicial para a contagem dos menores
  int k=-1;   // Valor inicial para varredura dos índices (ajustado)
  while ( Nk != N2){  // Condições para a busca
	k++;   // Operação para a varredura -> Primeiro valor k=0
    Nk = numMenores(V[k]);  // Nº de elementos menores que Vk
  } 
  return k;
}

// Método para apresentar os elementos maiores e menores que a mediana
void maiorMenor(int Vk){ // Entrada: mediana
  vector<int> XV, VX;  // Vetores para armazenar dados
  for (int i=0; i<N; ++i){  // Varredura por todos elementos de V 
    if (V[i] < Vk){   // Elementos menores
      XV.push_back(V[i]);  // Salvando
    } else if (V[i] > Vk) { // Elementos maiores
      VX.push_back(V[i]);        // Salvando
    }
  } // Resultados
  cout << "Elementos < " << Vk << ":\n";
  showV(XV);
  cout << "Elementos > " << Vk << ":\n";
  showV(VX);
}

// Função Principal
int main(){
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");
  // Semente randômica
  srand(time(0));
  
  // Criando e mostrando o conjunto
  crieV();
  showV(V);

  // Encontrando a mediana
  int K = findMed();
  cout << "Mediana = " << V[K] << endl; // Resultado

  // Maiores e Menores que a mediana
  maiorMenor(V[K]);

  return 0;
}
//FIM
// Para compilar: g++ prog.cc -o saida
