#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int> & nums, int target) {
		vector<vector<int>> result;

		if (nums.size() < 4 )
			return result;
		sort(nums.begin(), nums.end());

		for (int i=0; i<nums.size() - 3; ++i) {
			for (int j=i+1; j<nums.size() - 2; ++j) {
				
				int k = j+1;
				int l = nums.size() -1;

				while ( k < l) {
					int num = nums[i] + nums[j] + nums[k] + nums[l];

					if (num > target) {
						--l;
					} else if (num < target) {
						k++;
					} else {
						result.push_back({nums[i], nums[j], nums[k], nums[l]});
						++k;
						--l;
					}
				}
			}
		}

		return result;
	}
	
};

int main(int argc, char const *argv[])
{
	vector<int> v = {-3, -1, -1,0,1,3,4,0,5,6,8};
	Solution *s = new Solution();
	vector<vector<int>> r = s->fourSum(v, 5);

	if (r.size()) {
		for (int i=0; i<r.size(); i++) {
			for (int j=0; j<r[i].size(); j++) {
				cout << r[i][j] << " ";
			}
			cout << endl;
		}
		 cout << endl;
	}
	return 0;
}