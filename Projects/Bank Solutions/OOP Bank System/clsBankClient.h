#pragma once

#include<iostream>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"

using namespace std;

static string ClientsFile = "Clients.txt";



class clsBankClient: public clsPerson
{
private:
	enum enMode{EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;


	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#") {
	
		vector<string>vClientData = clsString::Split(Line, Separator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#") {

		string strClientRecord = Client._AccountNumber;
		strClientRecord += Separator + Client.FirstName;
		strClientRecord += Separator + Client.LastName;
		strClientRecord += Separator + Client.Email;
		strClientRecord += Separator + Client.Phone;
		strClientRecord += Separator + Client.PinCode;
		strClientRecord += to_string(Client.AccountBalance);

		return strClientRecord;
	}

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile() {

		vector<clsBankClient> vClient;

		fstream MyFile;
		MyFile.open(ClientsFile, ios::in);

		if (MyFile.is_open()) {
		
			string Line;
			while (getline(MyFile, Line)) {
			
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClient.push_back(Client);
			}
			MyFile.close();
		}
		return vClient;
	}
	static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out);//overwrite

		string DataLine;
		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void _AddDataLineToFile(string stDataLine)

	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}
	void _Update() {

		vector<clsBankClient> _vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == _AccountNumber) {
			
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone){

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	enum enSaveResults { svFaild = 0, svSucceeded = 1 };


	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;



	bool IsEmpty() {

		return (_Mode == enMode::EmptyMode);
	}

	void print() {

		cout << "\nInfo:";
		cout << "\n-------------------------";

		cout << "\nAcc. Number    : " << _AccountNumber;
		cout << "\nFirstName      : " << FirstName;
		cout << "\nLastName       : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nPassword       : " << _PinCode;
		cout << "\nBalance        : " << _AccountBalance;

		cout << "\n-------------------------";
	}

	//The Extensions
	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;
		MyFile.open(ClientsFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) {
			
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber);
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode) {

		fstream MyFile;
		MyFile.open(ClientsFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) {

				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber && Client.PinCode == PinCode);
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}


	enSaveResults Save() {

		switch (_Mode) {

		case enMode::EmptyMode:
			return enSaveResults::svFaild;
			
		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
		}
	}

	static bool IsClientExist(string AccountNumber) {

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}



};

#pragma once

#include<iostream>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"

using namespace std;

static string ClientsFile = "Clients.txt";



class clsBankClient: public clsPerson
{
private:
	enum enMode{EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;


	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#") {
	
		vector<string>vClientData = clsString::Split(Line, Separator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#") {

		string strClientRecord = Client._AccountNumber;
		strClientRecord += Separator + Client.FirstName;
		strClientRecord += Separator + Client.LastName;
		strClientRecord += Separator + Client.Email;
		strClientRecord += Separator + Client.Phone;
		strClientRecord += Separator + Client.PinCode;
		strClientRecord += to_string(Client.AccountBalance);

		return strClientRecord;
	}

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile() {

		vector<clsBankClient> vClient;

		fstream MyFile;
		MyFile.open(ClientsFile, ios::in);

		if (MyFile.is_open()) {
		
			string Line;
			while (getline(MyFile, Line)) {
			
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClient.push_back(Client);
			}
			MyFile.close();
		}
		return vClient;
	}
	static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out);//overwrite

		string DataLine;
		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void _AddDataLineToFile(string stDataLine)

	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}
	void _Update() {

		vector<clsBankClient> _vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == _AccountNumber) {
			
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone){

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	enum enSaveResults { svFaild = 0, svSucceeded = 1 };


	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;



	bool IsEmpty() {

		return (_Mode == enMode::EmptyMode);
	}

	void print() {

		cout << "\nInfo:";
		cout << "\n-------------------------";

		cout << "\nAcc. Number    : " << _AccountNumber;
		cout << "\nFirstName      : " << FirstName;
		cout << "\nLastName       : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nPassword       : " << _PinCode;
		cout << "\nBalance        : " << _AccountBalance;

		cout << "\n-------------------------";
	}

	//The Extensions
	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;
		MyFile.open(ClientsFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) {
			
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber);
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode) {

		fstream MyFile;
		MyFile.open(ClientsFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) {

				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber && Client.PinCode == PinCode);
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}


	enSaveResults Save() {

		switch (_Mode) {

		case enMode::EmptyMode:
			return enSaveResults::svFaild;
			
		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
		}
	}

	static bool IsClientExist(string AccountNumber) {

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}


};
