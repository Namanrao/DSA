class Solution {
public:

    vector<long long > summationAndsmallest(vector<vector<int>> &matrix){
        long long  smallest = abs(matrix[0][0]);
        long long n = matrix.size() ;
        long long m = matrix[0].size();
        long long sum = 0; 
        long long negative  =0 ;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(matrix[i][j]<0) negative++;
                if(smallest > abs(matrix[i][j])) smallest = abs(matrix[i][j]);
                sum+= abs(matrix[i][j]);
            }
        }
        vector<long long> result ; 
        result.push_back(sum);
        result.push_back(negative);
        result.push_back(smallest);
        return result;
    }


    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // initial  approach is if there is even number of negaties then the entire summation is the answer . 
        // if odd number of negatives then entire summation - (lower element in the entire matrix)
        vector<long long>result = summationAndsmallest(matrix);
        if(result[1]%2!=0){
            return result[0] - 2*result[2];
        }
        return result[0];
    }
};