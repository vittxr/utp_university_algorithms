#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void mostra_quadrados(int num) {
 	int i;
	 
	for(int i = 1; i <= num; i++) {
	   cout << "O quadrado de " << i << " eh " << pow(i, 2) << endl;
  	}	
}

void mostra_numeros(int min, int max) {
	int i;

    if(min > max) {
    	cout << "o valor MIN nao pode ser maior que o valor MAX";
	}
	else {
		for(i = min; i <= max; i++) 
		{
			cout << i << "\n";	
		}
	}
}

void soma_numeros(int min, int max, int step) {
	int cont, soma;
    
    for(cont=min; cont<=max; cont+=step) {
      soma = soma + cont;
    }
    
    cout << soma;
}

void fill_list(float arr[], int length, int min, int max) { 
    int i;
    
    for (int i = 0; i <= length; i++) {
        arr[i] = min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
        cout << "posicao " << i << " preenchida com o valor " << arr[i] << endl;
    }
}

float aggr(float nums[], int length) {
	int i;
	float res;
	
	for(int i = 0; i <= length; i++) {
       	res += nums[i];
	}
	
	return res;
}

int aggr(int nums[], int length) {
	int res = 0; // pega lixo de memória, se nao inicializar com 0.
	
	for(int i = 0; i <= length; i++) {
       	res += nums[i];
	}
	
	cout << "soma dos elementos do vetor: " << res << endl;
	return res;
}

void mount_multi_table(int nums[], int target_value, int length) {
	cout << "tabuada do numero " << target_value << ": ";
	for(int i = 0; i <= length; i++) {
		nums[i] = target_value * i;
		cout << nums[i] << " "; 
	}
	
	cout << "\n";
}

int* sum_lists(int nums1[], int nums2[], int length) {
	int* res = new int[length];
    cout << "soma dos vetores: ";
	
	for(int i = 0; i <= length; i++) {
		res[i] = nums1[i] + nums2[i];
        cout << res[i] << " ";
	}
	
	cout << "\n";
	return res;
}

void show_biggest_value(int nums[], int length) {
	int biggest_value = 0; 
	
	for(int i = 0; i <= length; i++) {
		if(nums[i] > biggest_value) {
			biggest_value = nums[i];
		}
	}
	
	cout << "o maior valor da lista eh " << biggest_value << endl;
}

int main() {
	// ex1: 
	// mostra_quadrados(20);

	// ex2: 
	// mostra_numeros(50, 100);
	
	// ex3: 
	// soma_numeros(1, 20, 1);
	
	// ex4: 
	/*srand(static_cast<unsigned int>(time(nullptr))); // usado para gerar numeros realmente aleatórios
	float nums[10];
	fill_list(nums, 10, 1, 5);
	float res = aggr(nums, 10);
	cout << "Soma do vetor: " << res;*/
	
	// ex5: 
	int nums[10], nums2[10];
	// preenhce os valores com a tabuada de N (2° parâmetro da função é o N): 
	mount_multi_table(nums, 5, 10);
	mount_multi_table(nums2, 3, 10);
	
	// soma 2 vetores 
    int* nums3 = sum_lists(nums, nums2, 10);
	
	// soma os elementos de um vetor: 
	int nums_aggr = aggr(nums, 10);
	
	// mostra o maior valor: 
	int nums4[4] = {10, 124, 94, 39};
	show_biggest_value(nums4, 4);
}