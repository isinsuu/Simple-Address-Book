#include <iostream>
#include <iomanip>
using namespace std;

class Contact{
	private:
		string name, number;
		
	public:
		Contact(): name {"Unknown"}, number{"0"}{}
		Contact(string a, string b): name{a}, number{b}{}
		void print(string mode);
		void SetName(string str_name) {name=str_name;}
		void SetNumber(string str_number) {number=str_number;}
		string GetName() {return name;}
		string GetNumber() {return number;}	
};

class AddressBook{
	private:
		int search(string srch);
		Contact contacts[40];
		Contact temp;
		int nrofcontacts{0};
		
	public:
		AddressBook(){}
		bool add(Contact cont);
		bool remove(string ad_name);
		void print();
		void menu();
};

int main()
{
	AddressBook obj;
	obj.menu();
	
	return 0;
}

void Contact::print(string mode) 
{
	if(mode=="light")
	{
		cout << left << setw(13) << GetName() << left << setw(13) << GetNumber() << endl;
	}
	
	else if(mode=="headers")
	{
		cout << "Name: " << GetName() << endl; 
		cout << "Number: " << GetNumber() << endl;
	}
}

int AddressBook::search(string srch)
{
	int flag{1}, i{0}, index;
	
	for(i=0; i<nrofcontacts; ++i)
	{
		if(srch==contacts[i].GetName())
		{
			flag=0;
			index=i;
		}
	}
	
	if(flag==0)
	{
		return index;
	}
	
	else
	{
		return -1;
	}
}


bool AddressBook::add(Contact cont)
{
	if(search(cont.GetName())==-1)
	{
		contacts[nrofcontacts].SetName(cont.GetName());
		contacts[nrofcontacts].SetNumber(cont.GetNumber());
		nrofcontacts++;
		return true;
	}
	
	else
	{
		cout << "Contact already exists." << endl;
		cout << endl;
		return false;
	}
}

bool AddressBook::remove(string ad_name)
{
	int control=search(ad_name);
	
	if(control!=-1)
	{
		nrofcontacts--;
		for(int i=control; i<nrofcontacts; ++i)
		{	
			contacts[i]=contacts[i+1];	
		}
		
		return true;
	}
	
	else
	{
		cout << "Contact is not available." << endl;
		cout << endl;
		return false;
	}
}

void AddressBook::print() 
{
	string mode;
	
	if(nrofcontacts==0)
	{
		cout << "No contacts available." << endl;
		cout << endl;
	}
	
	else
	{
		cout << "Choose how you want to print (light/headers): ";
		cin >> mode;
		
		cout << endl;
		
		for(int i=0; i<nrofcontacts; ++i)
		{
			contacts[i].print(mode);		
		}
		
		cout << endl;	
	}
}

void AddressBook::menu()
{
	AddressBook adr;
	string func_name, func_number;
	int choice;
	
	do{
		cout << "1.Display Address Book" << endl;
		cout << "2.Add New Contact" << endl; 
		cout << "3.Remove Contact" << endl;
		cout << "4.Exit" << endl;
	
		cout << "Enter your choice: ";
		cin >> choice;
		
		cout << endl;
		
		if(choice==1)
		{
			adr.print();
		}
	
		else if(choice==2)
		{
			cout << "Enter name: ";
			cin >> func_name;
			temp.SetName(func_name);
			
			cout << "Enter number: ";
			cin >> func_number;
			temp.SetNumber(func_number);
		
			if(adr.add(temp))
			{
				cout << "Contact added." << endl;
				cout << endl;		
			}		
		}
	
		else if(choice==3)
		{
			cout << "Enter name: ";
			cin >> func_name;
		
			if(adr.remove(func_name))
			{
				cout << "Contact removed." << endl;
				cout << endl;
			}
		}
	}while(choice!=4);
	
	cout << "Goodbye.";
}















