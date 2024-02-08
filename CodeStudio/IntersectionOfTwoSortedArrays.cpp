#include<iostream>
using namespace std;


// ================================================ Approach-I (Brute Force) ================================================
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
	vector<int> ans;
	vector<int> visited(m,0);

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr2[j] == arr1[i] && visited[j] == 0) {
				ans.push_back(arr2[j]);
				visited[j] = 1;
				break;
			}
			
			// No need for checking further as arrays are sorted
			if(arr2[j] > arr1[i]) break;
		}
	}

	return ans;
}
// TC : O(n*m)
// SC : O(m)


// ================================================ Approach-II (Optimal Approach) ================================================
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
	vector<int> ans;
	int i=0, j=0;	// 2 pointers

	while(i<n && j<m) {
		if(arr1[i] < arr2[j]) i++;
		else if(arr1[i] > arr2[j]) j++;
		else {
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}

	return ans;
}
// TC : O(n+m)
// SC : O(1)    [not using any extra space]