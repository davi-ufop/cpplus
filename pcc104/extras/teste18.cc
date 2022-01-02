/********************************************************************/
// Buscando o elemento K em uma lista encadeada com PONTEIROS
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO - DECOM 
/********************************************************************/
// Biblioteca
#include <cstdlib>       // malloc: Estabelece a memória usada pelo
#include <iostream>      // ponteiro: int *p = malloc(100*size(p))
                         // é o mesmo que o array int p[100].
// Prefixos
using namespace std;

// Definindo o objeto: Elemento(chave, endereço do próximo elemento)
struct Elemento{
  int chave;         // Valor chave
  Elemento *prox;    // Endereço hexadecimal na RAM - Posterior
};

// Método para construir a lista encadeada
Elemento* constroE(Elemento *E, int N){
  Elemento *PE; // Passo, representa o próximo E no cálculo  
  for (int i=0; i<N; ++i){
  cout << "Digite a chave do " << i+1 << "° elemento: ";
  cin >> E->chave;  // Atribuindo o valor da chave i+1
  PE = E+1;         // Próximo elemento
  E->prox = PE;     // Atribuindo o endereço de E+1
  cout << "Endereço do próximo elemento = " << E->prox << endl;
  E++;              // Passando para o elemento E=E+1
  }
  // Retorna a calda da lista:
  E++;
  return E;
}

// Função principal
int main(){
  // Parâmetros e variáveis
  int L, k, p=0;  		

  // Definindo o tamanho da lista
  cout << "Quantos elementos tem na lista?" << endl;
  cin >> L;

  // Definindo os ponteiros: A, HEAD e TAIL:
  Elemento *A, *PA, *H, *T; 

  // Definindo a capacidade de memória RAM usada:
  A = (struct Elemento * )malloc(L*sizeof(*A));

  // Elemento HEAD:
  H = A;         // Endereço do primeiro elemento -> H = A[0]
  H->chave = 0;  // Chave de HEAD, não de A[1]

  // Construindo a lista:
  A = constroE(A, L);  // Constrói A[1], A[2], ..., A[N-1]
  
  // Elemento TAIL:
  T = A;     // Salvando o último elemento A[N] = { }
  T->chave = 0;  // Atribuímos então uma chave
  T->prox = H;   // Depois estabelecemos a Condição Cíclica da lista

  // Conferindo HEAD e TAIL
  cout << "\nCONFERINDO os resultados:\n";
  cout << "End. de H = " << &H << endl;  // A[0], obs. q n há relação c A's
  cout << "H->prox = A2 = " << H->prox << endl;   // End. de A[2]
  cout << "T->prox = A1 = " << T->prox << endl;   // End. de A[1]
  cout << "(H+1)->prox = A3 = " << H->prox->prox << endl;  // End. de A[3]
  cout << "(T+1)->prox = A2 =" << T->prox->prox << endl;  // End. de A[2]
  cout << "(H+2)->chave = " << H->prox->prox->chave << endl; // Chave de A[3]
  cout << "(T+2)->chave = " << T->prox->prox->chave << endl; // Chave de A[2]

  // Definindo a chave de busca
  cout << "\n\tQUESTÃO PROPOSTA 1\n";
  cout << "\nDigite o valor da chave de busca: ";
  cin >> k;

  // Busca pela posição do elemento chave K
  while(T->chave != k){
    T--;  // Voltando desde o elemento A[N+1] = L+2
	p++;  // Somando a partir de 0
  }
  // Ajuste devido ao que foi representado anteriormente
  p = (L+2)-p;  // Por que voltou: Pra L+2=10: 7->3, 6->4 
  cout << "\nResultado:" << endl;
  cout << "O elemento com esta chave ocupa a " << p << "ª posição.\n"; 
  
  // SEGUNDA BUSCA
  p=0;         // Voltando a configuração original p=0
  T = A;       // Restaurando o ponteiro TAIL - calda 
  T->prox = H; // Não restaure a chave, apenas este atributo

  // Definindo a chave de busca
  cout << "\n\tQUESTÃO PROPOSTA 2\n";
  cout << "\nDigite o valor da chave de busca: ";
  cin >> k;

  // Busca pela posição do elemento chave K
  while(T->chave != k){
    T--;  // Voltando desde o elemento A[N+1] = L+2
	p++;  // Somando a partir de 0
  }
  // Ajuste devido ao que foi representado anteriormente
  p = (L+2)-p;  // Por que voltou: Pra L+2=10: 7->3, 6->4 
  cout << "\nResultado:" << endl;
  cout << "O elemento com esta chave ocupa a " << p << "ª posição.\n"; 

  cout << "\nFIM\n\n"; 
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste18.cc -o saida
