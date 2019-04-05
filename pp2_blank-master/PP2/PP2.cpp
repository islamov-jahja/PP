#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"
#include <string>

void ShowHelp()
{
	cout << "To launch the application, you need to pass 2 arguments: " << endl;
	cout << "	1) count of the Bank Client object" << endl;
	cout << "	2)primitive type: " << endl;
	cout << "		0 - mutex" << endl;
	cout << "		1 - critical section" << endl;
}

int main(int argc, char *argv[])
{

	if (argc == 2)
	{
		string command = argv[1];
		if (command == "/?")
		{
			ShowHelp();
			return 1;
		}
	}

	if (argc != 3)
	{
		return 1;
	}

	int lockTool = atoi(argv[2]);

	if (lockTool != 0 && lockTool != 1)
	{
		return 1;
	}

	CBank* bank = new CBank(lockTool);

	for (int i = 0; i < atoi(argv[1]); i++)
	{
			bank->CreateClient();
	}


	// TODO: WaitForMultipleObjects
	string command = "";
	while (true)
	{
		cin >> command;
		if (command == "exit" || command == "quit")
		{
			break;
		}
	}

	int totalBalanceOfClients = 0;
	int clientBalance = 0;

	for (CBankClient client : bank->GetClients())
	{
		clientBalance = bank->GetClientBalance(client);
		cout << "Client: " << client.GetId() << " balance: " << clientBalance << endl;
		totalBalanceOfClients += clientBalance;
	}

	cout << "Balance of all clients: " << totalBalanceOfClients << endl;
	cout << "Bank balance: " << bank->GetTotalBalance() << endl;
    return 0;
}