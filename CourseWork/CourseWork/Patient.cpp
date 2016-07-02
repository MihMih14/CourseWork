#include"Patient.h"
#include<iostream>
#include<fstream>

using namespace std;

void printHeadOnLine()
{
	for (int i = 0; i < 80; i++){
		cout << "-";
	}
}

void printPatient(Patient patient)
{
	cout << " ----------------------------------------------\n";
	cout << " ID : " << patient.ID << endl;
	cout << " FirstName : " << patient.firstName << endl;
	cout << " LastName : " << patient.lastName << endl;
	cout << " Sex : " << getSex(patient) << endl;
	cout << " Person-Code : " << patient.personCode << endl;
	cout << " City : " << patient.city << endl;
	cout << " ----------------------------------------------\n";
}

char* getSex(Patient patient)
{
	return patient.sex ? "Male" : "Famale";
}
void printPatientLine()
{
	for (int i = 0; i < 79; i++){
		cout << "-";
	}
	cout << endl;
}
void printPatientHeader()
{
	printPatientLine();
	cout << "| ID " << "|    FirstName    " << "|     LastName     " << "|  Sex  " << "| Person-Code " << "|    City    |\n";
	printPatientLine();
}

void printContent(Patient patient)
{
	cout << "|";
	cout.width(4);
	cout << left << patient.ID;

	cout << "|";
	cout.width(18);
	cout << left << patient.firstName;

	cout << "|";
	cout.width(18);
	cout << left << patient.lastName;

	cout << "|";
	cout.width(7);
	cout << left << getSex(patient);

	cout << "|";
	cout.width(13);
	cout << left << patient.personCode;

	cout << "|";
	cout.width(12);
	cout << patient.city;
	cout << "|\n";
	printPatientLine();
}

int getPatientSizeFile()
{
	ifstream file;
	file.open("Patients.dat", ios::binary);
	if (!file){
		file.close();
		return 0;
	}
	else{
		file.seekg(0, ios::end);
		int size = file.tellg();
		file.seekg(0, ios::beg);
		file.close();

		return size / sizeof(Patient);
	}
}


void newFileWrite(Patient *patient,int size)
{
	ofstream file;
	file.open("Patients.dat", ios::binary);
	for (int i = 0; i < size; i++)
	{
		file.write((char*)&patient[i],  sizeof(Patient));
	}
	file.close();
	cout << "\n Data Was Update!\n";
}

int setPatientID()
{
	
	int maxID = getMaxPatientID();
	int maxBackUpID = getMaxPatientBackUpID();

	return maxID > maxBackUpID  ? maxID + 1 : maxBackUpID + 1;
	
}



bool checkPersonCodeFile(char code[13])
{
	ifstream file;
	file.open("Patients.dat",ios::binary);
	if (!file){
		return false;
	}
	else{
		int size = getPatientSizeFile();
		Patient patient;
		while (file.read((char*)&patient, sizeof(Patient))){
			if (strcmp(code, patient.personCode) == 0){
				return true;
			}
		}

		return false;
	}
}

void fillPatient()
{
	system("cls");
	printHeadOnLine();
	cout << "\t\t\t\t Add Patient.\n";
	printHeadOnLine();
	cout << "\n\n\n\n";

	ofstream file;
	file.open("Patients.dat",ios::binary|ios::app);
	if (!file){
		cout << "File Is Wrong!\n";
	}
	else{
		Patient patient;

		cout << " Please Enter FirstName Patient : ";
		cin >> patient.firstName;

		cout << " Please Enter LastName Patient : ";
		cin >> patient.lastName;

		cout << " m - Male\n f - famale\n Please Enter Sex : ";
		char sex;
		cin >> sex;
		if (sex == 'm'){
			patient.sex = true;
		}
		else{
			patient.sex = false;
		}

		cout << " Format xxxxxx-xxxxx \n Please Enter PersonCode Patient : ";
		do{
			cin >> patient.personCode;
			if (checkPersonCodeFile(patient.personCode) || checkMistakeCode(patient.personCode)){
				cout << "Mistake! Please Repeat Enter : ";
			}
		} while (checkPersonCodeFile(patient.personCode) || checkMistakeCode(patient.personCode));

		cout << " Please Enter City : ";
		cin >> patient.city;

		patient.ID = setPatientID();

		system("cls");
		system("cls");
		printHeadOnLine();
		cout << "\t\t\t\t Add Patient.\n";
		printHeadOnLine();
		cout << "\n\n\n\n";

		printPatient(patient);
		cout << "\nDo you Want To Write Data ? (y/n) : ";
		char answer;
		cin >> answer;

		if (answer == 'y'){
			file.write((char*)&patient, sizeof(Patient));
			cout << "Patient Was Write!";
		}

		system("PAUSE");
	}

	file.close();
}

