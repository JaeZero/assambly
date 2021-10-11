#pragma once
#include "AccountBSTNode.h"
#include "AccountQueueNode.h"
#include <fstream>
#include <queue>

using namespace std;

class AccountBST
{
private:
	AccountBSTNode* Root;
	int size;
	int QPOPCount;
	char* Id;

public:
	AccountBST();
	~AccountBST();
	AccountBSTNode* GetRoot();
	bool Insert(AccountBSTNode* node);
	bool Search_Id(char* id);
	bool Delete(char* id);
	void Print_PRE(AccountBSTNode* node, queue <AccountBSTNode*>* ds_Account_bst);
	void Print_IN(AccountBSTNode* node, queue <AccountBSTNode*>* ds_Account_bst);
	void Print_POST(AccountBSTNode* node, queue <AccountBSTNode*>* ds_Account_bst);
	void Print_LEVEL(AccountBSTNode* node, queue<AccountBSTNode*>* ds_patient_bst);
	void SetFind(char* ID)
	{
		ID = Id;
	}
	string GetfindId() { return Id; }   

};