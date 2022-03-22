#include <cstddef>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

template <typename _Tp>
_Tp peak_finding_1D(vector<_Tp>& array, size_t head, size_t tail)
{
	size_t peak_position = (head + tail) / 2;
	if (peak_position != head && array[peak_position] < array[peak_position - 1])
		return peak_finding_1D(array, head, peak_position - 1);
	else if (peak_position != tail && array[peak_position] < array[peak_position + 1])
		return peak_finding_1D(array, peak_position + 1, tail);
	else
		return array[peak_position];
}

template <typename _Tp>
_Tp peak_finding_2D(vector<vector<_Tp>>& array, size_t peak_row)
{
	// Find the global maximum in the peak_row row
	// and choose this y axis position for peak_column 
	size_t peak_column;
	_Tp global_value = array[peak_row][0];
	for (size_t i = 0; i < array[peak_row].size(); ++i)
	{
		if (global_value < array[peak_row][i])
		{
			peak_column = i;
			global_value = array[peak_row][i];
		}
	}
	
	// Find the peak value
	if (peak_row != 0 && array[peak_row][peak_column] < array[peak_row - 1][peak_column])
		return peak_finding_2D(array, peak_row - 1);
	else if (peak_row != array.size() - 1 && array[peak_row][peak_column] < array[peak_row + 1][peak_column])
		return peak_finding_2D(array, peak_row + 1);
	else
	   	return array[peak_row][peak_column];
}

int main()
{
	/*static int i = 0;
	vector<int> array_1D(10000000);
	generate(array.begin(), array.end(), []() -> int {
			return i++; 
			});*/
	//vector<int> array_1D = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//vector<int> array_1D = {9, 8, 7, 6, 5, 4, 3, 2, 1}
	//vector<int> array_1D = {3, 1, 5, 2, 6, 2, 9, 7};
	vector<vector<int>> array_2D = {{1, 2, 3, 2, 7, 3},
									{7, 3, 5, 1, 8, 8},
									{3, 62, 2, 0, 21, 21},
									{81, 2, 3, 4, 5, 6}};

	auto start = high_resolution_clock::now();
	/*---------------------------------------------------------------------------------------*/
	//int result = peak_finding_1D<int>(array_1D, 0, array_1D.size() - 1);
	size_t peak_row = (array_2D.size() - 1) / 2;
	int result = peak_finding_2D(array_2D, peak_row);
	/*---------------------------------------------------------------------------------------*/
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Excute time: " << duration.count() << " microseconds\n";
	cout << "Peak value: " << result << "\n";
}
