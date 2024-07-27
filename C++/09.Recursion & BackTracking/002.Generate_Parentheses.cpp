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

/*
    Let there be n opening brackets and n closing brackets.

    Total number of states:- 2n

    And on every state we are making 2 calls .

    T.c:- O(2^(2*n))

    Auxilary Space:- O(2*n)

    Storange space is not counted as it is mandatory to store the string. Buts storage space will be equivalent to the time complexity .
*/

class Solution {
public:

	void recur(string &s, int open, int close, vector<string> &ans) {
		if (open == 0 && close == 0) {
			ans.pb(s);
			return;
		}

		if (open > 0) {
			s.pb('(');
			recur(s, open - 1, close, ans);

			s.pop_back();
		}

		if (close > 0 && open < close) { // Close brackets can only be applied if open is less than close at any point of time.
			s.pb(')');
			recur(s, open, close - 1, ans);

			s.pop_back();
		}
	}

	vector<string> generateParenthesis(int n) {

		string s = "";

		vector<string> ans;

		recur(s, n, n, ans);

		return ans;
	}
};