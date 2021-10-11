#include "Manager.h"

Manager::Manager()
{
    ds_bst = new AccountBST;   // make Location BST
   
    ds_Account_bst = NULL;   // initialization ds_Account_bst, NULL
    ds_heap = new UserHeap;   // make Max Heap
  

}

Manager::~Manager()
{
    delete ds_bst;
    delete ds_queue;

    delete ds_heap;
}

void Manager::run(const char* command)
{
    fin.open(command);   // open and read command.txt
    flog.open("log.txt", ios::app);
    if (!fin)   // if not open
    {
        flog << "File Open Error" << endl;   // error message
        return;   // return and finish function
    }

    for (int k = 0; k < 10; k++)
        Account_cnt[k] = NULL;

    char cmd[32];   // read command.txt by line and store to cmd array

    while (!fin.eof())   // while command.txt not finish
    {
        fin.getline(cmd, 32);   // read by line
        char* temp = strtok(cmd, " ");   // cut word by " ", and store word to temp
        if (strcmp(temp, "QLOAD") == 0)   // if command is "LOAD"
        {
            if (strtok(NULL, " ") == NULL)   // no more parameter, call function 'LOAD'
            {
                if (QLOAD())
                {
                    PrintSuccess(temp);   // if 'LOAD' success, call function 'PrintSuccess'
                }
                else
                    PrintErrorCode(100);   // if 'Lead' fail, call function 'PrintErrorCode', Error code is 100
            }
            else
                PrintErrorCode(100);   // more paraneter, call function 'PrintErrorCode', Error code is 100 
        }
        else if (strcmp(temp, "ADD") == 0)   // if command is "ADD"
        {
            i = 0;
            int j = 0;
            while (1)
            {
                temp = strtok(NULL, " ");
                if (temp == NULL)
                    break;
                Account_cnt[i] = temp;   // store Acocunt's information to Acocunt_info array
                i++;
            }

            if (ADD())
                PrintSuccess(temp);   // if 'ADD' success, call function 'PrintSuccess'
            else
                PrintErrorCode(200);   // if 'ADD' fail, call function 'PrintErroeCode', Error code is 200
        }
        else if (strcmp(temp, "QPOP") == 0)   // if command is "QPOP"
        {
            char* temp3;
            temp3 = (strtok(NULL, " "));
            char* temp4;
            temp4 = strtok(NULL, " ");
            if (temp3 == NULL || temp4 != NULL)
                PrintErrorCode(300);   // call function 'PrintErrorCode' if no or more parameter, Errir code is 300
            else
            {
                size = atof(temp3);   // change 'char' paramter to 'int' parameter (size)
                if (QPOP())
                    PrintSuccess(temp);   // if 'QPOP' success, call function 'PrintSuccess'
                else
                    PrintErrorCode(300);   // if 'QPOP' fail, call function 'PrintErrorCode', Error code is 300
            }
        }
        else if (strcmp(temp, "SEARCH") == 0)   // if command is "SEARCH"
        {
            AID = strtok(NULL, " ");
            Account_cnt[0] = strtok(NULL, " ");
            if (AID == NULL || Account_cnt[0] != NULL)
                PrintErrorCode(400);   // if no or more parameter, call function 'PrintErrorCode', Error code is 400
            else
            {
                if (SEARCH())
                    PrintSuccess(temp);    // if 'SEARCH' Success, call function 'PrintSuccess'
                else
                    PrintErrorCode(400);   // if "SEARCH; fail, call function 'PrintErrorCode', Error code is 400
            }
        }
        else if (strcmp(temp, "PRINT") == 0)   // if command is "PRINT"
        {
            Account_cnt[0] = strtok(NULL, " ");   // store first parameter
            Account_cnt[1] = strtok(NULL, " ");   // store second parameter
            Account_cnt[2] = strtok(NULL, " ");   // check if there is more parameter
            if (PRINT())
                PrintSuccess(temp);   // if 'PRINT' success, call function 'PrintSuccess'
            else
                PrintErrorCode(500);   // if 'PRINt' fail, call function 'PrintErrorCode', Error code is 500
        }
        else if (strcmp(temp, "DELETE") == 0)   // if command is "BPOP"
        {
            AID = (strtok(NULL, " "));   // store parameter
            Account_cnt[0] = strtok(NULL, " ");   // check if there is more parameter
            if (AID == NULL)
                PrintErrorCode(600);   // if no parameter, call function 'PrintErrorCode', Error code is 600
            else
            {
                if (DELETE())
                    PrintSuccess(temp);   // if 'BPOP' success, call function 'PrintSuccess'
                else
                    PrintErrorCode(600);   // if 'BPOP' fail, call function 'PrintErrorCode', Error code is 600
            }
        }
        else if (strcmp(temp, "EXIT") == 0)   // if command is "EXIT"
        {
            if (strtok(NULL, " ") == NULL)
            {
                PrintSuccess(temp);   // if no patameter, call fuction 'PrintSuccess' and break out loop
                break;
            }
            else
                flog << "EXIT Mesage Error" << endl;   // if more parameter, print error message
        }
        else
            flog << "입력하신 기능이 존재하지 않습니다." << endl;   // if other command, print error message

    }
    fin.close();   // close "command.txt"
    flog.close();   // close "log.txt"
}

