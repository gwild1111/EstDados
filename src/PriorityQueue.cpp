#include "PriorityQueue.hpp"

// Construtor
PriorityQueue::PriorityQueue() : firstElement(nullptr) {}

// Destrutor
PriorityQueue::~PriorityQueue() {
    // Libera a memória alocada para os nós
    Node* currElement = firstElement;
    while (currElement != nullptr) {
        Node* temp = currElement;
        currElement = currElement->nextNode;
        delete temp;
    }
}

// Método para criar um novo nó
Node* createNode(int priority, int value) {
    Node* newNode = new Node;
    newNode->priority = priority;
    newNode->content = value;
    newNode->nextNode = nullptr;
    return newNode;
}

// Método para adicionar um nó na lista com base na prioridade
void PriorityQueue::addNode(int priority, int value) {
    Node* newNode = createNode(priority, value);

    if (firstElement == nullptr || firstElement->priority > priority) {
        newNode->nextNode = firstElement;
        firstElement = newNode;
    } else {
        Node* currElement = firstElement;
        while (currElement->nextNode != nullptr && currElement->nextNode->priority <= priority) {
            currElement = currElement->nextNode;
        }
        newNode->nextNode = currElement->nextNode;
        currElement->nextNode = newNode;
    }
}

// Método para encontrar um nó dado um índice
Node* PriorityQueue::findNode(unsigned int index) const {
    Node* currElement = firstElement;
    for (unsigned int i = 0; i < index; ++i) {
        if (currElement == nullptr) {
            return nullptr; // Índice fora dos limites
        }
        currElement = currElement->nextNode;
    }
    return currElement;
}

// Método para remover um nó dado um índice
void PriorityQueue::remNode(unsigned int index) {
    if (firstElement == nullptr) {
        return;
    }
    if (index == 0) {
        Node* oldNode = firstElement;
        firstElement = firstElement->nextNode;
        delete oldNode;
        return;
    }

    Node* currNode = findNode(index - 1);
    if (currNode == nullptr || currNode->nextNode == nullptr) {
        return; // Índice fora dos limites
    }
    Node* oldNode = currNode->nextNode;
    currNode->nextNode = currNode->nextNode->nextNode;
    delete oldNode;
}

// Método para obter o valor de um nó dado um índice
int PriorityQueue::getNode(unsigned int index) const {
    Node* foundNode = findNode(index);
    if (foundNode != nullptr) {
        return foundNode->content;
    }
    return -1; // Índice fora dos limites
}

// Método para definir o valor de um nó dado um índice
void PriorityQueue::setNode(unsigned int index, int value) {
    Node* foundNode = findNode(index);
    if (foundNode != nullptr) {
        foundNode->content = value;
    }
}

// Método para contar o número de nós na lista
unsigned int PriorityQueue::countNodes() const {
    Node* currElement = firstElement;
    unsigned int count = 0;
    while (currElement != nullptr) {
        currElement = currElement->nextNode;
        count++;
    }
    return count;
}

// Método para exibir a lista
void PriorityQueue::showList() const {
    Node* currElement = firstElement;
    int i = 0;
    while (currElement != nullptr) {
        std::cout << "Valor: " << currElement->content << " Prioridade: " << currElement->priority << std::endl;
        currElement = currElement->nextNode;
        i++;
    }
    std::cout << "Lista com " << i << " elementos" << std::endl;
}

// Método para encontrar um valor na lista e retornar seu índice
unsigned int PriorityQueue::findVal(int value) const {
    Node* currElement = firstElement;
    unsigned int i = 0;
    while (currElement != nullptr && currElement->content != value) {
        currElement = currElement->nextNode;
        i++;
    }
    if (currElement == nullptr) {
        return -1; // Valor não encontrado
    }
    return i;
}
 