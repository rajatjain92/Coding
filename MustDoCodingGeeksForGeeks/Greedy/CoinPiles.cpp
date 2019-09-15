/*
Given an array arr[] of size N and an integer K which means there are N piles of coins and the ith contains arr[i] coins. The task 
is to adjust the number of coins in each pile such that for any two piles if a be the number of coins in the first pile and b be 
the number of coins in the second pile then |a – b| ≤ K.

One can remove coins from different piles to decrease the number of coins in those piles but cannot increase the number of coins 
in a pile by adding more coins. Find the minimum number of coins to be removed in order to satisfy the given condition.

e.g. Input: arr[] = {2, 2, 2, 2}, K = 0
Output: 0
For any two piles the difference in the number of coins is ≤ 0.
So, no need to remove any coins.

Input: arr[] = {1, 5, 1, 2, 5, 1}, K = 3
Output: 2
If we remove one coin each from both the piles containing
5 coins, then for any two piles the absolute difference
in the number of coins is ≤ 3.

T.C. O(n)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    vector<int> arr;
	    int n,k;
	    cin >> n;
	    cin >> k;
	    int mini = INT_MAX;
	    
    //taking input and keeping min in track
	    for(int i=0;i<n;i++){
	        int in;
	        cin>>in;
	        arr.push_back(in);
	        mini = min(mini,in);
	    }
	    
	    int count = 0;
	    for(int i=0;i<n;i++){
	        int diff = arr[i]-mini;
	        if(diff > k)
	            count += (diff-k);
	    }
	    cout<<count<<endl;
	}    
	return 0;
}

//T.C = O(n)

#############################---Special case---######################################
/*
What if it is allowed to even remove a pile by completely all tiles in pile.
3 2
1 8 9

The o/p of online judge is 1. It should be 1 because by simple removing '1' from the list, the conditions are satisfied.
*/



