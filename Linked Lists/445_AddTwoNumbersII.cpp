#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int>a,b;
    ListNode *head = nullptr, *temp = nullptr;
    int c = 0, s= 0;
    while(l1!=nullptr)
    {
        a.push(l1->val);
        l1 = l1->next;
    }
    while(l2!=nullptr)
    {
        b.push(l2->val);
        l2 = l2->next;
    }
    while(!a.empty() || !b.empty())
    {
        int x = 0, y = 0;
        if(!a.empty() && !b.empty())
        {
            x = a.top();
            y = b.top();
            a.pop();
            b.pop();
        }
        else if(!a.empty())
        {
            x = a.top();
            a.pop();
        }
        else
        {
            y = b.top();
            b.pop();
        }
        s = x+y+c;
        c = s/10;
        s = s%10;
        temp = new ListNode(s);
        if(head==nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    if(c>0)
    {
        temp = new ListNode(c);
        temp->next = head;
        head = temp;
    }
    return head;
}


int main(){
    vector<int>a{5};
    vector<int>b{5};
    ListNode *l1 = ListNode::createList(a);
    ListNode *l2 = ListNode::createList(b);
    ListNode::printList(addTwoNumbers(l1,l2));
}