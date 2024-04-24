#include <cstdio>
#include <math.h> 

void ex1()
{
   char a[8] = { 'p', 'e', 'i', 'i', 'm', 'r', 'a', 'r'};
   int  b[8] = { 5, 3, 4, 7, 1, 2, -1, 6};
   int i=0;
   while (i >= 0)
   {
   	printf("%c ", a[i]);
   	printf("%d \n", i); // sequencia: 0, 5, 2, 4, 1, 3, 7, 6. ao pegar o -1 (pos 6 do vetor b) o loop para. 
   	i = b[i];                  
   }
}

void ex2() 
{
	int i;
	int vet[50] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50}; 
	
    int lenght = sizeof(vet) / sizeof(vet[0]);
    for(i = 0; i < lenght; i++) {  
        printf("%d ** 2 = %f\n", vet[i], pow(vet[i], 2));
    }}

void ex3() 
{
   // é necessário usar long long int, se não vai ocorrer um overflow.
   long long int fibo[50], i; 
   long long int a = 1, b = 1, c = 1;
   
   for(i = 0; i < 50; i++) {
        fibo[i] = c;
    	c = a + b;
    	b = a;
    	a = c; 
	}
	
	// mostrando os valores 
	for(i = 0; i < 50; i++) {
		printf("%lld\n", fibo[i]);
	}
}

void ex4() {
	// para esse programa funcionar corretamente, é preciso tratar fatorial de 0, que por padrão é 1.
	// é preciso usar o tipo double, pois o fatorial de valores > 20 são muito grandes.
	double fat[50];
	double res;
	int i, j;
	
	for(i = 0; i <= 49; i++) {
		res = i; 
		if(res == 0) { // 0! = 1 
			res = 1; 
	    } 
	    else {
		    for(j = res; (j - 1) >= 1; j--) {
			    res *= (j - 1);	
			}	
		}
			  	
		fat[i] = res;
	}
	 
   	// mostrando os valores 
	for(i = 0; i <= 49; i++) {
		printf("fat de %d: %f\n", i, fat[i]);
	}
}

void ex5() {
	int vet[13] = {1, 1, 6, 6, 6, 6, 7, 7, 7, 1, 1, 1, 2};
    int bigest_seq, value_count, value_count_, length, i;
    
    bigest_seq = vet[0];
    length = sizeof(vet) / sizeof(vet[0]);
    for(i = 0; i <= length; i++) { 
       value_count_ = 1;
	   
	   while(vet[i + value_count_] == vet[i]) {
	   	value_count_ += 1;
	   }
	   
	   // se value_count_ de vet[i] for maior que o value_count global, substituiu o valor da váriavel global pelo value_count_ (value_count local)
	   if(value_count_ > value_count) {
	   	  value_count = value_count_;
	   	  bigest_seq = vet[i];
	   }
	}
	 
	printf("valor mais repetido: %d\n", bigest_seq);
	printf("quantidade: %d\n", value_count);
}

void ex6() {
	int vet[7] = {1, 1, 6, 6, 7, 7, 4};
	int seq_count, value_count, i, length; 
	bool is_in_seq;
	  
	length = sizeof(vet) / sizeof(vet[0]); 
    for(i = 0; i <= length; i++) { 
       value_count = 1;
	   
	   while(vet[i + value_count] == vet[i]) {
	    value_count += 1;
	   }
	   
	   is_in_seq = vet[i - 1] == vet[i]; // is_in_seq indica se o vet[i] está dentro de uma sequencia. Neste caso, não se deve incrementar seq_count
	   if(value_count > 1 && !is_in_seq) {
	   	seq_count += 1;
	   }
	}
	
	printf("seq_count: %d", seq_count);
}

int main() {
	ex6();
}