int singleNumber(vector<int>& nums) {
    /*
    Problem:
    Given a non-empty array where every element appears twice except for one,
    find that single one.

    Approach:
    - Use XOR to cancel out duplicates.
    - All duplicates XOR to 0, and 0 ^ unique = unique.

    Time Complexity: O(N)
    Space Complexity: O(1)
    */

    int res = 0;
    for (int num : nums) {
        res ^= num;
    }
    return res;
}
