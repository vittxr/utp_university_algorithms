#include <iostream>
#include <cstdlib> 

void modificaVetor(int n, int *v) {
	int biggest_value = 0;
	for(int i = 0; i <= n; i++) {
		if(v[i] > biggest_value) {
			biggest_value = v[i];
		} else {
			v[i] = 0;
		}
	}
}

int main() {
	int vetor []= {10, 5, 12, 8};
	int conta = 0, n = 4;
	ModificaVetor(n, vetor);
	cout << "Valor: ";
	for (conta = 0; conta < n; conta++)
		cout << " " << vetor[conta];
	cout << endl;
	system("pause");
	return 0;
}
