/********************************************************************/
// Busca e Inserção em uma lista encadeada com PONTEIROS - COMPLETO!
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

// Método para busca de um elemento K
int buscaE(Elemento *E, Elemento *G, Elemento *S, int l, int Lm){
  // Elemento TAIL (S):
  S = E;         // Astribuindo o elemento variável S (T) ao elemento E (A)
  S->prox = G;   // Apontando o ponteiro prox de S (T) para G (H)

  // Buscando a posição do elemento chave l
  int q=0;
  while(S->chave != l){
    S--;  // Voltando desde o elemento A[N+1] = L+2
	q++;  // Somando a partir de 0
  }
  
  // Ajuste devido ao que foi representado neste programa
  q = (Lm+2)-q;  // Por que voltou: Pra L+2=10: 7->3, 6->4 

  // Restaurando o ponteiro TAIL:
  S = E;         // T = A;
  S->prox = G;   // T->prox = HEAD

  // Pronto!
  return q;
}

// Método para realizar a Inserção na posição R (Z)
Elemento* inserE(Elemento *E, int R, int Lm){
  Elemento *AE;
  Lm = Lm+1;  // Ajuste devido as operações E++ noutros métodos
  for(int i=Lm; i>R; --i){  // Varredura até a posição R
    AE = E-1;               // Alocação de valores
    E->chave = AE->chave;   // A7 <- A6 ... A6 <- A5 ...
    E--;                    // Elemento anterior
  }	
  // Inserindo a chave - Corrigir R devido a contagem de C++
  cout << "Digite a nova chave da " << R+1 << "ª posição: ";
  cin >> E->chave;
  // Voltando para a calda TAIL:
  for (int i=R; i<=Lm; ++i){ E++; };
  // Pronto!
  return E;
}

// Função principal
int main(){
  // Parâmetros e variáveis
  int L, M, k, p, z;  		

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

  // Realizando M buscas
  cout << "\nQuantas buscas vamos realizar: ";
  cin >> M;
  for (int i=1; i<=M; ++i){
    cout << "\n\tQUESTÃO PROPOSTA " << i << endl;
    cout << "Digite o valor da chave de busca: ";
    cin >> k;
	// Busca pela posição do elemento chave K
    p = buscaE(A, H, T, k, L);
	// Resultado:
    cout << "\nResultado:" << endl;
    cout << "O elemento com esta chave ocupa a " << p << "ª posição.\n"; 
  }

  // Inserindo na posição Z:
  cout << "\n\tINSERÇÃO DE UMA CHAVE NOVA\n";
  cout << "Digite a posição na qual será inserida a nova chave: ";
  cin >> z;
  // Realizando a inserção. Z-1 remete ao ponto correto,  devido ao 
  // sistema de contagem de C++, o primeiro elemento (1) = A[0]
  A = inserE(A, z-1, L);

  // Apresentando o resultado:
  A -= 2;  // Ajuste do ponteiro A -> devido a iteração
  // Apresentando as chaves de A[N] ... até ... A[1]
  int n = L+1;  // Foi inserida 1 chave
  for (int k=0; k<=L; k++){
    cout << "Chave A[" << n << "] = " << A->chave << endl;
	A--;  // Elemento anterior
	n--;  // Índice n deste elemento
  }

  cout << "\nFIM\n\n"; 
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste18.cc -o saida
