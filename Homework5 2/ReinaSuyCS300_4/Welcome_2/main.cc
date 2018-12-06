#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include "BinarySearchTree.h"
#include "Item.h"

using namespace std;

BinarySearchTree<Item> tree;


int main(){
 
 int i= 0;
 
 Item* array = new Item[100000000];
 
     
 
 //Item* array = new Item[100000000];
 //upcCode is a key
 //itemName is a value
 string input;
 string firstline;
 ifstream file;
 file.open("upc_corpus.txt");
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

 
 
 tree.insert(item);
 array[i] = item;
 i++;

 
      

 }
 

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


Item arraySearched;

clock_t t2;
t2 = clock();

for(int i = 0; i < 10000000 ; i++ ){
    if(array[i] == item){
        arraySearched = array[i];
    }
}

t2 = clock() - t2;

 
 cout<<bstSearched.getItemName()<<endl;
 cout<<"BST time: "<<t1<<" miliseconds"<<endl;
 cout<<"Array time: "<<t2<<" miliseconds"<<endl;
 
}

