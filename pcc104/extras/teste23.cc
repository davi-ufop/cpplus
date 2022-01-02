/********************************************************************/
// Programa para criar uma Arvore Binária, com recursividade
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM DEPRO
/********************************************************************/
// Biblioteca
#include <iostream>

// Prefixo
using namespace std;

// Estrutura de um Nó da árvore
struct Noh {   
  int Valor;        // Valor chave
  struct Noh *RE;   // Ramo à esquerda
  struct Noh *RD;   // Ramo à direita
  // Método interno para construir o respectivo Nó
  Noh(int V){     // Entrada do Valor chave V
    Valor = V;    // Atribuição do valor V
    RE = NULL;    // Definição primária para o ramo à esquerda
    RD = NULL;    // Definição primária para o ramo à direita
  }
};

// Método externo pra Inserir o dado Nó S na árvore com raiz R
Noh* inseRe(Noh *R, Noh *S){       // Entrada
  if (R == NULL){ return S; }      // Conclusão da recursividade
  if (S->Valor < R->Valor){        // Condição: Vai pra esquerda  
    R->RE = inseRe(R->RE, S);      // O RE torna-se Raiz - Recursivo
  } else {                         // Condição: Vai pra direita
    R->RD = inseRe(R->RD, S);      // O RD torna-se Raiz - Recursivo
  }                                
  return R;                        // Quando RE ou RD for NULL: FIM
}                                  // Resultado: caminho desde a Raiz

// Função Principal
int main(){
  // Parâmetros e Variáveis do processo
  const int N=5;      // Tamanho da árvore - Número de nós
  int W, R;           // Variáveis

  // Definindo o Valor da Raiz
  cout << "\nDigite o valor da Raiz: ";
  cin >> R;   // Valor da Raiz
  struct Noh *Raiz = new Noh(R);  // Comando pra criar a Raiz
                                  // O comando 'new' aloca a RAM  
  // Processo de inserção dos Ramos                   
  // Dica: Digite 3 Maiores e 2 Menores que a Raiz -> Resultado L55
  for (int i=0; i<N; ++i){  // Siga a dica, evite erro de segmentação
    cout << "Digite o valor do Ramo " << i+1 << ": ";
    cin >> W;   // Valor o i-ésimo Ramo
    struct Noh *Ramo = new Noh(W);  // Comando pra criar o Ramo
    Raiz = inseRe(Raiz, Ramo);      // Processo recursivo pra definir  
  }                                 // o caminho do i-ésimo Ramo

  // Conferindo o Resultado - Se você seguiu a Dica: L47
  cout << "\nRaiz (R) = " << Raiz->Valor << endl;           
  cout << "R-D = " << Raiz->RD->Valor << endl;
  cout << "R-E = " << Raiz->RE->Valor << endl;
  cout << "R-D-D = " << Raiz->RD->RD->Valor << endl;
  cout << "R-E-E = " << Raiz->RE->RE->Valor << endl;
  cout << "R-D-D-D = " << Raiz->RD->RD->RD->Valor << endl;
/********************************************************************/
// O erro de segmentação ocorre se você não digitar os maiores em
// ordem crescente e os menores em ordem decrescente. 
// Exemplo 1: IN(R=12, 14, 16, 18, 9, 6) OUT-> 12, 14, 9, 16, 6, 18
// Exemplo 2: IN(R=12, 14, 18, 16, 9, 6) OUT-> 12, 14, 9, 18, 6, ERRO
// Exemplo 3: IN(R=12, 14, 16, 18, 6, 9) OUT-> 12, 14, 6, 16, ERRO
// O ERRO refere-se à Apresentação do Resultado e não à Árvore, que
// está OK! Use IN 2 ou 3, comente L56-L61 e descomente a seguir:
/********************************************************************/
  // Conferindo o Resultado para a entrada do Exemplo 2, descomente: 
//  cout << "\nRaiz (R) = " << Raiz->Valor << endl;           
//  cout << "R-D = " << Raiz->RD->Valor << endl;
//  cout << "R-E = " << Raiz->RE->Valor << endl;
//  cout << "R-D-D = " << Raiz->RD->RD->Valor << endl;
//  cout << "R-E-E = " << Raiz->RE->RE->Valor << endl;
//  cout << "R-D-D-E = " << Raiz->RD->RD->RE->Valor << endl;
  // Conferindo o Resultado para a entrada do Exemplo 3, descomente: 
//  cout << "\nRaiz (R) = " << Raiz->Valor << endl;           
//  cout << "R-D = " << Raiz->RD->Valor << endl;
//  cout << "R-E = " << Raiz->RE->Valor << endl;
//  cout << "R-D-D = " << Raiz->RD->RD->Valor << endl;
//  cout << "R-E-D = " << Raiz->RE->RD->Valor << endl;
//  cout << "R-D-D-D = " << Raiz->RD->RD->RD->Valor << endl;
// Estes EXEMPLOS demonstram que o algoritmo funciona!

  return 0;
}
/********************************************************************/
// FIM - Para compilar digite: g++ teste23.cc -o saida
