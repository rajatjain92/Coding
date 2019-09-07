/* Problem : (leetcode 62) A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below). 

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
//Exponential time complexity
#include <bits/stdc++.h>

int numberOfPaths(int m, int n) 
{ 
    // If either single row or single column is there then there is 1 path only
    if (m == 1 || n == 1) 
        return 1; 
  
    // for a cell its answer is ans of right cell + ans of down cell  or you can say to reach cell m,n you can come from m,n-1 and m-1,n 
    // no need to check if m or n becomes -ve because of above statement
    // you can reach m,n from m,n-1 and m-1,n  so numPaths of m-1,n + numPaths of m,n-1 will be total numPaths to m,n 
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);  
} 

##############################################################################################################
##############################################################################################################
//2-D Dynamic Programming
// T.C O(mn)  S.C  O(mn)

#include <bits/stdc++.h>

int uniquePaths(int m, int n) {
        int dp[m][n];
        //no need to m+1,n+1 size, whatever matrix we are given just map same and fill dp values    
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if there is single row or col ans is 1
                if(i==0 || j==0)
                    dp[i][j]=1;
                else 
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]; //paths to reach i,j-1 + i-1,j is same as paths to reach i,j
            }
        }
        return dp[m-1][n-1];
    }

##############################################################################################################
##############################################################################################################
//Mathematics Permutations and combinations
/*
This is a combinatorial problem and can be solved without DP. For mxn grid, robot has to move exactly m-1 steps down and 
n-1 steps right and these can be done in any order.

For the eg., given in question, 3x7 matrix, robot needs to take 2+6 = 8 steps with 2 down and 6 right in any order. 
That is nothing but a permutation problem. Denote down as 'D' and right as 'R', following is one of the path :-

D R R R D R R R

We have to tell the total number of permutations of the above given word. So, decrease both m & n by 1 and apply following formula:-
Total permutations = (m+n)! / (m! * n!
*/

#include <bits/stdc++.h>

int uniquePaths(int m, int n) {
        if(m==1 || n==1)
            return 1;
        
        m--;
        n--;
        
        //always consider m greater so that largest value is cancelled from numerator and denominator
        if(m<n)
            swap(m,n);
        
        long long int res = 1;
    
        //i will go from m+1 to m+n  and j will go from 1 to n.   m! in denominator is already cancelled
        for(int i=m+1,j=1;i<=m+n;i++,j++){
            res *= i;      //numerator
            res /= j;      //denominator
        }
        return res;
    }
