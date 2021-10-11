#include "UserListNode.h"

UserListNode::UserListNode()
{
	/*char* Name;
	int Age;
	int AccNum;
	UserListNode* pNext;
	AccountBSTNode* pHead;*/
}

UserListNode::~UserListNode()
{

}

char* UserListNode::GetName()
{
	return Name;
}

int UserListNode::GetAge()
{
	return Age;
}

UserListNode* UserListNode::GetNext()
{
	return this->pNext;
}

void UserListNode::SetName(char* name)
{
	Name = name;		
}

void UserListNode::SetAge(int age)
{
	Age = age;
}

void UserListNode::SetNext(UserListNode* node)
{
	this->pNext = node;
}

AccountBSTNode* UserListNode::InsertAccount(AccountBSTNode* node)
{

}

void UserListNode::Print_Accounts()
{
	

}

void UserListNode::Delete_Account(char* id)
{
AccountBSTNode* deleteNode = this->pHead;
	AccountBSTNode* parentNode = nullptr;
	while (deleteNode){
		parentNode = deleteNode;

		delete deleteNode;
	}
}