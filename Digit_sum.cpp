// LC-258: Add Digits
// Problem: Repeatedly add digits of a number until the result is a single digit.

// Helper function to get the sum of digits
int solve(int ans){
    int num = ans;       // Copy input to num
    ans = 0;
    while(num > 0){      // Repeat while num has digits left
        int rem = num % 10;  // Extract the last digit
        num = num / 10;      // Remove the last digit
        ans = ans + rem;     // Add digit to sum
    }
    return ans;
}

int addDigits(int num) {
    int ans = num;
    while(ans > 9){           // Repeat until ans is a single-digit number
        ans = solve(ans);     // Get digit sum
    }
    return ans;
}