Patient getPatient(int ID)
{
	ifstream file;
	file.open("Patients.dat", ios::binary);
	if (!file){
		return Patient{ -1, "", "", "", "", false };
	}
	else{
		Patient patinet;
		while (file.read((char*)&patinet, sizeof(Patient))){
			if (ID == patinet.ID){
				return patinet;
			}
		}
		return Patient{ -1, "", "", "", "", false };
	}


}

Patient getPatient(char personCode[13])
{
	ifstream file;
	file.open("Patients.dat", ios::binary);
	if (!file){
		return Patient{ -1, "", "", "", "", false };
	}
	else{
		Patient patient;
		while (file.read((char*)&patient, sizeof(Patient))){
			if (strcmp(personCode, patient.personCode) == 0){
				return patient;
			}
		}

		return Patient{ -1, "", "", "", "", false };
	}
}

void findPatientByID()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Find Patient By ID.\n";
	printHeadsLines();
	cout << "\n\n\n\n";

	cout << "Please Enter ID : ";
	int ID;
	cin >> ID;
	Patient patient = getPatient(ID);
	if (patient.ID == -1){
		cout << "Patient With ID " << ID << " - Don't Found !\n";
	}
	else{
		printPatient(patient);
	}
	system("PAUSE");
}

void findPatientByCode()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Find Patient By Code.\n";
	printHeadsLines();
	cout << "\n\n\n\n";

	cout << "Format: xxxxxx-xxxxx\nPlease Enter Person-Code : ";
	char personCode[13];
	cin >> personCode;

	Patient patient = getPatient(personCode);

	if (patient.ID == -1){
		cout << "Patietn With Person-Code " << personCode << "Dont Found!\n";
	}
	else{
		printPatient(patient);
	}
	system("PAUSE");
}



void filtrByMan()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Filtr Patient By Men.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat",ios::binary);

	if (!file){
		cout << "File is Wrong!";
	}
	else{
		Patient patient;
		if (countMan() > 0){
			printPatientHeader();
			while (file.read((char*)&patient, sizeof(Patient))){
				if (patient.sex){
					printContent(patient);
				}
			}
		}
		else{
			cout << "There not Men\n";
		}
	}

	file.close();
	system("PAUSE");
}

void showAllPatient()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Show All Patient.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat", ios::binary);

	if (!file){
		cout << "In DataBase Not Patient!";
	}
	else{
		Patient patient;
		printPatientHeader();
		while (file.read((char*)&patient, sizeof(Patient))){
			printContent(patient);
		}
	}

	file.close();
	system("PAUSE");
}

void filtrByWomen()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Filtr Patient By Women.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat",ios::binary);

	if (!file){
		cout << "File is Wrong!\n";
	}
	else{
		Patient patient;

		if (countWomen() > 0){
			printPatientHeader();
			while (file.read((char*)&patient, sizeof(Patient))){
				if (!patient.sex){
					printContent(patient);
				}
			}
		}
		else{
			cout << "There not A Women!";
		}
	}

	file.close();
	system("PAUSE");
}

void filtrPatientCity(char city[12])
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Filtr Patient By City.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat", ios::binary);
	if (!file){
		cout << "File is Wrong!\n";
	}
	else{
		Patient patient;
		printPatientHeader();
		while (file.read((char*)&patient, sizeof(Patient))){
			if (strcmp(city, patient.city) == 0){
				printContent(patient);
			}
		}
	}
	file.close();
	
}

void filtrPatientCity()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Filtr Patient By City.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	cout << "Please Enter City : ";
	char city[12];
	cin >> city;

	filtrPatientCity(city);
	system("PAUSE");
}

