#include<iostream>
#include<vector>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* convertArrayToLL(vector<int> &arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for(int i=1; i<arr.size(); i++) {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

void traverseLL(ListNode* head) {
    ListNode* temp = head;

    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int lengthLL(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;

    while(temp) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

bool searchLL(ListNode* head, int key) {
    ListNode* temp = head;

    while(temp) {
        if(temp->val == key) return true;
        temp = temp->next;
    }

    return false;
}

ListNode* deleteHead(ListNode* head) {
    // Edge case (LL has 0 element)
    if(head == NULL) return head;

    ListNode* temp = head;
    head = head->next;
    delete temp;     // OR free(temp)

    return head;
}

ListNode* deleteTail(ListNode* head) {
    // Edge case (LL has 0 or 1 element)
    if(head == NULL || head->next == NULL) return NULL;

    // Reach 2nd last element
    ListNode* temp = head;
    while(temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;

    return head;
}

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(7);

    ListNode* head = convertArrayToLL(arr);
    head = deleteTail(head);
    traverseLL(head);

    return 0;
}