bool Manager::QLOAD()
{
    ifstream fdata;
    fdata.open("data.txt");
    char Account_data[50];
    char* str;
    AccountQueueNode* newAccount;
    

    if (!(ds_queue->EMPTY()))  // if data alesay exist
    {
        return false;   // return false
    }
    if (!fdata.is_open())   // if file not open
    {
        return false;   // return 
    }
    else if (fdata.is_open())   // file open!
    {
        while (!fdata.eof())   // while data.txt not finished
        {
            fdata.getline(Account_data, 50);   // read txt file by line
            int count = 0;
            for (int i = 0; i < strlen(Account_data); i++)
            {
                if (Account_data[i] == ' ')
                    count++;   // count parameter's number
            }
            if (count == 3)   // have full parameter
            {
                newAccount = new AccountQueueNode;   // make new class to store new Acocunt's information
                Custormer_Name = strtok(Account_data, " ");
                int i = 0;
                /*Name*/
                str = Custormer_Name;
                newAccount->SetName(Custormer_Name);

                /*Age*/
                Custormer_Name = strtok(NULL, " ");
                newAccount->SetAge(atof(Custormer_Name));

                /*ID*/
                Custormer_Name = strtok(NULL, " ");
                str = Custormer_Name;
                newAccount->SetId(str);

                ds_queue->PUSH(newAccount);  // push new Acocunt's class to Acocunt queue              
            }
        }
        return true;   // if function finished rightly, return true
    }
}

bool Manager::ADD()
{
    if (i == 3)
    {
        AccountQueueNode* AccountQueue;
    AccountQueue = new AccountQueueNode;   // make new class to store new paient's information
    char* str(Account_cnt[0]);
    AccountQueue->SetId(str);  // name
    AccountQueue->SetName(Account_cnt[1]);   // Name
    AccountQueue->SetAge(atof(Account_cnt[2]));
    ds_queue->PUSH(AccountQueue);  
    return true;   // if function finished rightly, return true
}
        return false;   // if insufficient parameter, return false
}

bool Manager::QPOP()
{
    AccountBSTNode* AccountBsts;

    if (size > ds_queue_a->size() || ds_queue_a->empty())
        return false;   // if queue is empty or parameter is larger than queue size, return false
    else
    {
        for (int i = 0; i < size; i++)
        {
            ds_bst->Insert(ds_queue_a->front());   // Insert queue's front information to Location BST
            ds_queue_a->pop();   // after insert, pop queue's front information
        }
        return true;   // if function finished rightly, return true
    }
}


bool Manager::SEARCH()
{
   
}

bool Manager::PRINT()
{

    if (strcmp(Account_cnt[0], "B") == 0)   // if first parameter is "B", print BST
    {
        if (Account_cnt[1] == NULL)
            return false;   // if no second parameter, return false
        else if (strcmp(Account_cnt[1], "PRE") == 0)   // second parameter "PRE"
        {
            if (Account_cnt[2] != NULL)
                return false;   // if more parameter, return false
            ds_Account_bst = new queue<AccountBSTNode*>;
            ds_bst->Print_PRE(ds_bst->GetRoot(), ds_Account_bst);   // call Location BST function 'Print_PRE' 
            if (ds_Account_bst->empty())
                return false;   // if no data, return false
            else
                return true;   // if data exist, return true
        }
        else if (strcmp(Account_cnt[1], "IN") == 0)
        {
            if (Account_cnt[2] != NULL)
                return false;   // if more parameter, return false
            ds_Account_bst = new queue<AccountBSTNode*>;

            ds_bst->Print_IN(ds_bst->GetRoot(), ds_Account_bst);   // call Location BST function 'Print_IN'   
            if (ds_Account_bst->empty())
                return false;   // if no data, return false
            else
                return true;   // if data exist, return true
        }
        else if (strcmp(Account_cnt[1], "POST") == 0)
        {
            if (Account_cnt[2] != NULL)
                return false;   // if more parameter, return false
            ds_Account_bst = new queue<AccountBSTNode*>;
            ds_bst->Print_POST(ds_bst->GetRoot(), ds_Account_bst);   // call Location BST function 'Print_POST'
            if (ds_Account_bst->empty())
                return false;   // if no data, return false
            else
                return true;   // if data exist, return true
        }
        else if (strcmp(Account_cnt[1], "LEVEL") == 0)
        {
            if (Account_cnt[2] != NULL)
                return false;   // if more parameter, return false
            ds_Account_bst = new queue<AccountBSTNode*>;
            ds_bst->Print_LEVEL(ds_bst->GetRoot(), ds_Account_bst);   // call Location BST function 'Print_LEVEL'
            if (ds_Account_bst->empty())
                return false;   // if cno data, return false
            else
                return true;   // if data exist, return true
        }
    }
    else if (strcmp(Account_cnt[0], "H") == 0)   // if first parameter is "B", print Heap
    {
     
    }
    else
        return false;   // if function finished wrong, return false

}

bool Manager::DELETE()
{

}

bool Manager::HLOAD()
{

}

bool Manager::EXIT()
{

}

void Manager::PrintErrorCode(int num)
{
    flog << "========== ERROR ==========" << endl;
    flog << num << endl;
    flog << "===========================" << endl << endl;
}

void Manager::PrintSuccess(char* act)
{
    flog << "========== " << act << " ==========" << endl;
    flog << "Success" << endl;
    flog << "============================" << endl << endl;
}