/*
Problem : 1122(leetcode)

         Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
         Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  
         Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

Example:
         Input  : arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
         Output : [2,2,2,1,4,3,3,9,6,7,19]

TakeAway: Use unordered map when you need to keep count of something. Use ordered map when you want to print 
          access elements in sorting order. When you need predecessor or successor of elements.
          
          Ordered map is implemented as red black tree O(log(n)) operations.
          Unordered

*/

#include <bits/stdc++.h>

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //use ordered map bcoz we will not need to explicitly sort elements
        //which are not present in arr2. ordered map will do itself.
        map<int,int>hash;                             //to store frequency of arr1
        vector<int> res;                              //to store result
        
        int s1 = arr1.size();
        int s2 = arr2.size();
        
        //store frequency of elements of arr2 in hash(ordered map hence sorted -log(n) operation
        for(int i=0;i<s1;i++)
            hash[arr1[i]]++;
        
         //for every element present in arr2 store in res sequentially bcoz that's the order 
        for(int i=0;i<s2;i++)
        {
            //push as many times as frequency
            for(int j=0;j<hash[arr2[i]];j++)
                res.push_back(arr2[i]);
            
            //after inserting make fequency 0 for that element
            hash[arr2[i]]=0;
        }
        
        //below part is for elements not present in arr2 but in arr1
        for(auto i: hash)
        {
            //Keep in mind elements not in arr2 but in arr1 can also be repeated hence you need loop below
            //I was making mistake for above line.
            //elements already inserted will have i.second = 0 hence won't be inserted.
            for(int j=0;j<i.second;j++)
                res.push_back(i.first);
        }
        //return result
        return res;
    }

