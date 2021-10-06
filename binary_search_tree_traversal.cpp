// Program to implement Binary tree traversal using recursion in C++

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BTNode
{
	struct BTNode *Lchild;
	int data;
	struct BTNode *Rchild;
};
struct BTNode *root;

// Inorder Traversal
void inorder_traversal(struct BTNode *rt)
{
    if(rt!=NULL)
    {
	inorder_traversal(rt->Lchild);
	printf("%d\t", rt->data);
	inorder_traversal(rt->Rchild);
    }
}

// Preorder Traversal
void preorder_traversal(struct BTNode *rt)
{
    if(rt!=NULL)
    {
	printf("%d\t", rt->data);
	preorder_traversal(rt->Lchild);
	preorder_traversal(rt->Rchild);
    }
}

// PostOrder Traversal
void postorder_traversal(struct BTNode *rt)
{
   if(rt!=NULL)
   {
	postorder_traversal(rt->Lchild);
	postorder_traversal(rt->Rchild);
	printf("%d\t", rt->data);
   }
}

void place_node(struct BTNode *nnode, struct BTNode *rt)
{
	if(nnode->data < rt->data)
	{
		if(rt->Lchild == NULL)
		{
			rt->Lchild = nnode;
		}
		else
		{
			place_node(nnode, rt->Lchild);
		}
	}
	else
	{
		if(rt->Rchild == NULL)
		{
			rt->Rchild = nnode;
		}
		else
		{
			place_node(nnode, rt->Rchild);
		}
	}
}

void create_node(int val)
{
	struct BTNode *nn;
	nn = (struct BTNode *) malloc(sizeof( struct BTNode) );

	nn->data = val;
	nn->Lchild = NULL;
	nn->Rchild = NULL;

	if(root == NULL)
	{
		root = nn;
	}
	else
	{
		place_node(nn, root);
	}
}

int main()
{
	int ar[25], i, sz;
	root = NULL;

	printf("Enter total numbers of nodes : ");
	scanf("%d", &sz);

	printf("\nEnter %d elements\n", sz);
	for(i=0; i<sz; i++)
	{
		scanf("%d", &ar[i]);
	}

	for(i=0; i<sz; i++)
	{
		create_node(ar[i]);
	}

	printf("\n\nBinary Search Tree created\n");

	printf("\n\nIn-Order Traversal\n");
	inorder_traversal(root);

	printf("\n\nPre-Order Traversal\n");
	preorder_traversal(root);

	printf("\n\nPost-Order Traversal\n");
	postorder_traversal(root);

	return 0;
}

