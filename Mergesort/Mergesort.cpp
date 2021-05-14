/*
Name: Andrew Kim
Date: May 6, 2021
Program: Mergesort Lab

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <iostream>

using namespace std;

void mergeSort(int[], int, int);


int main()
{
	int nums[] = { 3, 2, 4, 6, 5, 1, 4, 2 }, // Numbers to be sorted
		size = (sizeof(nums) / sizeof(nums[0])); // Determine size of array

	mergeSort(nums, 0, size - 1);

	// Print sorted array
	for (int i = 0; i < 8; i++)
		cout << nums[i] << ' ';
}


// Sort given data collection using a mergesort algorithm
void mergeSort(int nums[], int first, int last)
{
	int split = first + (last - first) / 2, // Find split
		firstSize = split - first + 1, secondSize = last - split,
		firstIndex = 0, secondIndex = 0, numsIndex = first;
	
	// Create split arrays
	int* firstHalf = new int[firstSize], * secondHalf = new int[secondSize];

	if (first < last) // Continue if one or more elements remain
	{
		// Continue splitting into halves
		mergeSort(nums, first, split);
		mergeSort(nums, split + 1, last);

		// Assign elements to proper halved arrays
		for (int i = 0; i < firstSize; i++)
			firstHalf[i] = nums[first + i];
		for (int i = 0; i < secondSize; i++)
			secondHalf[i] = nums[split + 1 + i];

		// Merge arrays by comparing first element in each array
		// Continue incrementing until one side becomes empty
		while (firstIndex < firstSize && secondIndex < secondSize)
		{
			if (firstHalf[firstIndex] <= secondHalf[secondIndex])
			{
				nums[numsIndex] = firstHalf[firstIndex];
				firstIndex++;
			}
			else
			{
				nums[numsIndex] = secondHalf[secondIndex];
				secondIndex++;
			}
			numsIndex++;
		}

		// Assign the rest of the elements in the first half
		while (firstIndex < firstSize)
		{
			nums[numsIndex] = firstHalf[firstIndex];
			firstIndex++;
			numsIndex++;
		}

		// Assign the rest of the elements in the second half
		while (secondIndex < secondSize)
		{
			nums[numsIndex] = secondHalf[secondIndex];
			secondIndex++;
			numsIndex++;
		}

	}

	// Deallocate memory
	delete[] firstHalf;
	delete[] secondHalf;
}
