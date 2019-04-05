#include "Bank.h"

CBank::CBank(int lockTool)
{
	m_clients = std::vector<CBankClient>();
	m_totalBalance = 0;
	InitializeCriticalSection(&m_criticalSection);
	if (lockTool = 0)
	{
		m_lock_tool = Mutex;
	}
	else
	{
		m_lock_tool = CriticalSection;
	}
}



CBankClient* CBank::CreateClient()
{
	unsigned clientId = unsigned(m_clients.size());
	CBankClient* client = new CBankClient(this, clientId);
	m_clients.push_back(*client);
	return client;
}


void CBank::UpdateClientBalance(CBankClient &client, int value)
{
	ToLockSection();
	int totalBalance = GetTotalBalance();
	std::cout << "Client " << client.GetId() << " initiates reading total balance. Total = " << totalBalance << "." << std::endl;

	SomeLongOperations();
	SetClientBalance(client, value);
	totalBalance += value;

	std::cout
		<< "Client " << client.GetId() << " updates his balance with " << value
		<< " and initiates setting total balance to " << totalBalance
		<< ". Must be: " << GetTotalBalance() + value << "." << std::endl;

	// Check correctness of transaction through actual total balance
	if (totalBalance != GetTotalBalance() + value) {
		std::cout << "! ERROR !" << std::endl;
	}

	SetTotalBalance(totalBalance);
	ToUnlockSection();
}

vector<CBankClient> CBank::GetClients()
{
	return m_clients;
}


int CBank::GetTotalBalance()
{
	return m_totalBalance;
}

void CBank::SetClientBalance(CBankClient client, int value)
{
	auto clientAndBalance = m_clientAndBalance.find(client.GetId());

	if (clientAndBalance != m_clientAndBalance.end())
	{
		clientAndBalance->second += value;
	}
	else
	{
		m_clientAndBalance.emplace(pair<int, int>(client.GetId(), value));
	}
}

int CBank::GetClientBalance(CBankClient client)
{
	return m_clientAndBalance.at(client.GetId());
}

void CBank::ToLockSection()
{
	if (m_lock_tool == CriticalSection) {
		EnterCriticalSection(&m_criticalSection);
	}
	else if (m_lock_tool == Mutex) {
		m_mutex.lock();
	}
}

void CBank::ToUnlockSection()
{
	if (m_lock_tool == CriticalSection) {
		LeaveCriticalSection(&m_criticalSection);
	}
	else if (m_lock_tool == Mutex) {
		m_mutex.unlock();
	}
}


void CBank::SetTotalBalance(int value)
{
	m_totalBalance = value;
}

void CBank::SomeLongOperations()
{
	Sleep(1000);
}