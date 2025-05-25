//LC-19 Remove the nth node from end


    /*
    Approach:
    - Use two pointers: fast and slow.
    - Move fast pointer `n` steps ahead.
    - Then move both fast and slow one step at a time until fast reaches the last node.
    - Now, slow is just before the target node to delete.
    
    Edge Case:
    - If fast becomes NULL after initial movement, it means we need to delete the head node.

    Time Complexity: O(N)
    Space Complexity: O(1)
    */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If fast is NULL, we need to delete the head
    if (!fast) {
        return head->next;
    }

    // Move both fast and slow together until fast reaches the last node
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    slow->next = slow->next->next;

    return head;
}
