#include "AccountQueue.h"

AccountQueue::AccountQueue()
{
	this->Front = NULL;
	this->queue_size = 0;
}

AccountQueue::~AccountQueue()
{

}

AccountQueueNode* AccountQueue::POP()
{
	if (EMPTY() == true) {
		return ;
	}
	AccountQueueNode* current;
	AccountQueueNode* del;
	current = Front;
	del = Front;
	if (current->GetNext() != NULL)
	{
		current = current->GetNext();
		Front = Front->GetNext();
		Front = current;
		del->SetNext(NULL);
		queue_size--;
		return;
	}
	else
	{
		Front = NULL;
		del->SetNext(NULL);
		queue_size--;
		return;
	}
	
}
bool AccountQueue::PUSH(AccountQueueNode* node)
{
	AccountQueueNode* current;
	AccountQueueNode* prev;
	current = Front;
	prev = current;

	if (EMPTY() == true)
	{
		Front = node;
		queue_size++;
		return true;
	}
	else
	{
		current = current->GetNext();
		while (1)
		{
			if (current == NULL) {
				prev->SetNext(node);
				queue_size++;
				return true;
		}
			prev = current;
			current = current->GetNext();

		}
	}
	return false;
}

bool AccountQueue::EMPTY()
{
	if (this->Front == NULL)
		return true;
	else {
		return false;
	}
}

int AccountQueue::SIZE()
{
	return queue_size;
}

void AccountQueue::PRINT()
{

}