
# include <bits/stdc++.h>

int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.length();
        int s2 = text2.length();
        
        int dp[s1 + 1][s2 + 1];
        for(int i=0;i<=s1;i++){
            for(int j=0;j<=s2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s1][s2];
    }
