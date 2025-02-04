class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num_nodes = isConnected.size();
        int num_components = 0;
        std::queue<int> que;
        vector<bool> visited(num_nodes, false);

        for(int i=0; i<num_nodes; ++i)
        {
            if(!visited[i])
            {
                que.push(i);
                num_components++;
                visited[i] = true;
            }

            while(!que.empty())
            {
                int node = que.front();
                que.pop();

                for(int j=0; j<num_nodes; ++j)
                {
                    if(node != j && isConnected[node][j] == 1 && !visited[j])
                    {
                        que.push(j);
                        visited[j] = true;
                    }
                }
            }
        }

        return num_components;
    }
};