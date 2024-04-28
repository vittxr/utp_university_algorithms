#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "NotacaoPolonesa.h"

using namespace std;

int main() {
	// As operaçoes devem ter espaços (' ') como delimitadores obrigatoriamente! Leva-se em consideração ao convertê-lá para expressão polonesa reversa.
	char exp[] = "2 * (3 + 4)"; // 3 4 + 2 *
	char exp2[] = "2 * 3 + 4"; // 2 3 4 * +
    char exp3[] = "2 + (2 * 2 + (2 * 2))"; // 2 2 * 2 2 * 2 + + -> 4 2 2 * 2 + + -> 4 4 2 + + -> 8 2 + -> 10 
    char exp4[] = "2 + ((4 + 2) / 2)"; // 4 2 + 2 / 2 + -> 6 2 / 2 + -> 3 2 + -> 5
	char exp5[] = "2 * (1 + 2 + 7)" // 1 2 7 + + 2 * -> 3 7 + 2 * -> 10 2 * -> 20

	calculaNotacaoPolonesa(exp);
	
	return 0;
}
