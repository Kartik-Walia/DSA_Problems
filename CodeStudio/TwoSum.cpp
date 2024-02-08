#include<iostream>
using namespace std;


string read(int n, vector<int> book, int target) {
    int L=0, R=n-1;    // 2 pointers

    sort(book.begin(), book.end());     // O(NlogN)

    while(L <= R) {
        if(book[L] + book[R] > target) R--;
        else if(book[L] + book[R] < target) L++;
        else return "YES";
    }
    
    return "NO";
}

// TC : O(NlogN) + O(N)
// SC : O(1)    [not using any extra space]     [If you want to take in account the SC array we sorted, then it's going to be O(N)]