#include<bits/stdc++.h>
#include "../Headers/node.h"

using namespace std;
int main(){
    ListNode *head = new ListNode(5);
    // head->next = new ListNode(6);
    // head->next = new ListNode(7);
    // ListNode::printList(head);
    vector<int>v{1,2,3,4,5,6};
    head = ListNode::createList(v);
    ListNode::printList(head);
}