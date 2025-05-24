// LC Variant - Book Allocation Problem
// Problem: Given an array `arr` representing the number of pages in each book and an integer `k` representing the number of students, 
// allocate books such that the maximum number of pages assigned to a student is minimized. 
// Each student gets a contiguous block of books, and each book is assigned to exactly one student.

// Approach:
// 1. Use binary search on the answer space. The minimum possible value is the max element (a student must get at least the largest book), 
//    and the maximum is the sum of all pages (one student takes all).
// 2. For each mid (potential max pages per student), check if it’s possible to assign books within `k` students.
// 3. If possible, try smaller values (end = mid - 1); else, increase the limit (start = mid + 1).

// Time Complexity: O(n * log(sum - max)) → Binary search over range [max_element, sum] with linear scan for validation
// Space Complexity: O(1) → Constant extra space used

int findPages(vector<int> &arr, int k) {
    int n = arr.size();

    // Edge case: Not enough books for students
    if (n < k) return -1;

    // Lower bound: The largest book (a student must get at least this much)
    int start = *max_element(arr.begin(), arr.end());

    // Upper bound: All books to one student
    int end = accumulate(arr.begin(), arr.end(), 0);
    
    int ans; // To store the final answer

    // Binary search over the answer space
    while (start <= end) {
        int mid = start + (end - start) / 2; // Potential max pages per student
        
        int count = 1;  // Start with 1 student
        int pages = 0;  // Pages allocated to current student

        // Check how many students are needed for this `mid`
        for (int i = 0; i < n; i++) {
            pages += arr[i];

            if (pages > mid) {
                count++;          // Allocate to a new student
                pages = arr[i];   // Start counting for new student
            }
        }

        if (count <= k) {
            // Possible to allocate within `k` students; try to minimize further
            ans = mid;
            end = mid - 1;
        } else {
            // Too many students needed, increase pages limit
            start = mid + 1;
        }
    }

    return ans; // Minimum of the possible maximum pages per student
}
