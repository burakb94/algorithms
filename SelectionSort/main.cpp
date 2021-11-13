#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort (vector<int> &retVal) {
  int sortedIndex = 0;
  int min, swapIndex, tmpVal;
  bool isSwapped;
  for (int i=0;i<retVal.size();i++) {
    isSwapped = false;
    min = retVal[sortedIndex];
    for (int j=sortedIndex+1; j<retVal.size();j++) {
      if (min > retVal[j]) {
        min = retVal[j];
        swapIndex = j;
        isSwapped = true;
      }
    }
    if (isSwapped) {
      tmpVal = retVal[sortedIndex];
      retVal[sortedIndex] = retVal[swapIndex];
      retVal[swapIndex] = tmpVal;
    }
    sortedIndex++;
  }
  return retVal;
}

int main() {
  vector<int> arrayToSorted = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  selectionSort(arrayToSorted);

  for (auto i : arrayToSorted) {
    cout<<i<<" ";
  }

  return 0;
} 