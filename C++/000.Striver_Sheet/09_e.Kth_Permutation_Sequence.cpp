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

// Watch Striver Lecture to understand it properly .

class Solution {
public:
	string getPermutation(int n, int k) {

		int fact = 1;

		vector <int> numbers;

		for (int i = 1; i < n; i++) {
			fact = fact * i;
			numbers.push_back(i);
		}

		numbers.push_back(n);

		string ans = "";

		k = k - 1;

		while (true) {

			ans = ans + to_string(numbers[k / fact]);

			numbers.erase(numbers.begin() + k / fact);

			if (numbers.size() == 0) {
				break;
			}

			k = k % fact;
			fact = fact / numbers.size();
		}

		return ans;
	}
};