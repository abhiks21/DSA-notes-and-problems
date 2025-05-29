/*
=============================================================================
PROBLEM: Generate Valid Parentheses
=============================================================================
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

Example: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

=============================================================================
APPROACH: Backtracking
=============================================================================
1. Use recursion to build valid parentheses combinations
2. Track opening brackets used (i) and closing brackets used (j)
3. Add '(' when we haven't used all n opening brackets (i < n)
4. Add ')' when we have more opening than closing brackets (j < i)
5. Backtrack by removing the last added character using temp.pop_back()

=============================================================================
CRITICAL MISTAKES TO AVOID:
=============================================================================

❌ MISTAKE 1: Modifying parameters directly
   if(i < n){
       temp += '(';
       i++;  // ❌ This modifies original i permanently!
       solve(n, i, j, ans, temp);
       temp.pop_back();
   }
   
   Problem: This changes i for subsequent conditions in same function call

✅ CORRECT: Pass incremented values without modifying originals
   if(i < n){
       temp += '(';
       solve(n, i+1, j, ans, temp);  // ✅ Pass i+1, original i unchanged
       temp.pop_back();
   }

=============================================================================
TIME COMPLEXITY: O(4^n / √n)
=============================================================================
- This equals the n-th Catalan number: C(n) = (2n)! / ((n+1)! × n!)
- Catalan number approximates to 4^n / (√π × n^(3/2))
- Each valid combination takes O(n) time to construct
- Total valid combinations for n=3: C(3) = 5

=============================================================================
SPACE COMPLEXITY: O(n)
=============================================================================
- Recursion depth: Maximum 2n calls on call stack = O(n)
- Temporary string: Maximum length 2n = O(n) 
- Output space not counted in auxiliary space complexity

=============================================================================
RECURSION TREE VISUALIZATION (n=2):
=============================================================================

                    solve(2, 0, 0, "", ans)
                           |
                    [i<n: 0<2 ✓] temp += '('
                           |
                    solve(2, 1, 0, "(", ans)
                          / \
                   [i<n: 1<2 ✓]   [j<i: 0<1 ✓]
                   temp += '('     temp += ')'
                        |               |
              solve(2,2,0,"((")   solve(2,1,1,"()")
                     |                    |
               [j<i: 0<2 ✓]        [j<i: 1<1 ✗]
               temp += ')'         [i==n && j==n ✗]
                     |                    |
             solve(2,2,1,"(()")          return
                     |                    ↑
               [j<i: 1<2 ✓]         BACKTRACK
               temp += ')'          temp = "(" 
                     |                    |
             solve(2,2,2,"(())")    [i<n: 1<2 ✓]
                     |              temp += '('
               [i==n && j==n ✓]           |
               ans.push_back("(())")  solve(2,2,1,"(()")
                     |                    |
                  return             [j<i: 1<2 ✓]
                     ↑               temp += ')'
                BACKTRACK                 |
                temp = "(()"        solve(2,2,2,"(())")
                     ↑                    |
                BACKTRACK           [i==n && j==n ✓]
                temp = "(("         ans.push_back("(())")
                     ↑
                BACKTRACK
                temp = "("

Final ans = ["()", "(())"]
=============================================================================
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Main function - entry point
    vector<string> generateParentheses(int n) {
        vector<string> ans;  // Store all valid combinations
        string temp;         // Current combination being built
        
        // Start backtracking: n pairs, 0 opening used, 0 closing used
        solve(n, 0, 0, ans, temp);
        return ans;
    }
    
private:
    // Backtracking function
    // n: total pairs needed
    // i: opening brackets used so far  
    // j: closing brackets used so far
    // ans: reference to result vector (shared across all calls)
    // temp: reference to current string (shared across all calls)
    void solve(int n, int i, int j, vector<string> &ans, string &temp) {
        
        // BASE CASE: Used exactly n opening and n closing brackets
        if (i == n && j == n) {
            ans.push_back(temp);  // Found valid combination
            return;
        }
        
        // CHOICE 1: Add opening bracket '('
        // Condition: Haven't used all n opening brackets yet
        if (i < n) {
            temp += '(';                    // Add opening bracket
            solve(n, i+1, j, ans, temp);   // Recurse with i incremented
            //                    ^^^^
            // CRITICAL: i+1 is evaluated and passed to new function call
            // Original 'i' in current function remains unchanged!
            // This is because i is passed by VALUE, not reference
            
            temp.pop_back();               // BACKTRACK: Remove last character
            // We need this because temp is passed by REFERENCE
            // All function calls share the same temp string
        }
        
        // CHOICE 2: Add closing bracket ')'  
        // Condition: Have more opening brackets than closing brackets
        // This ensures we never have invalid sequences like ")(" 
        if (j < i) {
            temp += ')';                    // Add closing bracket
            solve(n, i, j+1, ans, temp);   // Recurse with j incremented
            //              ^^^^
            // Same principle: j+1 is evaluated and passed
            // Original 'j' in current function unchanged
            
            temp.pop_back();               // BACKTRACK: Remove last character
        }
        
        // After both recursive calls complete, function returns
        // Any changes to temp have been undone by pop_back()
        // Original values of i and j are preserved automatically
        // because they were passed by value (each call has own copy)
    }
};

/*
=============================================================================
KEY TAKEAWAYS:
=============================================================================
1. BACKTRACKING PATTERN: Add → Recurse → Remove (restore state)

2. PARAMETER PASSING UNDERSTANDING:
   - Pass by VALUE (int n, int i, int j): Each call gets independent copy
   - Pass by REFERENCE (vector<string> &ans, string &temp): Shared across calls
   
3. WHY WE DON'T MODIFY PARAMETERS DIRECTLY:
   - Doing i++ changes i for subsequent conditions in same function
   - Passing i+1 keeps original i unchanged for other branches
   
4. STATE MANAGEMENT:
   - Only temp needs explicit backtracking via pop_back() 
   - i and j restore automatically due to function call stack
   
5. VALIDITY ENSURES:
   - i < n: Can still add opening brackets
   - j < i: Can only add closing when we have more opening than closing
   - i == n && j == n: Perfect balance achieved

This pattern applies to ALL backtracking problems!
=============================================================================
*/
