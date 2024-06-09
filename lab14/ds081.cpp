// DS081. Making Binary Tree & Traversal

#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};
 
TreeNode* buildTree(int *nums, int size) {
    if (nums == NULL) return NULL;

    if (nums[0] == 0) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < size) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < size && nums[i] != 0) {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        i++;
        if (i < size && nums[i] != 0) {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void printInOrderTree(TreeNode* root) {
    if (!root) return;
    printInOrderTree(root->left);
    cout << root->val << " ";
    printInOrderTree(root->right);
}

int main() {
    int num;
    cin >> num;
    int* list = new int[num];

    for (int i = 0; i < num; i++)
        cin >> list[i];

    TreeNode* root = buildTree(list, num);
    printInOrderTree(root);
    
    delete[] list;
    return 0;
}