// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
	public:
		static vector<int> spiralOrder(vector<vector<int>>& matrix) {
			int total = matrix.size() * matrix[0].size();
			int topLeft[2] = {0, 0};
			int topRight[2] = {0, (int)matrix[0].size() - 1};
			int bottomLeft[2] = {(int)matrix.size() - 1, 0};
			int bottomRight[2] = {(int)matrix.size() - 1, (int)matrix[0].size() - 1};
			vector<int> result;
	
			while (result.size() < total) {
				for (int j = topLeft[1]; j <= topRight[1] && result.size() < total; ++j)
					result.push_back(matrix[topLeft[0]][j]);
				for (int i = topRight[0] + 1; i <= bottomRight[0] && result.size() < total; ++i)
					result.push_back(matrix[i][topRight[1]]);
				for (int j = bottomRight[1] - 1; j >= bottomLeft[1] && result.size() < total; --j)
					result.push_back(matrix[bottomRight[0]][j]);
				for (int i = bottomLeft[0] - 1; i > topLeft[0] && result.size() < total; --i)
					result.push_back(matrix[i][bottomLeft[1]]);
				topLeft[0]++; topLeft[1]++;
				topRight[0]++; topRight[1]--;
				bottomLeft[0]--; bottomLeft[1]++;
				bottomRight[0]--; bottomRight[1]--;
			}
			for (size_t index = 0 ; index < result.size(); index++)
				std::cout << result[index] <<  " ";
			std::cout << std::endl;
			return result;
		}
	};

	int main()
	{
		vector<int> tmp = {1, 2, 3};
		vector<int> tmp1 = {4, 5, 6};
		vector<int> tmp2 = {7, 8, 9};
		vector<vector<int>> matrix = {tmp, tmp1, tmp2};
		Solution::spiralOrder(matrix);
		return (0);
	}