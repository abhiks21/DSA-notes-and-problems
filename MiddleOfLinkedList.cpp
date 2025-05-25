//LC-876 Find middle node of a linked list

// ✅ Approach: Two Pointer Technique (Fast and Slow Pointers)
// ➤ Move `slow` by 1 step and `fast` by 2 steps
// ➤ When `fast` reaches the end, `slow` will be at the middle

// 🕒 Time Complexity: O(n) — Traverse the list once
// 🧠 Space Complexity: O(1) — No extra space used

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse list with two pointers
    while (fast && fast->next) {
        slow = slow->next;           // Move one step
        fast = fast->next->next;     // Move two steps
    }

    // When fast reaches the end, slow is at the middle
    return slow;
}
