#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int _val)
    {
        val = _val;
        next = NULL;
    }

    ListNode(int _val, ListNode *_next)
    {
        val = _val;
        this->next = _next;
    }

    static void printList(ListNode *head)
    {
        if(head==nullptr) cout<<"List is empty!";
        while(head!=NULL)
        {
            cout<<head->val<<" ";
            head = head->next;
        }
    }

    static ListNode* createList(vector<int>&v)
    {
        if(v.size()==0) return NULL;
        ListNode *head = new ListNode(v[0]);
        ListNode *temp = head;
        for(int i=1; i<v.size(); i++)
        {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return head;
    }
};