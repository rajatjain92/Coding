/*
In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be 
replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating 
System replaces one of the existing pages with a newly needed page. Given a sequence of pages and memory capacity, your task is to find 
the number of page faults using Least Recently Used (LRU) Algorithm.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains n number of pages and next 
line contains space seaprated sequence of pages. The following line consist of the capacity of the memory.

Example: 
2
9
5 0 1 3 2 4 1 0 5
4
8
3 1 0 2 5 4 1 2
4

Output:
8
7

Explanation:
Testcase 1:
memory allocated with 4 pages 5, 0, 1, 3: page fault = 4
page number 2 is required, replaces LRU 5: page fault = 4+1 = 5
page number 4 is required, replaces LRU 0: page fault = 5 + 1 = 6
page number 1 is required which is already present: page fault = 6 + 0 = 6
page number 0 is required which replaces LRU 1: page fault = 6 + 1 = 7
page number 5 is required which replaces LRU 3: page fault = 7 + 1  =8.

Learn about 
An unordered_set is implemented using a hash table where keys are hashed into indices of a hash table so that the insertion is always 
randomized. All operations on the unordered_set takes constant time O(1) on an average which can go up to linear time O(n) in worst case
which depends on the internally used hash function, but practically they perform very well and generally provide a constant time lookup
operation.
The unordered_set can contain key of any type – predefined or user-defined data structure but when we define key of type user define 
the type, we need to specify our comparison function according to which keys will be compared.

Sets vs Unordered Sets
Set is an ordered sequence of unique keys whereas unordered_set is a set in which key can be stored in any order, so unordered. 
Set is implemented as a balanced tree structure that is why it is possible to maintain order between the elements (by specific tree 
traversal). The time complexity of set operations is O(log n) while for unordered_set, it is O(1).


Logic:
> Create set as memory cache .Every operation takes O(1) timein set.
> To keep track of occurences we use map storing page arr[i] and occurence i. i number is treated as occurence number.
> For every element check if element is present in set (memory cache) ,if yes we only need to update map
> otherwise if element is not present in set, then check if set size is full or not. If not increase page fault , 
  insert set and update map. If size is full here means LRU needs to be implemented. for every element in set search map and see
  smallest page occurence. Erase it from set . Add new page[i] in set and update arr[i] in in map. No need to update map entry for min
  occurence page found which is erased from set. Because we are searching according to set and in set that element will be removed and 
  logically removed page occurence is still same.Whenever removed page will come 
> Time Complexity - O(n*k(cache size)))

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>arr;
	    
      //taking inputs
	    for(int i=0;i<n;i++){
	        int in;
	        cin>>in;
	        arr.push_back(in);
	    }
	    
      //memory capacity
	    int memory_size;
	    cin>>memory_size;
	    int page_faults = 0;
	  
	    //set to check in O(1) time if element is present or not in memory cache
      unordered_set<int> s;
    
      //map to keep page and latest index pair updated (unordered so O(1))
	    unordered_map<int,int> indexes;
	    
      //for every element
	    for(int i=0;i<n;i++)
	    {
          //if element is not present in memory cache
	        if(s.find(arr[i]) == s.end())
	        {
              //if till cache is not full
	            if(s.size() < memory_size)
	            {
                  //at this point means i is not present in cache and cache capacity is not still full
	                page_faults++;             //increase page fults
	                s.insert(arr[i]);          //insert in cache
	                indexes[arr[i]] = i;       //update map storing element arr[i] and its latest occurence i.
	            }
	            else
	            {
                  //if cache is full means LRU needs to be used
	                int a,b=INT_MAX;           //give b max value , b stores occurence number
                
                  //for every element in cache check map and store least occurence number
	                for(auto it=s.begin(); it != s.end(); ++it)
	                {
	                    if(indexes[*it] < b)
	                    {
	                        a = *it;
	                        b = indexes[*it];
	                    }
	                }
                
                  //remove least occurence used
	                s.erase(a);
                  //insert the latest page
	                s.insert(arr[i]);
                  //increase page fault
	                page_faults++;
                
                  //update latest page occurence in map
	                indexes[arr[i]]=i;
	            }
	        }
	        else
          {
              //Here it means element is already found in memory cache
              //so just update page arr[i] occurence i in map.
	            indexes[arr[i]] = i;
          }
	    }
	    cout<<page_faults<<endl;
	}
	return 0;
}
