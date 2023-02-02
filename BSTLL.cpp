#include <iostream>
using namespace std;
// Binary Search Tree using ADT 
class BST{
    private:
    class Tree{
        public:
        int data;
        Tree * left , * right;
        Tree(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    Tree * root; // This will the root / main data
    public:
    BST(){
        root = NULL;
    }
    //Insert
    void insert(int data){ // This is the Wrap Function
        root = inserted(root , data);
    }
    Tree * inserted(Tree * roots , int data){ // Inserted function had the data type of Tree
        if(roots == NULL){ // check the roots is eqaul to the NULL
            roots =  new Tree(data); // creating the root / main of the Tree
            return roots; // and return the roots
        }
        else{
            if(roots->data > data){ // check the roots data is Greater then the data
                roots->left = inserted(roots->left , data); // this will move to the left of the root
            }
            else if(roots->data < data){ // check the roots data is Smaller then the data
                roots->right = inserted(roots->right , data); // this will move to the right of the root
            }
        }
    }

    //
    void Search(int search){ // Wrap function of Search
        searched(root,search);
    }
    Tree * searched(Tree * roots , int search){
        if(roots->data == search){
            cout<<roots->data;
        }
        else{
            if(roots->data > search){ // check the root data is Greater then the search
                roots->left = searched(roots->left , search); // this will move to the left of the root
            }
            else if(roots->data < search){ // check the root data is Smaller then the search
                roots->right = searched(roots->right , search); // this will move to the right of the root
            }
            else{
                cout<<"Not Found";
            }
        }
    }
    Tree * minValueNode(Tree * node)
        {
            Tree * current = node;
        
            /* loop down to find the leftmost leaf */
            while (current && current->left != NULL)
                current = current->left;
        
            return current;
        }
    void Delete(int del){
        dele(root,del);
    }
    Tree * dele(Tree * root ,int del){
        if(root->data == del){
            if(root->right == NULL){ // Check that the root right is NULL
                Tree * temp = root; // We make a pointer which is pointing to the root
                root = root->left; // root will point to the left root
                delete temp; // delete the root
                temp = NULL;
                return root;
            }
            else if(root->left == NULL){ // Check that the root right is NULL
                Tree * temp = root; // We make a pointer which is pointing to the root
                root = root->right; // root will point to the right root
                delete temp; // delete the root
                temp = NULL;
                return root;
            }
            else{
                Tree * temp = minValueNode(root->right); //node with two children: Get the inorder successor
                root->data = temp->data; // Copy the inorder successor's content to this node
                root->right = dele(root->right, temp->data); // Delete the inorder successor
            }
        }
        else{
            if(root->data > del){ // check the root data is Greater then the search
                root->left = dele(root->left , del); // this will move to the left of the root
            }
            else if(root->data < del){ // check the root data is Smaller then the search
                root->right = dele(root->right , del); // this will move to the right of the root
            }
        }
    }
    //Display
    void in_order(){ // Wrap function of the In Order function
        inorder(root);
    }
    void inorder(Tree * root){ // function parameter passing root 
        if(root == NULL){
            return;
        }
        inorder(root->left); // Root moves to the left
        cout<<root->data<<","; // output the data
        inorder(root->right); // Root moves to the right
    }
    void post_order(){ // Wrap function of the post Order function
        postorder(root);
    }
    void postorder(Tree * root){ // function parameter passing root 
        if(root == NULL){
            return;
        }
        cout<<root->data<<","; // output the data
        postorder(root->left); // Root moves to the left
        postorder(root->right); // Root moves to the right
    }
    void pre_order(){ // Wrap function of the post Order function
        pre(root);
    }
    void pre(Tree * root){ // function parameter passing root 
        if(root == NULL){
            return;
        }
        pre(root->left); // Root moves to the left
        pre(root->right); // Root moves to the right
        cout<<root->data<<","; // output the data
    }
};
int main(){
    BST obj;
    obj.insert(5);
    obj.insert(3);
    obj.insert(4);
    obj.insert(2);
    obj.insert(7);
    obj.insert(6);
    cout<<" - - - IN - ORDER - - - "<<endl<<"\t";
    obj.in_order();
    cout<<"\n - - - POST - ORDER - - - "<<endl<<"\t";
    obj.post_order();
    cout<<"\n - - - PRE - ORDER - - - "<<endl<<"\t";
    obj.pre_order();
    cout<<"\n - - - DELETE - - - "<<endl<<"\t";
    obj.Delete(3);
    obj.post_order();
    cout<<"\n - - - SEARCHED - - - "<<endl<<"\t";
    obj.Search(6);
    return 0;
}