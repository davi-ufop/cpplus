/********************************************************************/
// Programa para testar a nossa biblioteca que gera vetores e listas
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM
/********************************************************************/
// Importando nossa biblioteca
#include "bteca.hpp"

// Função principal
int main(){
  // Parâmetros de entrada
  int N=15, L=70;
  
  // Variáveis de entrada
  vector<int> VA;
  vector<double> VB;
  list<int> LA;
  list<double> LB;

  cout << "\n\tVETORES" << endl;
  // Gerando os vetores
  VA = gerVec<int>(N, L);     // Inteiro
  VB = gerVec<double>(N, L);  // Real

  // Apresentando os vetores
  showVec<vector<int>>(VA);
  showVec<vector<double>>(VB);

  // Testando o tipo:
  VA[1] = 1.3*VA[1];
  VB[1] = 1.3*VB[1];

  // Apresentando os vetores de novo
  showVec<vector<int>>(VA);
  showVec<vector<double>>(VB);

  cout << "\n\tLISTAS" << endl;
  // Gerando as listas randômicas
  LA = gerLis<int>(N, L);  // Lista de inteiros
  LB = gerLis<double>(N, L);  // Lista de reais

  // Apresentando as listas criadas
  showLis<list<int>>(LA);
  showLis<list<double>>(LB);

  // Ordenando as listas
  LA.sort();
  LB.sort();
  
  // Apresentando as listas ordenadas
  showLis<list<int>>(LA);
  showLis<list<double>>(LB);

  return 0;
}
// FIM - Para compilar: g++ teste03.cc -o saida
