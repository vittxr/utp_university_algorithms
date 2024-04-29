#include <iostream>
#include <cstring>
#include "Pilha.h"
#include "Utils.h" 

const char mathOperators[] = {'+', '-', '*', '/'};
const int mathOperatorsSize = 4;


char* cleanExp(const char* str) {
    size_t len = strlen(str);
    char* result = new char[len + 1];
    size_t idx = 0;

    for (size_t i = 0; i < len; i++) {
        if (str[i] != 'U' && str[i] != 'u') {
            result[idx++] = str[i];
        }
    }
    result[idx] = '\0';  
    return result;
}

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
    char* newExp = (char*)malloc(expLength * sizeof(char));

    for(int i = 0; exp[i] != '\0'; i++) {
        mostInternalLeftParenthesisIdx = getLastIdxOccurrenceOfChar(exp, '(');
        mostInternalRightParenthesisIdx = getFirstIdxOccurrenceOfCharAfterIdx(exp, ')', mostInternalLeftParenthesisIdx);

        if(mostInternalLeftParenthesisIdx != -1 && mostInternalRightParenthesisIdx != -1) {
            int operatorsQty = getNumberOfOccurrencesOfChars(
                exp, 
                mathOperators, 
                mathOperatorsSize,
                mostInternalLeftParenthesisIdx, 
                mostInternalRightParenthesisIdx
            );
            char operators[operatorsQty];
            char numbers[operatorsQty + 1]; // a quantidade de números é sempre (quantidade de operadores + 1).
            int operatorsIdx = 0; 
            int numbersIdx = 0;

            // resolve parênteses mais internos.
            for(int i = mostInternalLeftParenthesisIdx + 1; i <= mostInternalRightParenthesisIdx - 1; i++) {
               if(exp[i] == ' ') continue;
               bool isOperator = containsChar(mathOperators, mathOperatorsSize, exp[i]);

               if(isOperator) {
                 operators[operatorsIdx] = exp[i];
                 operatorsIdx++;
               } else {
                 numbers[numbersIdx] = exp[i];
                 numbersIdx++;
               }
            }

            // faz-se a nova expressão: 
            int j = 0;
            for(int i = 0; i <= operatorsQty + 1; i++) { 
                if(i % 2 != 0) {
                    newExp[i] = ' ';
                } else {
                    newExp[i] = numbers[j];
                    j++;
                }
            }

            for(int i = j + 1, k = 0; k <= operatorsQty; i++, j++) { 
                if(i % 2 != 0) {
                    newExp[i] = ' ';
                } else {
                    newExp[i] = operators[k]; 
                    k++;
                }
            }

            for(int i = 0; exp[i] != '\0'; i++) { 
                if(i < mostInternalLeftParenthesisIdx || i > mostInternalRightParenthesisIdx) {
                    newExp[j] = exp[i];
                    j++;
                }
            }


            return converteParaNotacaoPolonesa(newExp);
        }
    } 

    exp = cleanExp(exp);
    trimRightWhitespace(exp);
    if(mostInternalLeftParenthesisIdx == mostInternalRightParenthesisIdx) {

       for (int i = 0; exp[i] != '\0'; i++) { 
            if(exp[i] == ' ') continue;
            bool isOperator = containsChar(mathOperators, mathOperatorsSize, exp[i]);

            if(isOperator & i + 1 != strlen(exp)) {
                bool isOperator_ = containsChar(mathOperators, mathOperatorsSize, exp[i + 2]);
                bool isOperator__ = containsChar(mathOperators, mathOperatorsSize, exp[i - 2]);
                bool isOperator___ = i - 4 < 0 ? true : containsChar(mathOperators, mathOperatorsSize, exp[i - 4]);

                if(!isOperator_ & !(!isOperator__ & !isOperator___)) {
                    int varTemp = exp[i];
                    exp[i] = exp[i + 2];
                    exp[i + 2] = varTemp;
                }
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
* Funcao    : calculaEmNotacaoPolonesa
* Descricao : Calcula notação polonesa de uma expressão matemática utilizando pilha.
* Parametros: 1. char exp[] - expressão matemática.
* Retorno   : resultado da expressão.
/************************************************************/
float calculaEmNotacaoPolonesa(char exp[]) {
    exp = converteParaNotacaoPolonesa(exp);
    return resolveNotacaoPolonesa(exp);
}

