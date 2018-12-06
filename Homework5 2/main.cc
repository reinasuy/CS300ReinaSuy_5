#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include "BinarySearchTree.h"
#include "Item.h"
#include "HashTable.h"

using namespace std;

BinarySearchTree<Item> tree;

Item find(Item* array, Item item){
    
    Item arraySearched;
    
        for(int i = 0; i < 10000000 ; i++ ){
            if(array[i] == item){
            arraySearched = array[i];
            return arraySearched;
        }
    }
}

void fileInserts(BinarySearchTree<Item> BST, string fileName){
 string input;
 
 string firstline;
 
 ifstream file;
 
 file.open(fileName);
 
 getline(file, firstline); //skipping over first line 
 
 while(getline(file, input)){ //reads the rest of the file starting from second line 
     
 istringstream ss(input);
 
 string upcCode;   
 
 string itemName;
 
 Item item;
 
 getline(ss, upcCode, ',');
 item.setupcCode(upcCode);
 
 getline(ss, itemName);
 item.setItemName(itemName);

 

BST.insert(item);


 }
}

void fileInserts(HashTable table, string fileName){
 string input;
 
 string firstline;
 
 ifstream file;
 
 file.open(fileName);
 
 getline(file, firstline); //skipping over first line 
 
 while(getline(file, input)){ //reads the rest of the file starting from second line 
     
 istringstream ss(input);
 
 string upcCode;   
 
 string itemName;
 
 Item item;
 
 getline(ss, upcCode, ',');
 item.setupcCode(upcCode);
 
 getline(ss, itemName);
 item.setItemName(itemName);

 

 table.insert(item);


 }
}

void fileInserts(Item* array, string fileName){
 
 int i = 0;
 
 string input;
 
 string firstline;
 
 ifstream file;
 
 file.open(fileName);
 
 getline(file, firstline); //skipping over first line 
 
 while(getline(file, input)){ //reads the rest of the file starting from second line 
     
 istringstream ss(input);
 
 string upcCode;   
 
 string itemName;
 
 Item item;
 
 getline(ss, upcCode, ',');
 item.setupcCode(upcCode);
 
 getline(ss, itemName);
 item.setItemName(itemName);

 

 array[i] = item;
 i++;


 }
}





int main(){
    
 HashTable table;
 
 Item* array = new Item[100000000];
 
 
 
 string filename = "upc_corpus.txt";
 string input;
 string firstline;
 ifstream file;
 file.open(filename);
 getline(file, firstline);
 while(getline(file, input)){
 istringstream ss(input);
 string upcCode;  
 string itemName;
 Item item;
 getline(ss, upcCode, ',');
 item.setupcCode(upcCode);
 getline(ss, itemName);
 item.setItemName(itemName);

 table.insert(item);
 }

 
 fileInserts(array, filename);
 
 fileInserts(tree, filename);
 
 

//where we will search for upc code 
 string userinput;
 Item item;
 cout<<"UPC Code:";
 cin>>userinput;
 item.setupcCode(userinput);
 
clock_t t1;
t1 = clock();

Item bstSearched = tree.search(item);

t1 = clock() - t1;



clock_t t2;
t2 = clock();

Item itemArray = find(array, item);

t2 = clock() - t2;


clock_t t3;
t3 = clock();

table.find(item);

t3 = clock() - t3;

 
 cout<<bstSearched.getItemName()<<endl;
 cout<<"BST time: "<<t1/1000<<" milliseconds"<<endl;
 cout<<"Array time: "<<t2/1000<<" milliseconds"<<endl;
 cout<<"Hash Table time:"<<t3/1000<<" milliseconds"<<endl;
 
}

