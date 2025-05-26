/*
Problem:
- Find the second largest element in the given array.

Approach:
- Use two variables `a` and `b` to track the largest and second largest elements.
- Traverse the array once:
    - If current element > a:
        - Update b = a
        - Update a = current element
    - Else if current element > b and < a:
        - Update b = current element
- Return b as the second largest element.
- This approach avoids sorting or using extra data structures.

Time Complexity: O(n)
- Only one traversal of the array is done.

Space Complexity: O(1)
- Only two variables are used regardless of input size.
*/

int getSecondLargest(vector<int> &arr) {
    int a = INT_MIN;  // To store the largest element
    int b = INT_MIN;  // To store the second largest element

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > a) {
            b = a;
            a = arr[i];
        } else if (arr[i] > b && arr[i] < a) {
            b = arr[i];
        }
    }

    return b;
}
