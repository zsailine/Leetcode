// Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

#include <algorithm>
#include <vector>
#include <string>
#include <iterator> 
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
	public:
		void	binary(int number, vector<int> &tab)
		{
			int low = 0;
			int high = tab.size() - 1;
			int middle;
			int toReplace = -1;
			int tmp = INT_MAX;
			while (low <= high)
			{
				middle = low + (high - low) / 2;
				if (tab[middle] < number)
					low = middle + 1;
				else
				{
					if (tmp >= tab[middle])
					{
						tmp = tab[middle];
						toReplace = middle;
					}
					high = middle - 1;
				}
				
			}
			tab[toReplace] = number;
		}
		int lengthOfLIS(vector<int>& nums) {
			vector<int> tab;
			tab.push_back(nums[0]);
			for (size_t i = 1; i < nums.size(); i++)
			{
				if (nums[i] > tab[tab.size() - 1])
					tab.push_back(nums[i]);
				else
					binary(nums[i], tab);
			}
			return (tab.size());
		}
	};

	// int main()
	// {
	// 	vector<int> tab = {7, 7, 7, 7};
	// 	Solution soluce;
	// 	std::cout << soluce.lengthOfLIS(tab) << std::endl;
	// 	return (0);
	// }