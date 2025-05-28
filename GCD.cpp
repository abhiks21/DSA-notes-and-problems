// Problem: Find the Greatest Common Divisor (GCD) of two integers a and b.

// Concept:
// - The GCD of two numbers is the largest number that divides both without leaving a remainder.
// - Euclidean Algorithm is based on the principle: GCD(a, b) = GCD(b, a % b).
// - The process continues until b becomes 0.

// Approach:
// - Use recursion to repeatedly apply the Euclidean relation.
// - Base Case: If b == 0, return a.
// - Recursive Step: gcd(b, a % b)

int gcd(int a, int b) {
    if (b == 0) return a;           // Base case
    return gcd(b, a % b);           // Recursive step
}

// Time Complexity: O(log(min(a, b)))
// - With each step, the size of the input reduces significantly due to modulo operation.

// Space Complexity: O(log(min(a, b)))
// - Due to recursive function calls stored in the call stack.
