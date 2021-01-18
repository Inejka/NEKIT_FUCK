//
// Created by inejka on 18.01.2021.
//

#ifndef NEKIT_FUCK_FUCKING_TREE_H
#define NEKIT_FUCK_FUCKING_TREE_H
#include <iostream>

class f_tree {
	struct Node {
		int content;
		Node* next, * son;
		Node(int content)
				:content(content) { }
	};

	void find_and_add(Node* tmp, int content)
	{
		while (tmp->next)tmp = tmp->next;
		tmp->next = new Node(content);
	}

	void print(Node* parent, Node* son)
	{
		auto tmp = son;
		while (tmp) {
			std::cout << parent->content << "->" << tmp->content << '\n';
			tmp = tmp->next;
		}
		while (son) {
			print(son, son->son);
			son = son->next;
		}
	}

	void erase(Node*& to_erase)
	{
		auto tmp = to_erase->son;
		while (tmp) {
			auto tmp1 = tmp;
			tmp = tmp->next;
			erase(tmp1);
		}
		delete to_erase;
		to_erase = nullptr;
	}

	Node* search(Node* find, int& context)
	{
		if (find->content==context)return find;
		Node* to_return = nullptr;
		auto tmp = find->son;
		while (tmp) {
			to_return = search(tmp, context);
			if (to_return)return to_return;
			tmp = tmp->next;
		}
		return to_return;
	}

	void search_prev_and_fix(Node* find, int& context)
	{
		if (find->son->content==context) {
			find->son = find->son->next;
			return;
		}
		Node* to_return = nullptr;
		auto tmp = find->son;
		while (tmp) {
			if (tmp->next->content==context) {
				tmp->next = tmp->next->next;
				return;
			}
			tmp = tmp->next;
		}

		tmp = find->son;
		while (tmp) {
			search(tmp, context);
			tmp = tmp->next;
		}
	}

	Node* root = nullptr;

public:

	void add_elem(int content)
	{
		if (root)root->content = content;
		else root = new Node(content);
	}
	void add_leaf(int content)
	{
		if (root->son)find_and_add(root->son, content);
		else root->son = new Node(content);
	}
	f_tree search(int content)
	{
		f_tree to_return;
		to_return.root = search(this->root, content);
	}

	bool empty()
	{
		return !root;
	}

	void print()
	{
		print(root, root->son);
	}

	void erase(f_tree to_erase)
	{
		search_prev_and_fix(this->root, to_erase.root->content);
		erase(to_erase.root);
	}
};

#endif //NEKIT_FUCK_FUCKING_TREE_H
