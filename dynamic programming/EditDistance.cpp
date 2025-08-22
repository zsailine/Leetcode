// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

#include <algorithm>
#include <vector>
#include <string>
#include <iterator> 
#include <iostream>

using namespace std;

class Solution {
	public:
		int minDistance(string word1, string word2)
		{
			int m= word1.size();
			int n = word2.size();
			vector<vector<int>> tab(n + 1, vector<int>(m + 1));
			for (size_t i = 0; i <= m; i++)
				tab[0][i] = i;
			for (size_t i = 0; i <= n; i++)
				tab[i][0] = i; 
			for (size_t i = 1; i <= n; i++)
			{
				for (size_t j = 1; j <= m; j++)
				{
					if (word1[j - 1] == word2[i - 1])
						tab[i][j] = tab[i - 1][j - 1];
					else
						tab[i][j] = 1 + min(min(tab[i - 1][j], tab[i][j - 1]), tab[i - 1][j - 1]);
				}
			}
			return (tab[n][m]);
		}
	};

int main()
{
	Solution soluce;
	std::cout << soluce.minDistance("horse", "ros");
	return (0);
}