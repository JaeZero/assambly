#include "AccountBSTNode.h"

AccountBSTNode::AccountBSTNode()
{
	pRight = NULL;
	pLeft = NULL;
	pNext = NULL;
}

AccountBSTNode::~AccountBSTNode()
{

}

char* AccountBSTNode::GetName()
{
	return Name;
}

char* AccountBSTNode::GetId()
{
	return Id;
}

AccountBSTNode* AccountBSTNode::GetLeft()
{
	return this->pLeft;
}

AccountBSTNode* AccountBSTNode::GetRight()
{
	return this->pRight;
}

AccountBSTNode* AccountBSTNode::GetNext()
{
	return this->pNext;
}

void AccountBSTNode::SetName(char* name)
{
	Name = name;
}

void AccountBSTNode::SetId(char* disease)
{
	Id = disease;
}

void AccountBSTNode::SetLeft(AccountBSTNode* node)
{
	this -> pLeft = node;
}

void AccountBSTNode::SetRight(AccountBSTNode* node)
{
	this ->pRight = node;
}
void AccountBSTNode::SetNext(AccountBSTNode* node)
{
	this->pNext=node;
}