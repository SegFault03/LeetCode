#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLN.
ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr)
            return head;
        ListNode *odd = head, *even = head->next, *even_s = head->next,
                 *curr = head->next->next;
        int i = 3;
        while (curr != nullptr) {
            if (i % 2 == 0) {
                even->next = curr;
                even = curr;
            } else {
                odd->next = curr;
                odd = curr;
            }
            curr = curr->next;
            i++;
        }
        even->next = nullptr;
        odd->next = even_s;
        return head;
    }


int main(){
}