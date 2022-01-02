// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de permutação de Johnson-Trotter - Funciona pra N<5
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Set./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <locale>      // Gramática Local
#include <stack>       // Pilhas 
#include <vector>      // Vetores
#include <numeric>     // Operações vetoriais

// Prefixos -> Namespaces
using namespace std;

// Parâmetros e Variáveis globais
const int N=4;                // Tamanho da instância
const int M=N-1;              // Índice do último termo
int P=1;                      // Contagem de permutação
stack<int> ET;                // Pilha para os Elementos de Troca
vector<int> V(N);             // Vetor para os valores

// Método para calcular o valor fatorial FT de um inteiro F
int fatF(int F){  // Útil para limitar os ciclos a seguir
  int FT = F;   // Valor de entrada
  for (int i=2; i<F; ++i){ FT *= i; }  // Fatoração
  return FT;  // Resposta -> Valor fatorial de F = F!
}

// Método para imprimir os elementos do vetor 
void showVector(vector<int> X){   // Entrada um vetor X qualquer
  cout << "( ";
  for (int i=0; i<N; ++i){ cout << X[i] << " "; }  // Elementos de X
  cout << ")\n";
}

// Método para criar a pilha dos dos Elementos de Troca
void pilhaET(){  // Pilha dos elementos de permuta 
  for (int i=2; i<N; ++i){   // Elementos móveis para troca -> swapET()
    int j=i;                 // Parâmetro de controle para repetição
    while ( j>1 ){           // dos elementos. Por exemplo, se N=5:
      ET.push(i);            // ET = [4, 4, 4, 3, 3, 2]
	  j--;                   // Observe que i repete-se i-1 vezes
}}}

// Método para determinar o índice do Elemento de Troca
int indexET(int Ek){    // Útil para realizar as trocas -> swapET()
  int c=0;   // Variável para armazenar o índice, inicia com 0
  while ( V[c] != Ek ){ c++; }  // Varredura pelos elementos de V
  return c;  // Retorna o índice referente ao valor de entrada Ek
}

// Método para mover o maior termo da DIREITA para ESQUERDA
void mobVecDE(int C){  // Movimenta o maior valor de V, que é N
  while(C>0){   // Varredura por todas as posições de V, da Direita 
    P++;        // para Esquerda, ilustrando o movimento de N através de V
    swap(V[C], V[C-1]);  // Usando swap() e contando cada permuta com P
    cout << "Permuta " << P << " move " << N << " pra Esquerda" << endl;
    showVector(V);
    C--;   // Reduz o valor de C, que nesse contexto = M 
  }
}

// Método para mover o maior termo da ESQUERDA para DIREITA
void mobVecED(int C){  // Movimenta o maior valor de V, que é N
  while(C<M){  // Varredura por todas as posições de V, da Esquerda
    P++;       // para Direita, ilustrando o movimento de N através de V
    swap(V[C], V[C+1]); // Usando swap() e contando cada permuta com P
    cout << "Permuta " << P << " move " << N << " pra Direita" << endl;
    showVector(V);
    C++;
  }
}

// Método para movimentar outros elementos E<-D após cada ciclo de N
void swapETde(){ // Após o maior elemento completar seu movimento
  int iET = indexET( ET.top() ); // deve-se movimentar o 2° maior elemento
  ET.pop();      // móvel, definido como o maior elemento de V cujo 
  swap(V[iET], V[iET-1]);  // vizinho precedente deve ser menor que este
  P++;  // Então, se V[i] > V[i-1]  -> swap(Vi, Vi-1) e conte a permutação!
  cout << "Permuta " << P << " move " << V[iET-1] << " pra Esquerda" << endl;   
  showVector(V); // Resultado
}

// Método para movimentar outros elementos E->D após cada ciclo de N
void swapETed(){   // Após o maior elemento completar seu movimento
  int iET = indexET( ET.top() );  // deve-se movimentar o 2° maior elemento
  ET.pop();        // móvel, definido como o maior elemento de V cujo 
  swap(V[iET], V[iET+1]);  // vizinho adjacente deve ser menor que este
  P++;    // Então, se V[i] > V[i+1] -> swap(Vi, Vi+1) e conte a permutação!
  cout << "Permuta " << P << " move " << V[iET+1] << " pra Direita" << endl;   
  showVector(V);  // Resultado
}

// Método para realizar os ciclos: D->E->D->E->D->E .. até P = N!
void ciclosMob(){   // Vamos realizar a movimentação dos elementos de V
  int FT = fatF(N);  // Parâmetro de controle = Permutação limite!
  while ( P < FT){   // Condição principal, até realizarmos N! permutas
    pilhaET();   // Cria-se a pilha para as trocas swapETde()
    while ( !ET.empty() ){  // Enquanto houver mobilidade dos elementos != N
      if ( V[M] == N ){  // Se N estiver na extremidade Direita
        mobVecDE(M);     // Mova-o para Esquerda, até a outra extremidade
        swapETde();      // Daí realize o movimento do 2° elemento móvel
      } else if ( V[0] == N ){   // Quando N estiver na extremidade Esquerda 
        mobVecED(0);     // Mova-o para Direita, até a outra extremidade
        swapETde();      // Daí realize o movimento do 2° elemento móvel
	  }                  
    }                    // Neste ponto todos elementos moveram D->E 
    cout << "\nInverte a direção, agora movimentos da Esquerda pra Direita\n";
	pilhaET();      // Cria-se a pilha novamente
    while ( !ET.empty() ){  // Enquanto houver mobilidade dos elementos != N  
      if ( V[M] == N ){  // Se N estiver na extremidade Direita
        mobVecDE(M);     // Mova-o para Esquerda, até a outra extremidade
        swapETed();      // Daí realize o movimento do 2° elemento móvel
      } else if ( V[0] == N ){  // Quando N estiver na extremidade Esquerda
        mobVecED(0);     // Mova-o para Direita, até a outra extremidade
        swapETed();      // Daí realize o movimento do 2° elemento móvel 
	  }
    }                    // Neste ponto todos elementos moveram E->D 
    cout << "\nInverte a direção, agora movimentos da Direita pra Esquerda\n";
  }
}

// Função Principal
int main(){
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");
  
  // Preenchendo o vetor -> iota() está na biblioteca <numeric>
  iota(V.begin(), V.end(), 1);  // Preenchendo o vetor
 
  // Imprimindo a lista de entrada:
  cout << "Lista inicial ou Primeira permutação: \n";
  showVector(V);  

  // Realizando os movimentos que geram todas as permutações!
  ciclosMob();

  return 0;
}
//FIM
// Para compilar: g++ prog.cc -o saida
