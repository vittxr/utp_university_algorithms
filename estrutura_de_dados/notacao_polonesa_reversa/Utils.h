#include <algorithm>
#include <vector>
#if defined __GNUC__
    #include <cxxabi.h>                  
#endif

/************************************************************
* Funcao    : containsChar
* Descricao : checa se o array (vetor) contém o caractere especificado.
* Parametros: 1. arr - array (vetor) de caracteres.
*			  2. size - tamanho do array (vetor).
*			  3. charToFind - caractere a ser encontrado.
* Retorno   : booleano indicando se o caractere foi encontrado.
/************************************************************/
bool containsChar(const char* arr, int size, char charToFind) {
    return find(arr, arr + size, charToFind) != arr + size;
}

/************************************************************
* Funcao    : type
* Descricao : retorna o tipo de uma variável
* Parametros: 1. variable
* Retorno   : char* - o tipo da variável.
/************************************************************/
template <typename T>
char* type(const T& variable) {
    #if defined __GNUC__
        char* type = abi::__cxa_demangle(typeid(variable).name(), 0, 0, 0);
        return type;
    #endif
}

/************************************************************
* Funcao    : getFirstNumberIdx
* Descricao : retorna o primeiro index de um número dentro de uma string. Retorna -1 se nenhum número for encontrado.
* Parametros: 1. char arr[]
              2. int startIdx - o indice inicial do algoritmo de procura (search)
* Retorno   : int - o index do primeiro número da string.
/************************************************************/
int getFirstNumberIdx(char arr[], int startIdx = 0, bool reverseSearch = false) {
    
    for (int i = startIdx; arr[i] != '\0';) {
        if(arr[i] == ' ') continue;

        if(isdigit(arr[i])) {
            return i;
        }

        if(reverseSearch) {
            i--;
        } else {
            i++;
        }
    }
    
    
    return -1;
}

/************************************************************
* Funcao    : getLastNumberIdx
* Descricao : retorna o último index de um número dentro de uma string. Retorna -1 se nenhum número for encontrado.
* Parametros: 1. char arr[]
              2. int startIdx - o indice inicial do algoritmo de procura (search)
* Retorno   : int - o index do último número da string.
/************************************************************/
int getLastNumberIdx(char arr[], int startIdx = 0) {
    int lastNumberIdx = 0;

    for (int i = startIdx; arr[i] != '\0'; i++) {
        if(arr[i] == ' ') continue;

        if(isdigit(arr[i])) {
            lastNumberIdx = i; 
        }
    }
    
    return lastNumberIdx;
}

/************************************************************
* Funcao    : getCharIdx
* Descricao : retorna o index do charactere mais interno do array. Retorna -1 se o charactere não for encontrado.
* Parametros: 1. char arr[]
              2. char c
* Retorno   : int - index do charactere mais interno do array.
/************************************************************/
int getLastIdxOccurrenceOfChar(char arr[], char c) {
    int res = -1;
    for (int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == c) {
            res = i;
        }
    }
    return res;
} 

int getFirstIdxOccurrenceOfCharAfterIdx(char arr[], char c, int startIdx) {
    for(int i = startIdx; arr[i] != '\0'; i++) {
        if(arr[i] == c) {
            return i;
        }
    }
    return -1;
}

int getNumberOfOccurrencesOfChars() {
    
}