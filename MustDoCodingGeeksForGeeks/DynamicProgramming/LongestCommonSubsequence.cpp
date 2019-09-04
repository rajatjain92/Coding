/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without 
changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). 
A common subsequence of two strings is a subsequence that is common to both strings.
        
If there is no common subsequence, return 0.
Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3

Recursive solution:
ith index and jth index, let us start from last of string s1,s2
if char's are same reduce both length , if not try both cases of skipping each char
lcs(i,j) = if(s1[i]==s2[j]) ---> 1 + lcs(i-1,j-1);
            else max(lcs(i,j-1),lcs(i-1,j))
*/
        
# include <bits/stdc++.h>

int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.length();
        int s2 = text2.length();
        
        //increase length by 1 bcoz 
        int dp[s1 + 1][s2 + 1];
        for(int i=0;i<=s1;i++){
            for(int j=0;j<=s2;j++){
                //means filling row 0 and col 0.
                if(i==0 || j==0)
                    dp[i][j]=0;                                 //length 0 and i ,length 0 and j
                else if(text1[i-1]==text2[j-1])                 //if elements are same increase by subsequence by 1
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s1][s2];
    }



############################################################################################
############################################################################################

void PrintLcs(string text1,string text2,int dp[][]){
        int x = text1.length();
        int y = text2.length();
        string result;
        while(x!=0 && y!=0{
             if(text[x-1]==text2[y-1]){
                     result += text[x-1];
                     x--;
                     y--;
             }
             else if(text1[x][y] == text2[x-1][y])
                     x=x-1;
             else
                     y=y-1;
        }
              return result;
}
