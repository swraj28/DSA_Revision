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

class Solution {
public:

	double median_of_sorted_arrays(vector<int> &nums1, int n, vector<int> &nums2, int m) {

		if (n > m) {
			return median_of_sorted_arrays(nums2, m, nums1, n); ////ensuring that binary search happens on minimum size array
		}

		int st = 0, end = n;// Picking number of elements between zero and n.

		int median_pos_element = ((n + m) + 1) / 2;

		// If the total number of elements are even then we need to pick one element from left partition and one element from right partition.
		// If the total number of elements are odd then the median is present in the left partion itself.

		while (st <= end) {

			int cut1 = (st + (end - st) / 2); // No of elements we are chosing from array of size n.
			int cut2 = median_pos_element - cut1; // No. of elements we are chosing from array of size m.

			int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
			int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

			int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
			int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

			if (l1 <= r2 && l2 <= r1) {  // We got a valid partition
				if ((n + m) % 2 != 0) {
					return max({l1, l2});
				}

				return (max(l1, l2) + min(r1, r2)) / 2.0;
			} else if (l1 > r2) {
				end = cut1 - 1;
			} else {
				st = cut1 + 1;
			}
		}

		return 0.0;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		return median_of_sorted_arrays(nums1, (int)nums1.size(), nums2, (int)nums2.size());
	}
};