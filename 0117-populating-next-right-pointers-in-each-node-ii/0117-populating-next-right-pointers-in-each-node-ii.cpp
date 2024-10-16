/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<std::pair<Node*, int>> que;
        if(root == NULL)
            return root;

        int level = 1;
        que.push(std::pair(root, level));

        while(!que.empty())
        {
            int nodeLevel = que.front().second;
            Node* node = que.front().first;
            que.pop();

            if(que.empty() || que.front().second > nodeLevel)
                node->next = NULL;
            else if(que.front().second == nodeLevel)
                node->next = que.front().first;

            if(node->left != NULL)
                que.push(std::pair(node->left, nodeLevel+1));

            if(node->right != NULL)
                que.push(std::pair(node->right, nodeLevel+1));
        }

        return root;
    }
};