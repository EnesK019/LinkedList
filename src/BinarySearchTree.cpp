/**
* @file BinarySearchTree.cpp
* @description Ağaç yapısı oluşturulur (ekleme, çıkarma, sıralama)
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "BinarySearchTree.hpp"

void BinarySearchTree::SearchAndAdd(Node *&subNode, Doku *newDoku)
{
	if(subNode == NULL)
		subNode = new Node(newDoku);
	
	else if(newDoku->centerNumber() <= subNode->doku->centerNumber())
		SearchAndAdd(subNode->left,newDoku);
		
	else if(newDoku->centerNumber() > subNode->doku->centerNumber())
		SearchAndAdd(subNode->right,newDoku);
	
	else return;
}

bool BinarySearchTree::SearchAndDelete(Node *&subNode, Doku *doku)
{
	if(subNode == NULL) return false;

	if(subNode->doku == doku) return DeleteNode(subNode);

	else if(doku < subNode->doku) return SearchAndDelete(subNode->left,doku);

	else return SearchAndDelete(subNode->right,doku);
}

bool BinarySearchTree::DeleteNode(Node *&subNode)
{
	Node *DelNode = subNode;
			
	if(subNode->right == NULL) subNode = subNode->left;

	else if(subNode->left == NULL) subNode = subNode->right;

	else
    {
		DelNode = subNode->left;
		Node *parent = subNode;
		while(DelNode->right != NULL)
        {
			parent = DelNode;
			DelNode = DelNode->right;
		}
		subNode->doku = DelNode->doku;
		if(parent == subNode) subNode->left = DelNode->left;
            
		else parent->right = DelNode->left;
	}
	delete DelNode;
	return true;
}

void BinarySearchTree::inorder(Node *subNode)
{
	if(subNode != NULL)
    {
		inorder(subNode->left);
		cout<<subNode->doku->centerNumber()<<" ";
		inorder(subNode->right);
	}
}

void BinarySearchTree::preorder(Node *subNode)
{
	if(subNode != NULL)
    {
		cout<<subNode->doku->centerNumber()<<" ";
		preorder(subNode->left);
		preorder(subNode->right);
	}
}

void BinarySearchTree::postorder(Node *subNode)
{
	if(subNode != NULL)
    {
		postorder(subNode->left);
		postorder(subNode->right);
		cout<<subNode->doku->centerNumber()<<" ";
	}
}
		
int BinarySearchTree::Height(Node *subNode)
{
	if(subNode == NULL) return -1;
	return 1+max(Height(subNode->left), Height(subNode->right));
}

void BinarySearchTree::PrintLevel(Node *subNode,int level)
{
	if(subNode == NULL) return;
	if(level == 0) cout<< subNode->doku->centerNumber() <<" ";
	else
    {
		PrintLevel(subNode->left, level-1);
		PrintLevel(subNode->right, level-1);
	}
}

bool BinarySearchTree::Search(Node *subNode, Doku *item)
{
	if(subNode == NULL) return false;
	if(subNode->doku == item) return true;
	if(item < subNode->doku) return Search(subNode->left,item);
	else return Search(subNode->right,item);
}

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

bool BinarySearchTree::isEmpty()const
{
	return root == NULL;
}

void BinarySearchTree::Add(Doku *newDoku)
{
	SearchAndAdd(root, newDoku);
}

void BinarySearchTree::Delete( Doku *doku)
{
	if(SearchAndDelete(root,doku) == false) throw "Item not found.";
}

void BinarySearchTree::inorder()
{
	inorder(root);
}

void BinarySearchTree::preorder()
{
	preorder(root);
}

void BinarySearchTree::postorder()
{
	postorder(root);
}

void BinarySearchTree::levelorder()
{
	int h = Height();
	for(int level = 0; level <= h; level++)
    {
		PrintLevel(root, level);
	}
}

int BinarySearchTree::Height()
{
	return Height(root);
}

bool BinarySearchTree::Search(Doku *doku)
{
	return Search(root, doku);
}

void BinarySearchTree::Clear()
{
	while(!isEmpty()) DeleteNode(root);
}

Node* BinarySearchTree::rootbul()
{
    return root;
}

bool BinarySearchTree::	isBalanced(Node* root)
{
    int lh;
    int rh;
    if (root == NULL)
        return 1;

    lh = Height(root->left);
    rh = Height(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
 
    return 0;
}

void BinarySearchTree::dokulariyariyaindir(Node *subNode, BinarySearchTree *bst)
{
	if(subNode != NULL)
	{
		dokulariyariyaindir(subNode->left, bst);
		dokulariyariyaindir(subNode->right, bst);
		for(int i = 0; i < subNode->doku->size(); i++)
		{
			if(subNode->doku->elementAt(i) % 2 == 0)
			{
				subNode->doku->yariyaIndir(i);
			}
		}
		RadixSort *sortDoku = new RadixSort(subNode->doku, subNode->doku->size());
		subNode->doku = sortDoku->Sort();
		delete sortDoku;
		bst->Add(subNode->doku);
	}
}

BinarySearchTree* BinarySearchTree::mutasyonlumu(Node *subNode)
{
	if(subNode->doku->centerNumber() % 50 == 0)
	{		
		BinarySearchTree *bst = new BinarySearchTree();
		dokulariyariyaindir(subNode, bst);
		return bst;
	}
	return this;
}

BinarySearchTree::~BinarySearchTree()
{
    Clear();
}