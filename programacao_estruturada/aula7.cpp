#include <cstdio>

void ex1() {
  int x = 9, y = 0;
  int contX, contY;
  
  do {
  	y = (x % 2) + 10 * y;
  	x = x / 2;
  	printf("x = %d, y = %d\n", x, y);
  	contX = contX + 1;
  } while (x);
  
  while(y) {
  	x = y % 100; 
  	y = y / 10;
  	printf("x %d, y = %d \n", x, y);
  	contY = contY + 1;
  }
  
  printf("Primeira estrutura de repeticao: %d\n", contX); // 4 vezes
  printf("Segunda estrutura de repeticao: %d\n", contY); // 4 vezes
}

void ex2() {
	// se n = 7, o número de colunas a aparecer é 7.
	// se j <= 10, então o número de linhas a aparecer vai até 10.
	int i, j, n;
	n = 4; 
	for (i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
			printf("%3d", j * i);
		}
		printf("\n");
	}
}

void ex3() {
	int sum, i; 
	
	for(i = 1; i <= 10; i++) {
		if(i % 2 == 0) {
			sum = sum + i;
		}
	}
	
	printf("sum: %d", sum);
}

void ex4() {
	float x, res; 
	int y, i;
	
	printf("digite o valor de x:\n");
	scanf("%f", &x);
	
	printf("digite o valor de y:\n");
	scanf("%d", &y);
	
	res = x;
	for(i = 2; i <= y; i++) {
		res = res * x;
	}
	printf("%f ** %d = %f", x, y, res);
}

void ex5() {
	int i, x, res;
	
	printf("digite o valor de x: \n");
	scanf("%d", &x);
	
	res = x;
	for(i = x; (i - 1) >= 1; i--) {
		res *= (i - 1);
	}
	
    printf("fatorial: %d", res);
}

void ex6() {
	int i, n, sum;
	int a = 1, b = 1, c = 1;
	
    printf("digite o valor da sequencia fibonnaci: \n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
    	printf("%d \n", c);
    	
    	if(c % 2 == 0) {
    		sum += c;
		}
		
    	c = a + b;
    	b = a;
    	a = c; 
	}
	
	printf("Soma dos valores pares de fibonacci: %d", sum);
}

int main() {
	// ex1();
	// ex2();
	// ex3();
	// ex4();
	// ex5();
	ex6();
}