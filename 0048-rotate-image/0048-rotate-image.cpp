class Solution {
public:
    void rotate_in_place(vector<vector<int>>& matrix, int min_boundary, int max_boundary)
    {
        int swap_1=0, swap_2=0;

        for(int i=0; i<max_boundary-min_boundary; ++i)
        {
            swap_1 = matrix[min_boundary+i][max_boundary];
            matrix[min_boundary+i][max_boundary] = matrix[min_boundary][min_boundary+i];

            swap_2 = matrix[max_boundary][max_boundary-i];
            matrix[max_boundary][max_boundary-i] = swap_1;

            swap_1 = matrix[max_boundary-i][min_boundary];
            matrix[max_boundary-i][min_boundary] = swap_2;

            matrix[min_boundary][min_boundary+i] = swap_1;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix[0].size();
        int min_boundary = 0;
        int max_boundary = rows-1;
        for(int i=0; i<rows/2; ++i)
        {
            rotate_in_place(matrix, min_boundary+i, max_boundary-i);
        }

        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<rows; ++j)
                std::cout << matrix[i][j] << ", ";

            std::cout << std::endl;
        }
    }
};