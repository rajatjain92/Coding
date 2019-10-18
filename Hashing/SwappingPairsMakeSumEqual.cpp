/*Problem : Given two arrays of integers, write a program to check if a pair of values (one value from each array) 
exists such that swapping the elements of the pair will make the sum of two arrays equal.

logic:
We are looking for two values, a and b, such that: 
sumA - a + b = sumB - b + a
    2a - 2b  = sumA - sumB
      a - b  = (sumA - sumB) / 2
      
 (sumA - sumB)/2 will be integer in our case so need to take care of float variable and all .
 
 algorithm:

1. Find sum1(sum of small array elements) ans sum2
  (sum of larger array elements). // time O(m+n)
2. Make a hashset for small array(here array1).
3. Calculate diff as (sum1-sum2)/2 which will be int in our case if true
4. Run a loop for array2
     for (int i equal to 0 to n-1)
       if (unordered_map contains (array2[i]+diff))
           print array2[i]+diff and array2[i]
           set flag  and break;
5. If flag is unset then there is no such kind of 
pair.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin >> t;            //test case
	while(t){
	    t--;
	    int n,m;
	    cin >> n >> m;
	    vector<int> a1;
	    vector<int> a2;
      
      //taking inputs
	    for(int i=0;i<n;i++){
	        int input;
	        cin>>input;
	        a1.push_back(input);
	    }
	    
	    for(int i=0;i<m;i++){
	        int input;
	        cin>>input;
	        a2.push_back(input);
	    }
	    
      //calculate sums
	    int sum1=0;
	    for(int i=0;i<n;i++)
	        sum1 += a1[i];
	        
	    int sum2=0;
	    for(int i=0;i<m;i++)
	        sum2 += a2[i];
	    
      //due to our logic
	    int diff = (sum1 - sum2)/2;
      
      //you can create unordered map just to see if element is present in array or not because making unorderd map for n elements
      //will take O(n)time and O(1) to lookup. For n lookups it will be O(n) total.
      //use binary search if you want to look just once.
	    unordered_map<int,int> map;
	    for(int i=0;i<n;i++){
	        map[a1[i]]++;
	    }
	    int flag = 0;
	    for(int i=0;i<m;i++){
	        int temp = a2[i] + diff;
	        if(map.find(temp)!=map.end())
	            flag=1;
	    }
	    
	    if(flag == 1)
	        cout<<1<<endl;
	    else
	        cout<<-1<<endl;
	    
	}
	return 0;
}
