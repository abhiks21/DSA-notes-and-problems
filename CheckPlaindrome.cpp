//LC-234 Check Plaindrome
bool isPalindrome(ListNode* head) {
    /*
    Approach:
    - Use a stack to store values of all nodes.
    - Traverse the list again and compare each node's value with the top of the stack.
    - If all values match, it's a palindrome.

    Time Complexity: O(N)
    Space Complexity: O(N)
    */

    ListNode* temp = head;          // Pointer to traverse the list
    stack<int> st;                 // Stack to store node values

    st.push(temp->val);            // Push the first node's value to the stack

    // Step 1: Push all remaining values to the stack
    while (temp->next) {
        temp = temp->next;
        st.push(temp->val);
    }

    temp = head;                   // Reset temp to head for second traversal

    // Step 2: Compare each value with top of stack
    while (temp->next) {
        if (st.top() != temp->val) // If mismatch found, not a palindrome
            return 0;
        st.pop();                  // Pop the matched value
        temp = temp->next;        // Move to next node
    }

    return 1; // All values matched, it is a palindrome
}
