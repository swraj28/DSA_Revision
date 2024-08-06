
var minimumPushes = function(word) {

    const n = word.length;
    const cnt = new Array(26).fill(0);

    // Count the frequency of each character in the string
    for (let i = 0; i < n; i++) {
        cnt[word.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }

    // Create an array to store pairs of frequency and corresponding character
    const v = [];

    for (let i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            v.push({ count: cnt[i], character: String.fromCharCode(i + 'a'.charCodeAt(0)) });
        }
    }

    // Sort the array in descending order based on frequency
    v.sort((a, b) => b.count - a.count);

    let cycleNumber = 1;
    let cntr = 8;
    let ans = 0;

    // Calculate the minimum pushes required
    for (const ele of v) {
        const cnt1 = ele.count;
        const ch = ele.character;

        if (cntr === 0) {
            cntr = 8;
            cycleNumber++;
        }

        ans += cycleNumber * cnt1;
        cntr--;
    }

    return ans;
};

// Example usage
const word = "example";
const result = minimumPushes(word);
console.log("Minimum Pushes: " + result);