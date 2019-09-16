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

Logic
> just find min in one loop
> Now for every pile see if arr[i] - min -k >0 means that much tiles need to be removed for that pile.
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
A pile can have many tiles
logic:
> Here the difference here is that we can remove all tiles which will in turn remove whole pile. Hence pile will not be considered
  but in previous case after removing all tiles you cannot remove pile hence its value is considered 0.
> First we need to sort piles
> Now consider a pile i. We loop at i means we have removed all piles BEFORE that. That pile and after that are remaining. It is 
  already sorted, means pile at i is least for current scenario. Now i to n-1 we need to to what we did in above program. First loop 
  accounts for that.
> In second loop we are doing what we did in program above.
> e.g 1 2 8 10   with k=3 -->ans should be 3 (removing 1 and 2)
  now for i = 2 means we are at 8, means we meant to remove 1 2 . before_i = 1 + 2
  after_i = before_i(1+2) + 0(because 10-8-3) >0 fails Hence no problwm
  0th iteration here is same as above program where piles were not allowed to be removed
  ith iteration means we are considering ith pile min. (Remember we have sorted everything before)
  
  Time Complexity - O(n^2)
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    vector<int> arr;
	    int n,k;
	    cin >> n >> k;
	    
            // taking inputs
	    for(int i=0;i<n;i++){
	        int in;
	        cin>>in;
	        arr.push_back(in);
	    }
	    
	    int ans = INT_MAX;
	    //before_i stores all removed piles and after_i stores where piles are present but extra tiles need to be removed keeping in mind i(min) 
	    //after_i stores total to removed in that scenario means after_i = before_i + (extra tiles to be removed not piles)
	    int before_i = 0,after_i = 0;
	    sort(arr.begin(),arr.end());
	    for(int i=0;i<n-1;i++)
	    {   
		//before_i here stores value sum till i-1 included.
	        after_i = before_i;    //
	        before_i += arr[i];   //update before_i to be used in next loop
	        //below loop account for piles which will not be removed.
		for(int j=n-1;j>i;j--)
	        {
	            if(arr[j]-arr[i]-k > 0)
	                after_i += arr[j]-arr[i]-k;
	        }
	        ans = min(ans,after_i);
	    }
	    
	    cout<<ans<<endl;
	}    
	return 0;
}


