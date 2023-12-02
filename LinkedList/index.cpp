#include <iostream>
#include <LL.h>
using namespace std;

int validateChoice();

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
  delete ll;
}

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