#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<int> two_sum(const vector<int> &arr, int target) {
		// 1. 暴力破解法
		vector<int> res;
		// for (int i=0; i<arr.size(); i++) {
		// 	for (int j=i+1; j<arr.size(); j++) {
		// 		if (arr[i] == target - arr[j]) {
		// 			res.push_back(i);
		// 			res.push_back(j);
		// 			break;
		// 		}
		// 	}
		// }
		// return res;
		
		// 2 hash法
		unordered_map<int, int> my_map;

		for (int i=0; i<arr.size(); i++) {
			my_map[arr[i]] = i;
		}

		for (int i=0; i<arr.size();i++) {
			auto iter = my_map.find(target - arr[i]);
			if (iter != my_map.end() && i < iter->second) {
				res.push_back(i);
				res.push_back(iter->second);
				break;
			}
		}
		return res;
	
	}
};


int main(int argc, char const *argv[])
{
	vector<int> v = {1,2,3,4,6,7,8};

	Solution *s = new Solution;

	vector<int> res;
	res = s->two_sum(v, 9);


	for (auto i : res) {
		cout << " res : " << i << endl;
	}

	return 0;
}