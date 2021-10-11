#include "AccountBST.h"


AccountBST::AccountBST()
{
    Root = NULL;

}

AccountBST::~AccountBST()
{

}

AccountBSTNode* AccountBST::GetRoot()
{
    return Root;
}

bool AccountBST::Insert(AccountBSTNode* node)
{
    AccountBSTNode* ID = Root; AccountBSTNode* tID = NULL;
    if (Root == NULL)
    {
        Root = node;
        return true;
    }
    else
    {
        while (ID)
        {
            tID = ID;
            if (strcmp(node->GetId(), tID->GetId()) < 0)
                ID = ID->GetLeft();
            else if (strcmp(node->GetId(), tID->GetId()) > 0)
                ID = ID->GetRight();
        }
        if (strcmp(node->GetId(), tID->GetId()) < 0)
            tID->SetLeft(node);
        else if (strcmp(node->GetId(), tID->GetId()) > 0)
            tID->SetRight(node);
    }
}

bool AccountBST::Search_Id(char* id)
{
   
}




bool AccountBST::Delete(char* id)
{
    AccountBSTNode* parent = NULL;
    AccountBSTNode* temp = Root;

    if (Search_Id(id))   // if search Account's id in BST
    {
        while (temp && (strcmp(temp->GetId(), id) != 0))   // while not find same Acocunt's node
        {
            parent = temp;
            if (strcmp(temp->GetId(), id) > 0)   // if larger Acocunt's name
                temp = temp->GetLeft();   // move temp to left
            else if (strcmp(temp->GetId(), id) < 0)   // if smaller Acocunt's name
                temp = temp->GetRight();   // move temp to right
            else if (strcmp(temp->GetId(), id) == 0)
                break;   // if find same Acocunt's name, break out loop
        }
        if ((temp->GetLeft() == NULL) && (temp->GetRight() == NULL))   // leaf node
        {
            if (parent == NULL)
                Root = NULL;   // if BST only has Root node, change Root NULL
            else if (parent->GetLeft() == temp)
                parent->SetLeftNULL();   // if it is parent's left node, set parent's left node NULL
            else
                parent->SetRightNULL();   // if it is Acocunt's right node, set patent's right node NULL

            delete temp;   // Delete temp
        }
        else if (temp->GetLeft() == NULL)   // only have right child
        {
            if (parent == NULL)
                Root = temp->GetRight();   // if delete node is Root, set Root to delete node's right node
            else if (parent->GetLeft() == temp)
                parent->SetLeft(temp->GetRight());   // if it is parent's left node, set parent's left node to it's right node
            else
                parent->SetRight(temp->GetLeft());   // if it is parent's right node, set parent's right node to it's left node

            delete temp;   // Delte temp
        }
        else if (temp->GetRight() == NULL)   // only have left child
        {
            if (parent == NULL)
                Root = temp->GetLeft();   // if delete node is Root, set Root to delete node's left node
            else if (parent->GetLeft() == temp)
                parent->SetLeft(temp->GetLeft());   // if it is parent's left node, set parent's left node to it's left node
            else
                parent->SetRight(temp->GetLeft());   // if it is parent's right node, set parent's right node to it's right node

            delete temp;
            AccountBSTNode* parent = NULL;
            AccountBSTNode* temp = Root;

            if (Search_Id(id))   // if search Acocunt's name in BST
            {
                while (temp && (strcmp(temp->GetId(), id) != 0))   // while not find same Acocunt's node
                {
                    parent = temp;
                    if (strcmp(temp->GetId(), id) > 0)   // if larger Acocunt's name
                        temp = temp->GetLeft();   // move temp to left
                    else if (strcmp(temp->GetId(), id) < 0)   // if smaller Acocunt's name
                        temp = temp->GetRight();   // move temp to right
                    else if (strcmp(temp->GetId(), id) == 0)
                        break;   // if find same Acocunt's name, break out loop
                }
                if ((temp->GetLeft() == NULL) && (temp->GetRight() == NULL))   // leaf node
                {
                    if (parent == NULL)
                        Root = NULL;   // if BST only has Root node, change Root NULL
                    else if (parent->GetLeft() == temp)
                        parent->SetLeftNULL();   // if it is parent's left node, set parent's left node NULL
                    else
                        parent->SetRightNULL();   // if it is Acocunt's right node, set patent's right node NULL

                    delete temp;   // Delete temp
                }
                else if (temp->GetLeft() == NULL)   // only have right child
                {
                    if (parent == NULL)
                        Root = temp->GetRight();   // if delete node is Root, set Root to delete node's right node
                    else if (parent->GetLeft() == temp)
                        parent->SetLeft(temp->GetRight());   // if it is parent's left node, set parent's left node to it's right node
                    else
                        parent->SetRight(temp->GetLeft());   // if it is parent's right node, set parent's right node to it's left node

                    delete temp;   // Delte temp
                }
                else if (temp->GetRight() == NULL)   // only have left child
                {
                    if (parent == NULL)
                        Root = temp->GetLeft();   // if delete node is Root, set Root to delete node's left node
                    else if (parent->GetLeft() == temp)
                        parent->SetLeft(temp->GetLeft());   // if it is parent's left node, set parent's left node to it's left node
                    else
                        parent->SetRight(temp->GetLeft());   // if it is parent's right node, set parent's right node to it's right node

                    delete temp;
                }

            }
        }
    }
}

void AccountBST::Print_PRE(AccountBSTNode* node, queue <AccountBSTNode*>* ds_Account_bst)
{
    if (node != NULL)
    {
        ds_Account_bst->push(node);   // push current node to queue
        Print_PRE(node->GetLeft(), ds_Account_bst);   // left node
        Print_PRE(node->GetRight(), ds_Account_bst);   // right node
    }
}

void AccountBST::Print_IN(AccountBSTNode* node, queue <AccountBSTNode*>* ds_Account_bst)
{
    if (node != NULL)
    {
        Print_PRE(node->GetLeft(), ds_Account_bst);   // left node
        ds_Account_bst->push(node);   // push current node to queue
        Print_PRE(node->GetRight(), ds_Account_bst);   // right node
    }
}

void AccountBST::Print_POST(AccountBSTNode* node, queue <AccountBSTNode*>* ds_Account_bst)
{
    if (node != NULL)
    {
        Print_PRE(node->GetLeft(), ds_Account_bst);   // left node
        Print_PRE(node->GetRight(), ds_Account_bst);   // right node
        ds_Account_bst->push(node);   // push current node to queue

    }
}

void AccountBST::Print_LEVEL(AccountBSTNode* node, queue<AccountBSTNode*>* ds_Acocunt_bst)
{
    queue <AccountBSTNode*>* ABTN_queue;
    ABTN_queue = new queue<AccountBSTNode*>;
    if (Root != NULL)
    {
        ABTN_queue->push(Root);   // push Root Acocunt information first
        {
            while (!ABTN_queue->empty())
            {
                ds_Acocunt_bst->push(ABTN_queue->front());   // push front Acocunt's information to queue

                if (ABTN_queue->front()->GetLeft() != NULL)
                    ABTN_queue->push(ABTN_queue->front()->GetLeft());   // push left node to queue
                if (ABTN_queue->front()->GetRight() != NULL)
                    ABTN_queue->push(ABTN_queue->front()->GetRight());   // push right note to queue

                ABTN_queue->pop();   // pop front node 
            }
        }
    }
}