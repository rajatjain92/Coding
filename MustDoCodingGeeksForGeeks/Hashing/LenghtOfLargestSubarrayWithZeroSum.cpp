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

vector<int> Solution::lszero(vector<int> &A) {
    int s = A.size();
    if(s == 0)
        return vector<int> ();
    int a=-1;
    int b=-1;    
    unordered_map<int,int> hash;
    int sum = 0;
    int max_len = 0;
    for(int i=0;i<s;i++)
    {
        sum += A[i];
        if(A[i] == 0 && max_len == 0)
        {    
            max_len = 1;
            a = i;
            b = i;
        }
        if(sum == 0)
        {
            a = 0;
            max_len = i+1;
            b = i;
        }
        
        if(hash.find(sum) != hash.end())
        {
            if(i - hash[sum] > max_len)
            {
                max_len = max(max_len,i - hash[sum]);
                b = i;
                a = hash[sum]+1;
            }
        }
        else
            hash[sum] = i;
    }
    vector<int> ans;
    if(a == -1)
        return ans;
    for(int i = a;i<=b;i++)
        ans.push_back(A[i]);
    return ans;
}

