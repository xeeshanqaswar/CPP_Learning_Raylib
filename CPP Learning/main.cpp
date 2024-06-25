#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#include "LinkedList.h"
#include"DoublyLInkedList.h"
#include"stacks.h"
#include"Tree.h"
#include"HashTable.h"
#include"Graph.h"
#include "main.h"

void Merge(int* arr, int leftIndex, int mid, int rightIndex);

using namespace DoubleLinkedList;
using namespace NLinkedList;
using namespace std::literals;

void LinkedListFunc() {
	LinkedList* linkedList = new LinkedList();
	linkedList->Append(10);
	linkedList->Append(20);
	linkedList->Append(30);
	linkedList->Append(50);
	linkedList->Print();

	linkedList->Reverse();
	linkedList->Print();
}

void DoublyLLFunc() {
	DoublyLL* doubly = new DoublyLL();

	doubly->Append(6);
	doubly->Append(7);
	doubly->Append(8);
	doubly->Append(9);
	doubly->Print();

	doubly->Delete(2);
	doubly->Print();
}

void StackFunc() {
	Stack* stack = new Stack(10);
	stack->Push(9);
	stack->Push(8);
	stack->Push(7);
	stack->Push(6);
	stack->Push(5);
	stack->Push(4);

	stack->Print();
}

void BinarySTFunc() {
	BinarySearchTree* tree = new BinarySearchTree();
	tree->Insert(10);
	tree->Insert(5);
	tree->Insert(12);
	tree->Insert(3);

	//tree->BreathFirstSearch();
	//tree->DFSPreOrder();
	//tree->DFSPostOrder();
	//tree->DFSInOrder();
}

void HashTableFunc() {
	HashTable* hashTable = new HashTable();
	hashTable->Set("Zeeshan", 28);
	hashTable->Set("Naeem", 30);
	std::vector<std::string> keyList = hashTable->Keys();
	std::for_each(keyList.begin(), keyList.end(), [](std::string x) {std::cout << x << std::endl; });

	hashTable->PrintTable();
}

void GraphFunc() {
	Graph* g = new Graph();
	g->AddVertex("V");
	g->AddVertex("A");

	g->AddEdge("V", "A");

	g->PrintGraph();

	g->RemoveVertex("A");
	g->PrintGraph();
}

int Factorial(int n) {

	if (n <=1)
	{
		return 1;
	}

	return n* Factorial(n-1);

}

std::vector<int> BubbleSort(std::vector<int> v) {

	std::vector<int> result{ v };

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result.size(); j++)
		{
			if (result[j] > result[i])
			{
				int temp = result[j];
				result[j] = result[i];
				result[i] = temp;
			}
		}
	}

	return result;
}

std::vector<int> SelectionSort(std::vector<int> unsorted) {

	std::vector<int> temp = unsorted;
	for (int i = 0; i < temp.size(); i++)
	{
		int minIndex = i;
		for (int j = i+1; j < temp.size(); j++) {
			if (temp[j] < temp[minIndex])
			{
				minIndex = j;
			}
		}

		int auxVar = temp[i];
		temp[i] = temp[minIndex];
		temp[minIndex] = auxVar;
	}

	return temp;
}

std::vector<int> InsertionSort(std::vector<int> unsorted) {

	std::vector<int> result{ unsorted };

	for (int i = 0; i < result.size()-1; i++)
	{
		for (int j = i+1; j >0; j--)
		{
			if (result[j] < result[j-1])
			{
				int temp{ result[j] };
				result[j] = result[j - 1];
				result[j - 1] = temp;
			}
		}
	}

	return result;
}

void MergeSort(int unsorted[], int leftIndex, int rightIndex) {

	if (leftIndex >= rightIndex) return;

	int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
	MergeSort(unsorted, leftIndex, midIndex);
	MergeSort(unsorted, midIndex + 1, rightIndex);

	Merge(unsorted, leftIndex, midIndex, rightIndex);
}

void Merge(int arr[], int leftIndex, int mid, int rightIndex) {

	std::vector<int> leftArray;
	std::vector<int> rightArray;

	for (int i = leftIndex; i <= mid; i++)
		leftArray.push_back(arr[i]);

	for (int i = mid + 1; i <= rightIndex; i++)
		rightArray.push_back(arr[i]);

	int tLIndex = 0; int tRIndex = 0; int tSIndex = 0;
	while (tLIndex < leftArray.size() && tRIndex < rightArray.size()) {
			
		if (leftArray[tLIndex] < rightArray[tRIndex])
		{
			arr[tSIndex] = leftArray[tLIndex];
			tLIndex++;
		}
		else {

			arr[tSIndex] = rightArray[tRIndex];
			tRIndex++;
		}

		tSIndex++;
	}

	while (tLIndex < leftArray.size()) {
		arr[tSIndex] = leftArray[tLIndex];
		tLIndex++;
		tSIndex++;
	}

	while (tRIndex < rightArray.size()){
		arr[tSIndex] = rightArray[tRIndex];
		tRIndex++;
		tSIndex++;
	}
}

void Swap(int arr[], int firstIndex, int secondIndex) {
	int temp = arr[firstIndex];
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
}

int Pivot(int arr[], int pivotIndex, int endIndex) {

	int swapIndex{ pivotIndex };

	for (int i = pivotIndex + 1; i <= endIndex; i++)
	{
		if (arr[i] < arr[pivotIndex]) {
			swapIndex++;
			Swap(arr, swapIndex, i);
		}
	}

	Swap(arr, pivotIndex, swapIndex);
	return swapIndex;
}

void QuickSort(int arr[], int leftIndex, int rightIndex) {

	if (leftIndex >= rightIndex)
	{
		return;
	}

	int pivotIndex = Pivot(arr, leftIndex, rightIndex);
	QuickSort(arr, leftIndex, pivotIndex-1);
	QuickSort(arr, pivotIndex+1, rightIndex);
}

int main() {

	//LinkedListFunc();
	//DoublyLLFunc();
	//StackFunc();
	BinarySTFunc();
	//HashTableFunc();
	//GraphFunc();

	//std::cout << "Factorial of N " << Factorial(5) << std::endl;
	/*std::vector<int> unsorted{ 1, 3, 7, 8,2, 4,5,6 };
	std::vector<int> sorted;*/
	//sorted = BubbleSort(unsorted);
	//sorted = SelectionSort(unsorted);
	//sorted = InsertionSort(unsorted);
	
	/*int sample[] { 1, 3, 7, 8, 2, 4, 5, 6 };
	int size = sizeof(sample) / sizeof(int);*/
	
	//MergeSort(sample, 0 , size-1);
	/*QuickSort(sample, 0, size-1);

	for (int i = 0; i < size; i++)
		std::cout << sample[i] << std::endl;*/

	//std::for_each(sorted.begin(), sorted.end(), [](int x) {std::cout << x << std::endl; });


	return 0;
}