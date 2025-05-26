Node* segregate(Node* head) {
    /*
    Problem:
    - Given a linked list with nodes containing 0s, 1s, and 2s, 
      rearrange the nodes so that all 0s come first, followed by 1s, then 2s.
    - Do not change data in nodes, only rearrange the links.

    Approach:
    - Create three dummy nodes to form three lists: for 0s, 1s, and 2s.
    - Traverse the list and connect nodes to their respective lists.
    - Merge the three lists at the end.

    Time Complexity: O(N) → Traverse the list once
    Space Complexity: O(1) → Only using extra pointers
    */

    // Create dummy heads for 0s, 1s, and 2s lists
    Node* head0 = new Node(0);     
    Node* head1 = new Node(0);     
    Node* head2 = new Node(0);     

    // Tail pointers for 0s, 1s, and 2s lists
    Node* temp0 = head0;
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* temp = head;  // Pointer to traverse the input list

    // Step 1: Distribute nodes into 0s, 1s, and 2s lists
    while (temp) {
        if (temp->data == 0) {
            temp0->next = temp;
            temp0 = temp0->next;
        } else if (temp->data == 1) {
            temp1->next = temp;
            temp1 = temp1->next;
        } else {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    // Step 2: Connect the three lists
    temp2->next = NULL;           // End 2s list
    temp1->next = head2->next;    // Connect 1s list to 2s list
    temp0->next = head1->next;    // Connect 0s list to 1s list

    // Return the head of the merged list (skip dummy)
    return head0->next;
}
