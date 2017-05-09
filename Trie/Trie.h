//
//  Trie.h
//  
//
//  Created by Divakar Kapil on 2016-11-13.
//
//

#ifndef TRIE_H
#define TRIE_H

#ifndef nullptr
#define nullptr 0
#endif

#include "ece250.h"
#include "Trie_node.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Trie {
private:
    Trie_node *root_node;
    int trie_size;
    bool search();
    
public:
    Trie();
    ~Trie();
    
    // Accessors
    
    int size() const;
    bool empty() const;
    bool member( std::string const & ) const;
    Trie_node *root() const;
    // Mutators
    
    bool insert( std::string const & );
    bool erase( std::string const & );
    void clear();
   
    
    // Friends
    
    friend std::ostream &operator<<( std::ostream &, Trie const & );
};

Trie::Trie():
root_node( nullptr ),
trie_size( 0 ) {
    // empty constructor
}

Trie::~Trie() {
    clear();
}

int Trie::size() const {
    return trie_size;
}

bool Trie::empty() const {
    
    if(size() == 0){
    return true;
    }
    
    else{
        return false;
    }
}

Trie_node *Trie::root() const {
    
    if(root_node == nullptr){
        return nullptr;
    }
    
    else{
        return root_node;
    }
}

bool Trie::member( std::string const &str ) const {
    
    if(root_node == nullptr){
        return false;
    }
    
    //Check if the string is valid
    for(int i = 0; i<str.size(); i++){                                                  //Strictly less than sign as every string ends with a null character.
        
        if((str[i] < 0x41 || str[i] > 0x5A) && (str[i] < 0x61 || str[i] > 0x7A)){
            
            throw illegal_argument();
        }
    }
    cout<<"calling member"<<endl;
    return root_node->member(str,0);
}

bool Trie::insert( std::string const &str ) {
    //Check if the string is valid
    for(int i = 0; i<str.size(); i++){
        
        char r =str[i];
        //cout<<r<<endl;
        
        if((r < 65 || r > 90) && (r < 97 || r > 122)){
            //cout<<"here"<<endl;
            throw illegal_argument();
        }
    }
    
    cout<<str.size()<<endl;
    //Search the string in the trie
    
    if(size() == 0){
        cout<<16<<endl;
        root_node = new Trie_node();
        root_node -> insert(str,0);
        trie_size++;
        return true;
    }
    
    else{
    
        if(member(str) == true){ return false;}
        
    
        else{
            cout<<21<<endl;
            root_node->insert(str,0);
            trie_size++;
            return true;
        }
    }
}

bool Trie::erase( std::string const &str ) {
    
    
    //Check if the string is valid
    for(int i = 0; i<str.size(); i++){
        
        if((str[i] < 0x41 || str[i] > 0x5A) && (str[i] < 0x61 || str[i] > 0x7A)){
            
            throw illegal_argument();
        }
    }
    
    cout<<"I am in erase"<<endl;
    //Search the string in the trie
    
    if(member(str) == false){ return false;}
    
    else{
            if(root_node == nullptr){
            cout<<"root is null"<<endl;
            return false;
        }
        
        else{
            cout<<"e2"<<endl;
            root_node->erase(str,0,root_node);
            trie_size--;
            return true;
            
            /*if(size() == 1){
                delete root_node;
            }*/
        }
    }
}

void Trie::clear() {
    
    if(root_node == nullptr){
      throw illegal_argument();
    }
    
    root_node->clear();
    trie_size = 0;                                  //to notify that the tree is empty
}

#endif
