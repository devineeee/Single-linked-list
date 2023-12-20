#include <iostream>
using namespace std;

// Deklarasi single linked list
struct Buku {
  // Member
  string judul, pengarang; 
  int tahunTerbit;
  
  // Pointer ke node berikutnya
  Buku *next;
};

// Pointer head, tail, current, dan temp
Buku *head = nullptr; 
Buku *tail = nullptr;
Buku *cur = nullptr;
Buku *newNode = nullptr;

// Fungsi-fungsi linked list
void createSingleLinkedList(string judul, string pengarang, int tB);  
void addFirst(string judul, string pengarang, int tB);
void addLast(string judul, string pengarang, int tB);
void printSingleLinkedList();
void freeLinkedList();

int main() {

  // Buat linked list
  createSingleLinkedList("Kata", "Geez & Aan", 2018);
  
  // Print
  printSingleLinkedList();
  
  // Tambah node di awal
  addFirst("Dia Adalah Kakakku", "Tere Liye", 2009); 
  
  // Print lagi 
  printSingleLinkedList();
   
  // Tambah node di akhir
  addLast("Aroma Karsa", "Dee Lestari", 2018);
  
  // Print
  printSingleLinkedList();  

  // Dealokasi memori
  freeLinkedList();

  return 0;
}

// Buat single linked list
void createSingleLinkedList(string judul, string pengarang, int tB) {

  // Buat node head
  head = new Buku();

  // Set member
  head->judul = judul;
  head->pengarang = pengarang;  
  head->tahunTerbit = tB;
  
  // Pointer next ke null
  head->next = nullptr;
  
  // Tail sama dengan head
  tail = head;
}

// Tambah node di awal
void addFirst(string judul, string pengarang, int tB) {

  // Buat node baru
  newNode = new Buku();

  // Set member node baru
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tB;

  // Next dari newNode tunjuk ke head lama
  newNode->next = head;

  // Head baru adalah newNode
  head = newNode;
}

// Tambah node di akhir 
void addLast(string judul, string pengarang, int tB) {

  // Buat node baru
  newNode = new Buku();

  // Set member node baru
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tB;
  
  // Next dari tail ke newNode
  tail->next = newNode;

  // Tail baru adalah newNode
  tail = newNode;
  
  // Next dari newNode ke null
  newNode->next = nullptr; 
}

// Print
void printSingleLinkedList() {

  // Mulai dari head
  cur = head; 
  
  // Traverse
  while(cur != nullptr) {
     cout << "Judul Buku: " << cur->judul << endl;
     cout << "Pengarang Buku: " << cur->pengarang << endl; 
     cout << "Tahun Terbit Buku: " << cur->tahunTerbit << endl;
    
     cur = cur->next; 
  }
}

// Dealokasi memori
void freeLinkedList() {

  // Mulai dari head
  cur = head;

  // Traverse dan delete satu-persatu
  while(cur != nullptr) {
    newNode = cur;
    cur = cur->next;
    delete newNode;
  }
}