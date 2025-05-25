//LC-237
// ✅ Approach: Overwrite the node to be deleted by shifting values of next nodes
// ➤ We're only given a pointer to the node to be deleted, not the head
// ➤ So we simulate deletion by copying the data from the next node into the current node
//    and repeating this until the second last node
// ➤ Finally, we nullify the last node's next pointer to disconnect the last duplicate

// 🕒 Time Complexity: O(n) in worst case (if deleting from the start of a long list)
// 🧠 Space Complexity: O(1) (constant space)

void deleteNode(ListNode* node) {
    // Continue shifting values from the next node until reaching second last node
    while(node->next->next){
        node->val = node->next->val;  // Copy value from next node
        node = node->next;            // Move to next node
    }
    
    // Handle the last copy and delete operation
    node->val = node->next->val;  // Copy value from the last node
    node->next = NULL;            // Remove the last node (unlink it)
}
