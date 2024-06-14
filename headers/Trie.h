#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    char val;
    bool wordEnds;
    vector<Trie*>children;

    Trie(){
        val = ' ';
        wordEnds = false;
    }

    void insert(string word){
        // Get a temporary reference to the root node for iterating over it
        Trie* temp = this;
        
        // Iterate over the word
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            bool hasChild = false;
            // Check if the current node's children contain the current character
            for(Trie* child: temp->children){
                if(child->val == ch){
                    
                    // Set current node to child node
                    temp = child;
                    
                    // If the current character is the last character, check if wordEnds prop is true
                    if(i==word.length()-1)
                    {
                        if(!child->wordEnds){
                            child->wordEnds = true;
                        }
                        cout<<"Word is already present"<<endl;
                        return;
                    }
                    hasChild = true;
                    break;
                }
            }
            if(hasChild)
            continue;
            // No children contain the current character, create a new node and add it to the current node
            Trie* newNode = new Trie();
            newNode->val = ch;
            temp->children.push_back(newNode);
            
            // If it is the last character, then set wordEnds to true, and return
            if(i==word.length()-1){
                newNode->wordEnds = true;
                cout<<"Word inserted successfully"<<endl;
                return;
                }
            
            // Else, set current node to newNode and continue;
            temp = newNode; 
        }
    }

    bool search(string word){
        // Get a temporary reference to the root node for iterating over it
        Trie* temp = this;

        // Iterate over the word
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            bool hasWord = false;
            // Check if the current node's children contain the current character
            for(Trie* child: temp->children){
                if(child->val == ch){
                    
                    // Set current node to child node
                    temp = child;
                    
                    // If the current character is the last character, check if wordEnds prop is true
                    if(i==word.length()-1)
                    {
                        return child->wordEnds?true:false;
                    }
                    hasWord = true;
                    break;
                }
            }
            if(hasWord) continue;
            // No children contain the current character
            return false;
        }
    }

    bool isPrefix(string word){
        // Get a temporary reference to the root node for iterating over it
        Trie* temp = this;

        // Iterate over the word
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            bool hasWord = false;
            // Check if the current node's children contain the current character
            for(Trie* child: temp->children){
                if(child->val == ch){                   
                    // Set current node to child node
                    temp = child;
                    hasWord = true;
                    break;
                }
            }
            if(hasWord) continue;
            // No children contain the current character
            return false;
        }
        return true;
    }
};