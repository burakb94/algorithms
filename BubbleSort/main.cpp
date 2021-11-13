#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort (vector<int> &retArr) {
  int lastSorted = retArr.size() - 1;
  int tempVal;
  bool isAlreadySorted = true;
  for (int i=0; i<retArr.size(); i++) {
    isAlreadySorted = true;
    for (int j=0; j<lastSorted; j++) {
      if (retArr[j] > retArr[j+1]){
        tempVal = retArr[j];
        retArr[j] = retArr[j+1];
        retArr[j+1] = tempVal;
        isAlreadySorted = false;
      }
    }
    if (isAlreadySorted) {
      return retArr;
    }
    lastSorted--;
  }
  return retArr;
}

int main() {
  vector<int> arrayToSort = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 111, 61, 
    99, 2547, 65646, 88221, 1232, 125056, 4641120, 21, 3, 9, 14, 67, 38, 11111111,
    22232365, -64547545, 0};

  vector<int> alreadySorted = {0, 1, 2, 3, 4, 5};    
  vector<int> nearlySorted = {0, 1, 3, 2, 5, 4};    

  bubbleSort(arrayToSort);
  bubbleSort(alreadySorted);
  bubbleSort(nearlySorted);

  for (auto i : arrayToSort) {
    cout<<i<<" ";
  }
  cout<<endl;

  for (auto i : alreadySorted) {
    cout<<i<<" ";
  }
  cout<<endl;

  for (auto i : nearlySorted) {
    cout<<i<<" ";
  }
  cout<<endl;    

  return 0;
} 