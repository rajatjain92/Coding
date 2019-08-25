/*
Problem : leetocode(451) Given a string, sort it in decreasing order based on the frequency of characters.
Example: Input: "tree"     ---  Output:"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

TakeAway: when sorting needed for values not keys use unordered map and write modified sort function.
          Learn about [&].
*/

#include <bits/stdc++.h>

string frequencySort(string s) {
        int string_size = s.size();
        //we need unordered map because we do not needto sort according to keys
        unordered_map<char,int> hash;
        
        //store frequency in hash of s
        for(int i=0;i<string_size;i++)
            hash[s[i]]++;
        
        //we have unordered map need to sort by values not keys
        //[&] means store all variables through reference
        //logic is a > b only when its frequency is more 
        //or if there frequencies are same then then a should appear before b
        sort(s.begin(),s.end(),[&](char a,char b){
            return (hash[a] > hash[b] || (hash[a]==hash[b] && a<b));
        });
        return s;
        
    }
