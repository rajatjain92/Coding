/*
Problem:-
In a candy store there are N different types of candies available  and the prices of all the N different types of candies are provided 
to you. You are now provided with an attractive offer.
You can buy a single candy from the store and get atmost K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to tell what is the minimum amount of money you have to spend to buy all 
the N different candies. Secondly, you have to tell what is the maximum amount of money you have to spend to buy all the N different 
candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
 

Input  
The first line of the input contains T the number of test cases. Each test case consists of two lines. The first line of each test 
case contains the values of N and K as described above.  Then in the next line N integers follow denoting the price of each of 
the N different candies.

Example:
Input    
 1
 4  2
 3 2 1 4

Output
 3 7

Explanation
As according to the offer if you but one candy you can take atmost two more for free.
So in the first case you buy the candy which costs 1 and take candies worth 3 and 4 for free, also you buy candy worth 2 as well.
So min cost = 1+2 =3.
In the second case I buy the candy which costs 4 and take candies worth 1 and 2 for free, also I  buy candy worth 3 as well.
So max cost = 3+4 =7.

T.C. = O(nlogn)
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    vector<int>arr;
	    for(int i=0;i<n;i++)
	    {
	        int input;
	        cin>>input;
	        arr.push_back(input);
	    }
	    
	    //sorting is necessary
	    sort(arr.begin(),arr.end());
	
	    int min=0,max=0;
		
	    //groups of k+1 will be formed. k free candies + 1 for which we pay
	    int groups = ceil((float)n/(float)(k+1));
	    
	    for(int i=0;i<groups;i++)
	    {
	        min += arr[i];
	        max += arr[n-1-i];
	    }
	    cout<<min<<' '<<max<<endl;
	}
	return 0;
}
