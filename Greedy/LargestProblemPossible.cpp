/*
Problem:-
Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits 
should be equals to 'S'.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains two space separated integers N and S, where N is the number of digits and 
S is the sum.
 
Output
Print the largest number that is possible.
If their is no such number, then print -1 
 
Constraints:

1 <= T <= 30
1 <= N <= 50
0 <= S <= 500
 
Example 
Input
2
2 9
3 20

Output 
90
992 

Expected Time Complexity: O(n)

Logic:-
> if (s is 0) or (s > 9*n) then it is impossible
> Now add 9 as a digit from left till s > 9 , as s becomes <9 copy as it and break.
> then print vector
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,s;
	    cin>>n>>s;
	    
      //Cases when not possible scenario
	    if(s == 0 || s > 9*n)
	    {
	        cout<<-1<<endl;
	        continue;
	    }
	    
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++)
	    {
          //if s>9 add to array and reduce s to s-9
	        if(s>9)
	        {
	            arr[i]=9;
	            s = s-9;
	        }
	        else
	        {
              //when s<9 is remaining copy same and break bcoz sum has becomes 0
	            arr[i]=s;
	            break;
	        }
	    }
	    
	    int ans;
      
      //print no from left to right
	    for(int i=0;i<n;i++)
	        cout<<arr[i];
	    cout<<endl;
	}
	return 0;
}


####################################---Using string---###########################################

//another way of doing using string
// T.C. O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    
	    if(s == 0 || s > 9*n){
	        cout<<-1<<endl;
	        continue;
	    }
	    
	    string str;
	    for(int i=0;i<n;i++){
	        if(s>9){
	            str += char(9 + '0'); 
	            s = s-9;
	        }
	        else{
              //do not break here bcoz you need to add zeros
	            str += char(s + '0');
	            s = 0;
	        }
	    }
	    cout<<str<<endl;
	}
	return 0;
}
