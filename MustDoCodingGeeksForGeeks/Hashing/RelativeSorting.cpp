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

#include
