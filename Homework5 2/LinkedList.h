
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

using namespace std;
template <class T>
struct LinkNode{
        //generic type of data in the list
	T data;
        //the next node of whatever node
	LinkNode* next;
};

template <class T>
class LinkedList{
	private:
		LinkedList(const LinkedList&)=delete; //copy constructor

        protected:       
                
                //the count of the list
		int count;
                
                //creates the head and the last node
		LinkNode<T> *head, *last; 
        public:
		LinkedList();
		bool isEmpty();
		int length();
		T front();
		T back();
                bool searchNode(T&);
		void insertFirst(T&);
		void insertLast(T&);
		void deleteNode(T&);
		void destroylist();
		LinkedList<T>& operator=(LinkedList<T>&);
		template <class U>
		friend ostream& operator<<(ostream& os, LinkedList<U>& list);
		~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList(){
     head = last = NULL;
     count = 0;
}
template <class T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}
template <class T>
int LinkedList<T>::length(){
	return count;
}
template <class T>
T LinkedList<T>::front(){
	return head->data;
}
template <class T>
T LinkedList<T>::back(){
	return last->data;
}
template <class T>
void LinkedList<T>::insertFirst(T& item){
	LinkNode<T> *temp = new LinkNode<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if(last==NULL) last = temp;

}


template <class T>
void LinkedList<T>::insertLast(T& item){
	LinkNode<T> *newnode = new LinkNode<T>;
	newnode->data = item;
	newnode->next = NULL;
	if(head==NULL){
		head = last = newnode;
	}else{
		last->next = newnode;
		last = newnode;
	}
	count++;
}

template <class T>
bool LinkedList<T>::searchNode(T& item){
	if(head == NULL)
		cerr<<"empty list";
	else{
		if(head->data == item){
                    return true;
                    
		}else{
			LinkNode<T>* p = head;
			LinkNode<T>* q = p->next;
			while(q!=NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if(q!=NULL){
                            return true;
			}
		}
	}
        
}


template <class T>
void LinkedList<T>::deleteNode(T& item){
	if(head == NULL)
		cerr<<"empty list";
	else{
		if(head->data == item){
			LinkNode<T>* p = head;
			head = head->next;
			delete p;
			count--;
			if(head==NULL) last = NULL;
		}else{
			LinkNode<T>* p = head;
			LinkNode<T>* q = p->next;
			while(q!=NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if(q!=NULL){
				p->next = q->next;
				count--;
				if(last == q) last = p;
				delete q;
			}
		}
	}
}

template <class T>
void LinkedList<T>::destroylist(){
	LinkNode<T> *p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
	if(this!= &list){
		copylist(list);
	}
	return *this;
} 
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	LinkNode<T> *p = list.head;
	while(p!= NULL){
		os<<p->data<<" "<<endl;
		p = p->next;
	}

}

template <class T>
LinkedList<T>::~LinkedList(){
	destroylist();
}



#endif /* LINKEDLIST_H_ */
