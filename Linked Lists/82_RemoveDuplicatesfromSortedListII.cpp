//ACCEPTED SOLUTION
#include<bits/stdc++.h>
#include "../Headers/node.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *newHead = nullptr, *temp = NULL, *trav = head;
        while(trav!=NULL)
        {
            if(trav->next != nullptr && trav->next->val == trav->val)
            {
                while(trav->next!=nullptr && trav->next->val == trav->val) trav = trav->next;
                trav = trav->next;
                continue;
            }

            if(newHead==nullptr)
            {
                newHead = trav;
                temp = trav;
            }
            else
            {
                temp->next = trav;
                temp = temp->next;
            }
            trav = trav->next;
        }
        if(temp!=nullptr) temp->next = nullptr;
        return newHead;
    }

int main(){
    vector<int>test{1,1,2,2,4,4,4,5,5};
    ListNode *head = ListNode::createList(test);
    head = deleteDuplicates(head);
    ListNode::printList(head);
}