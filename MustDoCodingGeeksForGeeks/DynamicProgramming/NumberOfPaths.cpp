/* Problem : A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner
of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
*/

//Recursion 
#include <bits/stdc++.h>

int numberOfPaths(int m, int n) 
{ 
    // If either single row or single column is there then there is 1 path only
    if (m == 1 || n == 1) 
        return 1; 
  
    // for a cell its answer is ans of right cell + ans of down cell  or you can say to reach cell m,n you can come from m,n-1 and m-1,n 
    // no need to check if m or n becomes -ve because of above statement
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);  
} 

##############################################################################################################
##############################################################################################################
