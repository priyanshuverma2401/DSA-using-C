//avl tree implementation using c
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
    int hyt;
};
int max(int a,int b)
{
    return (a>b)?a:b;
}
int height(struct node*n)
{
    if(n==0)return 0;
    return n->hyt;
}
struct node* create(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=0;
    newnode->right=0;
    newnode->hyt=1;
    return newnode;
}
struct node*rytrtt(struct node*y)
{
    struct node*x=y->left;
    struct node*t2=x->right;
    x->right=y;
    y->left=t2;
    y->hyt=max(height(y->left),height(y->right))+1;
    x->hyt=max(height(x->left),height(x->right))+1;
    return x;
}
struct node*lftrtt(struct node*x)
{
    struct node*y=x->right;
    struct node*t2=y->left;
    y->left=x;
    x->right=t2;
    x->hyt=max(height(x->left),height(x->right))+1;
    y->hyt=max(height(y->left),height(y->right))+1;
    return y;
}
int bf(struct node*n)
{
    if(n==0) return 0;
    return (height(n->left)-height(n->right));
}
struct node* insert(struct node*root,int val)
{
    if(root==0) return (create(val));
    if(val<root->data)
        root->left=insert(root->left,val);
    else if(val>root->data)
        root->right=insert(root->right,val);
    else return root;
    root->hyt=1+max(height(root->left), height(root->right));
    int bal=bf(root);
    if(bal>1&&val<root->left->data) return rytrtt(root);
    if(bal<-1&&val>root->right->data) return lftrtt(root);
    if(bal>1&&val>root->left->data)
    {
        root->left=lftrtt(root->left);
        return rytrtt(root);
    }
    if(bal<-1&&val<root->right->data)
    {
        root->right=rytrtt(root->right);
        return lftrtt(root);
    }
    return root;
}
struct node*minValNode(struct node*root)
{
    struct node*curr=root;
    while(curr->left!= NULL) curr=curr->left;
    return curr;
}
struct node*deletenode(struct node*root,int val)
{
    if(root==NULL) return root;
    if(val<root->data) deletenode(root->left,val);
    else if(val>root->data) deletenode(root->right,val);
    else
    {
        if((root->left==NULL)||(root->right==NULL))
        {
            struct node*temp = root->left ?root->left:root->right;
            if(temp==0)
            {
                temp=root;
                root=0;
            }
            else
                *root=*temp;
            free(temp);
        }
        else
        {
            struct node*temp=minValNode(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
    }
    if(root==0) return root;
    root->hyt=1+max(height(root->left),height(root->right));
    int bal=bf(root);
    if(bal<-1&&bf(root->right)<=0) return lftrtt(root);
    if(bal>1&&bf(root->left)>=0) return rytrtt(root);
    if(bal<-1&&bf(root->right)>0)
    {
        root->right=rytrtt(root->right);
        return lftrtt(root);
    }
    if(bal>1&&bf(root->left)<0)
    {
        root->left=lftrtt(root->left);
        return rytrtt(root);
    }
    return root;
}
void inorder(struct node*root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{
    struct node*root=0;
    int data;
    printf("\nenter data (enter -1 to esp)\n");
    while(1)
    {
        scanf("%d",&data);
        if(data==-1) break;
        root=insert(root,data);
    }
    printf("\ninorder transversal is: \n");
    inorder(root);
    return 0;
}