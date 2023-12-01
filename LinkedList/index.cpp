#include <iostream>

using namespace std;

class LinkedList{
private:
  struct Node {
    int ID;
    double GPA;
    string NAME;
    Node* next;
    Node(int id,double gpa, string name) {
      ID = id;
      GPA = gpa;
      NAME = name;
      next = nullptr;
    };
  };
  Node* head;
  int validateID() {
    int id;
    while(true) {
      cout << "\033[32mPlease Enter ID: \033[0m";
      cin >> id;
      if (cin.fail()){
        cout << "\033[31mPlease enter a valid ID!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }else {
        break;
      }
    };
    return id;
  };
  double validateGPA() {
    double gpa;
    while(true) {
      cout << "\033[32mPlease Enter GPA: \033[0m";
      cin >> gpa;
      if (cin.fail()){
        cout << "\033[31mPlease enter a valid GPA!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }else {
        break;
      }
    };
    return gpa;
  };
  string validateName() {
    string name;
    while(true) {
      cout << "\033[32mPlease Enter Name: \033[0m";
      cin.ignore();
      getline(cin,name);
      if (cin.fail()){
        cout << "\033[31mPlease enter a valid Name!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }else {
        break;
      }
    }
    return name;
  };
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

LinkedList::LinkedList(){}
LinkedList::~LinkedList(){
  Node* cur = head;
  while (cur != nullptr) {
    Node* temp = cur;
    cur = cur->next;
    delete temp;
  }
}
void LinkedList::Add(){
  int id = validateID();
  double gpa = validateGPA();
  string name = validateName();
  Node* newNode = new Node(id,gpa,name);
  if (head == nullptr) {
    head = newNode;
  }else {
    Node* cur = head;
    while (cur->next != nullptr){
      cur = cur->next;
    }
    cur->next = newNode;
  }
};
void LinkedList::Delete(){
  int id = validateID();
  if (head == nullptr) {
      cout << "\033[31mLinked List is Empty!\033[0m";
  }else if (head->next != nullptr) {
    Node* cur = head;
    while(cur->next != nullptr){
      if (cur->next->ID == id) {
        break;
      }
      cur = cur->next;
    };
    Node* temp1 = cur->next;
    Node* temp2 = temp1->next;
    delete temp1;
    cur->next = temp2;
  }else {
      Node* temp = head;
      delete temp;
      head = nullptr;
  }
};
void LinkedList::Display(){
  if (head == nullptr) {
    cout << "\033[31mLinked List is Empty!\033[0m";
  }else {
    Node* cur = head;
    while (cur != nullptr) {
      cout << "ID: " << cur->ID << " | GPA: " << cur->GPA << " | NAME: " << cur->NAME << endl;
      cur = cur->next;
    }
  }
};
void LinkedList::Modify(){
  if (head == nullptr) {
    cout << "\033[31mLinked List is Empty!\033[0m";
  }else {
    int id = validateID();
    double gpa = validateGPA();
    string name = validateName();
    Node* cur = head;
    while (cur == nullptr) {
      if (cur->ID == id) {
        cout << "We found matching ID." << endl << "ID: " << cur->ID << " | GPA: " << cur->GPA << " | NAME: " << cur->NAME << endl << endl;
        cur->GPA = gpa;
        cur->NAME= name;
        cout << "ID: " << cur->ID << " | GPA: " << cur->GPA << " | NAME: " << cur->NAME << endl;
        break;
      }
    }
    cur == nullptr ? cout << "ID was not found": cout << endl;
  }
};
void LinkedList::Purge(){
  if (head == nullptr) {
    cout << "\033[31mLinked List is Empty!\033[0m";
  }else {
    Node* cur = head;
    while (cur != nullptr) {
    Node* temp = cur;
    cur = cur->next;
    delete temp;
  }
  }
};
void LinkedList::Search(){
 if (head == nullptr) {
    cout << "\033[31mLinked List is Empty!\033[0m";
  }else {
    int id = validateID();
    Node* cur = head;
    while (cur == nullptr) {
      if (cur->ID == id) {
        cout << "We found matching ID." << endl;
        cout << "ID: " << cur->ID << " | GPA: " << cur->GPA << " | NAME: " << cur->NAME << endl;
        break;
      }
    }
    cur == nullptr ? cout << "ID was not found": cout << endl;
  }
};

int validateChoice() {
  int choice;
    while(true) {
      cin >> choice;
      if (cin.fail() || 0 > choice || choice > 8){
        cout << "\033[31mPlease enter a valid choice 1-8!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }else{
        break;
      }
    };
    return choice;
}

int main() {
  LinkedList* ll = nullptr;
  int choice;
  while (choice != 8) {
    cout << "Enter Command\n";
    cout << "1. Create\n2. Add\n3. Delete\n4. Display\n5. Modify\n6. Purge entire list\n7. Search for a Node\n8. Exit\n";
    choice = validateChoice();
    switch(choice) {
      case 1: //Create
        if (ll != nullptr) {
          cout << "\033[31mLinked list is already created\033[0m" << endl;
        }else {
          ll = new LinkedList();
          cout << "\033[32mLinked List is created.\033[0m" << endl;
        }
        break;
      case 2: //Add
        if (ll == nullptr) {
          cout << "\033[31mCreate Linked list first.\033[0m"<< endl;
        }else {
          ll->Add();
        }
        break;
      case 3: //Delete
        if (ll == nullptr) {
          cout << "\033[31mCreate Linked list first.\033[0m"<< endl;
        }else {
          ll->Delete();
        }
        break;
      case 4: //Display
        if (ll == nullptr) {
          cout << "\033[31mCreate Linked list first.\033[0m"<< endl;
        }else {
          ll->Display();
        }
        break;
      case 5: //Modify
        if (ll == nullptr) {
          cout << "\033[31mCreate Linked list first.\033[0m"<< endl;
        }else {
          ll->Modify();
        }
        break;
      case 6: //Purge entire list
        if (ll == nullptr) {
          cout << "\033[31mCreate Linked list first.\033[0m"<< endl;
        }else {
          ll->Purge();
        }
        break;
      case 7: //Search for a node
        if (ll == nullptr) {
          cout << "\033[31mCreate Linked list first.\033[0m"<< endl;
        }else {
          ll->Search();
        }
        break;
    }

  }
}