int countMan()
{
	ifstream file;
	file.open("Patients.dat",ios::binary);

	if (!file){
		return 0;
	}
	else{
		Patient patient;
		int count = 0;
		while (file.read((char*)&patient, sizeof(Patient))){
			if (patient.sex){
				count++;
			}
		}

		return count;
	}
}

int countWomen()
{
	ifstream file;
	file.open("Patients.dat",ios::binary);
	if (!file){
		return 0;
	}
	else{
		Patient patient;
		int count = 0;
		while (file.read((char*)&patient, sizeof(Patient))){
			if (!patient.sex){
				count++;
			}
		}
		file.close();
		return count;
	}

}

void sortedByFirstName()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Sorted Patient By FirstName.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;

	file.open("Patients.dat", ios::binary);
	if (!file){
		cout << "File is Wrong!\n";
	}
	else{

		int size = getPatientSizeFile();

		Patient *patient = new Patient[size];

		file.read((char*)patient, sizeof(Patient)* size);
		file.close();

		bool check = true;
		for (int i = 0; i < size && check; i++){
			check = false;
			for (int j = 0; j < size - i - 1; j++){
				check = true;
				if (tolower(patient[j].firstName[0]) > tolower(patient[j + 1].firstName[0])){
					swap(patient[j], patient[j + 1]);
				}
			}

		}

		
		printPatientHeader();
		for (int i = 0; i < size; i++){
			printContent(patient[i]);
		}
		





	}

	
	system("PAUSE");
}

void sortedByLastName()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Sorted Patient By LastName.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat",ios::binary);
	if (!file){
		cout << "File Is Wrong!";
	}
	else{

		int size = getPatientSizeFile();

		Patient *patient = new Patient[size];

		file.read((char*)patient, sizeof(Patient)* size);
		file.close();

		bool check = true;
		for (int i = 0; i < size || check; i++){
			check = false;
			for (int j = 0; j < size - i - 1; j++){
				if (tolower(patient[j].lastName[0]) > tolower(patient[j + 1].lastName[0])){
					check = true;
					swap(patient[j], patient[j + 1]);
				}
			}
		}


		printPatientHeader();
		for (int i = 0; i < size; i++){
			printContent(patient[i]);

		}

	}

	system("PAUSE");
}

void deletePacient(int ID){
	
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Delete Patient By Person Code.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat", ios::binary);

	if (!file){
		cout << "File Is Wrong\n";
	}
	else{

		int size = getPatientSizeFile();
		Patient *patient = new Patient[size];
		file.read((char*)patient, sizeof(Patient)* size);
		file.close();

		ofstream newFile;
		newFile.open("Patients.dat", ios::binary);

		for (int i = 0; i < size; i++){
			if (patient[i].ID != ID){
				newFile.write((char*)&patient[i], sizeof(Patient));
			}
			else{
				printPatient(patient[i]);
				cout << "Do you Want Delete This Patients ? (y/n) : ";
				char answer;
				cin >> answer;
				if (answer != 'y'){
					newFile.write((char*)&patient[i], sizeof(Patient));
					
				}
				else{
					cout << "Pacient is Delete! \n";
					writeBackUp(patient[i]);
				}
			}
		}

		newFile.close();

	}

	
}

void deletePacient(char code[13])
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Delete Patient By Person Code.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat",ios::binary);

	if (!file){
		cout << " File is Wrong! ";
	}
	else{

		int size = getPatientSizeFile();

		Patient *patient = new Patient[size];

		file.read((char*)patient,sizeof(Patient) * size);
		file.close();

		ofstream newFile;
		newFile.open("Patients.dat", ios::binary);

		for (int i = 0; i < size; i++){

			if (strcmp(code, patient[i].personCode) == 0){
				
				printPatient(patient[i]);
				cout << "Do you Want to Delete This Patient ? (y/n) : ";
				char answer;
				cin >> answer;
				if (answer == 'n'){
					newFile.write((char*)&patient[i], sizeof(Patient));
					
				}
				else{
					cout << "Pacient is Delete! \n";
					writeBackUp(patient[i]);
				}
				
			}
			else{
				newFile.write((char*)&patient[i], sizeof(Patient));
			}
			newFile.close();


		}
	}
}


