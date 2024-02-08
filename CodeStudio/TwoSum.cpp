#include<iostream>
using namespace std;


string read(int n, vector<int> book, int target) {
    int L=0, R=n-1;    // 2 pointers

    sort(book.begin(), book.end());

    while(L <= R) {
        if(book[L] + book[R] > target) R--;
        else if(book[L] + book[R] < target) L++;
        else return "YES";
    }
    
    return "NO";
}
