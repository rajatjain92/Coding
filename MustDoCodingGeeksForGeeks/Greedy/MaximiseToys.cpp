/*
Given an array consisting cost of toys. Given an integer K depicting the amount with you. Maximise the number of toys you can have 
with K amount.
*/


//Simple solution to just sort and iterate 

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
    cin>>t;
    
    while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        
        int arr[n];
        
        for(int i=0;i<n;i++)
          cin>>arr[i];
        
        sort(arr,arr+n);
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            //if present element is > remaing sum break it
            if(arr[i] > sum)
                break;
            count++;
            calculate remaining sum
            sum = sum - arr[i];
        }
        cout<<count<<"\n";
        
    }
	return 0;
}