void deletePacientByID()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Delete Patient By ID.\n";
	printHeadsLines();
	cout << "\n\n\n\n";

	cout << "Please Enter ID : ";
	int ID;
	cin >> ID;
	deletePacient(ID);
	system("PAUSE");
}

void deletePacientByCode()
{
	
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Delete Patient By Person Code.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	cout << "Formart : xxxxxx-xxxxx\nPlease Enter Person-Code : ";
	char personcode[13];
	cin >> personcode;
	deletePacient(personcode);
	system("PAUSE");
}

void changePatientPersonCode()
{

	
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Change Patient Person Code.\n";
	printHeadsLines();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Patients.dat",ios::binary);

	if (!file){
		cout << "File is Wrong\n";
	}
	else{
		cout << "Please Enter ID : ";
		int ID;
		cin >> ID;

		int size = getPatientSizeFile();

		Patient *patient = new Patient[size];
		file.read((char*)patient, sizeof(Patient)* size);
		file.close();
		bool check = true;
		for (int i = 0; i < size ; i++)
		{
			if (ID == patient[i].ID){
				
				printPatient(patient[i]);
				cout << "Do you Want Change Person-Code  (y/n) ? : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					check = false;
					cout << "Please Enter New Person-Code : ";
					do{
						cin >> patient[i].personCode;
						if (checkPersonCodeFile(patient[i].personCode) || checkMistakeCode(patient[i].personCode)){
							cout << "Format : xxxxxx-xxxxx\nMistake!\nPlease Repeat Enter : ";
						}
					} while (checkPersonCodeFile(patient[i].personCode) || checkMistakeCode(patient[i].personCode));
				}

			}

			
		}
		newFileWrite(patient, size);

		if (!check){
			cout << "Data Change!\n";
		}
		else{
			cout << "Data Dont Change!";
		}
	}

	system("PAUSE");
}

void changePatientFirstName()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Change Patient FirstName.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat",ios::binary);
	if (!file) {
		cout << "File is Wrong!\n";
	}
	else{
		cout << "Please Enter ID :";
		int ID;
		cin >> ID;

		int size = getPatientSizeFile();
		Patient *patient = new Patient[size];

		file.read((char*)patient, sizeof(Patient) * size);
		file.close();

		bool check = true;
		for (int i = 0; i < size ; i++){
			if (patient[i].ID == ID){
				printPatient(patient[i]);
				cout << "\nDo You Want To Change This Patient FirstName (y/n) ? : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					check = false;
					cout << "Please Enter New FirstName : ";
					cin >> patient[i].firstName;
				}
				
			}
		}

		if (!check){
			cout << "Do you Want to Change Data (y/n)? : ";
			char answer;
			cin >> answer;

			if (answer == 'y'){
				newFileWrite(patient, size);
				cout << "Data Was Update!\n";
			}
			else{
				cout << "Data didnt update!\n";
			}

		}
		else{
			cout << "Data didnt update!\n";
		}

	}

	system("PAUSE");

}

void changePatientCity()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Change Patient City.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat",ios::binary);
	if (!file){
		cout << "File Is Wron\n";
	}
	else{

		cout << "Please Enter ID : ";
		int ID;
		cin >> ID;

		int size = getPatientSizeFile();

		Patient *patient = new Patient[size];
		file.read((char*)patient,sizeof(Patient) * size);
		file.close();
		bool check = true;
		for (int i = 0; i < size ; i++){
			if (ID == patient[i].ID){
				printPatient(patient[i]);
				cout << "\n Do You Want Change This Patient (y/n) ? : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					check = false;
					cout << "Please Enter New City : ";
					cin >> patient[i].city;
				}
			}
		}


		if (!check){
			cout << "Do you Want To Change Data (y/n) ? : ";
			char answer;
			cin >> answer;
			if (answer == 'y'){
				newFileWrite(patient, size);
				cout << "Data Was Change!\n";
			}
			else{
				cout << "Data Wasn't Change!\n";
			}
		}
		else{
			cout << "Data Wasn't Change!\n";
		}

	}

	system("PAUSE");
}

