#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>


using namespace std;
using namespace std::chrono;


template <typename _Tp>
void heapify(vector<_Tp>& list, int index, int size)
{
	int left_child = 2 * index;
	int right_child = 2 * index + 1;	
	int max_index = index;

	if (left_child < size && list[left_child] > list[max_index])
		max_index = left_child;
	if (right_child < size && list[right_child] > list[max_index])
		max_index = right_child;
	if (max_index != index)
	{
		swap<_Tp>(list[index], list[max_index]);
		heapify(list, max_index, size);
	}
}


template <typename _Tp>
void build_heap(vector<_Tp>& list, int length)
{
	for (int i = (length - 1) / 2; i >= 0; --i)
	{
		heapify<_Tp>(list, i, length);
	}
}


template <typename _Tp>
vector<_Tp>& heap_sort(vector<_Tp>& list)
{
	for (int i = 0; i < list.size(); ++i)
	{
		build_heap<_Tp>(list, list.size() - i);
		swap<_Tp>(list[0], list[list.size() - 1 - i]);
	}
	return list;
}


int main()
{
	vector<int> list(100000);
	generate(list.begin(), list.end(), []() -> int {
			return rand() % 100; 
			});
	auto start = high_resolution_clock::now();
	/*---------------------------------------------------------------------------------------*/
	vector<int> result = heap_sort(list);
	cout << "\nResult: ";
	for (auto iter = result.begin(); iter != result.end(); ++iter)
		cout << *iter << ' ';
	/*---------------------------------------------------------------------------------------*/
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nExcute time: " << duration.count() << " microseconds\n";
}
