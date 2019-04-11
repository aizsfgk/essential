#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int index = 1;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[index - 1])
				nums[index++] = nums[i];
		}
		return index;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v = {1,1,2,3,3,4,5,5,6};

	Solution *s = new Solution();

	int r = s->removeDuplicates(v);

	for (int i = 0; i < r; ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;


	return 0;
}


// int removeDuplicates(int arr[], int len) {
// 	if (len == 0) {
// 		return 0;
// 	}

// 	int index = 1;
// 	for (int i=1; i<len; i++) {
// 		if (arr[i] != arr[index]) {
// 			arr[index++] = arr[i];
// 		}
// 	}


// 	return index;
// }

// int main(int argc, char const *argv[])
// {
// 	int arr[9] = {1,1,2,3,3,4,5,5,6};

// 	int r = removeDuplicates(arr, 9);

// 	for (int i = 0; i < r; ++i)
// 	{
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// 	return 0;
// }