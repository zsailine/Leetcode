#include <algorithm>
#include <vector>
#include <iterator> 
#include <iostream>

using namespace std;

class Solution {
	public:
		static vector<int> twoSum(vector<int>& nums, int target) {
			for (std::vector<int>::iterator i = nums.begin(); i < nums.end(); i++)
			{
				std::vector<int>::iterator tmp = std::find(i + 1, nums.end(), (target - *i));
				if (tmp != nums.end())
				{
					return (std::vector<int>{int(i - nums.begin()), int(tmp - nums.begin())});
				}
			}
			return (nums);
		}
	};