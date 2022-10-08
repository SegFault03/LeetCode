
#include <bits/stdc++.h>
using namespace std;

//Trim a binary tree within the range [low,high]
//ALGO:
//Define trim(Node *root,low,high)
/*if root!=null,
 * check if root->val lies in range
 * if true:
 *        root->left=trim(root->left),root->right=trim(root->right)
 *        return root
 * else if root->val>high, it follows that it's right subtree will be discarded automatically:
 *       replace the node:
 *       return(root->left) to caller module
 * else, it follows that root->val<low, which follows that it's left subtree will be discarded:
 *       return(root->left)
 *if root==NULL, return NULL
 */

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;

public:
    Tree()
    {
        this->val=0;
        this->left=NULL;
        this->right=NULL;
    }

    Tree(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

    Tree* buildTree(int val)
    {
        if(this==NULL)
        {
            Tree *temp=new Tree(val);
            return temp;
        }
        else
        {
            Tree *temp=NULL;
            if(this->val>val)
            {
                temp= this->left->buildTree(val);
                this->left=temp;
            }
            else
            {
                temp = this->right->buildTree(val);
                this->right=temp;
            }
            return this;
        }
    }

    void preOrder()
    {
        if(this!=NULL)
        {
            cout<<this->val<<",";
            this->left->preOrder();
            this->right->preOrder();
        }
    }

    //REPLACEMENT ALGORITHM [deletion]
    //if node->val does not lie in range [low, high], search in its right/left subtree (according to given conditions)..
    //for the node that lies in the range and return its address to the last known node lying in the range.
    //This only works if one of the left or right subtree can be completely discarded as two different addresses(left, right)...
    //cannot be returned

    Tree* trim(int low,int high)
    {
        if(this==NULL)
            return NULL;
        else
        {
            Tree *temp=NULL;
            if(this->val>=low&&this->val<=high)
            {
                temp=this->left->trim(low,high);
                this->left=temp;
                temp=this->right->trim(low,high);
                this->right=temp;
                return this;
            }
            else if(this->val>high)
                return(this->left->trim(low,high));
            else
                return(this->right->trim(low,high));
        }
    }

    //SWAPPING ALGORITHM
    //In this algorithm the node not lying in [low,high] is 'swapped' with a node that lies in the range
    //Swap the node that does not belong in the range with it's immediate left/right child (according to the given conditions)
    //Swap the node's left and right address with the child's left, right address as well
    //Call trim() again on the same node to check if the replaced node lies in the given range
    //The objective is to repeatedly swap until a node is found that lies in the given range and return the address to the last...
    //known node that lies in the range
    //The main difference between this and the replacement algo is that in the swapping algo, the tree is re-formed...
    //by swapping the node not lying in the range with the values of a node that does, although the address that is returned...
    //is still the same address.
    //But in case of the replacement algo, an address of a child node(of whose parent node does not lie in the range) is sent back...
    //and the objective is to search for a child node that fits in the given range, while the node on which the function...
    // is called is 'ignored' (it's address is not returned, only used to search for a child node). Both algos have the exact same complexity.

    Tree* trim_by_delete(int low, int high)
    {
        if(this!=NULL)
        {
            Tree *temp=NULL,*temp2= nullptr;
            if(this->val>=low&&this->val<=high)
            {
                temp=this->left->trim(low,high);
                this->left=temp;
                temp=this->right->trim(low,high);
                this->right=temp;
                return this;
            }
            else if(this->val>high)
            {
                temp=this->left->left;
                temp2=this->left->right;
                this->val=this->left->val;
                this->left=temp;
                this->right=temp2;
                return(this->trim_by_delete(low,high));
            }
            else
            {
                temp=this->right->left;
                temp2=this->right->right;
                this->val=this->right->val;
                this->left=temp;
                this->right=temp2;
                return(this->trim_by_delete(low,high));
            }
        }
    }
};

int main()
{
    int a[] = {-12,4,1,10,-4,3,2,11,8,-7,6,5,-1,-2};
    //Running some tests
    Tree *root=new Tree(a[0]);
    for(int i=1;i<14;i++)
        root=root->buildTree(a[i]);
    root->preOrder();
    Tree *root2=root->trim(-3,7);
    Tree *root3=root->trim_by_delete(-3,7);
    cout<<"\n";
    root2->preOrder();
    cout<<"\n";
    root3->preOrder();
}


