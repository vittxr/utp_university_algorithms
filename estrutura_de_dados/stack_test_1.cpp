#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Pilha {
    Node* top;
};

Pilha* criarPilha() {
    Pilha* pPilha = new Pilha;
    pPilha->top = nullptr;
    return pPilha;
}

void push(Pilha* pPilha, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = pPilha->top;
    pPilha->top = newNode;
}

int pop(Pilha* pPilha) {
    if (pPilha->top == nullptr) {
        cerr << "Erro: Pilha vazia!" << endl;
        return -1; // Return a default value or handle the error as needed
    }
    Node* temp = pPilha->top;
    int poppedValue = temp->data;
    pPilha->top = temp->next;
    delete temp;
    return poppedValue;
}

int verTopo(Pilha* pPilha) {
    if (pPilha->top == nullptr) {
        cerr << "Erro: Pilha vazia!" << endl;
        return -1; // Return a default value or handle the error as needed
    }
    return pPilha->top->data;
}

int main() {
    Pilha* pPilha = criarPilha();
    push(pPilha, 4);
    push(pPilha, 5);
    push(pPilha, 2);
    push(pPilha, pop(pPilha) + pop(pPilha));
    push(pPilha, (verTopo(pPilha) % 2 == 0 ? pop(pPilha) - pop(pPilha) : pop(pPilha) + pop(pPilha)));
    cout << "Valor calculado: " << pop(pPilha) << endl; // 11
    delete pPilha;
    system("pause");
    return 0;
}
