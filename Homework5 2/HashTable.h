#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <sstream>
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "item.h"
#include <list>
//include a linked list

using namespace std;


class HashTable{
   static const int TABLE_SIZE = 1000;
   //size of table is of size 1000
   //unchangeable size
   //a linked list that holds T objects that points to HashTable(array) 
   LinkedList<Item>HashT[TABLE_SIZE]; 
   
    public: 
        
      HashTable(); 
      void insert(Item data); 
      int hashFunction(Item data);
      bool find(Item data); 
    

};


HashTable::HashTable(){}

void HashTable::insert(Item data){
    
    HashT[hashFunction(data)].insertFirst(data);
    
}

int HashTable::hashFunction(Item data){
    string s = data.getupcCode();
    
    stringstream ss(s);
    
    int x = 0;
    ss>>x;
    
    int num = x %1000;
    
    if(num < 0){
        num = -num;
    }
    return num;
}


 bool HashTable::find(Item data){
         //get the hash index of key;
    int index = hashFunction(data);
    
    return HashT[index].searchNode(data);
    
    
    
 }   
    

  

#endif