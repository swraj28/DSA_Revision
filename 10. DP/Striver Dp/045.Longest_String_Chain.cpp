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

// Variation of LIS

class Solution {
public:

	bool is_predecessor(string &a, string &b) { // Here we are checking wheather string 'a' is a predecessor of b or not. (b.length()+1=a.length())

		int n = a.length(), m = b.length();

		int i = 0, j = 0;

		while (i < n && j < m) {
			if (a[i] != b[j]) {
				break;
			}
			i++, j++;
		}

		j++;

		while (i < n && j < m) {
			if (a[i] != b[j]) {
				return false;
			}
			i++, j++;
		}

		return true;
	}

	int recur(vector<string> &words, int n, int si, vector<int> &dp) {
		if (si >= n) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		int ans = 1;

		for (int i = si + 1; i < n; i++) {

			int a = words[si].length();
			int b = words[i].length();

			if ((b - a) > 1) {
				break;
			}

			if ((a + 1) == b && is_predecessor(words[si], words[i])) {

				ans = max(ans, 1 + recur(words, n, i, dp));
			}
		}

		return dp[si] = ans;
	}

	int longestStrChain(vector<string>& words) {

		int n = words.size();

		sort(all(words), [](string & a, string & b) {

			return a.length() < b.length();
		});

		int ans = 1;

		vector<int> dp(n + 1, -1);

		for (int i = 0; i < n; i++) {
			ans = max(ans, recur(words, n, i, dp));
		}

		return ans;
	}
};

// Iterative :-

class Solution {
public:

	bool is_predecessor(string &a, string &b) { // Here we are checking wheather string 'a' is a predecessor of b or not. (b.length()=a.length()+1)

		int n = a.length(), m = b.length();

		if (abs(n - m) != 1) {
			return false;
		}

		int i = 0, j = 0;

		while (i < n && j < m) {
			if (a[i] != b[j]) {
				break;
			}
			i++, j++;
		}

		j++;

		while (i < n && j < m) {
			if (a[i] != b[j]) {
				return false;
			}
			i++, j++;
		}

		return true;
	}

	int longestStrChain(vector<string>& words) {

		int n = words.size();

		sort(all(words), [](string & a, string & b) {

			return a.length() < b.length();
		});

		vector<int> dp(n);
		dp[0] = 1;

		int mx = 1;

		for (int i = 1; i < n; i++) { // Longest Increasing Subsequence Ending at i

			dp[i] = 1;

			int a = words[i].length();

			for (int j = i - 1; j >= 0; j--) {

				int b = words[j].length();

				if (is_predecessor(words[j], words[i])) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}

			mx = max(mx, dp[i]);
		}

		return mx;
	}
};