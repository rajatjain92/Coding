/* Problem: Josephous Problem
There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds 
around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. 
The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only 
the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons 
are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one 
remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, 
then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the 
person at position 3 survives.

*/

###################################---RECURSION---#####################################
/*
logic:
> This function returns index of last person remaining.
> We want ans between 1 to n,means indexing starts from 1.
> If 1 person remains he is the answer.
> "1 2 3 4 5 ... n" when k = 3 then sequence left will be 1 2 4 5...n , Now we need to start from 4 for (n-1)th recursion call.
  So we need add something to shift its starting position from 1 to 4. Value added will be k. So recursion becomes
  J(n,k) = (J(n-1,k) + k)%n  .Do %n so that we dont go beyond n.
> Everything is fine but what is our answer is n , in that case we will get 0 as answer due to mod operator. So we subtract 1 from inside
  bracket value which is to be mod and add 1 at the end to compensate subtraction.S0 recursion is:
  J(n,k) = (J(n-1,k) + k - 1) % n + 1
  */

#include <bits/stdc++.h>

//Recursive O(n) solution
int lastRemaining(int n,int k) {
    //if n is 1 then he is the answer.Do not go below 1.
    if (n == 1)
       return 1;
        
    return (lastRemaining(n-1,k) + k - 1) % n + 1;
}


##################################---Special case when k=2---#######################################
/*
Logic:

