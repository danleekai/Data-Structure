#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* parent;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* CreateBST (int value) {

    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->value = value;
    temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void InsertBST (TreeNode* BST , int value) {

    if(BST->value > value){
        if(BST->left==NULL) {
                BST->left = CreateBST(value);
                BST->left->parent = BST;
        } else {
            InsertBST(BST->left,value);
        }
    }

    if(BST->value < value){
        if(BST->right==NULL) {
                BST->right = CreateBST(value);
                BST->right->parent = BST;
        } else {
            InsertBST(BST->right,value);
        }
    }
}

int SearchBST (TreeNode* BST,int value) {

    if(BST->value==value) { return BST; }

    else if(BST->value > value) {
        if (BST->left) {
            SearchBST(BST->left,value);
        } else {
            return NULL;
        }
    }
    else {
        if (BST->right) {
            SearchBST(BST->right,value);
        } else {
            return NULL;
        }
    }
}

void DeleteBST (TreeNode* BST,int value) {

    TreeNode* Target = SearchBST(BST,value);
    TreeNode* replace = NULL;

    //case1 : 欲刪除節點只有left child (找左子樹裡最大的補)
    if(Target->left) {
        replace = Target->left;
        while(replace->right) {  replace = replace->right; }

    //case2 : 欲刪除節點只有right child (找右子樹裡最小的補)
    } else if(Target->right) {
        replace = Target->right;
        while(replace->left) { replace = replace->left;}
    //case3 : 欲刪除節點沒有其他子樹
    }else {
        replace = Target;
    }

    Target->value = replace->value;
    TreeNode* parents = replace->parent;
    TreeNode* subreplace = NULL;

    if(replace->left) { subreplace=replace->left; }
    if(replace->right) { subreplace=replace->right; }

    if(parents) {
        if(parents->left==replace) {
            if(subreplace) {
                parents->left = subreplace;
            } else {
                parents->left = NULL;
            }
        }
        if(parents->right==replace) {
            if(subreplace) {
                parents->right = subreplace;
            } else {
                parents->right = NULL;
            }
        }
    }
    free(replace):

}

int main()
{
    TreeNode* BST = CreateBST(15);
    InsertBST(BST,20);
    InsertBST(BST,22);
    InsertBST(BST,14);

    return 0;
}
