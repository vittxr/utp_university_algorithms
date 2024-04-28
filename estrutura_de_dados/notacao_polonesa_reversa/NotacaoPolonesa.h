#include <iostream>
#include <cstring>
#include "Pilha.h"
#include "Utils.h" 

const char mathOperators[] = {'+', '-', '*', '/'};
const int mathOperatorsSize = 4;

/************************************************************
* Funcao    : converteParaNotacaoPolonesa
* Descricao : converte uma expressão em notação matemática para uma polonesa.
* Parametros: 1. char exp[] - expressão em notação matemática.
* Retorno   : char* - expressão em notação polonesa.
/************************************************************/
char* converteParaNotacaoPolonesa(char exp[]) {
    size_t expLength = strlen(exp); 
    int mostInternalLeftParenthesisIdx = 0;
    int mostInternalRightParenthesisIdx = -1;
    char newExp[expLength]; 

    for(int i = 0; exp[i] != '\0'; i++) {
        mostInternalLeftParenthesisIdx = getLastIdxOccurrenceOfChar(exp, '(');
        mostInternalRightParenthesisIdx = getFirstIdxOccurrenceOfCharAfterIdx(exp, ')', mostInternalLeftParenthesisIdx);

        if(mostInternalLeftParenthesisIdx != -1 && mostInternalRightParenthesisIdx != -1) {
            // newExp[0] = exp[mostInternalLeftParenthesisIdx + getFirstNumberIdx(exp, mostInternalLeftParenthesisIdx)];
            // newExp[2] = exp[mostInternalRightParenthesisIdx - getFirstNumberIdx(exp, mostInternalRightParenthesisIdx, true)];

            operatorsQty = getNumberOfOccurrencesOfChars(
                exp, 
                mathOperators, 
                mostInternalLeftParenthesisIdx, 
                mostInternalRightParenthesisIdx
            )

            char[] operators[operatorsQty]
            char[] numbers[operatorsQty + 1] // a quantidade de números é sempre (quantidade de operadores + 1).

            for(int i = mostInternalLeftParenthesisIdx; i <= mostInternalRightParenthesisIdx; i++) {
               if(exp[i] == ' ') continue;
               bool isOperator = containsChar(mathOperators, mathOperatorsSize, exp[i]);

               if(isOperator) {

               }
            }

            return converteParaNotacaoPolonesa(newExp);
        }
    }  

    if(mostInternalLeftParenthesisIdx == mostInternalRightParenthesisIdx) {
        int lastNumberIdx = getLastNumberIdx(exp); 

        for (int i = 0; exp[i] != '\0'; i++) {
            if(exp[i] == ' ') continue;

            bool isOperator = containsChar(mathOperators, mathOperatorsSize, exp[i]);
            if(isOperator) {
                int varTemp = exp[lastNumberIdx];
                exp[lastNumberIdx] = exp[i];
                exp[i] = varTemp;                
            }
        }
    } 

    return exp;
}

/************************************************************
* Funcao    : resolveNotacaoPolonesa
* Descricao : Resolve a expressão polonesa usando uma pilha.
* Parametros: 1. char exp[] - expressão polonesa.
* Retorno   : resultado do calculo.
/************************************************************/
float resolveNotacaoPolonesa(char exp[]) {
    float res;
    Pilha *p = criarPilha();

    for (int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == ' ') continue; 

        bool isOperator = containsChar(mathOperators, mathOperatorsSize, exp[i]);

        if(isOperator) {
            switch (exp[i]) {
                case '+':
                    push(p, pop(p) + pop(p));
                    break;
                
                case '-':
                    push(p, pop(p) - pop(p));
                    break;

                case '*':
                    push(p, pop(p) * pop(p));
                    break;

                case '/': 
                    push(p, pop(p) / pop(p));
                    break;

                default:
                    break;
            }
        } else {
            push(p, static_cast<float>(exp[i] - '0'));
        }
    }

    res = pop(p);
    liberarPilha(p);
    return res;
}

/************************************************************
* Funcao    : calculaNotacaoPolonesa
* Descricao : Calcula notação polonesa de uma expressão matemática utilizando pilha.
* Parametros: 1. char exp[] - expressão matemática.
* Retorno   : vetor contendo a notação polonesa e o resultado da expressão.
/************************************************************/
char* calculaNotacaoPolonesa(char exp[]) {
    exp = converteParaNotacaoPolonesa(exp);
    cout << "expressão matemática em notação polonesa reversa: " << exp << endl;
    
    char expPolonesa1[] = "3 4 + 2 *";
    char expPolonesa2[] = "3 2 + 9 *";
    printf("exp1 polonesa exemplo: %f", resolveNotacaoPolonesa(expPolonesa1));
    printf("exp2 polonesa exemplo: %f", resolveNotacaoPolonesa(expPolonesa2));

    return exp;
}

