#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
	时间复杂度 O(n)
	
 */


class Solution {
public:
	int longestConsecutive(const vector<int> &nums) {
		unordered_set<int> my_set;

		for (auto num : nums)
			my_set.insert(num);


		int longest = 0;

		for (auto num : nums) {
			int length = 1;
			for (int j = num - 1; my_set.find(j) != my_set.end(); --j) {
				my_set.erase(j);
				++length;
			}

			for (int j = num + 1; my_set.find(j) != my_set.end(); ++j) {
				my_set.erase(j);
				++length;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};


int main(int argc, char const *argv[])
{
	Solution *s = new Solution;
	vector<int> v = {7,1,3,2,5,9,10};
	int len = s->longestConsecutive(v);

	cout << "res : " << len << endl;
	return 0;
}