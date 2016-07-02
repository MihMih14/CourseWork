#include"CardPatient.h"
#include"Doctors.h"
#include"Patient.h"
#include<iostream>
#include<fstream>

using namespace std;

/*
	viwew
*/



void printCardHeader()
{

	printCardLine();
	cout << "|Account| ID Doc | ID Pat |     Diagnoz    |  Price  | Paid |\n";
	printCardLine();
}



void printCardContent(CardPatiet card)
{
	cout << "|";
	cout.width(7);
	cout << left << card.AccountNumber;

	cout << "|";
	cout.width(8);
	cout << left << card.Doc_ID;

	cout << "|";
	cout.width(8);
	cout << left << card.Pat_ID;

	cout << "|";
	cout.width(16);
	cout << left << card.diagnoz;

	

	cout << "|";
	cout.width(7);
	
	
	cout << fixed;
	cout.precision(2);
	cout << left << card.price << "EU";
	cout << "|";
	cout.width(6);
	cout << left << getPaid(card.Paid) << "|" <<endl;
	printCardLine();
}


void showAllCard()
{
	ifstream file;
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Show All Card.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File is Wrong!\n";
	}
	else{
		CardPatiet card;
		printCardHeader();
		while (file.read((char*)&card, sizeof(CardPatiet))){
			printCardContent(card);
		}
	}

	file.close();
	system("Pause");
}
void printCard(CardPatiet card)
{
	
	cout << "\n-------------------------------------------------\n";
	cout << "Account Number : " << card.AccountNumber << endl;
	cout << "ID Doctor : " << card.Doc_ID << endl;
	cout << "ID Patient : " << card.Pat_ID << endl;
	cout << "Diagnoz : " << card.diagnoz << endl;
	cout << "Paid : " << getPaid(card.Paid) << endl;
	cout << "Price : " << card.price << endl;
	cout << "-------------------------------------------------\n\n";
}

char* getPaid(bool paid){
	return paid ? "Yes" : "No";
}

void printCardLine()
{
	for (int i = 0; i < 61; i++){
		cout << "-";
	}
	cout << endl;
}

void addBill()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Add Bill.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ofstream fileCard;
	ifstream fileDoc, filePat;
	fileDoc.open("Doctors.dat", ios::binary);
	filePat.open("Patients.dat", ios::binary);
	fileCard.open("Card.dat", ios::binary | ios::app);

	if (!fileDoc || !fileCard || !filePat){
		cout << "File Is Wrong!\n";
	}
	else{
		fileDoc.close();
		filePat.close();
		CardPatiet card;
		card.AccountNumber = setAccountNumber();

		cout << "Please Enter ID Doctor : ";
		setDoctorID(&card);

		
		cout << "Please Enter ID Patietn : ";
		setPatientID(&card);

		cout << "Please Enter Diagnoz : ";
		cin >> card.diagnoz;



		cout << "Please Enter Price in Euro : ";
		cin >> card.price;

		cout << "Does Patient Paid (y/n)? : ";
		char answer;
		cin >> answer;
		if (answer == 'y'){
			card.Paid = true;
		}
		else{
			card.Paid = false;
		}
		system("cls");
		printCard(card);

		cout << "\nDo you Want Write this Data (y/n)? : ";
		cin >> answer;
		if (answer == 'y'){
			fileCard.write((char*)&card, sizeof(CardPatiet));
			cout << "Data Was Write!\n";
		}
		else{
			cout << "Data Dont write!\n";
		}

	}

	fileCard.close();
	system("PAUSE");
}


void showAllBill(int ID)
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Show All Bill.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!";
	}
	else{



		CardPatiet card;
		printCardHeader();
		while (file.read((char*)&card, sizeof(CardPatiet))){
			if (ID == card.Pat_ID){
				printCardContent(card);
			}
		}



	}
	file.close();
	system("PAUSE");
}
void showAllDoctorPatient(int ID)
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Show All History Patient By ID.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!";
	}
	else{


		CardPatiet card;
		printCardHeader();
		while (file.read((char*)&card, sizeof(CardPatiet))){
			
			printCardContent(card);
		}


	}
	file.close();
	system("PAUSE");
}

void showPatientBillID()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Patient Bill.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	cout << "Please Enter ID : ";
	int ID;
	cin >> ID;

	if (checkPatientID(ID)){
		showAllBill(ID);
	}
	else{
		cout << "Not Found!\n";
	}

	system("PAUSE");
}

void showDoctorBillID()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Doctor Bill.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	cout << "Please Enter ID : ";
	int ID;
	cin >> ID;

	if (checkDoctorID(ID)){
		showAllDoctorPatient(ID);
	}
	else{
		cout << "Not Found!\n";
	}

	system("PAUSE");
}

