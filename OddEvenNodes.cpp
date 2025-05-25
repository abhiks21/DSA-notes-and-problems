//LC-328 Odd even nodes 
    // Approach:
    // - Use two pointers: one for odd-indexed nodes, another for even-indexed nodes.
    // - Rearrange the next pointers to group all odd nodes first, followed by even nodes.
    
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;  // Edge cases: empty list or one node

    ListNode* odd = head;                   // Points to current odd node
    ListNode* even = head->next;           // Points to current even node
    ListNode* evenHead = even;             // Store head of even list to attach later

    while (even && even->next) {
        odd->next = even->next;            // Link odd to next odd node
        odd = odd->next;                   // Move odd pointer

        even->next = odd->next;            // Link even to next even node
        even = even->next;                 // Move even pointer
    }

    odd->next = evenHead;                  // Attach even list at end of odd list
    return head;
}
