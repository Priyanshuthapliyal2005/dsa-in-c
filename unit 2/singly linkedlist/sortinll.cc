#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;  // Already sorted or empty list
        }

        // Find the maximum number of digits in the list
        int maxDigits = getMaxDigits(head);

        // Perform counting sort for each digit place
        for (int i = 1; i <= maxDigits; ++i) {
            head = countingSort(head, i);
        }

        return head;
    }

private:
    int getMaxDigits(ListNode* head) {
        int maxDigits = 0;
        while (head) {
            int numDigits = 0;
            int val = abs(head->val);
            while (val > 0) {
                val /= 10;
                ++numDigits;
            }
            maxDigits = max(maxDigits, numDigits);
            head = head->next;
        }
        return maxDigits;
    }

    ListNode* countingSort(ListNode* head, int exp) {
        const int base = 10;  // Assuming decimal numbers

        vector<ListNode*> buckets(base, nullptr);
        vector<ListNode*> ends(base, nullptr);

        while (head) {
            int digit = getDigit(head->val, exp);
            if (!buckets[digit]) {
                buckets[digit] = ends[digit] = head;
            } else {
                ends[digit]->next = head;
                ends[digit] = head;
            }
            head = head->next;
        }

        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        for (int i = 0; i < base; ++i) {
            if (buckets[i]) {
                if (!newHead) {
                    newHead = buckets[i];
                    tail = ends[i];
                } else {
                    tail->next = buckets[i];
                    tail = ends[i];
                }
            }
        }

        if (tail) {
            tail->next = nullptr;
        }

        return newHead;
    }

    int getDigit(int value, int exp) {
        while (exp > 1) {
            value /= 10;
            --exp;
        }
        return value % 10;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(170);
    head->next = new ListNode(45);
    head->next->next = new ListNode(75);
    head->next->next->next = new ListNode(90);
    head->next->next->next->next = new ListNode(802);
    head->next->next->next->next->next = new ListNode(24);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(66);

    cout<<"before sorting algorithm:"<<endl;
    printList(head);
    Solution solution;
    ListNode* sortedList = solution.sortList(head);
    cout<<"after sorting algorithm:"<<endl;
    // Print the sorted linked list
    printList(sortedList);

    return 0;
}
