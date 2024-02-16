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

ListNode* deleteKthNode(ListNode* head, int k) {
    // Edge case (LL is empty)
    if(head == NULL) return head;

    // Delete 1st Node 
    if(k == 1) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Delete middle Node (itself includes Tail deletion)
    int cnt = 0;
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

ListNode* deleteValue(ListNode* head, int value) {
    // Edge case (LL is empty)
    if(head == NULL) return head;

    // Delete 1st Node 
    if(head->val == value) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Delete middle Node (itself includes Tail deletion)
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp != NULL) {
        if(temp->val == value) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

ListNode* insertHead(ListNode* head, int value) {
    // Edge case (LL is empty)
    if(head == NULL) return new ListNode(value);

    ListNode* newNode = new ListNode(value, head);
    return newNode;
}   // TC : O(1)

ListNode* insertTail(ListNode* head, int value) {
    // Edge case (LL is empty)
    if(head == NULL) return new ListNode(value);

    ListNode* temp = head;
    while(temp->next != NULL) temp = temp->next;
    ListNode* newNode = new ListNode(value);
    temp->next = newNode;
    return head;
}

ListNode* insertKthNode(ListNode* head, int k, int value) {
    // Edge case (LL is empty)
    if(head == NULL) {
        if(k == 1) return new ListNode(value);
        else return head;
    }

    // Insert 1st Node 
    if(k == 1) {
        ListNode* newNode = new ListNode(value, head);
        return newNode;
    }

    // Insert middle Node (itself includes Tail insertion)
    int cnt = 0;
    ListNode* temp = head;
    while(temp != NULL) {
        cnt++;
        if(cnt == k-1) {
            ListNode* newNode = new ListNode(value, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}   // TC : O(N) in worst case

ListNode* insertBeforeValue(ListNode* head, int value, int eleVal) {
    // Edge case (LL is empty)
    if(head == NULL) return head;

    // Insert 1st Node 
    if(head->val == value) {
        ListNode* newNode = new ListNode(eleVal, head);
        return newNode;
    }

    // Insert middle Node (itself includes Tail insertion)
    ListNode* temp = head;  // To access node previous to node with given value
    while(temp->next != NULL) {    // Don't need to access last node
        if(temp->next->val == value) {
            ListNode* newNode = new ListNode(eleVal, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
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
    head = insertBeforeValue(head, 73, 4800);
    traverseLL(head);

    return 0;
}