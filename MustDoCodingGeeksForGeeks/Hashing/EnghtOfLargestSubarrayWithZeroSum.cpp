/* Problem : Given an array of integers, find the length of the longest subarray with sum equals to 0
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
*/

#include <bits/stdc++.h>

int maxLen(vector<int> arr)
{
