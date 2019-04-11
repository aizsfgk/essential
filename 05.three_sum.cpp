#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;


class Solution {
public:
	vector<vector<int> > three_sum(const vector<int> &nums) {
		unordered_set<int> my_set;

		vector<vector<int>> all_res;
		for (int i = 0; i < nums.size(); ++i) {
			my_set.insert(nums[i]);
		}

		for (int i=0; i< nums.size(); ++i) {
			for(int j=i+1; j<nums.size(); ++j) {
				int sum = nums[i] + nums[j];
				// cout << "sum : " << sum << endl;
				int target = -sum;
				// cout << "target: " << target << endl;
				auto iter = my_set.find(target);

				if ( iter != my_set.end() && nums[i] <= nums[j] && nums[j]<= *iter) {
					// res.push_back(nums[i]);
					// res.push_back(nums[j]);
					// res.push_back(*iter);
					all_res.push_back({nums[i], nums[j], *iter});
					break;
				}
			}
		}
		return all_res;
	}
};


int main(void)
{
	Solution *s = new Solution;

	vector<int> v = { -3,-2, -1, 1, 2, 3,  4, 8};
	vector<vector<int>> res = s->three_sum(v);

	if (!res.empty()) {
		for (auto i : res) {
			for (auto j : i) {
				cout << j  << " ";
			}
			cout << endl;
		}
	} else {
		cout << "res is null" << endl;
	}
	return 0;
}