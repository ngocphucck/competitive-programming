#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;


template <typename _Tp>
vector<_Tp> merge(vector<_Tp> list1, vector<_Tp> list2)
{
	vector<_Tp> sorted_list;
	auto iter1 = list1.begin();
	auto iter2 = list2.begin();

	while (true)
	{
		if (iter1 == list1.end() && iter2 == list2.end())
			break;
		else if (iter1 == list1.end())
		{
			sorted_list.push_back(*iter2);
			iter2++;
		}
		else if (iter2 == list2.end())
		{
			sorted_list.push_back(*iter1);
			iter1++;
		}
		else if (*iter1 > *iter2)
		{
			sorted_list.push_back(*iter2);
			iter2++;
		}
		else 
		{
			sorted_list.push_back(*iter1);
			iter1++;
		}
	}

	return sorted_list;
}


template <typename _Tp>
vector<_Tp> merge_sort(vector<_Tp> list, size_t begin, size_t end)
{
	if (begin == end)
		return vector<_Tp>({list[begin]});
	else
	{
		int mid = (begin + end) / 2;
		vector<_Tp> left = merge_sort<_Tp>(list, begin, mid);
		vector<_Tp> right = merge_sort<_Tp>(list, mid + 1, end);
		return merge<_Tp>(left, right);
	}
}


int main()
{
	vector<int> list(100000);
	generate(list.begin(), list.end(), []() -> int {
			return rand() % 100; 
			});
	auto start = high_resolution_clock::now();
	/*---------------------------------------------------------------------------------------*/
	vector<int> result = merge_sort<int>(list, 0, list.size() - 1);
	cout << "\nResult: ";
	for (auto iter = result.begin(); iter != result.end(); ++iter)
		cout << *iter << ' ';
	/*---------------------------------------------------------------------------------------*/
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nExcute time: " << duration.count() << " microseconds\n";
}

