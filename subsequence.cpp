/*
PROBLEM: Generate All Subsets (Power Set)
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the answer in any order.

Example: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

APPROACH: Recursive Backtracking (Include/Exclude Pattern)
For each element at index i, we have 2 choices:
1. Exclude the element - move to next index
2. Include the element - add to current subset, then move to next index

Base case: When i == nums.size(), we've made decisions for all elements

MISTAKES MADE IN ORIGINAL CODE:
1. Used reference (&temp) but forgot to backtrack after including element
2. This caused temp vector to accumulate elements across different recursive branches
3. Led to incorrect subsets being generated due to polluted state

COST OF THE MISTAKE:
- Incorrect output: subsets contained elements they shouldn't have
- Logic error: different recursive branches interfered with each other
- Hard to debug: state pollution across function calls
*/

// ============================================================================
// METHOD 1: REFERENCE + BACKTRACKING (OPTIMAL)
// ============================================================================

void solve_reference(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int i) {
    // Base case: processed all elements
    if (i == nums.size()) {
        ans.push_back(temp);  // Add current subset to answer
        return;
    }
    
    // Choice 1: Exclude current element nums[i]
    solve_reference(nums, ans, temp, i + 1);
    
    // Choice 2: Include current element nums[i]
    temp.push_back(nums[i]);        // Include element
    solve_reference(nums, ans, temp, i + 1);
    temp.pop_back();                // BACKTRACK - remove element
}

vector<vector<int>> subsets_reference(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve_reference(nums, ans, temp, 0);
    return ans;
}

// ============================================================================
// METHOD 2: PASS BY VALUE (SIMPLE BUT INEFFICIENT)
// ============================================================================

void solve_value(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int i) {
    // Base case: processed all elements
    if (i == nums.size()) {
        ans.push_back(temp);  // Add current subset to answer
        return;
    }
    
    // Choice 1: Exclude current element nums[i]
    solve_value(nums, ans, temp, i + 1);  // temp passed by value (copy)
    
    // Choice 2: Include current element nums[i]
    temp.push_back(nums[i]);              // Modify the copy
    solve_value(nums, ans, temp, i + 1);  // Pass modified copy
    // No need to backtrack - each call has its own copy
}

vector<vector<int>> subsets_value(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve_value(nums, ans, temp, 0);
    return ans;
}

/*
COMPLEXITY ANALYSIS:

METHOD 1: REFERENCE + BACKTRACKING
Time Complexity: O(n × 2^n)
- 2^n subsets to generate
- Each subset takes O(n) time to copy into answer
- Total: O(n × 2^n)

Space Complexity: O(n)
- Recursion stack depth: O(n)
- Single temp vector: O(n) maximum size
- Total auxiliary space: O(n)
- Output space: O(n × 2^n) - but not counted in auxiliary space

METHOD 2: PASS BY VALUE
Time Complexity: O(n × 2^n)
- Same as method 1 for generating subsets
- Additional overhead for copying vectors at each recursive call

Space Complexity: O(n × 2^n)
- Total recursive calls: 2^n
- Each call creates a copy of temp vector
- Average copy size: n/2
- Total space: 2^n × (n/2) = O(n × 2^n)

COMPARISON SUMMARY:
+------------------+--------------+------------------+------------------+
| Aspect           | Reference    | Pass by Value    | Winner           |
+------------------+--------------+------------------+------------------+
| Time Complexity  | O(n × 2^n)   | O(n × 2^n)       | Tie              |
| Space Complexity | O(n)         | O(n × 2^n)       | Reference        |
| Memory Usage     | Minimal      | Exponentially    | Reference        |
|                  |              | higher           |                  |
| Code Complexity  | Medium       | Simple           | Pass by Value    |
| Error Prone      | Yes          | No               | Pass by Value    |
| Performance      | Faster       | Slower           | Reference        |
| Learning Value   | High         | Good for         | Reference        |
|                  |              | beginners        |                  |
+------------------+--------------+------------------+------------------+

RECOMMENDATION:
- Use REFERENCE + BACKTRACKING for interviews and production code
- Use PASS BY VALUE for learning and simple implementations
- Always remember to backtrack when using references!

KEY TAKEAWAY:
The "pass by value" approach works because each recursive call gets its own 
independent copy of the temp vector, eliminating the need for manual backtracking.
However, this convenience comes at the cost of exponential space usage.
*/
