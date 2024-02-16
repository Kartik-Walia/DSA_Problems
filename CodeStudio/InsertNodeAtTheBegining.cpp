#include<iostream>
using namespace std;


class Node {
public:
    int val;
    Node* next;

    Node() : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

Node* insertAtFirst(Node* list, int newValue) {
    // Edge case (LL is empty)
    if(list == NULL) return new Node(newValue);

    Node* newNode = new Node(newValue, list);
    return newNode;
}