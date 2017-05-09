//
//  Trie_node.h
//  
//
//  Created by Divakar Kapil on 2016-11-13.
//
//

#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

#ifndef nullptr
#define nullptr 0
#endif

#include <string>
#include <cctype>
#include "ece250.h"
using namespace std;

class Trie;

class Trie_node {
private:
    Trie_node **children;
    bool is_terminal;
    static int const CHARACTERS = 26;
    
    bool insertUtil(Trie_node*node,std::string const &str, int index);
    bool eraseUtil(Trie_node*node,std::string const &str, int index);
    
    
public:
    Trie_node();
    Trie_node *child( int ) const;
    
    bool member( std::string const &, int ) const;
    
    bool insert( std::string const &, int );
    bool erase( std::string const &, int, Trie_node *& );
    void clear();
    
    friend class Trie;
    
    // if ptr is a pointer to a Trie_node object
    // in one of the friendly classes, you should:
    //    use   ptr->next_   to modify it
    //    use   ptr->next()      to access it
};

Trie_node::Trie_node():
children( nullptr ),
is_terminal( false ) {
    // empty constructor
}

Trie_node *Trie_node::child( int n ) const {
    if ( children == nullptr ) {
        return nullptr;
    } else {
        return children[n];
    }
}

bool Trie_node::member( std::string const &str, int depth ) const {
    
    if(depth == (str.size())){
        cout<<"done"<<endl;
        cout<<this->is_terminal<<endl;
        return this->is_terminal;                            //return whatever is the state of the last node.
    }
    
    
    string new_str = str;
    for(int i=0; i<str.size();i++){
        new_str[i] = toupper(new_str[i]);                          // converting the word into upper case
    }
    char ch = new_str[depth];                                       //Obtain the character of str at index
    int offset = ch-0x41;
    cout<<offset<<endl;
    //Calculate its offset w.r.t A
    
    if(this->children == nullptr){
        return false;
    }
    
    else if(this->children[offset] == nullptr){
        cout<<"H"<<endl;
        return false;
    }
    
    else{
        cout<<"G"<<endl;
        bool state = (this->children[offset])->member(str,depth+1);
        return state;
    }

}

bool Trie_node::insert( std::string const &str, int depth ) {
    
    string new_str = str;
    for(int i=0; i<str.size();i++){
        new_str[i] = toupper(new_str[i]);                          // converting the word into upper case
    }

    
    if(depth == str.size()){
        this->is_terminal = true;
        cout<<"E"<<endl;
        return true;
    }
    
    char ch = new_str[depth];                                       //Obtain the character of str at index
    int offset = ch-0x41;                                       //Calculate its offset w.r.t A
   
    

    if(this->children == nullptr){
        
        this->children = new Trie_node*[CHARACTERS];
        cout<<18<<endl;

        for(int i = 0; i < CHARACTERS; i++){
            
            children[i] = nullptr;
        }

    }
    
    if((this->children[offset]) == nullptr){
        this->children[offset]  = new Trie_node();
    }
    
    //Trie_node *temp = *((this->children) + offset);
    
    this->children[offset] ->insert(str,depth+1);
    return true;
    
    //return insertUtil(this,str,0);                                 //calling the method on the object itself
    //return false;
}

bool Trie_node::erase( std::string const &str, int depth, Trie_node *&ptr_to_this ) {
    
    string new_str = str;
    for(int i=0; i<=str.size();i++){
        new_str[i] = toupper(new_str[i]);                          // converting the word into upper case
    }
    
    if(depth == str.size()){
        if(is_terminal != true){
            return false;
        }
        
    else{
            
            if(this->children == nullptr){
                //delete this;
                ptr_to_this = nullptr;
                delete this;
                return true;
        }
            
            cout<<"If is Bypassed"<<endl;
            
            for(int i = 0;i < CHARACTERS; i++){                   //If we have reached the end ; if children is non empty then set to false

                if(this->children[i] != nullptr){
                    this->is_terminal = false;
                    cout<<"I am going back"<<endl;
                    return true;
                }
            }
            delete []children;                                  //if the children array of a node has become empty as a result of deleting all its children nodes, delete the array and delete the node
            delete this;
            return true;
        }
    }
    
    char ch = new_str[depth];
    int offset = ch-0x41;
    
    if(this->children == nullptr){                         // if the node has no children and is not the end of the string, return false
        return false;
    }
    
    else{
        
        bool eraseState = this->children[offset]->erase(str,depth+1,this->children[offset]);
        if(eraseState == true){
            
            //ptr_to_this = nullptr;
            for(int i = 0;i < CHARACTERS; i++){                   //If we have reached the end ; if children is non empty then set to false
                
                if(this->children[i] != nullptr){
                    //this->is_terminal = false;
                    return true;
                }
            }
            
            if(this->is_terminal == false){
                delete []children;                                  //if the children array of a node has become empty as a result of deleting all its children nodes, delete the array and delete the node
                ptr_to_this = nullptr;
                delete this;
            }
            return true;
        }
        
        else{
            return false;
        }
    }
    
 
}

void Trie_node::clear() {
    
    if(this->children == nullptr){
        cout<<"Cleared"<<endl;
        delete this;
    }
    
    else{
        Trie_node *temp = new Trie_node;
        cout<<"Clearing"<<endl;
        
        for(int i = 0; i<CHARACTERS; i++){
            temp = children[i];
            
            if(temp != nullptr){
                temp->clear();
                temp = nullptr;
            }
        }
        delete[] children;
        delete temp;
        delete this;
    }
}




#endif