/*
	ID
*/

void setDoctorID(CardPatiet *card)
{
	int ID;
	Doctor doctor;
	do{
		cin >> ID;
		doctor = findDoctor(ID);
		if (doctor.ID == -1){
			cout << "Doctor With ID " << ID << "Not Found!\n";
			cout << "Please Repeat Enter!\n";
			cout << "Please Enter ID : ";
		}
		else{
			printDoctor(doctor);
			cout << "Is This Doctor ? (y/n) : ";
			char answer;
			cin >> answer;
			if (answer == 'n'){
				doctor.ID = -1;
				cout << "Please Enter ID : ";
			}
			



		}
	} while (doctor.ID == -1);

	card->Doc_ID = ID;
}

void setPatientID(CardPatiet *card)
{
		int ID;
		Patient patient;
		do{
			cin >> ID;
			patient = getPatient(ID);
			if (patient.ID == -1){
				cout << "Patient With ID " << ID << "Not Found!\n";
				cout << "Please Repeat Enter!\n";
				cout << "Please Enter ID : ";
			}
			else{
				printPatient(patient);
				cout << "Is This Doctor ? (y/n) : ";
				char answer;
				cin >> answer;
				if (answer == 'n'){
					patient.ID = -1;
					cout << "Please Enter ID : ";
				}
				



			}
		} while (patient.ID == -1);

		card->Pat_ID = ID;
	}

int setAccountNumber()
{
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		return 1;
	}
	else{
		int size = getSizeCardFile();
		if (size == 0){
			return 1;
		}
		else{
			CardPatiet *card = new CardPatiet[size];
			file.read((char*)card, sizeof(CardPatiet)* size);
			file.close();

			return card[size - 1].AccountNumber + 1;
		}
	}
}


/*
	Check
*/

bool checkPatientID(int ID)
{
	ifstream file;
	file.open("Card.dat",ios::binary);
	if (!file){
		return false;
	}
	else{
		CardPatiet card;
		while (file.read((char*)&card, sizeof(CardPatiet))){
			if (card.Pat_ID == ID){
				return true;
			}
		}

		return false;
	}
}

bool checkDoctorID(int ID)
{
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		return false;
	}
	else{
		
		CardPatiet card;
		while (file.read((char*)&card, sizeof(CardPatiet))){
			if (card.Doc_ID == ID){
				return true;
			}
		}

		return false;
	}
}

bool checkAccount(int account)
{
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		return false;
	}
	else{
		CardPatiet card;
		while (file.read((char*)&card, sizeof(CardPatiet))){
			if (account == card.AccountNumber){
				return true;
			}
		}

		return false;
	}
}

/*
	filtr
*/

void filtrPayBill()
{

	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Filtr Pay Bill.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Card.dat",ios::binary);

	if (!file){
		cout << "File Is Wrong ! \n";
	}
	else{
		CardPatiet card;
		if (countPayBill() > 0){
			printCardHeader();
			while (file.read((char*)&card, sizeof(CardPatiet))){
				if (card.Paid){
					printCardContent(card);
				}
			}
			cout << endl;
		}
		else{
			cout << "Not Sach People Which Paid!\n";
		}
	}

	file.close();
	system("PAUSE");
}

void filtrBill()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Filtr Bill.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Card.dat",ios::binary);
	if (!file){
		cout << "File Is Wrong!";
	}
	else{

		if (countBill() == 0){
			cout << "Now not Bill! \n";
		}
		else{
			CardPatiet card;
			printCardHeader();
			while (file.read((char*)&card, sizeof(CardPatiet))){
				if (!card.Paid){
					printCardContent(card);
				}
			}
			cout << endl;
		}
	}

	file.close();
	system("PAUSE");
}

/*
	
	count

*/

int getSizeCardFile()
{
	ifstream file;
	file.open("Card.dat",ios::binary);
	if (!file){
		file.close();
		return 0;
		
	}
	else{
		file.seekg(0, ios::end);
		int size = file.tellg();
		file.seekg(0, ios::beg);
		file.close();
		return size / sizeof(CardPatiet);

		
	}
}

int countBill()
{
	ifstream file;
	file.open("Card.dat",ios::binary);
	if (!file){
		file.close();
		return 0;
	}
	else{
		CardPatiet card;
		int count = 0;
		while (file.read((char*)&card, sizeof(CardPatiet))){
			if (!card.Paid){
				count++;
			}
		}
		file.close();
		return count;
	}
}

int countPayBill()
{
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		return 0;
	}
	else{
		CardPatiet card;
		int count = 0;
		while (file.read((char*)&card, sizeof(CardPatiet))){
			if (card.Paid){
				count++;
			}
		}

		file.close();
		return count;


	}
}

/*
	find
*/

