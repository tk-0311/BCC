#include <iostream>
using namespace std;
struct Matrix {
  int row1[2];
  int row2[2];
  string name;
};
void get_matrix(Matrix &);
void get_scalar(int & );
void calc_sum(Matrix, Matrix, Matrix&);
void calc_diff(Matrix, Matrix, Matrix&); 
void scalar_mult(int, Matrix, Matrix&); 
void calc_prod(Matrix, Matrix, Matrix&);
void calc_inv(Matrix, Matrix &r); 
void print_matrix(Matrix&); 
int main() {
  Matrix  m1, m2, result; 
  result.name = "result";
  int scalar;
  int ops = 1;
  while (ops != 9) {
    cout << "\n 1. get_matrix \n 2. get_scaler \n 3. calc_sum \n 4. calc_diff \n 5. scalar_mult \n 6. calc_prod \n 7. calc_inv \n 8. print_matrix \n 9. EXIT program " ;
    cout << "\nSelect operation to conduct 1 - 9 => \n";
    cin >> ops;
    while (ops < 1 || ops > 9) {
      cout << " Out of Bound \n";
      cout << " Select from operations 1 - 9 => \n";
      cin >> ops;
    }
    switch(ops) {
      case 1: // get matrix
        cout << "Get Matrix";
        cout << "Matrix 1: \n";
        get_matrix(m1);
        cout << "\nMatrix 2: \n";
        get_matrix(m2);
        break;
      case 2: // getscaler
        cout << "Get Scalar";
        get_scalar(scalar);
        break;
      case 3: //calc sum
        calc_sum(m1,m2,result);
        print_matrix(result);
        break;
      case 4: //calc diff
        calc_diff(m1,m2,result);
        print_matrix(result);
        break;
      case 5: //scaler mult
        cout << "\n Select the Matrix \n1. " << m1.name << "\n 2. " << m2.name <<"\n";
        scalar_mult(scalar, m1, result);
        print_matrix(result);
        scalar_mult(scalar, m2, result);
        print_matrix(result);
        break;
      case 6: //calc prod
        calc_prod(m1, m2, result);
        print_matrix(result);
        break;
      case 7: // calc inv
        calc_inv(m1, result); 
        print_matrix(result);
        calc_inv(m2, result); 
        print_matrix(result);
        break;
      case 8: // print_matrix
        cout << "Printing Matrix..." << endl;
        print_matrix(m1);
        print_matrix(m2);
        print_matrix(result);
        break;
      case 9:
        cout << "Exiting the program"<< endl;
        return 0;
        break;
    }
  }
}
void get_matrix(Matrix &m) {
  cout << "Input name of Matrix:" ;
  cin >> m.name;
  for (int i = 0; i < 2; i++) {
    cout << "\nInput value for (1, " << i+1 << "): ";
    cin >> m.row1[i];
    cout << "\nInput value for (2, " << i+1 << "): ";
    cin >> m.row2[i];
  }
};
void get_scalar(int & k) {
  cout << "Enter scalar value :" <<endl;
  cin >> k;
};
void calc_sum(Matrix m1, Matrix m2, Matrix &result) {
result.row1[0]  = m1.row1[0] + m2.row1[0] ;
result.row1[1]  = m1.row1[1] + m2.row1[1] ;
result.row2[0]  = m1.row2[0] + m2.row2[0] ;
result.row2[1]  = m1.row2[1] + m2.row2[1] ;
};
void calc_diff(Matrix m1, Matrix m2, Matrix &result) {
result.row1[0]  = m1.row1[0] - m2.row1[0] ;
result.row1[1]  = m1.row1[1] - m2.row1[1] ;
result.row2[0]  = m1.row2[0] - m2.row2[0] ;
result.row2[1]  = m1.row2[1] - m2.row2[1] ;
}; 
void scalar_mult(int k, Matrix m, Matrix &result) {
  for(int i = 0;i <2;i++){
    result.row1[i] = k*m.row1[i];
    result.row2[i] = k*m.row2[i];
  }
}; 
void calc_prod(Matrix m1, Matrix m2, Matrix &result) {
  result.row1[0] = m1.row1[0] * m2.row1[0] + m1.row1[1]*m2.row2[0];
  result.row2[0] = m1.row2[0] * m2.row1[0] + m1.row2[1]*m2.row2[0];
  result.row1[1] = m1.row1[0] * m2.row1[1] + m1.row1[1]*m2.row2[1];
  result.row2[1] = m1.row2[0] * m2.row1[1] + m1.row2[1]*m2.row2[1];
};
void calc_inv(Matrix m, Matrix &r) {
  int d;
  d = 1/((m.row1[0]*m.row2[1])*(m.row1[1]*m.row2[0]));
  r.row1[0]=m.row1[0]*d;
  r.row1[1]=m.row1[1]*d;
  r.row2[0]=m.row2[0]*d;
  r.row2[1]=m.row2[1]*d;
}; 
void print_matrix(Matrix &m) {
  cout << "\n Matrix Name : " << m.name << endl;
  for (int i = 0; i < 2; i++) {
    cout <<  "( " << m.row1[i] <<  " )"; 
  } 
  cout << "\n";
    for (int i = 0; i < 2; i++) {
    cout <<  "( " << m.row2[i] <<  " )"; 
  } 
}; 