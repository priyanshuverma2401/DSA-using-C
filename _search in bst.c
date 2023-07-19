#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*temp;

struct node*create(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

struct node*insert(struct node*root,int x)
{
    struct node*temp,*prev;
    temp=root;
    while(temp!=NULL) {

        prev=temp;
        if(x>temp->data)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }

    }
    if(x>prev->data)
    {
        prev->right=create(x);
    }
    else
    {
        prev->left=create(x);
    }
    printf("node inserted succesfully\n");
}

struct node*search(struct node*root,int val)
{
    if(root==NULL)
        return NULL;
    if (val==root->data)
        return root;
    else if(val<root->data)
        return search(root->left,val);
    else
        return search(root->right,val);
}

void inorder(struct node*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d(%p) ",root->data,root);
    inorder(root->right);
}

int main()
{
    struct node*root;
    printf("enter root node\n");
    int rootNode;
    scanf("%d",&rootNode);
    root=create(rootNode);
    int a;
    printf("enter elements\n");
    scanf("%d",&a);
    while(a!=-1)
    {
        insert(root,a);
        printf("\nenter node data: ");
        scanf("%d",&a);
    }
    printf("\ntree created successfully.");
    printf("\ninorder transversal is: ");
    inorder(root);
    printf("\nenter the value to be searched: ");
    int val;
    while(1) {
        scanf("%d",&val);
        struct node*result=search(root,val);
        if(result==NULL)
            printf("\ndata not found.\n");
        else printf("\ndata %d found\n",result->data);
    }

    return 0;
}