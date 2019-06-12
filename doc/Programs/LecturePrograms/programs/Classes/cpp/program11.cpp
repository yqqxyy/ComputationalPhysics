// This program uses its own function for allocating and freeing memory for matrices
// It can be seen as an intermediate step towards the construction of a more general 
// matrix vector class

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "time.h"

using namespace std; // note use of namespace
int main (int argc, char* argv[])
{
  // read in dimension of square matrix
  int n = atoi(argv[1]);
  double s = 1.0/sqrt( (double) n);
  // Start timing
  clock_t start, finish;
  start = clock();
  // Allocate space for the three matrices
  vector <vector<double> > A(n, vector<double>(n));
  vector <vector<double> > B(n, vector<double>(n));
  vector <vector<double> > C(n, vector<double>(n));
  
  for(auto& row : A) fill(row.begin(),row.end(),0.0);
  for(auto& row : B) fill(row.begin(),row.end(),0.0);
  for(auto& row : C) fill(row.begin(),row.end(),0.0);
  // Set up values for matrix A and B and zero matrix C
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      double angle = 2.0*M_PI*i*j/ (( double ) n);
      A[i][j] = s * ( sin ( angle ) + cos ( angle ) );
      B[j][i] =  A[i][j];
    }
  }
  // Then perform the matrix-matrix multiplication
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      double sum = 0.0;
       for (int k = 0; k < n; k++) {
           sum += B[i][k]*A[k][j];
       }
       C[i][j] = sum;
    }
  }
  // Compute now the Frobenius norm
  double Fsum = 0.0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      Fsum += C[i][j]*C[i][j];
    }
  }
  Fsum = sqrt(Fsum);
  finish = clock();
  double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
  cout << setiosflags(ios::showpoint | ios::uppercase);
  cout << setprecision(10) << setw(20) << "Time used  for matrix-matrix multiplication=" << timeused  << endl;
  cout << "  Frobenius norm  = " << Fsum << endl;
  return 0;
}


//  Allocating space for a double type matrix
double ** CreateMatrix(int m, int n){
  double ** mat;
  mat = new double*[m];
  for(int i=0;i<m;i++){
    mat[i] = new double[n];
    for(int j=0;j<m;j++)
      mat[i][j] = 0.0;
  }
  return mat;
}


 
















