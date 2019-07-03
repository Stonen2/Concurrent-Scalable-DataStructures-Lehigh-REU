#pragma once
#include <iostream>
#include <cstddef>
using namespace std; 


class srmap {

	//Created by Nick Stone and Thomas Maranzatto 

	//Concurrent single linked link list. 

	//Assuming all values are unique

	//Created on 6/17/2019

	

	private:

		struct Node {
			Node* next;
			void* data; 
			bool inuse;


			//int val;
			//int key; 
			//bool marked;
			bool end;
			Node(Node* nnext, void* id ,bool iuse,  bool iend) {
				this->next = nnext;
				this->data = id;
				this->inuse = iuse; 
				//this->key = kkey;
				//this->marked = mmarked;
				this->end = iend;


			}


		};
		//Linked List Data Structure
		Node* head;

		//Size of the heap 
		size_t heap; 
		size_t next; 



		//Pointer to the first value 

		void* start; 
		
		//Number of Pieces allocated
		int count; 


	public:

		srmap() {
			head = NULL;
			heap = 0; 
			next = 0; 
			start = nullptr; 
			count = 0; 

			/* 
			Instaniate Some of the allocator data here
			
			*/
		}

		~srmap() {
			if (head) {
				Node* lead = head->next;
				Node* follow = head;
				while (lead) {
					delete(follow);
					follow = lead;
					lead = lead->next;
				}
				delete(follow);
			}
		}


		//Node(Node* nnext, T vval, bool mmarked, bool iend) {

		void insert(void * vall) {

			Node* temp = head;
			//Empty list 
			if (head == NULL) {
				head = new Node(NULL, vall,true,  true);
			}

			//One element
			else if (head->next == NULL) {
				head->end = false;
				Node* temp = new Node(NULL, vall,true, true);
				head->next = temp;

			}

			//Arbitrary Number of elements
			else {


				while (temp->next != NULL) {
					continue;



				}
				//temp->marked = false;
				Node* curr = new Node(NULL, vall,true, true);
				temp->next = curr;
			}
			count = count + 1; 
		}
		/*
		void mark(int vall, bool mmar) {
			if (head == NULL) {
				cout << "List is empty";
				//break;
			}
			Node* temp = head;
			while (temp->next != NULL) {
				if (temp->val == vall && temp->marked == mmar) {
					cout << "Already IN this state";
					break;

				}
				else if (temp->val == vall && temp->marked != mmar) {
					temp->marked = mmar;

				}
				else {
					temp = temp->next;

				}

			}

		}*/
		void remove() {
			//size_t temps = head ->;
			if (head == NULL) {
				cout << "NULL";
			}

			//Only one element
			else if (head->next == NULL) {
				delete(head);
				head = NULL;
			}
			else {
				Node* temp = head->next;
				delete(head);
				head = temp;
			}

			count = count - 1; 
		

		}

		void print() {
			Node* temp = head;

			while (temp != NULL) {
				cout << temp->data;
				cout << endl;
				temp = temp->next;


			}


		}

		bool search(void* value) {
			Node* temp = head;
			//bool marked[1] = { false };
			if (head == NULL) {
				return false;
			}
			while (temp != NULL) {
				if (temp->data == value) {
					cout << "FOUND";
					return true;
				}

				else {
					temp = temp->next;


				}

			}
			return false;
		}

		void* malloc(size_t s) {

			size_t pad_size = PAD(s);        // TODO: pad the size appropriately
			void* retval = &start + next;
			next += pad_size;
			heap += pad_size;
			return retval;
		}

		size_t PAD(size_t s) {
			size_t temp = s;
			if (s % 8 == 0) {
				return temp;

			}
			else {
				temp = s / 8;
				size_t offset = 8 - temp;
				temp = s + offset;
				return temp;

			}

			//return temp; 
		}

		void free() {

			/*
			
			
			Temporary No- OP 
			
			
			*/




		}

};