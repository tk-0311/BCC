#include <iostream>

using namespace std;

struct Stack {
  int arr[15];
  int top;
  Stack() {
    top = -1;
    for (int i = 0; i < 15; i++) {
      arr[i] = -1;
    }
  }
};

void push(Stack*);
void pop(Stack*);
void top(Stack*);
void print(Stack*);
int validation();
void validation(char&);

int main() {
  char opt;
  while (opt != 'E') {
    opt = 1;
    Stack stack;
    print(&stack);
    while (opt < 'D') {
      cout << "Menu\n A: Push\n B: Pop\n C: Top\n D: Purge\n E: Exit\n" << endl;
      validation(opt);
      switch (opt) {
        case 'A':
          push(&stack);
          break;
        case 'B':
          pop(&stack);
          break;      
        case 'C':
          top(&stack);
          break;
        case 'D':
          cout << "Purge stack" << endl;
          break;
      }
    }
  }
};

void push(Stack* s) {
  if (s->top < 14) {
    cout << "Enter a number between 0 and 99 to push to the stack: ";
    int value = validation();
    s->top += 1;
    s->arr[s->top] = value;
    print(s);
  }else cout << "Error overflow, stack is full" << endl;
};

void pop(Stack* s) {
  if (s->top > -1) {
    cout << s->arr[s->top] << " is popped." << endl;
    s->top -= 1;
    print(s);
  }else cout << "Error underflow, stack is Empty" << endl;
};

void top(Stack* s) {
    if (s->top > -1) {
    cout << "Top of the Stack\n----\n|"  << ((s->arr[s->top] > 9) ? to_string(s->arr[s->top]) : "0" +to_string(s->arr[s->top])) << "|\n----" << endl;
  }else cout << "there is no element in stack" << endl;
};

void print(Stack* s) {
  cout << "Items on the Stack\n----\n";
  for (int i = 0; i <= s->top; i++) {
    cout << "|" << ((s->arr[i] > 9) ? to_string(s->arr[i]) : "0" +to_string(s->arr[i])) << "|\n";
  };
  cout << "----" << endl;
};

int validation() {
  while(1) {
    int val;
    cin >> val;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Wrong input try again\n" << "Enter a number between 0 and 99 to push to the stack: ";
    }else if (val < 100 && val > -1) return val;
    else cout << "Wrong input try again\n" << "Enter a number between 0 and 99 to push to the stack: ";
  }
};

void validation(char& opt) {
  while (1) {
    cin >> opt;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else if (opt < 70 && opt > 64) break;
    else if (opt < 101 && opt > 96) {
      opt = opt - 32;
      break;}
    cout << "Wrong input try again" << endl;
  }
};