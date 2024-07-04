#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;


/**
 * Merges nodes between zeros in a linked list
 * 
 * Logic and Intuition:
 * 1. We traverse the list, summing up values between zeros.
 * 2. When we encounter a zero, we update the current node with the sum.
 * 3. We reuse existing nodes, overwriting their values with the calculated sums.
 * 4. This approach efficiently removes all zero nodes, including the initial one.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the list
 * Space Complexity: O(1), as we only use a constant amount of extra space
 */
ListNode* mergeNodes(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode *newHead = head;        // Will be the first sum node
    ListNode *nextNode = head;       // Tracks the next position for a sum node
    ListNode *currNode = head;       // Tracks the current sum node being formed
    ListNode *temp = head->next;     // Used to traverse the list, starts after first zero
    int sum = 0;                     // Accumulates the sum between zeros

    while (temp != nullptr) {
        if (temp->val == 0) {
            currNode->next = nextNode;   // Link the previous sum node to this one
            currNode = currNode->next;   // Move currNode to this sum node
            currNode->val = sum;         // Set the accumulated sum
            currNode->next = nullptr;    // Temporarily set next to null (may be updated later)
            nextNode = temp;             // Move nextNode to current zero (will be overwritten next)
            sum = 0;                     // Reset sum for next group
        } else {
            sum += temp->val;
        }
        temp = temp->next;
    }

    // newHead now points to the first sum node, all zeros have been removed
    return newHead;
}

int main(){
}