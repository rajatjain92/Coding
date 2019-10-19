/*
Problem : 151. Reverse Words in a String

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

logic:
> take 2 iterators to track word
> read about substring function in c++

*/
#include <bits/stdc++.h>

string reverseWords(string s) {
        string res;
        int start_word = 0;
        int end_word = 0;
        int len = s.size();
        
        for(end_word = 0;end_word < len;end_word++){
            if(s[end_word] == ' '){
                if(end_word > start_word)
                    res = s.substr(start_word,end_word - start_word) + ' ' + res;
                //this line is to be implemented every time.
                //if white spaces at start of line both pointers will move at same point
                //after we have attached the word change start word
                start_word = end_word + 1;
            }
            else if(end_word == len-1)  //check if you are at the end of string, here we use len-1 but below we use len - start_word
               res = s.substr(start_word,len - start_word) + ' ' + res; //use (len-start_word) to include last element at len-1. 
        }
        
        len = res.size();
        //delete last space added to result string due to our approach
        res = res.substr(0,len-1);
        return res;
    }
