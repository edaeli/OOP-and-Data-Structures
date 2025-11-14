#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility> 
#include <stdexcept>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root) {
    if (!root) 
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

//1

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    } 
    return root;
}

//2

bool search(TreeNode* root,int val){
    if(!root)
        return false;
    if(root->data == val)
        return true;
    if(root->data > val){
        return search(root->left,val);
    }
    else 
        return search(root->right,val);
}


//3

int findMinBST(TreeNode* root) {
    TreeNode* tmp = root;
    while (tmp->left) {
      tmp = tmp->left;
    }
    return tmp->data;
    
}

int findMaxBST(TreeNode* root) {
    TreeNode* tmp = root;
    while (tmp->right) {
      tmp = tmp->right;
    }
    return tmp->data;
}

//4

bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->data <= minVal || node->data >= maxVal)
        return false;
    return isValidBSTHelper(node->left, minVal, node->data) &&
           isValidBSTHelper(node->right, node->data, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, std::numeric_limits<long long>::min(),
                                   std::numeric_limits<long long>::max());
}

//5

void inorder(TreeNode* root, int& k, int& result, bool& found) {
    if (!root || found) 
        return;

    inorder(root->left, k, result, found);
    if (--k == 0) {
        result = root->data;
        found = true;
        return;
    }

    inorder(root->right, k, result, found);
}

int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    bool found = false;
    inorder(root, k, result, found);
    return result;
}

//6

TreeNode* buildBST(std::vector<int> nums,int left,int right){

    if (left > right)
        return nullptr;

    int mid = left + (right - left)/2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = buildBST(nums,left,mid-1);
    root->right = buildBST(nums,mid+1,right); 

    return root;


}



TreeNode* sortedArrayToBST(std::vector<int> nums){
    return buildBST(nums,0,nums.size() - 1);
} 

//7

TreeNode* findMin(TreeNode* root){
    while(root->left)
        root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root,int key){
    if(!root)
        return nullptr;
    if(key < root->data){
        deleteNode(root->left,key);
    }
    else if(key > root->data)
        deleteNode(root->right,key);
    else   
        // case 1
        if(!root->right && !root->left){
            delete root;
            return nullptr;
        }
        
        // case 2
        if(!root->left){
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }

        if(!root->left){
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }

        // case 3

        if(!root->left && !root->right){
            TreeNode* tmp = findMin(root->right);
            root->data = tmp->data;

            root->right = deleteNode(root->right,tmp->data);
        }

        return root;
}

//8

int countInRange(TreeNode* root,int low,int high){
    if(!root)
        return 0;

    if(root->data < low)
        return countInRange(root->right,low,high);

    if(root->data > high)
        return countInRange(root->left,low,high);

    return 1 + countInRange(root->left,low,high) + countInRange(root->right,low,high);
}


//9 

bool hasPathSum(TreeNode* root,int sum){
    if(!root)
        return false;

    if(!root->right && !root->left)
        return root->data == sum;

    return hasPathSum(root->left, sum - root->data) || hasPathSum(root->right, sum - root->data);
}

int main() {
    //1

    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);

    inorder(root); 
    std::cout << std::endl;

    std::cout << "------------------" << std::endl;

    //2

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);

    bool found = search(root2, 3);  // found = true
    bool notFound = search(root2, 10);  // notFound = false

    std::cout << found << ' ' << notFound << std::endl;

    std::cout << "------------------" << std::endl;

    //3

    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(7);
    root3->left->left = new TreeNode(1);

    int minVal = findMinBST(root3);  // minVal = 1
    int maxVal = findMaxBST(root3);  // maxVal = 7

    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;

    std::cout << "------------------" << std::endl;

    //4

    TreeNode* root4 = new TreeNode(5);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(7);
    root4->left->left = new TreeNode(1);

    std::cout << std::boolalpha;
    std::cout << "Valid: " << isValidBST(root4) << "\n"; 

    TreeNode* invalid = new TreeNode(5);
    invalid->left = new TreeNode(7);  
    invalid->right = new TreeNode(3); 

    std::cout << "Not valid: " << isValidBST(invalid) << "\n";

    std::cout << "------------------" << std::endl;


    //5

    TreeNode* root5 = new TreeNode(5);
    root5->left = new TreeNode(3);
    root5->right = new TreeNode(7);
    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(4);

    int result = kthSmallest(root5, 3);  // result = 4
    // Отсортированная последовательность: 1, 3, 4, 5, 7

    std::cout << "kth smallest: " << result << std::endl;

    std::cout << "------------------" << std::endl;


    //6

    std::vector<int> arr = {1, 3, 5, 7, 9};
    TreeNode* root6 = sortedArrayToBST(arr);
    // Получаем сбалансированное дерево с корнем 5

    //7

    TreeNode* root7 = new TreeNode(5);
    root7->left = new TreeNode(3);
    root7->right = new TreeNode(7);
    root7->left->left = new TreeNode(1);
    root7->right->right = new TreeNode(9);

    root = deleteNode(root7, 7);
    // Узел 7 удален, дерево остается корректным BST

    //8

    TreeNode* root8 = new TreeNode(10);
    root8->left = new TreeNode(5);
    root8->right = new TreeNode(15);
    root8->left->left = new TreeNode(3);
    root8->left->right = new TreeNode(7);
    root8->right->right = new TreeNode(18);

    int count = countInRange(root8, 7, 15);
    // count = 3 (узлы: 7, 10, 15)

    std::cout << "count in range: " << count << std::endl;

    std::cout << "---------------------"<<std::endl;

    //9

    TreeNode* root9 = new TreeNode(5);
    root9->left = new TreeNode(4);
    root9->right = new TreeNode(8);
    root9->left->left = new TreeNode(11);
    root9->left->left->left = new TreeNode(7);

    bool hasPath = hasPathSum(root9, 27);
    // hasPath = true (путь: 5 -> 4 -> 11 -> 7)
    
    std::cout << hasPath;
    



}
