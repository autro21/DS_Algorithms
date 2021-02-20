//============================================================================
// Name        : test.cpp
// Author      : TheAngel
// Version     :
// Copyright   : Your copyright notice
// Description : Binary Search Tree
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;

#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//-------------------------------------------------------------//
#ifndef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1<<" | ";
	__f(comma+1, args...);
}
#else
#define debug(...)
#endif

struct node{
	int val;
	node* right;
	node* left;
	node(int vl): val(vl), right(nullptr), left(nullptr)
	{

	};
};
void insert_value(int v, node* root)
{
	if(root == nullptr)
	{
		root = new node(v);
		return;
	}

	if(v > root->val)
	{
		if(root->right == nullptr)
			root->right = new node(v);
		else
			insert_value(v, root -> right);
	}
	else
	{
		if(root->left == nullptr)
			root->left = new node(v);
		else
			insert_value(v, root->left);
	}
}
void inOrder(node* root){
	if(root == nullptr)
		return;
	inOrder(root->left);
	cout << (root->val) << " ";
	inOrder(root->right);
}
void inOrder(node* root){
	if(root == nullptr)
		return;

	//left root right
	inOrder(root->left);
	cout << (root->val) << " ";
	inOrder(root->right);
}

void preOrder(node* root){
	if(root == nullptr)
		return;

	//root left right
	cout << (root->val) << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node* root){
	if(root == nullptr)
		return;

	//left right root
	postOrder(root->left);
	postOrder(root->right);
	cout << (root->val) << " ";
}

int main() {
	int n;
	cin >> n;
	node* bst = nullptr;
	for(int i = 0; i < n; ++i)
	{
		int u;
		cin >> u;
		if(bst == nullptr)
			bst = new node(u);
		else
			insert_value(u, bst);

	}
	//call above functions
	return 0;
}
