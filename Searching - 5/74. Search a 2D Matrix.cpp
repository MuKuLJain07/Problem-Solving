class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col - 1;

        int mid = start + (end-start)/2;

        while(end>=start){
            if(matrix[mid/col][mid%col] == target){
                return true;
            }

            if(matrix[mid/col][mid%col] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }

        return false;



    }
};