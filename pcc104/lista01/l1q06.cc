/////////////////////////////////////////////////////////////////////
// Programa para implementar os códigos referentes à questão 06
// Davi Neves - DECOM/PPGCC - UFOP - Agosto de 2021 
/////////////////////////////////////////////////////////////////////
// Importando bibliotecas
#include <iostream>

// Definindo os prefixos
using namespace std;

// Função para realizar a checagem da prioridade
int check(int D){		// Dado D de entrada
		int P;			// Resultado da prioridade
		if (D > 60) {
				P = 1;	// Prioridade = SIM (1)
		}else{
				P = 0;  // Prioridade = NÃO (0)
		}
		return P;       // Retorno
}

// Função Principal - Onde a mágica acontece
int main(){
		cout << "\n\tQUESTÃO 6\n" << endl;
		
		// Parâmetros e Variáveis
		int N = 20;	  // Número máximo de pessoas na fila
		int i, k=0, j=0; // Índices para as filas
		int PF[N], SF[N];   // Arrays Não Ordenados
		// Entrada de valores - Array Não Ordenado
		int V[N] = {18, 62, 45, 38, 67, 72, 59, 81, 24, 40}; 
		// Inserindo os valores na Fila
		for (int i=0; i<10; i++){
				int P = check(V[i]);
				if (P == 1) {
						SF[j] = V[i];
						j += 1;
				} else {
						PF[k] = V[i];
						k += 1;
				}
		}
		// First Fila - Primeira Fila
		cout << "\nPrimeira Fila:" << endl;
		int t = j+k;  // Total de Pessoas na fila
		int FF[N];    // Arranjo da Fila Final
		for (i=0; i<j; i++){ FF[i] = SF[i]; }   // Ajustando
		for (i=j; i<t; i++){ FF[i] = PF[i-j]; } // Resultado
		for (i=0; i<t; i++){ cout << FF[i] << endl; } // Print

		// Entrada de um valor especial
		int NF[N], UF[N];
		int D, s;
		cout << "\nDigite o valor da entrada D: ";
		cin >> D;
		// Quantas pessoas já sairam da fila?
		cout << "\nNesse instante, quantos sairam?\n";
		cin >> s;
		// Primeiro vamos inserir D, pra analisar a complexidade:
		int P = check(D);
		if (P == 1){
				for (i=0; i<j; i++){ NF[i] = FF[i]; }
				NF[i] = D;
				for (i=j; i<t; i++){ NF[i+1] = FF[i]; }
		} else { 
				for (i=0; i<t; i++) { NF[i] = FF[i]; }
			    NF[i] = D;
		}
	    // Agora vamos suprimir as saídas
        int n = t-s+1;
		for (i=0; i<n; i++){ UF[i] = NF[i+s]; }
		// Resultado
		cout << "\nÚLTIMA FILA:" << endl;
		for (i=0; i<n; i++){ cout << UF[i] << endl; } // Print
}
/////////////////////////////////////////////////////////////////////
// Para compilar: g++ l1q06.cc -o saida
// Para executar: ./saida
// FIM
