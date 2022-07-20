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
    Let us assume on an average the length of the word in the table array is 4.

    Let n be the length of the string digit.

    Therefore the overall time complexity is n*(4^n). (Analyse the recursive Tree to understand the complexity better).

    Auxiliary Space:- O(n)
*/

class Solution {
public:
	string table[10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz"};

	vector<string> ans;

	void recur(string digits, int n, int si, string &s) {
		if (si >= n) {
			ans.pb(s);
			return;
		}

		int idx = digits[si] - '0';
		string temp = table[idx];

		for (auto ch : temp) {
			s += ch;
			recur(digits, n, si + 1, s);

			s.pop_back(); // Backtracking.
		}
	}

	vector<string> letterCombinations(string digits) {

		string s = "";
		int n = digits.length();

		if (n == 0)return ans;

		recur(digits, n, 0, s);

		return ans;
	}
};