#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*left,*right;
}*temp;

struct node*create(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=0;
    newnode->right=0;
    return newnode;
}

struct node*insert(struct node*root,int n)
{
    struct node*prev;
    temp=root;
    while(temp!=NULL)
    {
        prev=temp;
        if(n>temp->data)
            temp=temp->right;
        else
            temp=temp->left;
    }
    if(n>prev->data)
        prev->right=create(n);
    else
        prev->left=create(n);
    printf("\nnode inserted successfully.\n");
}

void inorder(struct node*root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node*root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void preorder(struct node*root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node*inOrderpre(struct node*root)
{
    root=root->left;
    while(root->right!=NULL)
        root=root->right;
    return root;
}

struct node*deletenode(struct node*root,int val)
{
    struct node*ipre;
    if(root==0) return 0;
    if(root->left==0&&root->right==0)
    {
        free(root);
        return 0;
    }
//SEARCHING FOR A NODE
    if(val<root->data)
        root->left = deletenode(root->left,val);
    else if(val>root->data)
        root->right = deletenode(root->right,val);
    else
    {
        ipre=inOrderpre(root);
        root->data=ipre->data;
        root->left= deletenode(root->left,ipre->data);
    }
    return root;
}

int main()
{
    struct node*root;
    printf("\nenter root data.\n");
    int rootnode;
    scanf("%d",&rootnode);
    root=create(rootnode);
    int a;
    printf("\nenter elements\n");
    scanf("%d",&a);
    while(a!=-1)
    {
        insert(root,a);
        scanf("%d",&a);
    }
    printf("\npreorder traversal is:\n");
    preorder(root);
    printf("\npostorder traversal is \n");
    postorder(root);
    printf("\ninorder traversal is \n");
    inorder(root);
    int delnode;
    printf("\nenter node to be deleted: ");
    scanf("%d",&delnode);
    root=deletenode(root,delnode);
    inorder(root);
    return 0;
}