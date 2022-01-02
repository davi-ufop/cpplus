// Biblioteca e sufixos
#include <iostream>
using namespace std;

// Template para organizar um array
template <class V>
void orGanize(V W[], int N){
  for (int i=0; i<N; ++i)
    for (int j=N-1; i<j; --j)
      if (W[j] < W[j-1]) 
        swap(W[j], W[j-1]); 
}

int main(){
  // Parâmetros de contagem
  const int K=11;
  const int K1=K-1;
  // Variáveis do processo
  char letras[K] = {'A','C','B','E','F','D','H','J','I','K','G'};
  int vetor[K] = {1, 3, 2, 5, 6, 4, 7, 9, 8, 11, 10};
  
  // Ordenando os números do vetor
  int i=0, j=0;
  while (i < K1){ cout << vetor[i]; ++i; }
  cout << vetor[K1] << endl;
  int P = sizeof(vetor)/sizeof(vetor[0]);
  orGanize<int>(vetor, P);
  while (j < K1){ cout << vetor[j]; ++j; }
  cout << vetor[K1] << endl;

  // Ordenando as letras 
  int p=0, q=0;
  while (p < K1){ cout << letras[p]; ++p; }
  cout << letras[K1] << endl;
  int Q = sizeof(letras)/sizeof(letras[0]);
  orGanize<char>(letras, Q);
  while (q < K1){ cout << letras[q]; ++q; }
  cout << letras[K1] << endl;
}
// FIM - Para compilar: g++ teste02.cc -o saida
