#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int remove_two_ele(vector<int> &nums) {
		if (nums.size() <= 2)
			return nums.size();

		int index = 2;
		for (int i=2; i<nums.size(); i++) {
			if (nums[i] != nums[index - 2]) {
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};


int main(int argc, char const *argv[])
{
	vector<int> v = {1,2,2,2,3,4,4,4,5,5,6,7,7,7};
	Solution *s = new Solution;
	int len = s->remove_two_ele(v);

	for (int i=0; i< len; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}