#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int removeElement(vector<int> &nums, int target) {
		int index = 0;

		for (int i=0; i < nums.size(); ++i) {
			if (nums[i] != target) {
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};

int main(void) {
	vector<int> v = {1,2,3,4,3,3,2,4,1};
	Solution *s = new Solution;

	int len = s->removeElement(v, 3);

	cout << "len: " << len << endl;
	
	return 0;
}