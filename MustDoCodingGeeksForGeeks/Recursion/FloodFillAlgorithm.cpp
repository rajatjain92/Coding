/* Problem : leetcode (733)
n image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, 
"flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color 
as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), 
and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Input: 
image = [[1,1,1],
         [1,1,0],
         [1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],
         [2,2,0],
         [2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
*/

#include <bits/stdc++.h>

void func(vector<vector<int>>& image, int sr, int sc, int newColor,int prevColor) {
        //whole code should be in if block bcoz one pixel may call back to pixel which called it. Means
        //reverse recursive call can be ther. 
        if(image[sr][sc] == prevColor){
                  image[sr][sc] = newColor;
                  //go down
                  if(sr + 1 < image.size())    func(image,sr+1,sc,newColor,prevColor);
                  //go right
                  if(sc + 1 < image[0].size()) func(image,sr,sc+1,newColor,prevColor);
                  //go up
                  if(sr - 1 >= 0)              func(image,sr-1,sc,newColor,prevColor);
                  //go left
                  if(sc - 1 >= 0)              func(image,sr,sc-1,newColor,prevColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        
        //if new color is same as old color do not call recursion function
        if(prevColor != newColor)
            func(image,sr,sc,newColor,prevColor);
        return image;
    }
};
