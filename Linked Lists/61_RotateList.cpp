/*
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
#include "../Headers/node.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int count = 0;
        ListNode *temp = head, *first = head, *newHead = nullptr;
        while(temp->next!=nullptr)
        {
            count++;
            temp = temp->next;
        }
        count++;
        if(k % count==0) return head;
        int r = count - (k % count);
        count = 0; 
        while(first!=nullptr)
        {
            count++;
            if(count==r) break;
            first = first->next;
        }
        newHead = first->next;
        first->next = nullptr;
        temp->next = head;
        return newHead;  
    }

int main(){
}