void changeSex()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Change Patient.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat", ios::binary);
	if (!file) {
		cout << "File is Wrong!\n";
	}
	else {


		cout << "Please Enter ID : ";
		int ID;
		cin >> ID;


		Patient changePatient = getPatient(ID);

		if (changePatient.ID != -1){
			printPatient(changePatient);
			cout << "Do you Want To Change Sex This Patient (y/n) ? : ";
			char answer;
			cin >> answer;

			if (answer == 'y'){
				cout << "Male - m\nFamale - f\nPlease Enter New Sex : ";
				char sex;
				cin >> sex;

				if (sex = 'm'){
					changePatient.sex = true;
				}
				else{
					changePatient.sex = false;
				}

				cout << "Do you Want Change Data (y/n) ? : ";
				cin >> answer;

				if (answer == 'y'){
					int size = getPatientSizeFile();
					Patient *patient = new Patient[size];
					file.read((char*)patient,sizeof(Patient) * size);
					file.close();

					bool check = true;
					for (int i = 0; i < size ; i++){
						if (changePatient.ID == patient[i].ID){
							check = false;
							patient[i].sex = changePatient.sex;
						}
					}

					newFileWrite(patient, size);
					cout << "Data Was Update!";
				}
				else{
					cout << "Data Dont Update!\n";
				}
			}
			else{
				cout << "Patient Not Found! ";
			}

		}
		else{
			cout << "Patietn With ID " << ID << " Not Found! \n";
		}

	}
	system("PAUSE");
}

void changePatientLastName()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Change Patient.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Patients.dat", ios::binary);
	if (!file) {
		cout << "File is Wrong!\n";
	}
	else{
		cout << "Please Enter ID :";
		int ID;
		cin >> ID;

		int size = getPatientSizeFile();
		Patient *patient = new Patient[size];

		file.read((char*)patient, sizeof(Patient)* size);
		file.close();

		bool check = true;
		for (int i = 0; i < size ; i++){
			if (patient[i].ID == ID){
				printPatient(patient[i]);
				cout << "\nDo You Want To Change This Patient LastName (y/n) ? : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					check = false;
					cout << "Please Enter New LastName : ";
					cin >> patient[i].lastName;
				}

			}
		}

		if (!check){
			cout << "Do you Want to Change Data (y/n)? : ";
			char answer;
			cin >> answer;

			if (answer == 'y'){
				newFileWrite(patient, size);
				cout << "Data Was Update!\n";
			}
			else{
				cout << "Data didnt update!\n";
			}

		}
		else{
			cout << "Data didnt update!\n";
		}

	}

	system("PAUSE");

}
/*

* New Function.

*/
void writeBackUp(Patient patient)
{
	ofstream file;
	file.open("PatientBackUp.dat", ios::binary | ios::app);
	file.write((char*)&patient, sizeof(Patient));
	file.close();
}

int getPatientBackupFile()
{
	ifstream file;
	file.open("PatientBackUp.dat", ios::binary);
	if (!file){
		return 0;
	}
	else{
		file.seekg(0, ios::end);
		int size = file.tellg();
		file.seekg(0, ios::beg);
		file.close();

		return size / sizeof(Patient);
	}
}

int getMaxPatientBackUpID()
{
	ifstream file;
	file.open("PatientBackUp.dat",ios::binary);
	if (!file){
		return 0;
	}
	else{
		int size = getPatientBackupFile();
		if (size == 0){
			return 0;
		}
		else{
			Patient *patient = new Patient[size];

			file.read((char*)patient,sizeof(Patient) * size);
			file.close();

			int minID = patient[0].ID;

			for (int i = 1;  i < size ; i++){
				if (minID < patient[i].ID) {
					minID = patient[i].ID;
				}
				
			}

			return minID;


		}
	}
}

int getMaxPatientID()
{
	ifstream file;
	file.open("Patients.dat", ios::binary);
	if (!file){
		return 0;
	}
	else{
		int size = getPatientSizeFile();
		if (size == 0){
			return 0;
		}
		else{
			Patient *patient = new Patient[size];

			file.read((char*)patient, sizeof(Patient)* size);
			file.close();

			int maxID = patient[0].ID;

			
				for (int i = 1; i < size; i++){
					if (patient[i].ID > maxID){
						maxID = patient[i].ID;
					}
					
				}

				return maxID;
			
		

		}
	}
}

