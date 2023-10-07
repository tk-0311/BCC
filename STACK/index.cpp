#include <iostream>

using namespace std;

struct Stack {
  int arr[15] = {NULL};
  int top = -1;
  Stack() {
    for (int i = 0; i < 15; i++) {
      arr[i] = NULL;
    }
  }
};

void push(Stack&);
int pop(Stack&);
int top(Stack&);
void print(Stack&);
int validation();
void validation(char&);

int main() {
  char opt;
  while (opt != 'E') {
    Stack stack;
    while (opt != 'E' || opt != 'D') {
      validation(opt);
      switch (opt) {
        case 'A':
          push(stack);
          break;
        case 'B':
          pop(stack);
          break;      
        case 'C':
          top(stack);
          break;   
      }
      print(stack);
    }
  }
}

void push(Stack& s) {
  int value = validation()
};

int pop(Stack&) {

};

int top(Stack&) {

};

void print(Stack&) {

};

int validation() {

};

void validation(char& opt) {
  while (1) {
    cin >> opt;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else if (int(opt) < 70 && int(opt) > 64) {
      break;
    }else if (int(opt) < 101 && int(opt) > 96) {
      opt = opt - 32;
      break;
    }
  }
};