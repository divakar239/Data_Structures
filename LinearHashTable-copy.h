//
//  LinearHashTable.h
//  LinearHashTable.h
//
//  Created by Divakar Kapil on 2016-10-29.
//  Copyright © 2016 Divakar Kapil. All rights reserved.
//

#ifndef LINEAR_HASH_TABLE_H
#define LINEAR_HASH_TABLE_H
#include "Exception.h"
#include "ece250.h"

enum state {EMPTY, OCCUPIED, DELETED};

template<typename T>
class LinearHashTable {
private:
    int count;
    int power;
    int array_size;
    int mod;
    T *array;
    state *occupied;
    
    int load = 0;
    
    //int h1( T const & ) const; // first hash function
   // int h2( T const & ) const; // second hash function
    
    
    
public:
    LinearHashTable( int = 5 );
    ~LinearHashTable();
    int size() const;
    int capacity() const;
    double load_factor() const;
    bool empty() const;
    bool member( T const & ) const;
    T bin( int ) const;
    
    
    void insert( T const & );
    bool remove( T const & );
    void clear();
    void print() const;
};

template<typename T >
LinearHashTable<T >::LinearHashTable( int m ):
array_size( 1 << m ){
    
    load = 1 << m;
    power = m;
    array = new T [array_size];
    occupied = new state [array_size];
    
    
    
    for(int i = 0; i < array_size; i++){
        
        occupied[i] = EMPTY;
    }
    
}

template<typename T >
LinearHashTable<T >::~LinearHashTable() {
    
    delete [] array;
    delete [] occupied;
    
}

template<typename T >
int LinearHashTable<T >::size() const {
    
    if (count < 0){
        
        throw underflow();
    }
    
    return count;
    
}

template<typename T >
int LinearHashTable<T >::capacity() const {
    
    if(array_size <= 0){
        
        throw underflow();
    }
    
    return array_size;
}

template<typename T >
double LinearHashTable<T >::load_factor() const {
    
   
    if(array_size == 0){
        
        throw division_by_zero();
    }
    
    else{
       return ((float)count/((float)array_size));                   // Have to cast into float otherwise can't comapre with 0.25
    }
    
}

template<typename T >
bool LinearHashTable<T >::empty() const {
    
    if(count == 0){
        
        return true;
    }
    
    else{
        return false;
    }
}


template<typename T >
bool LinearHashTable<T >::member( T const &obj ) const {
    
    int i = 0;
    int hash1 = ((int)obj+array_size)%array_size;
    int hash_obj = hash1;
    
    
    while(occupied[hash1] != EMPTY){
        
        if(array[hash1] == obj){
            
            return true;
            
        }
        
        else{
            i++;
            hash1 = (hash_obj + i)%array_size;
        }
    }

    return false;
}

template<typename T >
T LinearHashTable<T >::bin( int n ) const {
    
    if (count == 0){
        
        throw underflow();
    }
    
    else{
        
        return array[n];
    }
}

template<typename T >
void LinearHashTable<T >::insert( T const &obj ) {
    
    //load = count/array_size;
    
    if (load_factor() > 0.75){
        
        array_size = 2*array_size;
        T *new_array = new T[array_size];
        state *new_occupied = new state[array_size];
        
        for(int j = 0; j<array_size; j++){
            
            new_occupied[j] = EMPTY;
        }
        
        
        
        for(int i = 0; i < (array_size)/2; i++){
            
            
            if(occupied[i] == OCCUPIED){
                
                int j =0;
                int hash1 = (array[i]+array_size)%array_size;
                int hash_obj = hash1;

                
                while(new_occupied[hash1] == OCCUPIED){
                    
                    j++;
                    hash1 = (hash_obj + j + array_size)%array_size;
                }
                
                new_array[hash1] = array[i];            //Copying the old elements
                new_occupied[hash1] = occupied[i];      // Updating the state of the old elements
            }
        }
        T *temp_array = array;
        array = new_array;
        delete [] temp_array;
        
        state *temp_occupied = occupied;
        occupied = new_occupied;
        delete [] temp_occupied;
        
        int i = 0;
        int hash1 = ((int)obj + i + array_size)%array_size;
        int hash_obj = hash1;
        
        while(occupied[hash1] == OCCUPIED){
            
            i++;
            hash1 = (hash_obj + i +array_size)%array_size;
        }
        
        array[hash1] = obj;
        occupied[hash1] = OCCUPIED;
        count++;

    }
    
    else {
        
        int i = 0;
        int hash1 = ((int)obj+array_size)%array_size;
        int hash_obj = hash1;
        
        while(occupied[hash1] == OCCUPIED){
            //std::cout<<hash1<<std::endl;

            
            i++;
            hash1 = (hash_obj + i + array_size)%array_size;
            
        }
        array[hash1] = obj;
        occupied[hash1] = OCCUPIED;
        count++;
        
        std::cout<<count<<std::endl;
    }
}

template<typename T >
bool LinearHashTable<T >::remove( T const &obj ) {
    
    
    if(member(obj) == false){
        
        return false;
    }
    
    else{
        
            if(load_factor() <= 0.25 && capacity() != load){
            
            //std::cout<<load_factor()<<std::endl;
                
            array_size = array_size/2;
            T *new_array = new T[array_size];
            state *new_occupied = new state[array_size];
            
            int hash1 = ((int)obj+array_size)%array_size;
            int hash_obj = hash1;
            
            for(int j = 0; j<array_size; j++){
                
                new_occupied[j] = EMPTY;
            }
            
            
            for(int i = 0; i < 2*array_size; i++){
            
                while(new_occupied[hash1] == OCCUPIED){
                    
                    i++;
                    hash1 = (hash_obj + i + array_size)%array_size;
                }
                
                new_array[hash1] = array[i];            //Copying the old elements
                new_occupied[hash1] = occupied[i];      // Updating the state of the old elements
                
            }
            
            T *temp_array = array;
            array = new_array;
            delete [] temp_array;
            
            state *temp_occupied = occupied;
            occupied = new_occupied;
            delete [] temp_occupied;
                
            
            
                                                   // Decrease the size of the hash table and is
        }                                                       // current size of the hash table
        
        
        //else{
            
            //std::cout<<"Here"<<std::endl;
            int i = 0;
            int hash1 = ((int)obj+array_size)%array_size;
            int hash_obj = hash1;
            
            while(occupied[hash1] == OCCUPIED){
                
                if(array[hash1] == obj){
                    
                   // std::cout<<"Here Now Too"<<std::endl;
                    array[hash1] = NULL;                                // removing element from the array
                    occupied[hash1] = DELETED;                          // setting the state of the element
                    count--;                                            // Decrease number of elements
                    //array_size--;
                    
                    return true;
                    
                }
                
                else{
                    
                   // std::cout<<"Here Now"<<std::endl;
                    i++;
                    hash1 = (hash_obj + i + array_size)%array_size;
                }
            }
            
            array[hash1] = NULL;                                // removing element from the array
            occupied[hash1] = DELETED;                          // setting the state of the element
            count--;                                            // Decrease number of elements
            array_size--;
        
        return true;
        //}
    }
    
}

template<typename T >
void LinearHashTable<T >::clear() {
    
    count = 0;
    
    for(int i = 0; i < array_size; i++){
        array[i] = 0;
        occupied[i] = EMPTY;
    }
}

template<typename T >
void LinearHashTable<T >::print() const{
 
    for(int j =0; j<array_size; j++){
        
        std:: cout<<array[j]<<occupied[j]<<std::endl;
        //std::cout<<power<<std::endl;
    }
    
    // enter your implemetation here
}

#endif
