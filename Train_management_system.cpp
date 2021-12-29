#include <iostream>
#include <string>
using namespace std;
int static count_bogie = 0;
class Person
{
	string Name;
	int Age;
	char Gender;
public:
	virtual void printdata()
	{

	};
	Person()
	{
		Name = " ";
		Age = 0;
		Gender = '\0';

	}
	Person(string name1, int age1, char gender)
	{
		Name = name1;
		Age = age1;
		Gender = gender;
	}
	string getname()
	{
		return Name;
	}
	int getage()
	{
		return Age;
	}
	char getgender()
	{
		return Gender;
	}
	void setname(string nam)
	{
		Name = nam;
	}
	void setage(int nam)
	{
		Age = nam;
	}
	void setgender(char nam)
	{
		Gender = nam;
	}
};

class Adult :public Person
{
	string Occupation;
	string Qualification;
	string NIC;
public:
	Adult()
	{
		Occupation = " ";
		Qualification = " ";
		NIC = " ";
	}
	string getoccupation()
	{
		return Occupation;
	}
	string getqualification()
	{
		return Qualification;
	}
	string getnic()
	{
		return NIC;
	}
	void setoccup(string occup)
	{
		Occupation = occup;
	}
	void setqualif(string quali)
	{
		Qualification = quali;
	}
	void setnic(string nic)
	{
		NIC = nic;
	}
	Adult(string ocup, string quali, string nic, string name1, int age1, char gender) :Person(name1, age1, gender)
	{
		Occupation = ocup;
		Qualification = quali;
		NIC = nic;
	}
	void printdata();
	void addadult();
};
void Adult::printdata()
{
	cout << " Name of ADULT          :  " << getname() << endl;
	cout << " AGE of ADULT           :  " << getage() << endl;
	cout << " gender of ADULT        :  " << getgender() << endl;
	cout << " QUALIFICATION OF ADULT :  " << getqualification() << endl;
	cout << " OCCUPATION OF ADULT    :  " << getoccupation() << endl;
	cout << " NIC of Adult           :  " << getnic() << endl;
}
void Adult::addadult()
{
	string name;
	int age = 0;
	char gender = '\0';
	string ocpat;
	string qualif;
	string nic;
	cout << " ENTER THE NAME OF ADULT...........: " << endl;
	cin >> name;
	this->setname(name);
	cout << " ENTER THE AGE OF ADULT.............: " << endl;
	cin >> age;
	this->setage(age);
	cout << " ENTER THE GENDER OF ADULT...........: " << endl;
	cin >> gender;
	this->setgender(gender);
	cout << " ENTER THE QUALIFICATION OF ADULT.....: " << endl;
	cin >> qualif;
	this->setqualif(qualif);
	cout << " ENTER THE OCCUPATION OF ADULT........: " << endl;
	cin >> ocpat;
	this->setoccup(ocpat);
	cout << " ENTER THE NIC OF ADULT................: " << endl;
	cin >> nic;
	this->setnic(nic);
}
class kid :public Person
{
	string B_form_number;
public:
	kid()
	{
		B_form_number = " ";
	}
	void setbform(string bb)
	{
		B_form_number = bb;
	}
	string getbform()
	{
		return B_form_number;
	}
	kid(string bform, string name1, int age1, char gender) :Person(name1, age1, gender)
	{
		B_form_number = bform;
	}
	void addkid();
	void printdata();
	kid operator= (kid &obj)
	{
		this->B_form_number = obj.B_form_number;
	}
};
void kid::printdata()
{
	cout << " NAME OF CHILD  :  " << getname() << endl;
	cout << " AGE OF CHIL    :  " << getage() << endl;
	cout << " GENDER OF CHILD:  " << getgender() << endl;
	cout << " BFORM NO.      :  " << getbform() << endl;
}
void kid::addkid()
{
	string name;
	int age = 0;
	string bform;
	char gender = '\0';
	cout << "ENTER THE NAME OF KID....: " << endl;
	cin >> name;
	this->setname(name);
	cout << " ENTER THE AGE OF KID....: " << endl;
	cin >> age;
	this->setage(age);
	cout << " ENTER THE GENDER OF KID..: " << endl;
	cin >> gender;
	this->setgender(gender);
	cout << " ENTER THE B_FORM NUMBER...: " << endl;
	cin >> bform;
	this->setbform(bform);
}
class Bogie
{
	int Bogie_ID;
	Person **Adults;
	Person **kids;
	string familyName;
	Bogie *next;
	int  adult_num;
	int  kid_num;
public:
	Bogie()
	{
		Bogie_ID = 0;
		next = nullptr;
		Adults = nullptr;
		kids = nullptr;
		familyName = " ";
		adult_num = 0;
		kid_num = 0;
	}
	int getadult_num()
	{
		return adult_num;
	}

