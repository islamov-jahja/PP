#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <mutex>

#include "BankClient.h"
#include "stdafx.h"

class CBank
{
public:
	CBank(int lockTool);
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	vector<CBankClient> GetClients();
	int GetTotalBalance();
	void SetClientBalance(CBankClient client, int value);
	int GetClientBalance(CBankClient client);

private:
	void ToLockSection();
	void ToUnlockSection();
	vector<CBankClient> m_clients;
	map<int, int> m_clientAndBalance;

	int m_totalBalance;
	LockTool m_lock_tool;


	CRITICAL_SECTION m_criticalSection;
	mutex m_mutex;

	void SetTotalBalance(int value);
	void SomeLongOperations();
};