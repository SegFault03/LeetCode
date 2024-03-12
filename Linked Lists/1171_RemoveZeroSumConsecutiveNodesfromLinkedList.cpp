#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED
This code removes consecutive sublists that sum to zero from a linked list. Here's a breakdown of how it works:

Setup:

An unordered_map rec is created to store prefix sums (sum of elements up to a certain point in the list) and the corresponding nodes.
A dummy node first is created to handle edge cases where the head itself might be part of a zero-sum sublist.
Iterate through the list:

The code iterates through the original linked list (head).
For each node, it calculates the current prefix sum (sum) by adding the current node's value to the previous sum.
Check for zero-sum sublist:

It checks if the prefix sum (sum) exists in the rec map.
If it exists, it means there's a sublist starting from the node mapped to that sum that adds up to zero.
Remove zero-sum sublist:

A temporary pointer (temp) is set to the node corresponding to the found prefix sum (rec[sum]).
It iterates through subsequent nodes, keeping track of the cumulative sum (cumSum).
For each subsequent node, it checks if the cumSum is present in the map. If it is, it removes that entry from the map as it's part of the zero-sum sublist.
Finally, it sets the next pointer of the node before the sublist (pointed to by temp) to nullptr, effectively removing the sublist.
Update information:

If no zero-sum sublist is found (rec.find(sum) == rec.end()):
A new node with the current element's value is created and added to the rec map with the current prefix sum as the key.
The temp pointer is updated to point to the newly created node.
Move on:

The head pointer is advanced to the next node in the original list.
Return result:

After iterating through the entire list, the code removes the dummy node (first->next) and returns the actual head of the modified list.
This approach uses the prefix sum concept and a hash table to efficiently identify and remove zero-sum sublists in the linked list.
*/
ListNode* removeZeroSumSublists(ListNode* head) {
       unordered_map<int, ListNode*>rec;
       ListNode *first = new ListNode();
       ListNode *temp = first;
       int sum = 0;
       rec[0] = first;
       while(head!=nullptr){
        sum += head->val;
        if(rec.find(sum)!=rec.end()){
        //start from the node where the value was last seen, and
        //then remove all the nodes, as well as map entries after that
        temp = rec[sum];
        temp = temp->next;
        int cumSum = sum;
        while(temp!=nullptr){
            cumSum += temp->val;
            if(rec[cumSum]==temp)
            rec.erase(cumSum);
            temp = temp->next;
        }
        //set temp to nullptr before reinitializing it to rec[sum]
        temp = rec[sum];
        temp->next = nullptr;
        }
        else{
            rec[sum] = new ListNode(head->val);
            temp->next = rec[sum];
            temp = temp->next;
        }
        head = head->next;
       }
       first = first->next;
       return first;
    }

int main(){
    vector<int>test{1,2,3,-3,-2};
    ListNode *v = ListNode::createList(test);
    ListNode::printList(removeZeroSumSublists(v));
}