//LC-160 Intersection point of two linked list

// ✅ Approach:
// 1. Find lengths of both linked lists.
// 2. Advance the pointer of the longer list by the length difference.
// 3. Traverse both lists together until the nodes match (intersection) or reach the end (nullptr).

// ⏱️ Time Complexity: O(n + m)
// 💾 Space Complexity: O(1)

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    // Base case: if either list is empty, return null
    if (!headA || !headB) return nullptr;

    int lenA = 0, lenB = 0;
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    // 🔁 Count the length of List A
    while (tempA) {
        lenA++;
        tempA = tempA->next;
    }

    // 🔁 Count the length of List B
    while (tempB) {
        lenB++;
        tempB = tempB->next;
    }

    // Reset pointers to the heads
    tempA = headA;
    tempB = headB;

    // 🎯 Advance the pointer of the longer list by the length difference
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff--) tempA = tempA->next;
    } else {
        int diff = lenB - lenA;
        while (diff--) tempB = tempB->next;
    }

    // 🔄 Move both pointers together until they meet or reach end
    while (tempA && tempB && tempA != tempB) {
        tempA = tempA->next;
        tempB = tempB->next;
    }

    // Return the intersection node (or nullptr if no intersection)
    return tempA;
}
