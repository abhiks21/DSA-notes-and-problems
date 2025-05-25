GFG
    // Approach:
    // - Use Floyd's Cycle Detection Algorithm (Tortoise and Hare) to detect a loop.
    // - If a loop is found, count the number of nodes in the loop by traversing it once.
    
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    
int countNodesinLoop(Node *head) {
    Node* slow = head; // Initialize slow pointer
    Node* fast = head; // Initialize fast pointer

    // Step 1: Detect if a loop exists in the linked list
    while (fast && fast->next) {
        slow = slow->next;           // Move slow by 1 step
        fast = fast->next->next;     // Move fast by 2 steps

        if (slow == fast) {          // Loop detected
  // Step 2: Count number of nodes in the loop
            int count = 1;
            Node* temp = slow->next;

            while (temp != slow) {   // Traverse the loop until back to starting point
                count++;
                temp = temp->next;
            }

            return count;            
        }
    }

    return 0; // No loop found
}
