#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"
#include <string>

int main(int argc, char *argv[])
{
	CBank* bank = new CBank();

	if (argc > 1)
	{
		for (int i = 0; i < atoi(argv[1]); i++)
		{
			bank->CreateClient();
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			bank->CreateClient();
		}
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