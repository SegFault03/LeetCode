#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
ListNode* swapNodes(ListNode *A)
{
    if(A==nullptr) return nullptr;
    if(A->next == nullptr) return A;
    ListNode *curr = A, *next = A->next;
    ListNode *nHead = A->next;
    curr->next = next->next;
    nHead->next = curr;
    next = curr->next;
    while(next!=nullptr)
    {
        if(next->next==nullptr) break;
        curr->next = next->next;
        next->next = next->next->next;
        curr->next->next = next;
        curr = curr->next->next;
        next = curr->next;
    }
    return nHead;
}


int main(){
}