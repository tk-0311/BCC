#include <iostream>

using namespace std;

class LinkedList{
private:
  struct Node {
    int id;
    double gpa;
    string name;
    Node* next;
  };
  Node* head;
public:
  LinkedList();
  ~LinkedList();
  void Add();
  void Delete();
  void Display();
  void Modify();
  void Purge();
  void Search();
};

LinkedList::LinkedList(){
}
LinkedList::~LinkedList(){
}
void LinkedList::Add(){

};
void LinkedList::Delete(){

};
void LinkedList::Display(){

};
void LinkedList::Modify(){

};
void LinkedList::Purge(){

};
void LinkedList::Search(){

};
