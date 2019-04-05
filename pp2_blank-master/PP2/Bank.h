#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "BankClient.h"
#include "stdafx.h"

class CBank
{
public:
	CBank();
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	vector<CBankClient> GetClients();
	int GetTotalBalance();
	void SetClientBalance(CBankClient client, int value);
	int GetClientBalance(CBankClient client);

private:
	vector<CBankClient> m_clients;
	map<int, int> m_clientAndBalance;

	int m_totalBalance;

	void SetTotalBalance(int value);
	void SomeLongOperations();
};