#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;




int main(){
    Trie *root = new Trie();
    root->insert("apple");
    root->insert("apst");
    root->insert("bow");
    cout<<"apple search - "<<root->search("apple")<<endl;
    cout<<"apst search - "<<root->search("apst")<<endl;
    cout<<"bow search - "<<root->search("bow")<<endl;
    cout<<"xerox search - "<<root->search("xerox")<<endl;
    cout<<"apple prefix search - "<<root->isPrefix("apple")<<endl;
    cout<<"app prefix search - "<<root->isPrefix("app")<<endl;
    cout<<"bo prefix search - "<<root->isPrefix("bo")<<endl;
    cout<<"apx prefix search - "<<root->isPrefix("apx")<<endl;
    cout<<endl;
}