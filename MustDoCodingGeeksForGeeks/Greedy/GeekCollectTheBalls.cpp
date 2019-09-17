/*
There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. The buckets on both 
roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end of the road which 
has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of 
the road).
The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads). Now 
you need to help Geek to collect the maximum number of balls.

Input:
The first line of input contains T denoting the number of test cases. The first line of each test case contains two integers N and M, 
denoting the number of buckets on road1 and road2 respectively. 2nd line of each test case contains N integers, number of balls in 
buckets on the first road. 3rd line of each test case contains M integers, number of balls in buckets on the second road.

Output:
For each test case output a single line containing the maximum possible balls that Geek can collect.

Constraints:
1<= T <= 1000
1<= N <= 10^3
1<= M <=10^3
0<= A[i],B[i]<=10^6

Example:
Input:
1
5 5
1 4 5 6 8
2 3 4 6 9

Output:
29

Explanation:

The path with maximum sum is (2,3,4)[5,6](9). Integers in [] are the buckets of first road and in () are the buckets of second road. 
So, max balls geek can collect is 29.
*/

//T.C O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    vector<int>arr1;
	    vector<int>arr2;
	    
      //take input in arr1 and arr2
	    for(int i=0;i<m;i++){
	        int in;
	        cin>>in;
	        arr1.push_back(in);
	    }
	    
	    for(int i=0;i<n;i++){
	        int in;
	        cin>>in;
	        arr2.push_back(in);
	    }
	    
	    int ans=0,sum1=0,sum2=0;
	    int i=0,j=0;
      
	    while(i<m && j<n)
	    {
	        if(arr1[i] < arr2[j])
	            sum1 += arr1[i++];
            else if(arr1[i] > arr2[j])
                sum2 += arr2[j++];
            else
            {
                int tmp = arr1[i];
                while(arr1[i] == tmp)
                    sum1 += arr1[i++];
                    
                while(arr2[j] == tmp)
                    sum2 += arr2[j++];
                    
                ans += max(sum1,sum2);
                sum1 = 0;
                sum2 = 0;
            }
	    }
	    
	    while(i < m)
	        sum1 += arr1[i++];
	    while(j < n)
	        sum2 += arr2[j++];
	        
	    ans += max(sum1,sum2);
	    cout<<ans<<endl;
	}
	return 0;
}
