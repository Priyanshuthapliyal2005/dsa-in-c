
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;  // Already sorted or empty list
        }

        // Find the range of values in the list
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        ListNode* current = head;
        while (current) {
            minVal = min(minVal, current->val);
            maxVal = max(maxVal, current->val);
            current = current->next;
        }

        // Create a counting array to store the frequency of each value
        vector<int> count(maxVal - minVal + 1, 0);

        // Count the occurrences of each value in the list
        current = head;
        while (current) {
            count[current->val - minVal]++;
            current = current->next;
        }

        // Reconstruct the sorted list
        current = head;
        int index = 0;
        while (current) {
            while (count[index] == 0) {
                index++;
            }
            current->val = minVal + index;
            count[index]--;
            current = current->next;
        }

        return head;
    }

