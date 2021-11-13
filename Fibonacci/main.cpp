#include <iostream>
#include <map>

using namespace std;

  int calcForIterative=0, calcForRecursive=0, calcForMemoized=0;

int fibonacciRecursive (int value) 
{
  calcForRecursive++;
  if (value > 1) 
  {
    return fibonacciRecursive(value - 1) + fibonacciRecursive(value - 2);
  }
  else if (value == 1) 
  {
    return value;
  }
  else 
  {
    return 0;
  }
}

int fibonacciIterative (int value) 
{
  calcForIterative++;
  int indexOne = 0;
  int indexTwo = 1;
  int retVal = 0;

  for (int i=0;i<value-1;i++)
  {
    retVal = indexOne + indexTwo;
    indexOne = indexTwo;
    indexTwo = retVal;
  }
  if (value == 1) 
  {
    return 1;
  }
  return retVal;
}

int fibonacciMemoized (int value) 
{
  calcForMemoized++;
  static map<int, int> cache;

  if (cache[value])
  {
    return cache[value];
  }
  else
  {
    if (value > 1) 
    {
      cache[value] = fibonacciMemoized(value - 1) + fibonacciMemoized(value - 2);
      return cache[value];
    }
    else if (value == 1) 
    {
      return value;
    }
    else 
    {
      return 0;
    }
  }
}

int main() 
{
  cout<<"Iterative : "<<fibonacciIterative(20)<<" took "<<calcForIterative<<endl;
  cout<<"Recursive : "<<fibonacciRecursive(20)<<" took "<<calcForRecursive<<endl;
  cout<<"Memoized  : "<<fibonacciMemoized(20)<<" took "<<calcForMemoized<<endl;
  
  return 0;
} 