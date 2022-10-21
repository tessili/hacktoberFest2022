#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left,*right;
}node;
node *root=NULL;

node *createnode(int y){
    node *new=(node*) malloc (sizeof(node));
    new->data=y;
    new->left=NULL;
    new->right=NULL;
    return new;

}
node *insert(node* root,int x){
    
    if(root==NULL){
        return createnode(x);
    }
    else{
        if(root->data<x){
            root->right=insert(root->right,x);
        }
        else
            root->left=insert(root->left,x);
    return root;
    }

}
node* search(node* root,int value){
    while(root!=NULL){
        if(root->data==value)
        return root;
        else if(root->data>value){
            root=root->left;
        }
        else
        root=root->right;
    }
        return NULL;
}

node *successor(node* root){
    node *current=root;
    while(current&& current->left!=NULL)
        current=current->left;
    return current;

}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);

    }
}
void preorder(node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);

    }
}


int height(node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int ldepth=height(root->left);
        int rdepth=height(root->right);
        if(ldepth>rdepth){
            return ldepth+1;
        }
        else
        return rdepth+1;
    }
}

node *delete (node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {

        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = successor(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

int main(){
    root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);


  printf("\nInorder traversal: ");
  inorder(root);
  printf("\nPreorder traversal: ");
  preorder(root);
  printf("\nPostorder traversal: ");
  postorder(root);
  int h=height(root);
  printf("\n%d",h);
  root=delete(root,1);
  printf("\nInorder traversal: ");
  inorder(root);



    return 0;
}