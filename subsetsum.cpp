/*
=================================================================================
                              SUBSET SUM PROBLEM
=================================================================================

PROBLEM STATEMENT:
Given an array of integers and a target sum, determine if there exists a subset 
of the array whose elements sum exactly to the target sum.

Example: 
Input: Array = [3, 34, 4, 12, 5, 2], Target Sum = 9
Output: True 
Explanation: Subset [4, 5] sums to 9

=================================================================================
                                  APPROACH
=================================================================================

RECURSIVE BACKTRACKING:
- For each element, we have two choices: INCLUDE it or EXCLUDE it
- Use recursion to explore both possibilities systematically
- At each step, maintain current sum and check if it equals target
- Use pruning to avoid unnecessary computations

BASE CASES:
1. If current sum equals target sum → return true (found valid subset)
2. If we've processed all elements → return false (no valid subset)
3. If current sum exceeds target → return false (pruning optimization)

DECISION TREE EXAMPLE: [3, 4], Target = 7
                    Start(sum=0, i=0)
                   /                \
            Include 3              Exclude 3
           (sum=3, i=1)           (sum=0, i=1)
           /         \             /         \
    Include 4    Exclude 4   Include 4   Exclude 4
   (sum=7)✓     (sum=3)      (sum=4)     (sum=0)

=================================================================================
                            COMMON MISTAKES & FIXES
=================================================================================
MISTAKE 4: ❌ Missing Early Termination
Problem: Not checking if answer already found before making recursive calls
Issue: Continues exploring even after finding valid subset
Fix: ✅ if(ans) return; // Stop exploration once answer is found

MISTAKE 3: ❌ Unnecessary References
Problem: void solve(..., int &sum, int &i, ...) 
Issue: 'sum' and 'i' don't need to be references (read-only values)
Fix: ✅ void solve(..., int sum, int i, ...) // Only use & when modifying

=================================================================================
                                   CODE
=================================================================================
*/


class Solution {
public:
    void solve(vector<int> &arr, int sum, int &s, int i, bool &ans){
        // Early termination - if answer already found, stop exploring
        if(ans) return;
        
        // Base case - processed all elements
        if(i == arr.size()) return;
        
        // Choice 1: Include current element (if it doesn't exceed sum)
        if(s + arr[i] <= sum){
            s += arr[i];  // Include current element
            
            // Check if we reached target sum
            if(s == sum){
                ans = true;
                return;
            }
            
            // Recurse with next element
            solve(arr, sum, s, i+1, ans);
            
            // Backtrack - remove current element for other paths
            s -= arr[i];
        }
        
        // Choice 2: Exclude current element (only if answer not found yet)
        if(!ans) {
            solve(arr, sum, s, i+1, ans);  // Fixed: proper parameter order
        }
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int s = 0;        // Current sum tracker
        bool ans = false; // Result tracker (passed by reference)
        
        // Start recursion from index 0
        solve(arr, sum, s, 0, ans);
        
        return ans;
    }
};

/*
=================================================================================
                          TIME & SPACE COMPLEXITY
=================================================================================

TIME COMPLEXITY: O(2^n)
- In worst case, we explore all possible subsets of the array
- For each element, we make 2 choices (include/exclude)
- Total number of subsets = 2^n
- Each recursive call does O(1) work
- Overall: O(2^n)

SPACE COMPLEXITY: O(n)
- Recursion stack depth in worst case = n (length of array)
- Each recursive call uses O(1) extra space
- No additional data structures used
- Overall: O(n) for recursion stack

OPTIMIZATIONS USED:
1. Early Termination: Stop as soon as valid subset is found
2. Pruning: Don't explore paths where current sum > target sum
3. Backtracking: Properly restore state to explore independent paths

WHEN TO USE THIS APPROACH:
- Small to medium array sizes (n ≤ 20-25)
- When we need to find if ANY subset exists (not all subsets)
- When constraints don't allow DP approach due to large sum values

ALTERNATIVE APPROACHES:
- Dynamic Programming: O(n × sum) time, O(n × sum) space
- Better for larger arrays with reasonable sum values
- Bitmasking: Similar time complexity but different implementation
=================================================================================
*/
