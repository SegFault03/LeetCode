//ACCEPTED SOLUTION
#include<bits/stdc++.h>
#include "../Headers/node.h"

using namespace std;

    ListNode* reverseList(ListNode* head)
    {
        if(head==nullptr||head->next==nullptr) return head;
        else
        {
            ListNode* link = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return link;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right || head->next==nullptr) return head;
        if(head==nullptr) return nullptr;
        //Extract the list to be reversed
        int count = 0;
        ListNode *first = nullptr, *firstNext = nullptr, *last = nullptr, *lastNext = nullptr, *temp=head;
        if(left==1)
        first = head;
        while(temp!=nullptr)
        {
            count++;
            if(count==left-1)
            first = temp;
            if(count==right)
            last = temp;
            temp = temp->next;
        }
        lastNext = last->next;
        last->next = nullptr;
        ListNode* reverseHead = left==1?reverseList(first):reverseList(first->next);
        if(left>1)
        {
            firstNext = first->next;
            first->next = reverseHead;
            firstNext->next = lastNext;
            return head;
        }
        else {
            first->next = lastNext;
            return reverseHead;
        }
    }

int main(){
}