#include <iostream>

using namespace std;

int factorialRecursive (int value) {
  if (value > 1){
    return value * factorialRecursive(value - 1);
  }
  else {
    return 1;
  }
}

int factorialIterative (int value) {
  int retVal=1;
  for (int i=value; i>0; i--) {
    retVal = retVal * i;
  }
  return retVal;
}

int main() {

  cout<<"Recursive : "<<factorialRecursive(5)<<endl;
  cout<<"Iterative : "<<factorialIterative(5)<<endl;
  
  return 0;
} 