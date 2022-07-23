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

// Similar Question :- Count Inversion in an array

class Solution {
public:

	int merge(vector<int> &nums, int st, int end) {

		int mid = (st + (end - st) / 2);

		int total = 0;
		int j = mid + 1;
		for (int i = st; i <= mid; i++) {

			while (j <= end && nums[i] > 2LL * nums[j]) {
				j++;
			}

			total += (j - (mid + 1));
		}


		/***************************************************************/

		vector<int> temp((end - st) + 1);

		int i = st;
		j = mid + 1;

		int k = 0;

		while (i <= mid && j <= end) {
			if (nums[i] <= nums[j]) {
				temp[k++] = nums[i];
				i++;
			} else {
				temp[k++] = nums[j];

				j++;
			}
		}

		while (i <= mid) {
			temp[k++] = nums[i];
			i++;
		}

		while (j <= end) {
			temp[k++] = nums[j];
			j++;
		}

		int pos = 0;

		for (int x = st; x <= end; x++) {
			nums[x] = temp[pos];
			pos++;
		}

		return total;
	}

	int get_Inversions(vector<int> &nums, int st, int end) {

		if (st == end) {
			return 0;
		}

		int cnt = 0;

		int mid = (st + (end - st) / 2);

		cnt += get_Inversions(nums, st, mid);
		cnt += get_Inversions(nums, mid + 1, end);

		cnt += merge(nums, st, end);

		return cnt;
	}

	int reversePairs(vector<int>& nums) {

		int n = nums.size();

		return get_Inversions(nums, 0, n - 1);
	}
};