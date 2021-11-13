#include <iostream>
#include <vector>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(vector<int> &arr, int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	// Create temp arrays
  vector<int> leftArray (subArrayOne);
  vector<int> rightArray (subArrayTwo);

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
  {
		leftArray[i] = arr[left + i];
  }
	for (auto j = 0; j < subArrayTwo; j++)
  {
		rightArray[j] = arr[mid + 1 + j];
  }

	int indexOfSubArrayOne = 0; // Initial index of first sub-array
	int	indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
  {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
    {
			arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else 
    {
			arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) 
  {
		arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) 
  {
		arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector<int> &arr, int begin, int end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

// Function to print an array
void printArray(vector<int> arr)
{
	for (auto i : arr)
  {
		cout << i << " ";
  }
}

int main()
{
	vector<int> arrayToSorted = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

	cout << "Given array is \n";
	printArray(arrayToSorted);

	mergeSort(arrayToSorted, 0, arrayToSorted.size()-1);

	cout << "\nSorted array is \n";
	printArray(arrayToSorted);

	return 0;
}