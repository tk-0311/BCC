#include <string>

class LinkedList {
  private:
    struct Node {
      int ID;
      double GPA;
      std::string NAME;
      Node* next;
      Node(int id,double gpa, std::string name) {
        ID =id;
        GPA = gpa;
        NAME = name;
        next = nullptr;
      };
    };
    Node* head;
    int validateID();
    double validateGPA();
    std::string validateName();
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