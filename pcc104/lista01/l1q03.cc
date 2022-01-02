//////////////////////////////////////////////////////////////////////
// Programa pra implementar o algoritmo de Euclides -> L1/Q3 
// Davi Neves - UFOP - DECOM - PPGCC - Agosto de MM21
//////////////////////////////////////////////////////////////////////
// Importando bibliotecas
#include <iostream>

// Definindo prefixos
using namespace std;

// Função para a iteração de Euclides
int gcd(int n, int d){    // Entrada, numerador e denominador
		int r;            // Resto da divisão
		while (d != 0){
				r = d;       // Processo de Euclides
				d = n % d;
				n = r;
		}
		return n;			// Último resto não nulo
}

// Função principal
int main(){
		int a, b, A, B;
		cout << "\n\tMaior Divisor Comum de A e B\n";
		// Entrada dos Dados
        cout << "\nDigite o valor de A: ";
		cin >> a;
        cout << "\nDigite o valor de B: ";
		cin >> b;
		// Operações requeridas
		A = a;   // Armazenando os valores originais
		B = b;
		a = gcd(a, b);  // Determinando o MDC
		// Resultado
		cout << "\nO MDC de "<< A << " e " << B << " = " << a << endl;
		return 0;
}
//////////////////////////////////////////////////////////////////////
// Para compilar: g++ l1q03.cc -o saida
// Para executar: ./saida
// FIM