void showBackUpPat()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Show All Back-Up Patient.\n";
	printHeadsLines();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("PatientBackUp.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong\n";
	}
	else{
		Patient patient;
		int size = getPatientBackupFile();
		if (size == 0) {
			cout << "No Data!\n";
		}
		else{
			printPatientHeader();
			while (file.read((char*)&patient, sizeof(Patient))){
				printContent(patient);
			}
		}
	}

	system("PAUSE");
}

Patient getBackUpPatient(int ID)
{
	ifstream file;
	file.open("PatientBackUp.dat",ios::binary);
	if (!file){
		return Patient{ -1, "", "", "", "", false };
	}
	else{
		Patient patient;
		if (getPatientBackupFile() == 0){
			return Patient{ -1, "", "", "", "", false };
		}
		else{
			while (file.read((char*)&patient, sizeof(Patient))) {
				if (ID == patient.ID){
					return patient;
				}
			}

			return Patient{ -1, "", "", "", "", false };
		}
	}


}

Patient getBackUpPatient(char code[13])
{
	ifstream file;
	file.open("PatientBackUp.dat", ios::binary);
	if (!file){
		return Patient{ -1, "", "", "", "", false };
	}
	else{
		Patient patient;
		if (getPatientBackupFile() == 0){
			return Patient{ -1, "", "", "", "", false };
		}
		else{
			while (file.read((char*)&patient, sizeof(Patient))) {
				if (strcmp(code,patient.personCode) == 0){
					return patient;
				}
			}

			return Patient{ -1, "", "", "", "", false };
		}
	}
}

void findBackUpPatientID()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Find BackUp Patient.\n";
	printHeadsLines();
	cout << "\n\n\n\n";

	cout << "Please Enter ID : ";
	int ID;
	cin >> ID;
	Patient patient = getBackUpPatient(ID);
	if (patient.ID == -1){
		cout << "Dont Found!\n";
	}
	else{
		printPatient(patient);
	}

	system("PAUSE");
}

void findBackUpPatientCode()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Find BackUp Patient.\n";
	printHeadsLines();
	cout << "\n\n\n\n";

	cout << "Please Enter Person Code : ";
	char code[13];
	cin >> code;
	Patient patient = getBackUpPatient(code);
	if (patient.ID == -1){
		cout << "Dont Found!\n";
	}
	else{
		printPatient(patient);
	}

	system("PAUSE");
}
void printHeadsLines()
{
	for (int i = 0; i < 80; i++)
	{
		cout << "-";
	}
}

void returnOldPatient()
{
	system("cls");
	printHeadsLines();
	cout << "\t\t\t\t Return Patient.\n";
	printHeadsLines();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("PatientBackUp.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong !\n ";
	}
	else{
		int size = getPatientSizeFile();
		Patient *patient = new Patient[size];
		file.read((char*)patient, sizeof(Patient)* size);
		file.close();
		cout << "Please Enter ID : ";
		int ID;
		cin >> ID;

		Patient rPatient = getBackUpPatient(ID);
		if (rPatient.ID == -1){
			cout << "\n Dont Found!\n";
		}
		else{
			printPatient(rPatient);
			cout << "Do you Want to return This Patient (y/n) ? : ";
			char answer;
			cin >> answer;
			if (answer == 'y'){
				ofstream file1, file2;
				file1.open("Patients.dat", ios::binary | ios::app);
				file1.write((char*)&rPatient, sizeof(Patient));
				file1.close();

				int sizeBackUp = getPatientBackupFile();
				file2.open("PatientBackUp.dat",ios::binary);
				
				for (int i = 0; i < sizeBackUp; i++) {
					if (patient[i].ID != ID){
						file2.write((char*)&patient[i], sizeof(Patient));
					}
				}
				file2.close();

				cout << "Data Was Change!\n";
			}
			else{
				cout << "Data Dont Change !\n";
			}
		}
	}
}

//дописать.
bool checkMistakeCode(char code[13])
{
	if (strlen(code) < 12 || strlen(code) > 12){
		return true;
	}
	

	if (code[6] != '-'){
		return true;
	} 

	for (int i = 0; i < 6; i++){
		if (!isdigit(code[i])){
			return true;
		}
	}
	for (int i = 7; i < 12; i++){
		if (!isdigit(code[i])){
			return true;
		}
	}

	return false;
}
