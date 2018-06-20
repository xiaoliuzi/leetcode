/*
832. Flipping an Image
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed. For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

思路：
由题意可知，需要将二维数组中的每一行逆序，然后将二维数组中的全部元素如果是0，则置1，如果是1，则置0。

时间复杂度O(n^2),空间复杂度O(1)
*/
class Solution {
public:
    void swap(int& a, int& b) {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A[0].size() > 20) return A;
        int len = A[0].size();
        //int half_len = A[0].size() << 1;
        // flip
        for(int i = 0; i < len; ++i) {
            for(int l = 0, h = len-1; l < h; ++l, --h) {
                if(A[i][l] >= 0 && A[i][l] <= 1
                  && A[i][h] >= 0 && A[i][h] <= 1) {
                    swap(A[i][l], A[i][h]);
                } else {
                    return A;
                }
                
            }
            
        }
        
        // invert
        for(int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if(A[i][j] == 0) A[i][j] = 1;
                else A[i][j] = 0;
            }
        }
        return A;
    }
};