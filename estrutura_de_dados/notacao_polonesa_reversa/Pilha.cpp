#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "NotacaoPolonesa.h"

using namespace std;

int main() {
	// OBS: As operaçoes devem ter espaços (' ') como delimitadores obrigatoriamente! Leva-se em consideração ao convertê-lá para expressão polonesa reversa.
	char exp[] = "2 * (3 + 4)"; // 3 4 + 2 *
	char exp2[] = "2 * 3 + 4"; // 2 3 * 4 +
	char exp3[] = "9 * 7 + (4 + 3)"; // 2 3 * 4 +
    char exp4[] = "2 + (2 * 2 + (2 * 2))"; // 2 2 * 2 2 * 2 + + -> 4 2 2 * 2 + + -> 4 4 2 + + -> 8 2 + -> 10 
    
	cout << "resultado exp: " << calculaEmNotacaoPolonesa(exp) << endl; // funciona 
	cout << "resultado exp 2: " << calculaEmNotacaoPolonesa(exp2) << endl; // funciona 
	cout << "resultado exp 3: " << calculaEmNotacaoPolonesa(exp3) << endl; // funciona 
	cout << "resultado exp 4: " << calculaEmNotacaoPolonesa(exp4) << endl; // não funciona 

    // a expressão polonesa foi pensada um pouco diferente. Pensei primeiro em converter da expressão matemática para polonesa e foi mais fácil resolver calculando dois números sequências, usando seu próximo operador. Diretamente, passar uma expressão com diversos números e operadores como "2 2 4 * /" não irá funcionar, pois eu fiz a função trabalhar convertendo da expressão matemática para "2 2 * 4 /"
    char exp5[] = "1 3 * 4 +"; // res: 7
	char exp6[] = "3 4 + 2 *"; // res: 14

	cout << "resultado exp 5: " << resolveNotacaoPolonesa(exp5) << endl; // funciona 
	cout << "resultado exp 6: " << resolveNotacaoPolonesa(exp6) << endl; // funciona 

	return 0;
}
