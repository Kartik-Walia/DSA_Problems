#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// =========================================== Approach-I (Brute Force - Data Replacement) ===========================================
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Edge case (LL is empty or LL has only 1 element)
        if(!head || !head->next) return head;

        vector<int> oddEven;

        // Adding Odd elements in vector
        ListNode* tempOdd = head;
        while(tempOdd != NULL && tempOdd->next != NULL) {
            oddEven.push_back(tempOdd->val);
            tempOdd = tempOdd->next->next;
        }
        // In case of odd length linked list you might skip the last node
        if(tempOdd) oddEven.push_back(tempOdd->val);

        // Adding Even elements in vector
        ListNode* tempEven = head->next;
        while(tempEven != NULL && tempEven->next != NULL) {
            oddEven.push_back(tempEven->val);
            tempEven = tempEven->next->next;
        }
        // In case of even length linked list you might skip the last node
        if(tempEven) oddEven.push_back(tempEven->val);

        // Replacing data of LL with Odd & Even elements
        ListNode* temp = head;
        int i=0;
        while(temp != NULL) {
            temp->val = oddEven[i++];
            temp = temp->next;
        }

        return head;
    }
};
// TC : O(N/2) + O(N/2) + O(N)
// SC : O(N)    [using external vector to store all elements]


// ================================================= Approach-II (Better Approach) =================================================
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* mover = dummyNode;
        ListNode* temp = head;
        ListNode* temp1 = head;

        // Adding odd nodes
        int cnt=0;
        while(temp != NULL) {
            cnt++;
            if(cnt % 2 != 0) {
                ListNode* newNode = new ListNode(temp->val);
                mover->next = newNode;
                mover = mover->next;
            }
            temp = temp->next;
        }

        // Adding even nodes
        cnt=0;
        while(temp1 != NULL) {
            cnt++;
            if(cnt % 2 == 0) {
                ListNode* newNode = new ListNode(temp1->val);
                mover->next = newNode;
                mover = mover->next;
            }
            temp1 = temp1->next;
        }

        return dummyNode->next;
    }
};
// TC : O(N) + O(N)
// SC : O(N)    [using additional space to create new nodes for the odd and even linked lists]


// ================================================== Approach-III (Optimal Approach) ==================================================
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Edge case (LL is empty or LL has only 1 element)
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;    // Save the head of the even list

        // even is always ahead of odd, so all your checks should be done on even
        while(even && even->next) {
            // Linking all odds
            odd->next = odd->next->next;
            odd = odd->next;
            // Linking all evens
            even->next = even->next->next;
            even = even->next;
        }

        // Linking last odd to first even
        odd->next = evenHead;

        return head;
    }
};
// TC : O(N/2)x2    [You're doing 2 link changes]
// SC : O(1)