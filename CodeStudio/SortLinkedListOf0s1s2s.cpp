#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(NULL) {}
    Node(int x) : data(x), next(NULL) {}
    Node(int x, Node* next) : data(x), next(next) {}
};


// ============================================== Approach-I (Brute Force - Data Replacement) ==============================================
Node* sortList(Node *head){
    Node* temp = head;

    int cnt0=0, cnt1=0, cnt2=0;
    while(temp) {
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }

    temp = head;
    while(temp) {
        if (cnt0) {
            temp->data = 0;
            cnt0--;
        } else if(cnt1) {
            temp->data = 1;
            cnt1--;
        } else {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }

    return head;
}
// TC : O(N) + O(N)
// SC : O(1)


// ============================================= Approach-II (Optimal Approach - Link Changes) =============================================
Node* sortList(Node *head){
    // Edge case (LL is empty or LL has 1 node)
    if(!head || !head->next) return head;

    // Creating dummy nodes for 0s, 1s and 2s
    Node* dummy0 = new Node(-1);
    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);

    // Creating movers for 0s, 1s and 2s
    Node* zero = dummy0;
    Node* one = dummy1;
    Node* two = dummy2;

    Node* temp = head;
    while(temp) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if(temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    } 

    // Handling cases where we've only 0s, 1s or 2s, or any other combinations of them 
    zero->next = dummy1->next ? dummy1->next : dummy2->next;
    one->next = dummy2->next;
    two->next = NULL;

    Node* newHead = dummy0->next;

    // Deleting dummy nodes
    delete dummy0;
    delete dummy1;
    delete dummy2;

    return newHead;
}
// TC : O(N)    [Link changes after loop don't need to be counted]
// SC : O(1)    [using same nodes, not creating new nodes]