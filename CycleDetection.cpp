//LC-142
// ✅ Problem: Detect the starting node of a cycle in a linked list
// 🔁 Approach: Floyd's Cycle Detection Algorithm (Tortoise and Hare)

// 🕒 Time Complexity: O(n) — At most two passes through the list
// 🧠 Space Complexity: O(1) — Uses constant space

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // 🚫 Edge cases: empty list or single node
    if (head == NULL || head->next == NULL) return NULL;

    // Step 1️⃣: Detect if a cycle exists using slow and fast pointers
    while (fast && fast->next) {
        slow = slow->next;            // move 1 step
        fast = fast->next->next;      // move 2 steps
        if (slow == fast) break;      // cycle detected
    }

    // Step 2️⃣: If cycle exists, find the entry point
    if (slow == fast) {
        ListNode* temp = head;
        // Move both one step at a time until they meet
        while (temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }
        return temp; // starting node of the cycle
    }

    // No cycle found
    return NULL;
}
