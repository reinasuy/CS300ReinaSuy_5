#include <string>
#include <iostream>
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item{
    
private:
    
    string upcCode;
    string itemName;
    
public:
    bool operator<(Item& i){
        
        return(upcCode < i.upcCode);
    }
    
    bool operator>(Item& i){
        
        return(upcCode > i.upcCode);
    }
    
    bool operator==(Item& i){
        
        return(upcCode == i.upcCode);
    }
    
    bool operator!=(Item& i){
        
        return(upcCode != i.upcCode);
    }
    //make an overload for > = < for and item to item 
    
    void setupcCode(string code){
        upcCode = code;
    }
    string getupcCode(){
        return upcCode;
    }
    void setItemName(string item){
        itemName = item;
    }
    string getItemName(){
        return itemName;
    }
    
    void setAll(string upcCode, string itemName){
        this->upcCode = upcCode;
        this->itemName = itemName;
    }
    
    Item(string upcCode, string itemName){
        this->upcCode = upcCode;
        this->itemName = itemName;
    }
    
    void setAll(string upcCode){
        this->upcCode = upcCode;
    }
    Item(string upcCode){
        this->upcCode = upcCode;
    }
    
    Item(){}
    
    ~Item(){}
    
};


#endif /* ITEM_H */

