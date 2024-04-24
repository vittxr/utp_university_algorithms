#include <cstdio>

int main() {
	// ex 5: 
	// int vox = 10;
	// int *invox = &vox;
	
	// printf("Comparações: %d", invox == *vox); -> error
	// printf("Comparações: %d", vox == &invox); -> error
 	// printf("Comparacao: %d\n", vox == *invox); // -> true
	// printf("Comparacao: %d\n", invox == &vox); // -> true
	
	// ex6:
	// int j, *ptrj;
	// ptrj = &j;
    // *ptrj = 3;
    // printf("j = %d; *ptrj = %d; ptrj = %p", j, *ptrj, ptrj);
    
    // ex8: 
    // int i=3, j=5;
    // int *p, *q;
    // p= &i;    
	// q= &j;

	// printf("\n%d", **&p);
	// printf("\nres: %d", 3*-*p);
	// printf("\nres: %d", (*q)+7);
	// printf("\nres: %d", 3*-*p/(*q)+7);
	
	//int i=5, *p;
	//p= &i;
	//printf("%u %d %d %d %d", p, *p+2, **&p, 3**p, **&p+4);
	
	// ex10: 
	int i = 10, j = 20;
	int *p, *q;
	
	p = &i;  
	q = &j;
	
	printf("%d", (*p)++);
	i = (*p)++ + *q;
	
	printf("\n%d", i);
}