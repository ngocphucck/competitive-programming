#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;


template <typename _Tp>
struct Node
{
	_Tp value;
	Node<_Tp>* left = nullptr;
	Node<_Tp>* right = nullptr;
};


template <typename _Tp>
class AVLTree
{
	private:
		Node<_Tp>* root = nullptr;

		Node<_Tp>* BST_insert(Node<_Tp>* root, _Tp value)
		{
			if (root == nullptr)
			{
				root = new Node<_Tp>;
				root->value = value;
			}
			else if (root->value > value)
			{
				root->left = BST_insert(root->left, value);
			}
			else
			{
				root->right = BST_insert(root->right, value);
			}
			return root;
		}

		int height(Node<_Tp>* root)
		{
			if (root == nullptr)
				return -1;
			else 
				return max(height(root->left), height(root->right)) + 1;
		}

		/*
		 *		 0
		 *	    / \
		 *	   0   #
		 *	  / \
		 *   #   #
		 * */
		Node<_Tp>* right_rotation(Node<_Tp>* root)
		{
			Node<_Tp>* left_child = root->left;
			root->left = left_child->right;
			left_child->right = root;

			return left_child;
		}

		/*
		 *     0
		 *    / \
		 *   #   0 
		 *      / \
		 *     #   #
		 * */
		Node<_Tp>* left_rotation(Node<_Tp>* root)
		{
			Node<_Tp>* right_child = root->right;
			root->right = right_child->left;
			right_child->left = root;

			return right_child;
		}


		Node<_Tp>* update(Node<_Tp>* root)
		{
			Node<_Tp>* left_child = root->left;
			Node<_Tp>* right_child = root->right;

			if (height(root->left) - height(root->right) >= 2)
			{
				if (height(left_child->left) > height(left_child->right))
					root = right_rotation(root);
				else
				{
					root->left = left_rotation(root->left);
					root = right_rotation(root);
				}
			}
			else if (height(root->right) - height(root->left) >= 2)
			{
				if (height(root->right) > height(root->left))
					root = left_rotation(root);
				else
				{
					root->right = left_rotation(root->right);
					root = left_rotation(root);
				}
			}
			
			if (root->left != nullptr)
				root->left = update(root->left);
			if (root->right != nullptr)
				root->right = update(root->right);
			return root;
		}

		void traversal(Node<_Tp>* root)
		{
			if (root == nullptr)
				return;
			traversal(root->left);
			cout << "<" << height(root) << "," << root->value << ">" << endl;
			traversal(root->right);
		}

	public:
		void insert(_Tp value)
		{
			root = BST_insert(root, value);
			root = update(root);
		}

		void build_avl_tree(vector<_Tp> list)
		{
			for(size_t i = 0; i < list.size(); ++i)
				insert(list[i]);
		}

		void display()
		{
			traversal(root);
		}

};


int main()
{
	vector<int> list(10000);
	generate(list.begin(), list.end(), []() -> int {
			return rand() % 100; 
			});
	auto start = high_resolution_clock::now();
	AVLTree<int> avl_tree;
	avl_tree.build_avl_tree(list);
	auto end = high_resolution_clock::now();
	avl_tree.display();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "\nExcute time: " << duration.count() << " microseconds" << endl;
}
