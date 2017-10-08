#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:

	int longestConsecutive(const vector<int> &nums) {
		unordered_set<int> my_set;
		
		for (auto i : nums) my_set.insert(i);

		int longest = 1;
		for (auto i : nums) {
			int length = 1;

			for (int j = i - 1; my_set.find(j) != my_set.end(); j--) {
				length++;
				my_set.erase(j);
			}

			for (int j = i + 1; my_set.find(j) != my_set.end(); j++) {
				length++;
				my_set.erase(j);
			}

			longest = max(length, longest);
		}
		return longest;
	}

	void print(unordered_set<int> &my_set) {
		for (unordered_set<int>::iterator iter = my_set.begin(); 
			iter != my_set.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}
};

int main(int argc, char *argv[]) {
	vector<int> nums;
	nums.push_back(100); nums.push_back(4); nums.push_back(200);
	nums.push_back(1); nums.push_back(3); nums.push_back(2);
	
	unordered_set<int> my_set;
	for (auto i : nums) my_set.insert(i);

	Solution s;
	s.print(my_set);

	cout << "longest consecutive: " << s.longestConsecutive(nums) << endl;

	system("pause");
	return 0;
}