/*
🧩 Problem Statement:
Given a string `s` representing a sentence (with possible leading/trailing/multiple spaces),
reverse the order of the words, remove extra spaces, and return the cleaned string.

✅ Approach:
1. Trim leading spaces.
2. Reverse the entire string.
3. Remove new leading spaces (caused by reversal).
4. Reverse each word in place.
5. Remove extra spaces between words.

⏱️ Time Complexity: O(n) – Every character is processed at most a constant number of times.
🧠 Space Complexity: O(1) – In-place modification.
*/

string reverseWords(string s) {
    int i = 0;

    // Step 1: Remove leading spaces
    while (s[0] == ' ') {
        s.erase(0, 1);
    }

    // Step 2: Reverse the entire string
    reverse(s.begin(), s.end());

    // Step 3: Remove new leading spaces after reversal
    while (s[0] == ' ') {
        s.erase(0, 1);
    }

    int n = s.size(); // Update size after trimming
    i = 0;
    int j = 0;

    // Step 4: Reverse each word back to its original form
    while (j <= n) {
        if (s[j] == ' ' || j == n) {
            // Reverse the word from index i to j-1
            reverse(s.begin() + i, s.begin() + j);
            j++;

            // Step 5: Remove extra spaces between words
            while (j < n && s[j] == ' ') {
                s.erase(s.begin() + j); // remove the extra space
                n--;                    // decrease size
            }

            i = j; // Move i to the start of the next word
        }
        j++;
    }

    return s;
}
