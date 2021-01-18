//
// Created by inejka on 18.01.2021.
//

#ifndef NEKIT_FUCK_BIN_TREE_H
#define NEKIT_FUCK_BIN_TREE_H

#include <iostream>

using namespace std;

class Tree {
	class Node {
		Node* left = nullptr;
		Node* right = nullptr;
		int content;

		Node(int content)
		{
			this->content = content;
		}

		void print()
		{
			cout << content << " ";
			if (left!=nullptr) left->print();
			if (right!=nullptr) right->print();
		}

		friend Tree;
	};

	void erase(Node*& to_erase)
	{
		if (!to_erase)return;
		if (to_erase->left)erase(to_erase->left);
		if (to_erase->right)erase(to_erase->right);
		auto tmp = to_erase;
		to_erase= nullptr;
		delete tmp;
	}

	Node* search(Node* find, int& context)
	{
		if (find->content==context)return find;
		Node* to_return = nullptr;
		if (find->right)to_return = search(find->right, context);
		if (!to_return && find->left)to_return = search(find->left, context);
		return to_return;
	}

	Node* root = nullptr;
public:

	void add_element(int content)
	{
		if (root==nullptr) root = new Node(content);
		else root->content = content;
	}

	void add_element(int content, char par)
	{
		if (par=='l')
			if (root->left)
				root->left->content = content;
			else root->left = new Node(content);
		if (par=='r')
			if (root->right)
				root->right->content = content;
			else root->right = new Node(content);
	}

	void delete_element()
	{
		erase(root);
	}

	void delete_element(char par)
	{
		if (par=='l')
			erase(root->left);
		if (par=='r')
			erase(root->right);
	}

	Tree get_leaf(char par)
	{
		Tree to_return;
		if (par=='l')
			to_return.root = this->root->left;
		if (par=='r')
			to_return.root = this->root->right;
		return to_return;
	}

	Tree search(int context)
	{
		Tree to_return;
		to_return.root = search(this->root, context);
	}

	void print()
	{
		root->print();
	}

	bool empty()
	{
		return !root;
	}

};

#endif //NEKIT_FUCK_BIN_TREE_H
