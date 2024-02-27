#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Doku.hpp"
#include "RadixSort.hpp"

struct Node
{
    Doku *doku;
    Node *left;
    Node *right;
        
    Node(Doku *dt, Node *lf = NULL, Node *rg = NULL)
	{
		doku = dt;
		left = lf;
		right = rg;
	}
};

class BinarySearchTree
{
	private:	
		Node *root;

		void SearchAndAdd(Node *&subNode, Doku *newNode);
		bool SearchAndDelete(Node *&subNode, Doku *doku);
		bool DeleteNode(Node *&subNode);
		void inorder(Node *subNode);
		void preorder(Node *subNode);
		void postorder(Node *subNode);
		
		void PrintLevel(Node *subNode, int level);
		bool Search(Node *subNode, Doku *doku);

	public:
		
		BinarySearchTree();
		bool isEmpty()const;
		void Add(Doku *newNode);
		void Delete(Doku *doku);
		void inorder();
		void preorder();
		void postorder();
		void levelorder();
		int Height();
		int Height(Node *subNode);
		bool Search(Doku *doku);
		void Clear();
		Node* rootbul();
		bool isBalanced(Node* root);
		void dokulariyariyaindir(Node *subNode, BinarySearchTree *bst);
		BinarySearchTree* mutasyonlumu(Node *subNode);
		~BinarySearchTree();        
};

#endif