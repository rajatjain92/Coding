/*
Problem : Given a string, sort it in decreasing order based on the frequency of characters.
Example:
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

#include <bits/stdc++.h>

string frequencySort(string s) {
        int string_size = s.size();
        //we need 
        unordered_map<char,int> hash;
        
        for(int i=0;i<string_size;i++)
            hash[s[i]]++;
        
        sort(s.begin(),s.end(),[&](char a,char b){
            return (hash[a] > hash[b] || (hash[a]==hash[b] && a<b));
        });
        return s;
        
    }
