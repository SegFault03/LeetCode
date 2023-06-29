/*
In this problem, once the minimum element gets popped, we have to return
the next min element present in the stack. This means we need to implement
a memory of some sort that will remmeber the past minimums. This can be done
with a stack, Every time a smaller element is found, we add it to the stack.
Every time we update the min element, we push it to a stack retaining the past 
min elements. When the element that is the current minimum (and so at the top 
of the stack that is used for memory) is popped, we pop it from the memory 
stack as well, so that next time getMin() is called, we return the min element 
that came before it.

It can always be guaranteed that upon deleting or popping the current min 
element from the stack, the next min element that is stored in the memory
stack will always be present in the main stack. This is because the minimum
element, and the memory stack is updated in a sequential fashion. The current 
min element must have come AFTER the previous min element, meaning if the
current min has been popped, the prev min element must still be in the stack.
Note that this will only be applicable if we check if it is the min element
that got popped after EVERY pop operation, to make sure that the last 
element to get popped is the min element, and no more elements have been popped
since. This makes us guarantee the fact that the prev min element is still present
and not popped yet.

ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int>vstack;                      //this is the actual stack used for performing push, pop, top 
    stack<int>minStack;                     //this stack is used for remembering the past min elements    
    int curr;                               //points at the current topmost index of vstack    
    MinStack() {
        vector<int>temp;
        stack<int>temp2;
        vstack = temp;
        minStack = temp2;
        curr = -1;                          //initially, stack is empty
    }
    
    void push(int val) {
        vstack.push_back(val);
        curr++;
        if(minStack.empty())                //When minStack is empty, store the index of the first element in stack as the minimum
        minStack.push(0);
        if(vstack[minStack.top()] > val)    //Otherwise, check if the element to be pushed is smaller than current min, and store the new index
        minStack.push(curr);
    }
    
    void pop() {
        vstack.erase(vstack.begin()+curr);          //delete topmost element
        if(minStack.top()==curr) minStack.pop();    //if the index of the minimum element got deleted, fallback to the next minimum element
        curr--;
    }
    
    int top() {
        return vstack[curr];
    }
    
    int getMin() {
        return vstack[minStack.top()];
    }
};


int main(){
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout<<minStack->getMin()<<" "; // return -3
    minStack->pop();
    cout<<minStack->top()<<" ";    // return 0
    cout<<minStack->getMin()<<" "; // return -2
}