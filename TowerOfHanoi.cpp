/*
================================================================================
                            TOWER OF HANOI - COMPLETE NOTES
================================================================================

PROBLEM STATEMENT:
------------------
The Tower of Hanoi is a mathematical puzzle consisting of three rods and a number
of disks of different sizes which can slide onto any rod.

RULES:
1. Only one disk can be moved at a time
2. Each move consists of taking the upper disk from one of the stacks and 
   placing it on top of another stack or on an empty rod
3. No disk may be placed on top of a smaller disk

OBJECTIVE: Move all disks from the source rod to the destination rod

INPUT: Number of disks (n), Source rod (A), Destination rod (C), Auxiliary rod (B)
OUTPUT: Sequence of moves to solve the puzzle

EXAMPLES:
---------
n=1: A→C (1 move)
n=2: A→B, A→C, B→C (3 moves)  
n=3: A→C, A→B, C→B, A→C, B→A, B→C, A→C (7 moves)
Pattern: 2^n - 1 moves

APPROACH - DIVIDE AND CONQUER:
------------------------------
Key Insight: To move n disks from source to destination:
1. Move top (n-1) disks from source to auxiliary (using destination as helper)
2. Move the largest disk from source to destination  
3. Move (n-1) disks from auxiliary to destination (using source as helper)

Why this works:
- The largest disk only needs to move once (source → destination)
- All smaller disks must get out of the way first, then follow
- Each subproblem is identical in structure but smaller in size

RECURSIVE PATTERN RECOGNITION:
------------------------------
hanoi(n, source, dest, aux) breaks into:
1. hanoi(n-1, source, aux, dest)    // Use dest as helper
2. move(source → dest)              // Direct move of largest
3. hanoi(n-1, aux, dest, source)    // Use source as helper

CODE IMPLEMENTATION:
====================
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class TowerOfHanoi {
public:
    // METHOD 1: Basic Recursive Solution (Print moves)
    void solveHanoi(int n, char source, char destination, char auxiliary) {
        // Base case: only one disk to move
        if (n == 1) {
            cout << "Move disk 1 from " << source << " to " << destination << endl;
            return;
        }
        
        // Step 1: Move top n-1 disks from source to auxiliary
        // (using destination as temporary helper)
        solveHanoi(n-1, source, auxiliary, destination);
        
        // Step 2: Move the largest disk from source to destination  
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        
        // Step 3: Move n-1 disks from auxiliary to destination
        // (using source as temporary helper)
        solveHanoi(n-1, auxiliary, destination, source);
    }
    
    // METHOD 2: Store moves in vector for further processing
    void solvehanoiWithMoves(int n, char source, char destination, char auxiliary, 
                            vector<string>& moves) {
        // Base case
        if (n == 1) {
            moves.push_back("Move disk 1 from " + string(1,source) + " to " + string(1,destination));
            return;
        }
        
        // Recursive steps - same pattern as above
        solvehanoiWithMoves(n-1, source, auxiliary, destination, moves);
        moves.push_back("Move disk " + to_string(n) + " from " + string(1,source) + " to " + string(1,destination));
        solvehanoiWithMoves(n-1, auxiliary, destination, source, moves);
    }
    
    // METHOD 3: Count total moves without generating them
    long long countMoves(int n) {
        if (n == 1) return 1;
        return 2 * countMoves(n-1) + 1;  // T(n) = 2*T(n-1) + 1
    }
    

/*
TIME COMPLEXITY ANALYSIS:
=========================

Recurrence Relation: T(n) = 2*T(n-1) + 1
Base Case: T(1) = 1

Solving the recurrence:
T(n) = 2*T(n-1) + 1
     = 2*(2*T(n-2) + 1) + 1 = 4*T(n-2) + 2 + 1
     = 4*(2*T(n-3) + 1) + 3 = 8*T(n-3) + 4 + 2 + 1
     = 2^k * T(n-k) + (2^k - 1)

When k = n-1: T(n) = 2^(n-1) * T(1) + (2^(n-1) - 1)
                   = 2^(n-1) * 1 + 2^(n-1) - 1
                   = 2^n - 1

Therefore: TIME COMPLEXITY = O(2^n)

Why exponential?
- Each function call makes 2 recursive calls
- Forms a binary tree of height n
- Total nodes = 2^0 + 2^1 + 2^2 + ... + 2^(n-1) = 2^n - 1

SPACE COMPLEXITY ANALYSIS:
==========================

SPACE COMPLEXITY = O(n)

Components:
1. Recursion Stack: Maximum depth is n (when solving base cases)
2. Each recursive call uses O(1) extra space
3. No additional data structures that grow with input size

Stack trace for n=3:
hanoi(3) → hanoi(2) → hanoi(1) [max depth = 3]

Memory usage breakdown:
- Function call overhead: O(n) stack frames
- Local variables: O(1) per frame
- Output storage (if storing moves): O(2^n) for move list


*/
