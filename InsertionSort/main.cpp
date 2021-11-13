#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort (vector<int> &retVal) 
{
  int lastCheckedIndex, key;

  for (int i=1;i<retVal.size();i++) 
  {
    key = retVal[i];
    lastCheckedIndex = i-1;

    while ( (lastCheckedIndex >= 0) && (retVal[lastCheckedIndex] > key) ) 
    {
      retVal[lastCheckedIndex + 1] = retVal[lastCheckedIndex];
      lastCheckedIndex--;
    }
    retVal[lastCheckedIndex + 1] = key;
  }

  return retVal;
}

int main() 
{
  vector<int> arrayToSorted = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  insertionSort(arrayToSorted);

  for (auto i : arrayToSorted) 
  {
    cout<<i<<" ";
  }

  return 0;
} 