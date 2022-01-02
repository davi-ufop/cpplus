// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de gerar subconjuntos a partir de um conjunto
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Set./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <locale>    // Gramática Local
#include <vector>    // Para usar a classe vector
#include <string>    // Para lista de caracteres
#include <algorithm> // Para permutação

// Prefixos -> Namespaces
using namespace std;

// Método para determinar os subconjuntos
void SubConjuntos(string Letras[], int N);

// Função principal
int main() {
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");
  // Conjunto completo - Instância
  string letras[] = {"A", "B", "C", "D", "E"};
  // Tamanho da lista de caracteres/instância
  int n = sizeof(letras)/sizeof(letras[0]);
  // Construindo todos os subconjuntos
  SubConjuntos(letras, n);
  // Pronto!
  return 0;
}

// Função para construir os subconjuntos
void SubConjuntos(string Letras[], int N) {
  int N1 = N-1;  // Parâmetro do último índice
  vector<int> w(N,0);  // Vetor composto por zeros
  cout << "Subconjuntos:\n{ }" << endl;
  // Varredura sobre as permutações que geram os subconjuntos
  for (int k=0; k<N; ++k){
    w[N1-k]=1;  // Inserindo o elemento 1 no vetor Zero: (0,0,0)->(0,0,1)
	sort(w.begin(), w.begin()+N);  // Permutando/Ordenando
    do{  // Imprimindo os conjuntos
      //cout << "(" << w[0] << " " << w[1] << " " << w[2] << ")\n"; 
	  cout << "{ ";
      for ( int i=0; i<N; ++i ){
        if ( w[i] == 1 ){ cout << Letras[i] << " "; }
	  }
	  cout << "}\n";   // Fim da permutação
	} while ( next_permutation(w.begin(), w.begin()+N) );
  }
}

//FIM
// Para compilar: g++ prog.cc -o saida
