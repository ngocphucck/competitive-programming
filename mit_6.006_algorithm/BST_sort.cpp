#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;


template <typename _Tp>
struct Node
{
	_Tp value;	
	int subtree_len = 0;
	Node<_Tp>* left = nullptr;
	Node<_Tp>* right = nullptr;	
};


template <typename _Tp>
class BST
{
	private:
		Node<_Tp>* root = nullptr;

		Node<_Tp>* insert(_Tp value, Node<_Tp>* root)
		{
			if (root == nullptr)
			{
				root = new Node<_Tp>;
				root->value = value;
			}
			else if (root->value > value)
				root->left = insert(value, root->left);
			else
				root->right = insert(value, root->right);
			root->subtree_len ++;

			return root;
		}

		void travers(Node<_Tp>* root)
		{
			if (root == nullptr)
				return;
			else 
			{
				travers(root->left);
				cout << "<" << root->value << "," << root->subtree_len << ">\n";
				travers(root->right);
			}
		}
		
	public:
		void build_bst_tree(vector<_Tp> list)
		{
			for (size_t i = 0; i < list.size(); ++i)
			{
				root = insert(list[i], root);
			}
		}

		void insert(_Tp value)
		{
			root = insert(value, root);
		}	

		void display()
		{
			travers(root);
		}

};


template <typename _Tp>
void bst_sort(vector<_Tp> list)
{

}

int main()
{
	vector<int> list = {3, 1, 8, 4, 6, 2, 3, 5, 1, 0, 2, 3};
	auto start = high_resolution_clock::now();
	BST<int> bst_tree;
	bst_tree.build_bst_tree(list);
	bst_tree.display();
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "\nExcute time: " << duration.count() << " microseconds" << endl;
}
