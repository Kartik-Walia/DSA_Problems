#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

int length(Node *head) {
	Node* temp = head;
    int cnt = 0;

    while(temp) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

// TC : O(N)