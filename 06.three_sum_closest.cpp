#include <iostream>
#include <vector>
#include <iterator>
#include <limits.h>

using namespace std;

/*
	给定一个数组，找到3个值加起来的和最接近target。

 */

class Solution {
public:
	int three_sum_closest(vector<int> &nums, int target) {
		int result = 0;

		int min_gap = INT_MAX;

		sort(nums.begin(), nums.end());

		for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
			auto b = next(a);
			auto c = prev(nums.end());

			while (b < c) {
				int sum = *a + *b + *c;
				int gap = abs(sum - target);

				if (gap < min_gap) {
					result = sum;
					min_gap = gap;
				}

				if (sum < target)
					++b;
				else
					--c;
			}
		}
		return result;
	}
};



int main(void) {
	vector<int> v = {-1, 2, 1, -4, 1};
	Solution *s = new Solution;
	int res = s->three_sum_closest(v, 1);

	cout << "res : " << res << endl;

	return 0;
}