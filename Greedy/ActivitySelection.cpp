/*
Activity selection problem. It is similar to no overapping itervals problem. It is pretty similar to 
452 Minimum Number of Arrows to Burst Balloons
435 Non-overlapping Intervals <- very similar
56 Merge Intervals <- very similar
252 Meeting Rooms
253 Meeting Rooms II  

Same logic for all:
> Sort on the basis of starting point
> start count = 1 and end point
> Now if for current pair its starting point > end means no overlap new group start increase count and update end
> Now if there is overlapping means starting point < end means no group then we need to update end by giving end min value of all stop 
  points in that overlapping group.
  
Logic for updating end is if first of all start is all sorted ,So new pair will come out of the bule in between. Now is any pair comes 
which is overlapped we give value of end to min of all stop points in that overlapping. This is done because if we want to check overlapping
for new pair then its starting point should be less then min stoping point in that overlapping group. If that does not happen then new 
group to be started so end is new stop point.
*/

#######################---452 Minimum Number of Arrows to Burst Balloons---###########################
//***It is same as activity selection literally same ****** IMPORTANT
/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end 
coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and 
end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow 
shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up 
infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.
*/

//ALWAYS REMEMBER THINGS ARE SORTED FIRST eg (1,4),(4,8),(1,3). try visualise. Always ask interviewer what to do in corner cases.
int findMinArrowShots(vector<vector<int>>& points) {
       int s = points.size();
       if(s == 0)
           return 0;
        
       sort(points.begin(),points.end());
   
       int count = 0;
       int minEndLatestOverlap = INT_MAX;
        
       for(int i=0;i<s;i++)
       {
           //when equal it isconsidered as overlapping hence not equal to >=
           if(points[i][0] > minEndLatestOverlap)
           {
               //means new group
               count++;
               minEndLatestOverlap = points[i][1];
           }
           else
           {
               //means overlapping no need to update count. Just update minEndLatestOverlap
               minEndLatestOverlap = min(minEndLatestOverlap,points[i][1]);
               //increase for first element
               if(i == 0)
                 count++;
           }
       }
       return count;
   }

############################---NON OVERLAPPING PROBLEMS---##########################
/*Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals 
non-overlapping.
== case is not considered as overlapping
*/

int eraseOverlapIntervals(vector<vector<int>>& points) {
       int s = points.size();
       if(s == 0)
           return 0;
        
       sort(points.begin(),points.end());
       //start with 0
       int count = 0;
       int minEndLatestOverlap = INT_MAX;
        
       for(int i=0;i<s;i++)
       {
           //when equal it isconsidered as overlapping hence not equal to >=
           if(points[i][0] >= minEndLatestOverlap)
           {
               //means new group no overlapping
               minEndLatestOverlap = points[i][1];
           }
           else
           {
               //means overlapping no need to update count. Just update minEndLatestOverlap
               //for 1st pair dont ncrease count
               if(i != 0)
                  count++;
               minEndLatestOverlap = min(minEndLatestOverlap,points[i][1]);
           }
       }
       return count;
    }
