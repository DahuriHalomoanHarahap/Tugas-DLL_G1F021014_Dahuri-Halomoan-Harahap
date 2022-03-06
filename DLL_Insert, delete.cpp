#include <iostream>
using namespace std;

struct Buku{
	string judul, pengarang;
	int terbit;
	Buku *prev;
	Buku *next;
	
};

	Buku *head, *tail, *cur, *newNode, *del, *afterNode;
	
	//create Double Linked List
	void createDoubleLinkedList(string judul, string pengarang, int terbit) {
		head = new Buku();
		head->judul=judul;
		head->pengarang=pengarang;
		head->terbit=terbit;
		head->prev=NULL;
		head->next=NULL;
		tail = head;
	}
	
		//count Double Linked List
	int countDoubleLinkedList() {
			if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
			} else {
				cur = head;
				int jumlah = 0;
				while (cur != NULL) {
					jumlah++;
				cur= cur->next;
			}
			return jumlah;
		}
	}
	
	//add first Double Linked List
	void addfirst(string judul, string pengarang, int terbit) {
		if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
		} else {
		newNode = new Buku();
		newNode->judul=judul;
		newNode->pengarang=pengarang;
		newNode->terbit=terbit;
		newNode->prev=NULL;
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		}
	}
	
	//add last Double Linked List
	void addlast(string judul, string pengarang, int terbit) {
		if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
		} else {
		newNode = new Buku();
		newNode->judul=judul;
		newNode->pengarang=pengarang;
		newNode->terbit=terbit;
		newNode->prev=tail;
		newNode->next=NULL;
		tail->next=newNode;
		tail=newNode;
		}
	}
	
	//add middle Double Linked List
	void addmiddle(string judul, string pengarang, int terbit, int posisi) {
			if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
		} else {
			if (posisi == 1) {
				cout<<"Posisi 1 itu bukan posisi tengah"<<endl;
			} else if (posisi < 1 || posisi > countDoubleLinkedList() ) {
				cout<<"Posisi diluar jangkauan"<<endl;
			} else {
				newNode = new Buku();
				newNode->judul=judul;
				newNode->pengarang=pengarang;
				newNode->terbit=terbit;
				newNode->prev=tail;
				newNode->next=NULL;
				
				//tranversing
				cur = head;
				int nomor = 1;
				while (nomor < posisi - 1) {
					cur = cur->next;
					nomor++;
					}
					afterNode = cur->next;
					newNode->prev=cur;
					newNode->next=afterNode;
					cur->next=newNode;
					afterNode->prev=newNode;
			}
		}
	}

		//delete first
	void deletefirst() {
		if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
		} else {
		del=head;
		head=head->next;
		head->prev=NULL;
		delete del;
		}	
	}
	
	//delete last
	void deletelast() {
		if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
		} else {
		del=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete del;
		}	
	}
	
	//delete middle
	void deletemiddle(int posisi) {
		if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
		} else {
			if (posisi ==1 || posisi == countDoubleLinkedList() ) {
				cout<<"Posisi  bukan posisi tengah"<<endl;
			} else if (posisi < 1 || posisi > countDoubleLinkedList() ) {
				cout<<"Posisi diluar jangkauan"<<endl;
			} else {
				int nomor =1;
				cur = head;
				while (nomor < posisi - 1) {
					cur = cur->next;
					nomor++;
				}
				del = cur->next;
				afterNode=del->next;
				cur->next = afterNode;
				afterNode->prev = cur;
				delete del;
			}
		}
	}
	
	//print Double Linked List
	void printDoubleLinkedList() {
			if (head == NULL) {
				cout<<"Double Linked List belum dibuat";
			} else {
				cout<<"Jumlah Data : "<<countDoubleLinkedList()<<endl;
				cout<<"Isi Data : "<<endl;
				cur = head;
				while (cur != NULL) {
				cout << "Judul Buku   : "<< cur->judul<<endl;
				cout << "Pengarang    : "<< cur->pengarang<<endl;
				cout << "Tahun Terbit : "<< cur->terbit<<endl;
				
				cur= cur->next;
			}
		}
	}

	int main() {
	
	createDoubleLinkedList("Matematika", "Erlangga", 2009);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addfirst("Kimia", "Suryadi", 2012);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addlast("Bahasa Indonesia", "Suryono", 2018);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addmiddle("Biologi", "Siswanto", 2008, 2); //menambahakan data baru di posisi ke-2
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	/*deletefirst();
	printDoubleLinkedList();
	
	deletelast();
	printDoubleLinkedList();
	
	deletemiddle(3); //menghapus data pada posisi ke-3
	printDoubleLinkedList(); */
	
}
