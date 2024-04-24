#include <cstdio>
#include <conio.h>
#include <vector>
#include <iostream>

void ex2() {
   float n1, n2, n3, n4, mf;
   int nFaltas;
   
   printf("Digite a nota do 1 bimestre: \n");
   scanf("%f", &n1); 

   printf("Digite a nota do 2 bimestre: \n");
   scanf("%f", &n2);
   
   printf("Digite a nota do 3 bimestre: \n");
   scanf("%f", &n3);
   
   printf("Digite a nota do 4 bimestre: \n");
   scanf("%f", &n4);
   
   printf("Digite seu numero de faltas: \n");
   scanf("%d", &nFaltas);
   
   mf = (n1 + n2 + n3 + n4) / 4;
   
   if(mf >= 7 && nFaltas <= 20) {
   	 printf("aprovado: media entre 7.0 e 10.0 e numero de faltas ate 20\n");
   }
   else if(mf >= 4 && mf <= 7 && nFaltas <= 20) {
   	 printf("exame final: media entre 4.0 e 7.0 e numero de faltas ate 20\n");
   }
   else {
   	 printf("reprovado: media abaixo de 4.0 ou numero de faltas maior que 20\n");
   }
   
   printf("media final: %f\n", mf);
   printf("numero de faltas: %d\n", nFaltas);
}

void ex3() {
   float a, b, c; 
   
   printf("Digite o comprimento do lado 1\n");
   scanf("%f", &a);
   
   printf("Digite o comprimento do lado 2\n");
   scanf("%f", &b);
   
   printf("Digite o comprimento do lado 3\n");
   scanf("%f", &c);
   
   if(a == b && a == c && b == c) {
   	  printf("O triangulo eh equilatero");
   } 
   else if((a == b && a != c) || (b == a && b != c) || (c == a && c != b)) {
   	  printf("O triangulo eh isosceles");
   } 
   else {
   	  printf("O triangulo eh escaleno");
   }
}

int ex4() {
    int CURRENT_YEAR = 2023;
    bool is_leap = false;
    std::string date;
    
    std::cout << "Digite a data separado por '/' no formato dd/mm/yyyy: ";
    std::cin >> date;

    std::vector<std::string> parts;
    size_t pos = 0;
    while ((pos = date.find("/")) != std::string::npos) {
    	// std::string::npos representa o maior valor possível para o tipo size_t. Representa "não encontrado" em uma busca. Fonte: https://cplusplus.com/reference/string/string/npos/#:~:text=npos%20is%20a%20static%20member,used%20to%20indicate%20no%20matches.
    	// std::cout << "Pos: " << pos << std::endl; // debug
    	// std::cout << "std::string::npos: " << std::string::npos << std::endl; // debug
        // std::cout << "date.substr(0, pos): " << date.substr(0, pos) << std::endl;; // debug
        parts.push_back(date.substr(0, pos));
          // substr(pos, len). fonte: https://cplusplus.com/reference/string/string/substr/
          // 1° argumento: posição inicial
          // 2° argumento: a quantidade (tamanho) de chars que você vai "pegar" depois da pos inicial 
          
        date.erase(0, pos + 1); // + 1 para tirar '/' também
        std::cout << "date: " << date << std::endl;
    }
    parts.push_back(date); // adiciona a parte restante, depois da ultima '/' (ano)

    int d, m, y;
    if (parts.size() == 3) {
        d = std::stoi(parts[0]);
        m = std::stoi(parts[1]);
        y = std::stoi(parts[2]);
    } else {
        std::cout << "Data invalida." << std::endl;
    }
    
    std::cout << "Dia: " << d << std::endl;
    std::cout << "Mes: " << m << std::endl;
    std::cout << "Ano: " << y << std::endl;    
    
    // 1. Checar o ano;
    if(y > CURRENT_YEAR) {
	   std::cout <<"O ano nao pode ser maior que o atual";
	   return 0;
	}
	
	//2. checar mes
	if(m < 1 || m > 12) {
	   std::cout << "O mes deve estar entre";
	   return 0;
	}
	
	// 3. checar se o ano é bissexto (anos bissextos são divisiveis por 4) 
	if(y % 4 == 0) {
		is_leap = true;
	}
	
	// 4. checar se o dia é valido no mes de fevereiro
	if(m == 2) {
	   if(is_leap) {
	   	    if(d > 29) {
	   	      std::cout << "O dia nao pode ser maior que 29 em ano bissexto.";
	          return 0;
		    }
	   } else {
		   	if(d > 28) {
		   	 std::cout << "O dia nao pode ser maior que 28 em ano NAO bissexto.";
		     return 0;
		    }
	   }
	   
	}
	
	// 5. checar se os dias nao ultrapassam o limite do mes
	if(m == 4 || m == 6 || m == 9 || m == 11) {
	   if(d > 30) {
	   	 std::cout << "o dia nao pode ser maior que 30";
	   	 return 0;
	   }
	}
    else {
        if(d > 31) {
	   	 std::cout << "o dia nao pode ser maior que 31";
	   	 return 0;
	    }	
	}
	
	std::cout << "A data eh valida \n";
	if(is_leap) {
		std::cout << "o ano inserido eh bissexto\n";
	}
	
	return 0;
}

int main() {
    printf("MENU\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("[1] Programa 1\n");
    printf("[2] Programa 2\n");
    printf("[3] Programa 3\n");

    int USER_OPTION = getch(); // nao precisar apertar enter para continuar a execução do código, já o scanf precisa. É usado geralmente para fazer interfaces de menu.

    if (USER_OPTION == '1') {
    	ex2();
	} 
	else if (USER_OPTION == '2') {
	    ex3();
	}
	else if (USER_OPTION == '3') {
	    ex4();
	}
    else {
        printf("Opcao invalida\n");
    }
    
    return 0;
}