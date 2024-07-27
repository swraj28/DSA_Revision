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

// We will keep on expanding the window untill the number of character replacement is less than or equal to k .

// If it exceeds k then the total number of characters to be replaced = (total characters in the window - (max number of any character present in that particular window))

class Solution {
public:
	int characterReplacement(string s, int k) {

		int n = s.length(), j = 0, mx = 0;

		vector<int> cnt(26, 0);

		for (int i = 0; i < n; i++) {

			cnt[s[i] - 'A']++;

			while (((i - j + 1) - *max_element(all(cnt))) > k) {
				cnt[s[j] - 'A']--;
				j++;
			}

			mx = max(mx, (i - j) + 1);
		}

		return mx;
	}
};