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

Node *deleteLast(Node *list){
    // Edge case (LL has 0 or 1 element)
    if(list == NULL || list->next == NULL) return NULL;

    // Reach 2nd last element
    Node* temp = list;
    while(temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;

    return list;
}