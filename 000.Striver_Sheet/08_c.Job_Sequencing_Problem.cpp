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

struct Job {
	int id;	 // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};

class Solution {
public:
	vector<int> JobScheduling(Job arr[], int n) {

		vector<pair<int, int>> v(n);

		int mx_deadline = INT_MIN;

		for (int i = 0; i < n; i++) {
			v[i] = {arr[i].profit, arr[i].dead};
			mx_deadline = max(mx_deadline, arr[i].dead);
		}

		sort(all(v), greater < pair<int, int>>());

		vector<int> available(mx_deadline + 1, 0);

		int cnt = 0, total = 0;

		for (int i = 0; i < n; i++) {
			for (int j = v[i].ss; j >= 1; j--) {
				if (available[j] == 0) {
					available[j] = 1;

					cnt++;
					total += v[i].ff;
					break;
				}
			}
		}

		return {cnt, total};
	}
};