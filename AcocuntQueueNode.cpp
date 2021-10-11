#include "AccountQueueNode.h"

AccountQueueNode::AccountQueueNode()
{
	User_Name = NULL;
	User_age = 0;
	User_Id = NULL;
}

AccountQueueNode::~AccountQueueNode()
{

}

char* AccountQueueNode::GetName()
{
	return User_Name;
}

int AccountQueueNode::GetAge()
{
	return User_age;
}

char* AccountQueueNode::GetId()
{
	return User_Id;
}
AccountQueueNode* AccountQueueNode::GetNext()
{
	return this->pNext;
}

void AccountQueueNode::SetName(char* name)
{
	User_Name = name;
}

void AccountQueueNode::SetAge(int age)
{
	User_age = age;
}

void AccountQueueNode::SetId(char* id)
{
	User_Id = id;
}

void AccountQueueNode::SetNext(AccountQueueNode* node)
{
	this->pNext = node;
}