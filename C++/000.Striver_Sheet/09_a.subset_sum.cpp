#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

void sub_set_sum(vector<int>& nums, int si, vector<int>& result, int &val) {
	if (si == nums.size()) {
		result.push_back(val);
		return;
	}

	// v.push_back(nums[si]);
	val += nums[si];

	sub_set_sum(nums, si + 1, result, val);

	// v.pop_back();//backtrack
	val -= nums[si];

	sub_set_sum(nums, si + 1, result, val);
}

vector<int> subsetSum(vector<int> &num) {

	vector<int> result;
	int val = 0;

	sub_set_sum(num, 0, result, val);

	sort(all(result));

	return result;
}