CardPatiet getCardPatient(int accountNumber)
{
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		return CardPatiet{ -1, -1, -1, "", 0.0, false };
	}
	else{
		CardPatiet card;
		while (file.read((char*)&card, sizeof(CardPatiet))){
			if (card.AccountNumber == accountNumber){
				return card;
			}
		}

		return CardPatiet{ -1, -1, -1, "", 0.0, false };

	}
}

void findCardByAccountNum()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Find Bill By Account Number.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	cout << "Please Enter Account Number : ";
	int accountNumber;
	cin >> accountNumber;
	
	CardPatiet card = getCardPatient(accountNumber);
	if (card.AccountNumber == -1){
		cout << "Account Number Didnt find!\n";
	}
	else{
		Patient patient = getPatient(card.Pat_ID);
		if (patient.ID == -1){
			patient = getBackUpPatient(card.Pat_ID);
		}
		//Дописать Doctor.
		Doctor doctor = findDoctor(card.Doc_ID);
		if (doctor.ID == -1){
			doctor = getBackUpDoctor(card.Doc_ID);
		}
		cout << "DOCTOR\n";
		printDoctor(doctor);
		cout << "Patient\n";
		printPatient(patient);
		
		printCard(card);
	}

	system("PAUSE");
}



/*
	delete
*/
void deleteBill()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Delete Bill.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is wrong!\n";
	}
	else{
		cout << "Please Enter Account Number : ";
		int account;
		cin >> account;
		if (checkAccount(account)){
			int size = getSizeCardFile();
			CardPatiet *card = new CardPatiet[size];
			file.read((char*)card, sizeof(CardPatiet) * size);
			file.close();

			ofstream newFile;
			newFile.open("Card.dat", ios::binary);

			for (int i = 0; i < size; i++){
				if (card[i].AccountNumber == account){
					printCard(card[i]);
					cout << "\nDo you Want Delete It Bill (y/n) ? : ";
					char answer;
					cin >> answer;
					if (answer != 'y'){
						newFile.write((char*)&card[i], sizeof(CardPatiet));
					}
					else{
						cout << "Bill is Delete! \n";
					}
				}
				else{
					newFile.write((char*)&card[i], sizeof(CardPatiet));
				}
			}

			newFile.close();


		}
		else{
			cout << "There Dont Account Number With Number - " << account << endl;
		}
	}

	system("PAUSE");
}

void newFileWrite(CardPatiet *card,int size)
{
	ofstream file;
	file.open("Card.dat", ios::binary);

	for (int i = 0; i < size; i++){
		file.write((char*)&card[i],sizeof(CardPatiet));
	}

	file.close();
	cout << "Data Is Update!\n";

}

void changeDoctorID()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change Doctor ID.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!";
	}
	else{
		cout << "Please Enter Account Number : ";
		int account;
		cin >> account;

		CardPatiet card = getCardPatient(account);
		if (card.AccountNumber == -1){
			cout << "Bill With Number " << account << "Dont Found! \n";
		}
		else{
			cout << "Enter New Doctor ID : ";
			setDoctorID(&card);

			//system("cls");
			cout << "Do tou Want Change Data (y/n) ? : ";
			char answer;
			cin >> answer;
			if (answer == 'y'){
				int size = getSizeCardFile();
				CardPatiet *cards = new CardPatiet[size];
				file.read((char*)cards,sizeof(CardPatiet) * size);
				file.close();
				bool check = true;
				for (int i = 0; i < size && check; i++){
					if (account == cards[i].AccountNumber){
						check = false;
						cards[i].Doc_ID = card.Doc_ID;
					}
				}

				newFileWrite(cards, size);
			}
			else{
				cout << "Data Dont Write!\n";
			}

		}


	}
	system("PAUSE");
}

void changePatientID()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change Patient ID.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!";
	}
	else{
		cout << "Please Enter Account Number : ";
		int account;
		cin >> account;

		CardPatiet card = getCardPatient(account);
		if (card.AccountNumber == -1){
			cout << "Bill With Number " << account << "Dont Found! \n";
		}
		else{
			cout << "Enter New Patient ID : ";
			setPatientID(&card);

			system("cls");
			cout << "Do tou Want Change Data (y/n) ? : ";
			char answer;
			cin >> answer;
			if (answer == 'y'){
				int size = getSizeCardFile();
				CardPatiet *cards = new CardPatiet[size];
				file.read((char*)cards, sizeof(CardPatiet)* size);
				file.close();
				bool check = true;
				for (int i = 0; i < size ; i++){
					if (account == cards[i].AccountNumber){
						check = false;
						cards[i].Pat_ID = card.Pat_ID;
					}
				}

				newFileWrite(cards, size);
			}
			else{
				cout << "Data Dont Write!\n";
			}

		}


	}

	system("PAUSE");
}

