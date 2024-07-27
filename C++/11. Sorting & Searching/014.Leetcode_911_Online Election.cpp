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

// Brute Force:- o(n) for every query of q.

class TopVotedCandidate {
public:

	map<int, vector<int>> m;

	TopVotedCandidate(vector<int>& persons, vector<int>& times) {

		int n = persons.size();

		for (int i = 0; i < n; i++) {
			m[persons[i]].pb(times[i]);
		}
	}

	int q(int t) {

		int mx = 0, p = -1, r_v = -1;

		for (auto ele : m) {
			auto v = ele.ss;
			auto p1 = ele.ff;

			int idx = upper_bound(all(v), t) - v.begin();

			if (idx > mx) {
				mx = idx;
				p = p1;
				r_v = v[idx - 1];
			} else if (idx == mx) {
				int r_v_1 = v[idx - 1];

				if (r_v_1 > r_v) {
					r_v = r_v_1;
					p = p1;
					mx = idx;
				}
			}
		}

		return p;
	}
};

// Optimized :- (logn) for every query of q

class TopVotedCandidate {
public:

	map<int, int> m;

	TopVotedCandidate(vector<int>& persons, vector<int>& times) {

		int n = persons.size();
		int lead = -1;

		unordered_map<int, int> count;

		for (int i = 0; i < n; i++) {
			count[persons[i]]++;

			if (count[persons[i]] >= count[lead]) {
				lead = persons[i];

				m[times[i]] = lead;
			} else {
				m[times[i]] = lead;
			}
		}
	}

	int q(int t) {

		auto itr = m.upper_bound(t);
		--itr;

		return (*itr).ss;
	}
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */