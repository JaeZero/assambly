#pragma once
#include "UserHeapNode.h"
#include <fstream>
#include <vector>
using namespace std;

class UserHeap
{
private:
	vector<UserHeapNode*> Heap;
	UserHeapNode* HeapA;
public:
	UserHeap();
	~UserHeap();

	bool Insert(int agegroup);
	void Print();

	UserHeapNode* GetHeap() { return HeapA; }
};