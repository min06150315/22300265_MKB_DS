// DS082. Making Binary Tree & Traversal

#include <iostream>
#include <queue>
using namespace std;

// reuse DS081
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

void printPreOrderTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreOrderTree(root->left);
    printPreOrderTree(root->right);
}

void printPostOrderTree(TreeNode* root) {
    if (!root) return;
    printPostOrderTree(root->left);
    printPostOrderTree(root->right);
    cout << root->val << " ";
}

int main() {
    int num, menu;
    cin >> num >> menu;
    int* list = new int[num];

    for (int i = 0; i < num; i++)
        cin >> list[i];

    TreeNode* root = buildTree(list, num);

    if (menu == 1) {            // preorder traversal
        cout << "preorder traversal: ";
        printPreOrderTree(root);
    } else if (menu == 2) {     // postorder traversal
        cout << "postorder traversal: ";
        printPostOrderTree(root);
    }
    
    return 0;
}