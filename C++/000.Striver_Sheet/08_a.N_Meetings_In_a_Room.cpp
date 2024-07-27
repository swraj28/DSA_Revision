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

// The Key Idea here is to shrink the size of the intervals as much as possible and delete the overlapping intervals.

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

	int n = intervals.size();

	if (n == 1) {
		return 0;
	}

	sort(all(intervals));

	// for (int i = 0; i < n; i++) {
	// 	cout << intervals[i][0] << " " << intervals[i][1] << endl;
	// }

	int r = intervals[0][1]; // first interval extreme

	int cnt = 0;

	for (int i = 1; i < n; i++) {

		int l1 = intervals[i][0], r1 = intervals[i][1]; // Second Interval

		if (l1 <= r) {
			r = min(r, r1);
			cnt++;
		} else {
			r = r1;
		}
	}

	return cnt;
}

int maxMeetings(int start[], int end[], int n) {

	vector<vector<int>> v;

	for (int i = 0; i < n; i++) {
		v.pb({start[i], end[i]});
	}

	int cnt = eraseOverlapIntervals(v);

	return (n - cnt);
}