void changeDiagnoz()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change Diagnoz.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!\n";
	}
	else{

		cout << "Please Enter Account : ";
		int account;
		cin >> account;

		if (checkAccount(account)){
			int size = getSizeCardFile();
			CardPatiet *card = new CardPatiet[size];
			file.read((char*)card, sizeof(CardPatiet)* size);
			file.close();
			bool check = true;
			for (int i = 0; i < size; i++){
				if (account == card[i].AccountNumber){
					
					printCard(card[i]);
					cout << "Do you Want Change Diagnoz This Account (y/n) ? : ";
					char answer;
					cin >> answer;
					if (answer == 'y'){
						check = false;
						cout << "Enter New Diagnoz : ";
						cin >> card[i].diagnoz;
					}
					
					
				}
			}

			if (!check){
				cout << "Do you Want to change Data (y/n) ? : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					newFileWrite(card, size);
					cout << "Data is Update \n";
				}
				else{
					cout << "Data dont update!\n";
				}
			}
			else{
				cout << "Data Can't be Update!\n";
			}
			


		}
	}
	system("PAUSE");
}

void changePrice()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change Price.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	fstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!\n";
	}
	else{

		cout << "Please Enter Account : ";
		int account;
		cin >> account;

		if (checkAccount(account)){
			int size = getSizeCardFile();
			CardPatiet *card = new CardPatiet[size];
			file.read((char*)card, sizeof(CardPatiet)* size);
			file.close();
			bool check = true;
			for (int i = 0; i < size; i++){
				if (account == card[i].AccountNumber){
					printCard(card[i]);
					cout << "Do you Want Change Price This Account (y/n) : ";
					char answer;
					cin >> answer;
					if (answer == 'y'){
						check = false;
						cout << "Enter New Price : ";
						cin >> card[i].price;
					}
				}
			}

			if (!check){
				cout << "Do you Want to change Data (y/n) ? : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					newFileWrite(card, size);
					cout << "Data is Update \n";
				}
				else{
					cout << "Data dont update!\n";
				}
			}
			else{
				cout << "Data Can't be Update!\n";
			}

		}
	}

	system("PAUSE");
}

void changePaid()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change Paid.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!\n";
	}
	else{

		cout << "Please Enter Account : ";
		int account;
		cin >> account;

		if (checkAccount(account)){
			int size = getSizeCardFile();
			CardPatiet *card = new CardPatiet[size];
			file.read((char*)card, sizeof(CardPatiet)* size);
			file.close();
			bool check = true;
			for (int i = 0; i < size; i++){
				if (account == card[i].AccountNumber){
					printCard(card[i]);
					cout << "Do you Want Change Paid this Account (y/n) ? : ";
					char answer;
					cin >> answer;
					if (answer == 'y'){
						check = false;
						cout << "y - Yes\n n - No \n Enter New Paid : ";

						cin >> answer;
						if (answer == 'y'){
							card[i].Paid = true;
						}
						else{
							card[i].Paid = false;
						}
					}

					
				}
			}


			cout << "Do you Want to change Data (y/n) ? : ";
			char answer;
			cin >> answer;
			if (answer == 'y'){
				newFileWrite(card, size);
				cout << "Data is Update \n";
			}
			else{
				cout << "Data dont update!\n";
			}


		}
	}

	system("PAUSE");
}




void sortedPrice()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Sorted Price.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Card.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!\n";
	}
	else{
		int size = getSizeCardFile();
		CardPatiet *card = new CardPatiet[size];
		file.read((char*)card, sizeof(CardPatiet)* size);
		file.close();

		for (int i = 0; i < size - 1; i++){
			for (int j = 0; j < size - i - 1; j++){
				if (card[j].price < card[j + 1].price){
					swap(card[j], card[j + 1]);
				}
			}
		}

		printCardHeader();
		for (int i = 0; i < size; i++){
			printCardContent(card[i]);
		}

	}
	system("PAUSE");
}
//new


int countClient(int ID) {
	ifstream file;
	file.open("Card.dat", ios::binary);
	int count = 0;
	if (!file){
		return count;
	}
	else{
		CardPatiet card;
		while (file.read((char*)&card, sizeof(CardPatiet))) {
			if (card.Doc_ID == ID){
				count++;
			}
		}

		return count;
	}
}

int countVisitDoctor(int ID) {
	ifstream file;
	file.open("Card.dat", ios::binary);
	int count = 0;
	if (!file){
		return count;
	}
	else{
		CardPatiet card;
		while (file.read((char*)&card, sizeof(CardPatiet))) {
			if (card.Pat_ID == ID){
				count++;
			}
		}

		return count;
	}
}

