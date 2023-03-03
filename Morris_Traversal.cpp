vector<int> inOrder(Node* root) {
        // Morris Traversal TC-O(N) SC-O(1)
        vector<int>inorder;
        if(root==NULL)
            return {};
        auto curr = root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                auto prev = curr->left;
                while(prev->right and prev->right!=curr)
                {
                    prev = prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return inorder;