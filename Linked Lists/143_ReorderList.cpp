#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED
 * This code reorders a linked list by interleaving elements from the first and second halves in an alternating fashion.

Find the Middle: It uses two pointers to traverse the list. One pointer moves twice as fast as the other, effectively reaching the middle when the faster one reaches the end (or null).
Reverse the Second Half: The second half of the list is reversed using a separate function (reverseList). This function iterates through the list, reversing the links between nodes.
Interleave Halves: Two pointers iterate through the first and reversed second half, connecting them alternately. This creates the final interleaved structure.
Algorithm
Initialize two pointers: mid and temp.
Find the Middle:
Use a loop to iterate through the list.
Increment a counter count for each node visited.
Move mid only when count is even (effectively moving it halfway).
Move temp for every node.
Reverse the Second Half:
Call the reverseList function with mid as input to reverse the nodes from the middle point to the end.
Interleave Halves:
Initialize two more pointers: next1 and next2 to track the next nodes in the first and reversed second half, respectively.
Loop until both next1 and next2 are null:
Temporarily disconnect the current node (mid) from the second half.
Connect the current first half node (temp) to the current second half node (mid).
Connect the current second half node (mid) to the next node in the first half (next1).
Update pointers for the next iteration:
Move mid to the next node in the reversed second half (next2).
Move temp to the next node in the first half (next1).
Update next1 and next2 for the next iteration.
This algorithm achieves the desired reordering by finding the middle, reversing the second half, and then cleverly interleaving nodes from both halves.
*/
    ListNode* reverseList(ListNode* head){
        ListNode *newHead = nullptr, *temp;
        while(head!=nullptr){
            temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }

    void reorderList(ListNode* head) {
       int count = 0;
       ListNode *mid = head, *temp = head; 
       while(temp!=nullptr){
        count++;
        if(count%2==0)
            mid = mid->next;
        temp = temp->next;
       }
       mid = reverseList(mid);
       temp = head;
       ListNode* next1 = temp->next, *next2 = mid->next;
       
       while(next1!=nullptr && next2!=nullptr){
        mid->next = nullptr;
        temp->next = mid;
        mid->next = next1;
        mid = next2;
        temp = next1;
        next1 = temp->next;
        next2 = mid->next;
       }
    }


int main(){
    vector<int>t{0,1,2,3,4};
    ListNode *head = ListNode::createList(t);
    reorderList(head);
    ListNode::printList(head);
}