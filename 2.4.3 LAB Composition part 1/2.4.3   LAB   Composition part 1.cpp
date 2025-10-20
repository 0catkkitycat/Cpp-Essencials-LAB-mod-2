#include <iostream>
#include <string>
using namespace std;

class IpAddress
{
private:
	string ip;
public:
	IpAddress(string ip);
	string GetIp();
};

IpAddress::IpAddress(string ip)
{
	this->ip = ip;
}

string IpAddress::GetIp()
{
	return ip;
}

class Network
{
private:
	IpAddress* ipAdresses[10];
	int ipCount;
	int capacity;
public:
	Network();
	void AddIpAddress(IpAddress* ip);
	void PrintAll();
};

Network::Network()
{
	ipCount = 0;
	capacity = 10;
	for (int i = 0; i < 10; i++)
	{
		ipAdresses[i] = nullptr;
	}
}

void Network::AddIpAddress(IpAddress* ip)
{
	if (ipCount < capacity)
	{
		ipAdresses[ipCount] = ip;
		ipCount++;
	}
	else
	{
		cout << "No se pueden agregar más direcciones IP. Capacidad máxima alcanzada." << endl;
	}
}

void Network::PrintAll()
{
	for (int i = 0; i < ipCount; i++)
	{
		cout << ipAdresses[i]->GetIp() << endl;
	}
}

int main()
{
	Network network1;
	Network network2;

	string input;
	IpAddress* ip1 = new IpAddress("");
	IpAddress* ip2 = new IpAddress("");
	IpAddress* ip3 = new IpAddress("");
	IpAddress* ip4 = new IpAddress("");
	IpAddress* ip5 = new IpAddress("");

	cin >> input;
	ip1 = new IpAddress(input);

	cin >> input;
	ip2 = new IpAddress(input);

	cin >> input;
	ip3 = new IpAddress(input);

	cin >> input;
	ip4 = new IpAddress(input);

	cin >> input;
	ip5 = new IpAddress(input);

	network1.AddIpAddress(ip1);
	network1.AddIpAddress(ip2);
	network1.AddIpAddress(ip3);

	network2.AddIpAddress(ip3);
	network2.AddIpAddress(ip4);
	network2.AddIpAddress(ip5);

	cout << "Network 1:" << endl;
	network1.PrintAll();

	cout << "Network 2:" << endl;
	network2.PrintAll();

	return 0;
}