	void setadult_num(int num)
	{
		adult_num = num;
	}
	void setkid_num(int num2)
	{
		kid_num = num2;
	}
	int getkid_num()
	{
		return kid_num;
	}
	void setfname(string fname1)
	{
		familyName = fname1;
	}
	string getfname()
	{
		return familyName;
	}
	void setkids(Person **kids1)
	{
		kids = kids1;
	}
	void setAdults(Person **prsn)
	{
		Adults = prsn;
	}
	Person **getAdults()
	{
		return Adults;
	}
	Person **getkids()
	{
		return kids;
	}
	void setnext(Bogie *next1)
	{
		next = next1;
	}
	Bogie *getnext()
	{
		return next;
	}
	void setid(int id)
	{
		Bogie_ID = id;
	}
	int getid()
	{
		return Bogie_ID;
	}
	Bogie(int id)
	{
		Bogie_ID = id;
	}
	bool AddPassengers(); // should add adults and kids information etc
	void Print();     /////    
	~Bogie()
	{
		delete[] next;
		for (int i = 0; i < adult_num; i++)
		{
			delete Adults[i];
		}
		delete[]Adults;
		for (int i = 0; i < kid_num; i++)
		{
			delete kids[i];
		}
		delete[] kids;
	}

};

void Bogie::Print()
{
	cout << endl;
	for (int i = 0; i < getadult_num(); i++)
	{
		cout << " INFORMATION OF ..............ADULT" << endl;
		getAdults()[i]->printdata();
		cout << endl;
	}
	for (int i = 0; i < getkid_num(); i++)
	{
		cout << " INFORMATION OF................KID" << endl;
		getkids()[i]->printdata();
		cout << endl;
	}
}
bool Bogie::AddPassengers()
{
	if ((getadult_num() + getkid_num()) < 10)
	{
		int overall = 0;
		if (count_bogie != 0)
		{
			int count = 0;
			int choice;
			Bogie CS;
			if ((getadult_num() + getkid_num()) == 0)
			{
				string familyname;
				cout << " ENTER THE NAME OF FAMILY....... ." << endl;
				cin >> familyname;
				setfname(familyname);
			}
			int check1 = 0;
			cout << " 1.ENTER ONE TO ADD CHILD\n 2.ENTER 2 TO ADD ADULT\n ";
			cin >> choice;
			while (check1 != 1)
			{
				int num = 0;
				int check = 1;

				for (int j = 0; j < check; j++)
				{

					if (choice == 1)
					{
						int count2 = getkid_num();
						if (count2 < 4)
						{

							cout << " ENTER THE NUMBER OF CHILDS....ALREADY PRESENT CHILD INTHIS BOGIE ARE " << count2 << endl;
							cin >> num;
							num = count2 + num;
							int flag = 0;
							while (flag != 1)
							{
								if (num > 0 && num <= 4)
								{
									if (count2 > 0)
									{
										setkid_num(num);
										Person **kidk;
										kidk = new Person*[count2];
										check1 = 1;
										for (int i = 0; i < count2; i++)
										{
											kidk[i] = new kid;
											kidk[i] = kids[i];
										}
										kids = new Person*[num];
										for (int i = 0; i < count2; i++)
										{
											kids[i] = kidk[i];
										}
										flag = 1;
										for (int i = count2; i < num; i++)
										{
											check = 1;
											kid *temp = new kid();
											temp->addkid();

											kids[i] = temp;

											overall = 1;
											//kid_num++;

										}
									}
									else
									{
										kids = new Person*[num];
										setkid_num(num);
										for (int i = 0; i < num; i++)
										{
											check1 = 1;
											//kids[i] = new kid();
											kid *temp = new kid;
											//kids[i] = new kid();
											//kid *temp = new kid();
											//kids[i] = new kid(bfrom,name,age,ged);
											//temp = new kid();
											//kids[i].addkid();
											//Person * p = &(kids[i]);
											//kid *temp = (kid*)p;
											//temp = (kid*)&(kids[i]);
											 //temp = new kid();
											temp->addkid();

											kids[i] = temp;

											flag = 1;
											overall = 1;
											//delete temp;
											//temp = NULL;
										}
									}
								}
								else
								{
									cout << " INVALID INPUT.....ENTER VALUE FROM 1 TO 4......" << endl;
									cin.clear();
									cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									cin >> num;
									num = count2 + num;
									flag = 0;
								}
							}

						}
						else
						{
							cout << " NUMBER OF CHILD ARE FULL IN THIS BOGIE  " << endl;
							// check1 = 1;/////enter by me
						}
					}
					else if (choice == 2)
					{
						int count3 = getadult_num();
						if (count3 < 6)
						{
							cout << " ENTER THE NUMBER Of ADULTS YOU WANT TO ADD .......ALREADY PRESEENT ADULTS ARE " << count3 << endl;
							cin >> num;
							num = num + count3;
							//member_count++;
							check1 = 1;
							int flag = 0;
							while (flag != 1)
							{
								if (num > 0 && num <= 6)
								{
									if (count3 > 0)
									{

										check1 = 1;
										setadult_num(num);
										Person **adultk;
										adultk = new Person*[count3];
										//check1 = 1;
										for (int i = 0; i < count3; i++)
										{
											//adultk[i] = new kid;
											adultk[i] = Adults[i];
										}
										Adults = new Person*[num];
										for (int i = 0; i < count3; i++)
										{
											//kids[i] = new kid;
											Adults[i] = adultk[i];
										}
										for (int i = count3; i < num; i++)
										{
											check = 1;
											Adult *temp = new Adult();
											temp->addadult();

											Adults[i] = temp;
											flag = 1;
											overall = 1;

										}

									}
									else
									{
										setadult_num(num);
										Adults = new Person*[num];
										for (int i = 0; i < getadult_num(); i++)
										{
											//int count = getadult_num();
											//Adult *temp = (Adult*)&(Adults[i]);
											//Adults[i] = new Adult();
											Adult *temp;
											temp = new Adult();
											temp->addadult();
											Adults[i] = temp;
											flag = 1;
											overall = 1;
											//delete temp;
											//temp = nullptr;
										}
									}
								}
								else
								{
									cout << " INVALID INPUT.....ENTER VALUE FROM 1 TO 6......" << endl;
									cin.clear();
									cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									cin >> num;
									num = count3 + num;
									flag = 0;
								}
							}
						}
						else
						{
							cout << " NUMBER OF ADULTS IN THIS BOGIE ARE ALREADY SIX " << endl;
						}
					}
					else
					{
						cout << " INVALID INPUT ENTER AGAIN....." << endl;
						cin.clear();
						j--;
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin >> choice;
						check1 = 0;

					}
				}
				char choose;
				if (count < 1)
				{
					if (choice == 1)
					{
						cout << " DO YOU WANT TO ADD ADULTS IN THIS BOGIE.......IF YES THEN TYPE Y IF NO PRESS ANY KEY" << endl;
						cin >> choose;
						if (choose == 'y')
						{
							choice = 2;
							check++;
							count++;
							check1 = 0;
						}
					}
					else
					{
						cout << " DO YOU WANT TO ADD CHILD IN THIS BOGIE.......IF YES THEN TYPE Y IF NO PRESS press any key " << endl;
						cin >> choose;
						if (choose == 'y')
						{
							choice = 1;
							check++;
							count++;
							check1 = 0;
						}
					}
				}
			}
		}
		else
		{
			cout << endl;
			system("cls");
			cout << " THERE IS NO BOGIE TO ADD PASSENGERS......." << endl;
			return 0;
		}
		if (overall = 1)
		{
			system("cls");
			cout << " YOUR GIVEN DATA HAS BEEN ADDED...." << endl;
			cout << endl;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		cout << endl;
		cout << " BOGIE IS FULL " << endl;
	}
}
class train
{
	Bogie * engine;
	Bogie * tail;
public:
	Bogie *getengine()
	{
		return engine;
	}
	Bogie *gettail()
	{
		return tail;
	}
	train()
	{
		tail = nullptr;
		engine = nullptr;
	}
	void addBogie(int ID); //add bogie at the end of the train
	bool removeBogie(int ID); //search the bogie and delete it 
	void printTrain(); //print only the Bogie_ID of all bogies
	bool SearchBogie(int ID);//search the particular bogie
	void addpassengers(int id);
	void Print(int id);
	~train()
	{
		delete engine;
		delete tail;
	}
};
void train::Print(int id)
{
	int check = 0;
	Bogie *obj;
	cout << endl;
	if (count_bogie != 0)
	{
		obj = getengine();
		for (int i = 0; i < count_bogie; i++)
		{
			if (obj->getnext()->getid() == id)
			{
				obj = obj->getnext();
				check = 2;
				if ((obj->getadult_num() + obj->getkid_num()) != 0)
				{
					//system("cls");
					cout << " FAMILY NAME......." << obj->getfname() << endl;
					obj->Print();
					check = 1;
				}
			}
			else
			{
				obj = obj->getnext();
			}
		}
		if (check == 2)
		{
			cout << "  THERE IS NO PASSENGERS ADDED IN THIS BOGIE ......YET" << endl;
		}
		else if (check == 0)
		{
			cout << endl;
			system("cls");
			cout << " BOGIE WITH ID NUMBER " << id << "  IS NOT PRESENT........" << endl;
		}
	}
	else
	{
		system("cls");
		cout << endl;
		cout << " NO BOGIE IS ATTACHED YET....." << endl;
	}

}
void train::addpassengers(int id)
{
	if (count_bogie != 0)
	{
		Bogie *obj;
		obj = engine;
		obj = obj->getnext();
		int check = 0;
		for (int i = 0; i < count_bogie; i++)
		{
			if (obj->getid() == id)
			{
				int count = obj->getkid_num() + obj->getadult_num();
				if ((obj->getkid_num() + obj->getadult_num()) < 10)
				{
					obj->AddPassengers();
					check = 1;
					break;
				}
				else
				{
					cout << endl;
					cout << " TOTAL NUMBER OF PASSENGERS IN THIS BOGIE ARE ALREADY 10........." << endl;
					break;
				}
			}
			else
			{

				if (obj->getnext() == nullptr)
				{
					system("cls");
					cout << " BOGIE WITH THIS NAME IS NOT PRESENT........." << endl;
					break;
				}
				obj = obj->getnext();

			}
		}
	}
	else
	{
		cout << " THERE IS NO BOGIE TO ADD PASSENGERS YET " << endl;
	}
}
bool train::SearchBogie(int ID)
{
	if (count_bogie != 0)
	{
		int option = 0;
		int check = 0;
		Bogie *obj = engine;
		for (int i = 0; i < count_bogie; i++)
		{
			if (obj->getnext()->getid() == ID)
			{
				cout << endl;
				check = 1;
				return 1;

			}
			else
			{
				obj = obj->getnext();
			}
		}
		if (check == 0)
		{
			return 0;
		}

	}
	else
	{
		return 0;
	}
}
void train::printTrain()
{
	if (count_bogie != 0)
	{
		cout << " ID'S OF BOGIES .....THOSE ARE PRESENT IN TRAIN" << endl;
		Bogie *obj = engine;
		for (int i = 0; i < count_bogie; i++)
		{

			cout << " ID OF BOGIE :" << obj->getnext()->getid() << endl;
			obj = obj->getnext();
		}
	}
	else
	{
		cout << " THERE IS NO BOGIE TO PRINT.......YET " << endl;
	}
}
void train::addBogie(int id)
{
	int b = 0;
	int check = 0;
	Bogie *obj = new Bogie();
	b = SearchBogie(id);
	if (b == 1)
	{
		cout << " YOU CANNOT  ADD THIS BOGIE....." << endl;
	}
	else
	{
		count_bogie++;
		obj->setid(id);
		obj->setnext(nullptr);
		char y;
		cout << " PRESS Y TO ADD PASSENGERS IN THIS........ ELSE PRESS ANY KEY TO CONTINUE \n";
		cin >> y;
		if (y == 'y')
		{
			obj->AddPassengers();
		}

		if (engine == nullptr)
		{
			engine = new Bogie();
			engine->setnext(obj);
			tail = obj;
		}
		else
		{
			tail->setnext(obj);
			tail = tail->getnext();
		}
	}
}
bool train::removeBogie(int ID)
{
	{
		if (count_bogie != 0)
		{
			int c = 0;
			int check = 0;
			Bogie *obj = engine;
			while (c != count_bogie)
			{
				if (obj->getnext()->getid() == ID)
				{
					Bogie *temp;
					temp = obj->getnext();
					obj->setnext(obj->getnext()->getnext());
					temp->setnext(nullptr);
					check = 1;
					delete temp;
					break;

				}
				else
				{
					obj = obj->getnext();
				}
				c++;
			}
			if (check == 1)
			{
				count_bogie--;
				if (count_bogie == 0)
				{
					engine == nullptr;
				}
				else
				{
					system("cls");
					cout << endl;
					cout << "   bogie has been removed " << endl;
					obj = engine;
					for (int i = 0; i < count_bogie; i++)
					{
						if (i == count_bogie - 1)
						{
							tail->setnext(obj);
							tail = tail->getnext();
						}
						else
						{
							obj = obj->getnext();
						}
					}
					return 1;
				}
			}
			else
			{
				cout << endl;
				system("cls");
				cout << " BOGIE WITHIS NAME IS NOT AVAILABLE......" << endl;
				return 0;
			}
		}
		else
		{
			cout << endl;
			system("cls");
			cout << " no bogie is attached yet " << endl;
			return 0;
		}
	}
}
int main()
{

	train a;
	int id = 0;
	int choice;
	cout << "                                         " << endl;
	cout << " ######        WELCOME TRAIN MANAGEMENT SYSTEM       ######  " << endl;
label1:
	cout << endl;
	cout << " 1.ENTER 1 TO ADD BOGIE\n 2.ENTER 2 TO REMOVE BOGIE\n 3.ENTER 3 TO PRINT IDS OF BOGIEs\n 4.ENTER 4 TO SEARCH BOGIE\n 5.ENTER 5 TO ADD PASSENGERS IN BOGIE\n 6.ENTER 6 TO PRINT DATA OF ANY BOGIE\n 7.EXIT\n";
loop1:
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << " ENTER THE ID NUMBER....." << endl;
		cin >> id;
		while (id <= 0)
		{
			cout << " INVALID INPUT.....ENTER AGAIN......" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> id;
		}
		a.addBogie(id);
		system("cls");
		a.printTrain();
		break;
	case 2:
		cout << " ENTER THE ID NUMBER....." << endl;
		cin >> id;
		while (id <= 0)
		{

			cout << " INVALID INPUT.....ENTER AGAIN......" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> id;
		}
		a.removeBogie(id);
		a.printTrain();
		break;
	case 3:
		system("cls");
		a.printTrain();
		break;
	case 4:
		cout << " ENTER THE ID NUMBER....." << endl;
		cin >> id;
		while (id <= 0)
		{

			cout << " INVALID INPUT.....ENTER AGAIN......" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> id;
		}
		bool bol;
		bol = a.SearchBogie(id);

		if (bol == 1)
		{
			system("cls");
			cout << "BOGIE WITH ID " << id << " IS PRESENT\n";
		}
		else
		{
			system("cls");
			cout << "BOGIE WITH ID" << id << " IS NOT PRESENT\n";
		}
		a.printTrain();
		break;
	case 5:
		cout << " ENTER THE ID NUMBER....." << endl;
		cin >> id;
		while (id <= 0)
		{

			cout << " INVALID INPUT.....ENTER AGAIN......" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> id;
		}
		a.addpassengers(id);
		a.printTrain();

		break;
	case 6:
		cout << " ENTER THE ID NUMBER....." << endl;
		cin >> id;
		while (id <= 0)
		{

			cout << " INVALID INPUT.....ENTER AGAIN......" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> id;
		}
		system("cls");
		a.Print(id);
		break;

	case 7:
		return 0;
	default:
		cout << " INVALID INPUT......ENTER AGAIN" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		goto loop1;
	}
	goto label1;
}




