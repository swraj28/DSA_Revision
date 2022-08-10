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

class TimeMap {
public:
	unordered_map<string, vector<pair<int, string>>> m;

	void set(string key, string value, int timestamp) {

		m[key].pb({timestamp, value});
	}

	string get(string key, int timestamp) {

		string ans = "";

		if (m.count(key) == 0) {
			return ans;
		}

		// auto v = m[key]; // vector<pair<int,string>>

		// Assuming that the timestamp is in increasing order therefore we can apply Binary Search (Upper Bound) . Per Query O(log(n))

		// If the time stamp is not in increasing order then we need to sort and then apply binary search . Per Query O(nlog(n))

		int n = m[key].size();

		int st = 0, end = n - 1;

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			if (m[key][mid].ff <= timestamp) {
				st = mid;
			} else {
				end = mid;
			}
		}

		if (m[key][end].ff <= timestamp) {
			return m[key][end].ss;
		} else if (m[key][st].ff <= timestamp) {
			return m[key][st].ss;
		}

		return ans;
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */