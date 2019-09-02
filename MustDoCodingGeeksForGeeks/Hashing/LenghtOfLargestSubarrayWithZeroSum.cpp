/* Problem : Given an array of integers, find the length of the longest subarray with sum equals to 0 (interviewbit-largest continuous sequence zero)
Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
The largest subarray with 0 sum is -2, 2, -8, 1, 7

Input: arr[] = {1, 2, 3}
Output: 0
There is no subarray with 0 sum

Input: arr[] = {1, 0, 3}
Output: 1

Takeaway : What is difference between subarray,subsequence,set.
subarray->ordered according to index and contiguous.
subsequence->ordered according to index and not contiguous.
subset->not ordered and not contiguous.
example arr[]={5,6,7,8}
subarray can be {5,6,7},{6,7,8},{5,6},etc
subsequence can be {5,7,8],{5,6,8},etc
subset can be {6,8,5},{7,5,6},etc.
contiguous subsequence is same as subarray. 
*/

#include <bits/stdc++.h>


/* Approach
- create a map to store cumulative sum and index i.
- cases:
    -if current elem is zero and max_elem is zero.
    -if sum becomes 0 means you can take whole len till i
    -if sum != 0 and sum is find already in map means sum zero can be formed between that range.(hash[sum] to i)
    -if sum is not present then insert in map. 
*/
vector<int> Solution::lszero(vector<int> &A) {
    int s = A.size();
    
    //when A is empty
    if(s == 0)
        return vector<int> ();
    
    //to store index to print subarray
    int a=-1;
    int b=-1;    
    
    //we use unordered map because we do not need sorting
    unordered_map<int,int> hash;
    
    
    int sum = 0;
    int max_len = 0;
    for(int i=0;i<s;i++)
    {
        //storing cumulative sum from 0 to i
        sum += A[i];
        
        //if present ith elem is 0 and max len is 0
        if(A[i] == 0 && max_len == 0)
        {    
            max_len = 1;
            //a,b will be equal
            a = i;
            b = i;
        }
        
        //if eventually sum becomes 0
        if(sum == 0)
        {
            //starting point will be zero ndex
            a = 0;
            max_len = i+1; //no need to check max_len previous val bcoz i+1 will be max length whole length
            b = i;
        }
        
        //if sum is already present means there is subarray whose sum can become 0
        if(hash.find(sum) != hash.end())
        {
            if(i - hash[sum] > max_len)
            {
                max_len = max(max_len,i - hash[sum]);
                b = i;
                a = hash[sum]+1;
            }
        }
        else//means sum is not present
            hash[sum] = i;
    }
    vector<int> ans;
    
    //if sum does not become 0 then return empty vector
    if(a == -1)
        return ans;
    
    //store values in ans
    for(int i = a;i<=b;i++)
        ans.push_back(A[i]);
    
    //return ans
    return ans;
}

########################################################################################
########################################################################################
########################################################################################
//if only length is to be found.

vector<int> Solution::lszero(vector<int> &A) {
    int s = A.size();
    
    //when A is empty
    if(s == 0)
        return vector<int> ();    
    
    //we use unordered map because we do not need sorting
    unordered_map<int,int> hash;
    
    int sum = 0;
    int max_len = 0;
    for(int i=0;i<s;i++)
    {
        //storing cumulative sum from 0 to i
        sum += A[i];
        
        //if present ith elem is 0 and max len is 0
        if(A[i] == 0 && max_len == 0)
            max_len = 1;
        
        //if eventually sum becomes 0
        if(sum == 0)
            max_len = i+1; //in this case i+1 will be max so no need to check with previous max_lenvalue
        
        //if sum is already present means there is subarray whose sum can become 0
        if(hash.find(sum) != hash.end())
            max_len = max(max_len,i - hash[sum]);
        else//means sum is not present
            hash[sum] = i;
    }
    
    //return ans
    return len;
}
















