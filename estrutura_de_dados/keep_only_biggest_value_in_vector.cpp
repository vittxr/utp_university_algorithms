#include <iostream>
#include <cstdlib> 

using namespace std;

void modificaVetor(int n, int *v) {
    int biggest_value = 0;

    for(int i = 0; i < n; i++) {
        if(v[i] > biggest_value) {
            biggest_value = v[i];
        } 
    }

    for(int i = 0; i < n; i++) {
        if(v[i] != biggest_value) {
            v[i] = 0;
        }
    }
}


int main() {
	int vetor []= {10, 5, 12, 8};
	int conta = 0, n = 4;
	modificaVetor(n, vetor);
	cout << "Valor: ";
	for (conta = 0; conta < n; conta++)
		cout << " " << vetor[conta];
	cout << std::endl;
	system("pause");
	return 0;
}
