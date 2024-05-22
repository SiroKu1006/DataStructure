#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    Node(const T& item, Node<T>* nextPtr = nullptr, Node<T>* prevPtr = nullptr) 
        : data(item), next(nextPtr), prev(prevPtr) {}
    Node() : next(nullptr), prev(nullptr) {}
    
    T getData() const { return data; }
    Node<T>* getNext() const { return next; }
    Node<T>* getPrev() const { return prev; }
    
    void setNext(Node<T>* ptr) { next = ptr; }
    void setPrev(Node<T>* ptr) { prev = ptr; }
    
private:
    T data;
    Node<T> *next, *prev;
};

template <class T>
class DoubleLinkedList {
public:
    DoubleLinkedList() : first(nullptr), last(nullptr) {}
    
    bool IsEmpty() const { return first == nullptr; }
    
    void Print() {
        Node<T>* current = first;
        while (current != nullptr) {
            cout << current->getData();
            current = current->getNext();
        }
        cout << "\n";
    }
    Node<T>* getFirst() const { return first; }
    Node<T>* getLast() const { return last; } 
    void PrintReverse() {
        Node<T>* current = last;
        while (current != nullptr) {
            cout << current->getData();
            current = current->getPrev();
        }
        cout << "\n";
    }
    
    void addFront(const T& item) {
        Node<T>* newNode = new Node<T>(item, first);
        if (first != nullptr) {
            first->setPrev(newNode);
        }
        first = newNode;
        if (last == nullptr) {
            last = first;
        }
    }
    
    void addBack(const T& item) {
        Node<T>* newNode = new Node<T>(item, nullptr, last);
        if (last != nullptr) {
            last->setNext(newNode);
        }
        last = newNode;
        if (first == nullptr) {
            first = last;
        }
    }
    

private:
    Node<T> *first, *last;
};  