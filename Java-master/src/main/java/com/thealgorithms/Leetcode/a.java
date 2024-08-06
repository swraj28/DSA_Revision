package com.thealgorithms.Leetcode;

import java.util.*;

class Solution {

    public int minimumPushes(String word) {
        int n = word.length();
        int[] cnt = new int[26];

        // Count the frequency of each character in the string
        for (int i = 0; i < n; i++) {
            cnt[word.charAt(i) - 'a']++;
        }

        // Create a list to store pairs of frequency and corresponding character
        List<Pair> v = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                v.add(new Pair(cnt[i], (char) (i + 'a')));
            }
        }

        // Sort the list in descending order based on frequency
        v.sort((p1, p2) -> p2.count - p1.count);

        int cycleNumber = 1, cntr = 8;
        int ans = 0;

        // Calculate the minimum pushes required
        for (Pair ele : v) {
            int cnt1 = ele.count;
            char ch = ele.character;

            if (cntr == 0) {
                cntr = 8;
                cycleNumber++;
            }

            ans += (cycleNumber * cnt1);
            cntr--;
        }

        return ans;
    }

    // Helper class to store the pair of frequency and character
    static class Pair {
        int count;
        char character;

        Pair(int count, char character) {
            this.count = count;
            this.character = character;
        }
    }

    // Main method for testing
    public static void main(String[] args) {
        Solution solution = new Solution();
        String word = "example";
        int result = solution.minimumPushes(word);
        System.out.println("Minimum Pushes: " + result);
    }
}

