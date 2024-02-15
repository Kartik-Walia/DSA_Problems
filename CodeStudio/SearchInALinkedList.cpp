#include<iostream>
using namespace std;


template <typename T>
class Node {
public:
    int data;
    Node<T>* next;
    Node() : data(0), next(NULL) {}
    Node(T data) : data(data), next(NULL) {}
    Node(T data, T* next) : data(data), next(next) {}
};

int searchInLinkedList(Node<int> *head, int k) {
    Node<int>* temp = head;

    while(temp) {
        if(temp->data == k) return 1;
        temp = temp->next;
    }

    return 0;
}

// TC : O(N)