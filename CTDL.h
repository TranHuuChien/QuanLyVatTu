#pragma once
#define STACKSIZE 50
#define QUEUESIZE 50
//template<class T>
//class Stack{
//	private:
//		int sp;// STACK POINTER
//		T* nodes[STACKSIZE]; // POITER ARRAY TYPE T
//	public:
//		Stack(){
//			sp = -1;
//		}
//		int push(T* p){
//			if(isFull()){
//				return 0;
//			}
//			nodes[++sp] = p;
//			return 1;
//		}
//		int pop(T* &p){
//			if(isEmpty()){
//				return 0;
//			}
//			p = nodes[sp--];
//			return 1;
//		}
//		bool isFull(){
//			if(sp == STACKSIZE -1){
//				return true;
//			}
//			return false;
//		}
//		bool isEmpty(){
//			if(sp == -1){
//				return true;
//			}
//			return false;
//		}
//		T* getSp(){
//			return nodes[sp];
//		}
//};
//
//template<class T>
//class Queue{
//	private:
//		int front;
//		int rear;
//		T* nodes[QUEUESIZE];
//	public:
//		Queue(){
//			front = -1;
//			rear = -1;
//		}
//		bool isEmpty(){
//			if(front == -1 || rear == -1){
//				return true;
//			}
//			return 0;
//		}
//		bool isFull(){
//			if(rear - front + 1 == QUEUESIZE || rear -front + 1 == 0){
//				return 1;
//			}
//			return 0;
//		}
//		int push(T* p){
//			if(isFull()){
//				return 0;
//			}
//			if(rear == QUEUESIZE -1){
//				rear = 0;
//				nodes[rear] = p;
//			}
//			else{
//				nodes[++rear] = p;
//			}
//			if(front == -1){
//				front = 0;
//			}
//			return 1;
//		}
//		T* pop(){
//			T* p = nodes[front];
//			if(front == rear){
//				front = -1;
//				rear = -1;
//			}
//			else{
//				front++;
//			}
//			if(front == QUEUESIZE){
//				front = 0;
//			}
//			return p;	
//		}
//		T* getFront(){
//			return nodes[front];
//		}
//			
//};

template<class T>
struct node{
	T* data;
	node* next;
};

template<class T>
class Stack{
	private:
		node<T>* sp;
	public:
		Stack(){
			sp = NULL;
		}
		bool isEmpty(){
			if(sp==NULL){
				 return true;
			}
			return false;
		}
		void push(T* p){
			node<T>* temp = new node<T>();
			temp->data = p;
			temp->next = sp;
			sp = temp;
		}
		int pop(T* &p){
			if(isEmpty()){
				return 0;
			}
			node<T>* temp = sp;
			sp = temp->next;
			p = temp->data;
			delete temp;
			return 1;
		}
};

template<class T>
class Queue{
	private:
		node<T>* front;
		node<T>* rear;
	public:
		Queue(){
			front = NULL;
			rear =NULL;
		}
		bool isEmpty(){
			if(front == NULL || rear == NULL){
				return true;
			}
			return false;
		}
		void push(T* p){
			node<T>* temp = new node<T>();
			temp->data = p;
			temp->next = NULL;
			if(front == NULL){
				front = temp;
			}
			else{
				rear->next = temp;
			}
			rear = temp;
		}
		int pop(T* &p){
			if(isEmpty()){
				return 0;
			}
			node<T>* temp;
			p = front->data;
			temp = front;
			front = temp->next;
			delete temp;
			return 1;
		}
		T* getFront(){
			return front->data;
		}
};









