class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> coordinates;
        vector<vector<int>> pacific_matrix(m, vector<int>(n, 0));
        vector<vector<int>> atlantic_matrix(m, vector<int>(n, 0));

        std::queue<pair<int, int>> bfs_pacific;
        std::queue<pair<int, int>> bfs_atlantic;

        for(int i=0; i<m; ++i)
        {
            pacific_matrix[i][0] = 1;
            atlantic_matrix[i][n-1] = 1;
            bfs_pacific.push(make_pair(i,0));
            bfs_atlantic.push(make_pair(i,n-1));
        }

        for(int i=0; i<n; ++i)
        {
            pacific_matrix[0][i] = 1;
            atlantic_matrix[m-1][i] = 1;
            bfs_pacific.push(make_pair(0,i));
            bfs_atlantic.push(make_pair(m-1,i));
        }

        while(!bfs_pacific.empty())
        {
            pair<int, int> coord = bfs_pacific.front();
            bfs_pacific.pop();
            int row = coord.first;
            int col = coord.second;

            if(pacific_matrix[row][col] == 0)
                pacific_matrix[row][col] = 1;

            if(row+1 < m && heights[row][col] <= heights[row+1][col] && pacific_matrix[row+1][col] != 1)
            {
                bfs_pacific.push(make_pair(row+1, col));
            }

            if(col+1 < n && heights[row][col] <= heights[row][col+1] && pacific_matrix[row][col+1] != 1)
            {
                bfs_pacific.push(make_pair(row, col+1));
            }

            if(row-1 >= 0 && heights[row][col] <= heights[row-1][col] && pacific_matrix[row-1][col] != 1)
            {
                bfs_pacific.push(make_pair(row-1, col));
            }

            if(col-1 >= 0 && heights[row][col] <= heights[row][col-1] && pacific_matrix[row][col-1] != 1)
            {
                bfs_pacific.push(make_pair(row, col-1));
            }
        }
        
        /*for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
                std::cout << pacific_matrix[i][j] << ", ";

            std::cout << std::endl;
        }*/

        while(!bfs_atlantic.empty())
        {
            pair<int, int> coord = bfs_atlantic.front();
            bfs_atlantic.pop();
            int row = coord.first;
            int col = coord.second;
            //std::cout << row << ", " << col << " - ";

            if(atlantic_matrix[row][col] == 0)
                atlantic_matrix[row][col] = 1;

            if(row-1 >= 0 && heights[row][col] <= heights[row-1][col] && atlantic_matrix[row-1][col] != 1)
            {
                bfs_atlantic.push(make_pair(row-1, col));
            }

            if(col-1 >= 0 && heights[row][col] <= heights[row][col-1] && atlantic_matrix[row][col-1] != 1)
            {
                bfs_atlantic.push(make_pair(row, col-1));
            }

            if(row+1 < m && heights[row][col] <= heights[row+1][col] && atlantic_matrix[row+1][col] != 1)
            {
                bfs_atlantic.push(make_pair(row+1, col));
            }

            if(col+1 < n && heights[row][col] <= heights[row][col+1] && atlantic_matrix[row][col+1] != 1)
            {
                bfs_atlantic.push(make_pair(row, col+1));
            }
        }

        /*std::cout << std::endl;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
                std::cout << atlantic_matrix[i][j] << ", ";

            std::cout << std::endl;
        }*/

        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(pacific_matrix[i][j] == 1 && atlantic_matrix[i][j] == 1)
                {
                    vector<int> coord;
                    coord.push_back(i);
                    coord.push_back(j);
                    coordinates.push_back(coord);
                }
            }
        }

        return coordinates;
    }
};