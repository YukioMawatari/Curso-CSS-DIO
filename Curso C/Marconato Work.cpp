#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Criar lista vazia
    void createEmptyList() {
        head = nullptr;
    }

    // Inserir no início da lista
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            head->next = head;  
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Inserir no final da lista
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Imprimir a lista
    void printList() {
        if (head == nullptr) {
            std::cout << "Lista vazia." << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    // Remover o primeiro elemento da lista
    void removeFirstElement() {
        if (head == nullptr) {
            std::cout << "Lista vazia." << std::endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
    }

    // Remover o último elemento da lista
    void removeLastElement() {
        if (head == nullptr) {
            std::cout << "Lista vazia." << std::endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            delete head;
            head = nullptr;
        } else {
            prev->next = head;
            delete temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    CircularLinkedList lista;
    lista.createEmptyList();

    int opcao, valor;

    while (true) {
        std::cout << "\nMENU\n";
        std::cout << "1 - Inserir no inicio da lista\n";
        std::cout << "2 - Inserir no final da lista\n";
        std::cout << "3 - Imprimir a lista\n";
        std::cout << "4 - Remover o primeiro elemento da lista\n";
        std::cout << "5 - Remover o último elemento da lista\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Digite o valor a ser inserido no início da lista: ";
                std::cin >> valor;
                lista.insertAtBeginning(valor);
                break;
            case 2:
                std::cout << "Digite o valor a ser inserido no final da lista: ";
                std::cin >> valor;
                lista.insertAtEnd(valor);
                break;
            case 3:
                std::cout << "Lista: ";
                lista.printList();
                break;
            case 4:
                lista.removeFirstElement();
                break;
            case 5:
                lista.removeLastElement();
                break;
            case 0:
                return 0;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
