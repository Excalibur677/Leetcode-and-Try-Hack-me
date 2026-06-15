#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: single node list
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        // Fast moves 2x, Slow moves 1x
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // prev is now the node before the middle node (slow)
        prev->next = slow->next;
        delete slow; // Free memory

        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;
    ListNode* head = createList({1, 3, 4, 7, 1, 2, 6});
    
    cout << "Original: ";
    printList(head);
    
    head = sol.deleteMiddle(head);
    
    cout << "After Deleting Middle: ";
    printList(head); // Expected: 1 -> 3 -> 4 -> 1 -> 2 -> 6
    
    return 0;
}