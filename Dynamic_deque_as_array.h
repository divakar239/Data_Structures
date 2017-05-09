//
//  main.cpp
//  Deque Prac
//
//  Created by Divakar Kapil on 2016-10-01.
//  Copyright © 2016 Divakar Kapil. All rights reserved.
//

#include <iostream>
#include <cmath>

#include "EXCEPTION.h"
#include "ECE250.h"

class Dynamic_deque_as_array{
    
private:
    
    int *array;
    int ihead;
    int itail;
    int count;
    int arraySize;
    void doubleArray();

    
public:
    
    
    //Methods
    
    Dynamic_deque_as_array( int = 10 );
    ~Dynamic_deque_as_array();
    
    int size() const;
    int head() const;
    int tail() const;
    
    bool empty() const;
    int capacity() const;
    
    void enqueue_head( const int & );
    void enqueue_tail( const int & );
    int dequeue_head();
    int dequeue_tail();
    void clear();
    //void print();
    
    
};




// Constructor and Destructor

Dynamic_deque_as_array::Dynamic_deque_as_array(int n) {
    
   
    ihead=0;
    itail=0;
    count=0;
    
    
    
    if(n<1){
        
        arraySize = 1;
        array = new int[1];
    }
    
    else{
        arraySize = n;
        array = new int[n];
    }
    
}

Dynamic_deque_as_array::~Dynamic_deque_as_array() {
    
    delete [] array;
    
}



/*void Dynamic_deque_as_array:: print(){
    
    for(int i = 0; i<arraySize; i++){
        
        std::cout<<array[i]<<' ';
    }
    std::cout<<std::endl;
}*/






// Accessors

int Dynamic_deque_as_array::size() const {
    
    return count;
}

int Dynamic_deque_as_array::capacity() const {
    
    return arraySize;
}


bool Dynamic_deque_as_array::empty() const {
    
    if(count == 0){
        
        return true;
    }
    
    else{
        
        return false;
    }
}


int Dynamic_deque_as_array::head() const {
    
    if(empty()){
        
       throw underflow();
    }
    
    return array[ihead];
}


int Dynamic_deque_as_array::tail() const {
    
    if(count == 0){
        
       throw underflow();
    }
    
    
    return array[itail];
}



// This is the function that doubles the array size of the 
void Dynamic_deque_as_array::doubleArray(){
    
    
    int *newArray = new int[2*arraySize];
    
    if(ihead<=itail){
        
        for (int i=ihead; i<(itail+1);i++){
            
            newArray[i]=array[i];
            
        }
    }
    
    
    else if(ihead > itail){
        
        for(int i=0;i<(itail+1);i++){
            //print();
            newArray[i]=array[i];
        }
        
        for(int i=ihead;i<arraySize;i++){
            
            newArray[arraySize+i]=array[i];
            
        }
        ihead = ihead + arraySize;
        
        
    }
    arraySize = 2*arraySize;
    int *temp=array;
    array = newArray;
    
    delete [] temp;
    
}






// Mutators

void Dynamic_deque_as_array::enqueue_head( const int &obj ) {
    
    if(size()==arraySize){
        doubleArray();
    }
    
    if(size() == 0){
        
        //ihead =0;
        array[ihead]=obj;
        count++;
    }
    
    else{
            
        ihead = ((ihead-1)+arraySize)%arraySize;
        array[ihead]=obj;
        count++;
        
    }
    
    return;
}








void Dynamic_deque_as_array::enqueue_tail( const int &obj ) {
    
    if(size()==arraySize){
        doubleArray();
    }
    
    
    
    if(size() == 0){
        
        //itail =0;
        array[itail]=obj;
        count++;
    }
    
    else{
        
        itail = ((itail+1)+arraySize)%arraySize;
        array[itail]=obj;
        count++;
        
    }
    
    return;
}


int Dynamic_deque_as_array::dequeue_head() {
    
    int dispHead =INT_MAX;
    
    
    if(size()==0){
        
        throw underflow();
    }
    
    
    else if(size()==1){
        
        dispHead = array[ihead];
        
        clear();
        
    }
    
    else{
        
        dispHead = array[ihead];
        ihead=(ihead+1)%arraySize;
        count--;
    }
    
    return dispHead;
    
}

int Dynamic_deque_as_array::dequeue_tail() {
    
    int dispTail = INT_MAX;
    
    //if there was only 1 element
    
    
    if(empty()){
        
        throw underflow();
        
    }
    
    else if(count == 1){
        
        dispTail = array[itail];
        clear();
        
    }
    
    else{
        dispTail = array[itail];
        itail = ((itail-1)+ arraySize)%arraySize ;
        count--;
        
    }
    
    return dispTail;
}


void Dynamic_deque_as_array::clear() {
    
    count = 0; // Emptying the Deque
    
    ihead = 0;
    itail = 0;
    
    return;
}



