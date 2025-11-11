#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

//1

int countNodes(TreeNode* root){
    if(root == nullptr)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

//2

int treeHeight(TreeNode* root){
    if(root == nullptr){
        return 0;
    }

    return std::max(countNodes(root->left),countNodes(root->right)) + 1;
}


//3

int countLeaves(TreeNode* root){
    if(root == nullptr)
        return 0;

    if(root->left == nullptr &&  root->right == nullptr)
        return 1;


    return countLeaves(root->left) + countLeaves(root->right);

}


//4

void inorder(TreeNode* root){
    if(root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode* root){
    if(root == nullptr)
        return;

    std::cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);

}

void postorder(TreeNode* root){
    if(root == nullptr)
        return;

    inorder(root->left);
    inorder(root->right);
    std::cout << root->data << " ";
}

//5

void levelOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
    std::cout << std::endl;
}

//6


int sumNodes(TreeNode* root){

    if(root == nullptr)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

//7

int findMax(TreeNode* root){
    if(root == nullptr){
        return -1111111;
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return std::max(root->data,std::max(leftMax,rightMax));
}


int findMin(TreeNode* root){
    if(root == nullptr){
        return 111111111;
    }

    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    return std::min(root->data,std::min(leftMin,rightMin));
}

//8

bool areIdentical(TreeNode* root1,TreeNode* root2){
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }

    if (root1 == nullptr || root2 == nullptr)
        return false;

    if(root1->data != root2->data)
        return false;

    bool b1 = areIdentical(root1->left,root2->left);
    bool b2 = areIdentical(root1->right,root2->right);

    return (b1 && b2);
}

//9

int countNodesAtDepth(TreeNode* root,int k){
    if (!root)
        return 0;

    if (k == 1)
        return 1;

    return countNodesAtDepth(root->left,  k - 1) +
           countNodesAtDepth(root->right, k - 1);
}

//10


void mirrorTree(TreeNode* root){
    if(!root)
        return;

    std::swap(root->right,root->left);
    mirrorTree(root->right);
    mirrorTree(root->left);
}





int main() {

    //1

    std::cout << "Count: ";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    int count = countNodes(root);

    std::cout << count << std::endl;

    std::cout << "----------------" << std::endl;

    //2

    std::cout << "Height: ";

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);

    int height = treeHeight(root1);

    std::cout << height << std::endl;

    std::cout << "--------------------" << std::endl;

    //3

    std::cout << "Leaves: ";

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    int leaves = countLeaves(root2);
    std::cout << leaves << std::endl;  


    std::cout << "--------------------" << std::endl;

    //4

    std::cout << "Order" << std::endl;

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);

    std::cout << "Preorder: ";
    preorder(root3);   
    std::cout << std::endl;
    std::cout << "Ineorder: ";
    inorder(root3);    
    std::cout << std::endl;
    std::cout << "Preorder: ";   
    postorder(root3);  
    std::cout << std::endl;


    std::cout << "-------------------" << std::endl;

    //5 

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);

    levelOrder(root);
    // Вывод: 1 2 3 4 5

    std::cout << "-------------------" << std::endl;
    

    //6

    std::cout<<"Sum: ";

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);

    int sum = sumNodes(root5); //10

    std::cout << sum << std::endl;

    std::cout << "-------------------" << std::endl;    

    //7

    TreeNode* root6 = new TreeNode(5);
    root6->left = new TreeNode(3);
    root6->right = new TreeNode(8);
    root6->left->left = new TreeNode(1);

    int maxVal = findMax(root6);  // maxVal = 8
    int minVal = findMin(root6);  // minVal = 1

    std::cout << "max: " << maxVal << std::endl;
    std::cout << "min: " <<minVal << std::endl;

    std::cout << "-------------------" << std::endl;   

    //8

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    bool identical = areIdentical(tree1, tree2);
    std::cout << identical << std::endl;
    // identical = true

    std::cout << "-------------------" << std::endl;
    
    //9

    TreeNode* root9 = new TreeNode(1);
    root9->left = new TreeNode(2);
    root9->right = new TreeNode(3);
    root9->left->left = new TreeNode(4);
    root9->left->right = new TreeNode(5);

    int count1 = countNodesAtDepth(root9, 3);

    std::cout << "Depth: " << count1 << std::endl;

    std::cout << "-------------------" << std::endl;


    //10



    TreeNode* root10 = new TreeNode(1);
    root10->left = new TreeNode(2);
    root10->right = new TreeNode(3);
    root10->left->left = new TreeNode(4);

    mirrorTree(root10);


}