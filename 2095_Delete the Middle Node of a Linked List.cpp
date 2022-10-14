#include<bits/stdc++.h>
#include "E:\Code\DSA_headers\SinglyLinkedList\ListNode.cpp"
using namespace std;

ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr)
        return nullptr;
        ListNode *orig = head;
        ListNode *trav = head;
        ListNode *temp = head;
        int flag = 0;
        trav = trav->next;
        while(trav!=nullptr)
        {
            flag++;
            if(flag>2)
            {
                temp=temp->next;
                flag=1;
            }
            trav = trav->next;
        }
        ListNode *temp2 = temp->next->next;
        temp->next->next = nullptr;
        temp->next = temp2;
        return orig;
    }

int main(){
    vector<int>a={1,1,3,4,5,7,6,1,2,9,6};
    ListNode *head = ListNode::buildLinkedList(a);
    ListNode *nh = deleteMiddle(head);
    nh->printList();
}