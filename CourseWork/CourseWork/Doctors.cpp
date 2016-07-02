#include<iostream>
#include<fstream>
#include"Doctors.h"




using namespace std;

int setID()
{
	
	int MaxID1 = getMaxDoctorBackUpID();
	int MaxID2 = getMaxDoctorID();
	if (MaxID1 > MaxID2){
		return MaxID1+1;
	}
	else{
		return MaxID2+1;
	}
}


void printHeadLine()
{
	for (int i = 0; i < 80; i++){
		cout << "-";
	}
}

void fillDoctor()
{
	system("cls");
	printHeadLine();
	cout << "/t/t/t/tAdd Doctor.\n";
	printHeadLine();

	ofstream file;
	file.open("Doctors.dat",ios::binary|ios::app);
	
	if (!file){
		cout << "File is not being!";
	}
	else{

		Doctor doctor;

		cout << "Please Enter FirstName : ";
		cin >> doctor.firstName;

		cout << "Please Enter LastName : ";
		cin >> doctor.lastName;

		cout << "Format : xxxxxx-xxxxx\nPlease Enter Person-Code : ";
		do{
			cin >> doctor.personCode;
			if (checkCodeFile(doctor.personCode) || checkMistakeCode(doctor.personCode)){
				cout << "Person code is not agree\n";
				cout << "Format : xxxxxx-xxxxx\n";
				cout << "Please Repeat Enter : ";
			}

		} while (checkCodeFile(doctor.personCode)||checkMistakeCode(doctor.personCode));

		cout << "Please Enter Post : ";
		cin >> doctor.post;

		cout << "Please Enter City : ";
		cin >> doctor.city;

		doctor.ID = setID();

		system("cls");
		file.write((char*)&doctor, sizeof(Doctor));
		cout << "Data Was Write!";
	}

	file.close();
	system("Pause");
	system("cls");

}
/*

	View

*/



void printHeader()
{
	printLine();

	cout << "| ID |" << "    FirstName   |" << "    LastName    |" << " Person-Code |" << "   Post   |" << "    City    |\n";
	printLine();
}

void printDoctor(Doctor doctor){
	cout << " ----------------------------------------------\n";
	cout << " ID : " << doctor.ID << endl;
	cout << " FirstName : " << doctor.firstName << endl;
	cout << " LastName : " << doctor.lastName << endl;
	cout << " Person-Code : " << doctor.personCode << endl;
	cout << " Post :" << doctor.post << endl;
	cout << " City : " << doctor.city << endl;
	cout << " ----------------------------------------------\n";
}

void printContent(Doctor doctor)
{
	cout << "|";
	cout.width(4);
	cout << doctor.ID;
	
	cout << "|";
	cout.width(16);
	cout << doctor.firstName;

	cout << "|";
	cout.width(16);
	cout << doctor.lastName;

	cout << "|";
	cout.width(13);
	cout << doctor.personCode;

	cout << "|";
	cout.width(10);
	cout << doctor.post;

	cout << "|";
	cout.width(12);
	cout << doctor.city << "|\n";
	printLine();
	



	
}

void printLine()
{
	for (int i = 0; i < 78; i++)
		cout << "-";
	cout << endl;
}

void filtPost(char post[10]){
	
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Filtr Post.\n";
	printHeadLine();


	ifstream file;
	
	file.open("Doctors.dat",ios::binary);

	if (!file){
		cout << "Not Data!";
	}
	else{
		if (checkDoctorPost(post)){
			Doctor doctor;
			printHeader();
			
			while (file.read((char*)&doctor, sizeof(Doctor))){
				if (strcmp(post, doctor.post) == 0){
					printContent(doctor);
				}
			}
			


		}
		else{
			cout << "Not Data!";
		}
	}
	file.close();
	system("Pause");
}

void filtrCity(char city[12])
{

	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Filtr City.\n";
	printHeadLine();
	ifstream file;

	file.open("Doctors.dat", ios::binary);
	if (!file){
		cout << "Not Data!";
	}
	else{

		if (!checkDoctorCity(city)){
			Doctor doctor;
			printHeader();
			
			while (file.read((char*)&doctor, sizeof(Doctor))){
				if (strcmp(city,doctor.city) == 0){
					printContent(doctor);
				}
			}

		}
		else{
			cout << "Not Data!";
		}
	}

	file.close();
	system("PAUSE");
}

/*

	ChangeDoctors

*/

void changeFirstName()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change FirstName.";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		cout << "File Dont Open!";
	}
	else{

		Doctor *doctor = new Doctor[getSizeFile()];
		file.read((char*)doctor, sizeof(Doctor)* getSizeFile());
		file.close();

		cout << "Enter ID : ";
		int ID;
		cin >> ID;

		for (int i = 0; i < getSizeFile(); i++)
		{
			if (ID == doctor[i].ID){
				printDoctor(doctor[i]);
				cout << "if you want to change firstname Doctor then press button enter";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					cout << "Enter new FirtName : ";
					cin >> doctor[i].firstName;
				}
			}
		}


		cout << "\n\nif you want to change data please press button y \n";
		char answer;
		cin >> answer;
		if (answer == 'y'){
			newFileWrite(doctor, getSizeFile());
			cout << "Data is Change\n";
		}
	}

	system("PAUSE");
}
void changeLastName()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change FirstName.";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		cout << "File Dont Open!";
	}
	else{

		Doctor *doctor = new Doctor[getSizeFile()];
		file.read((char*)doctor,sizeof(Doctor) * getSizeFile());
		file.close();

		cout << "Enter ID : ";
		int ID;
		cin >> ID;

		for (int i = 0; i < getSizeFile(); i++)
		{
			if (ID == doctor[i].ID){
				printDoctor(doctor[i]);
				cout << "if you want to change lastname Doctor then press button y : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					cout << "\nEnter new LastName : ";
					cin >> doctor[i].lastName;
				}
			}
		}


		cout << "if you want to change data please press button Enter \n";
		char answer;
		cin >> answer;
		if (answer == 'y'){
			newFileWrite(doctor, getSizeFile());
			cout << "Data is Change";
		}





	}

	system("PAUSE");
}

void changePost()
{

	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change Post.";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Doctors.dat",ios::binary);
	if (!file){
		cout << "File Dont Open!\n";
		file.close();
	}
	else{

		Doctor *doctor = new Doctor[getSizeFile()];
		file.read((char*)doctor, sizeof(Doctor)* getSizeFile());
		file.close();

		cout << "Please Enter ID : ";
		int ID;
		cin >> ID;
		for (int i = 0; i < getSizeFile(); i++){
			if (ID == doctor[i].ID){
				printDoctor(doctor[i]);
				cout << "if you want to change post Doctor then press y : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					cout << "Enter new Post : ";
					cin >> doctor[i].post;
				}

			}
		}


		cout << "if you want to change data please press button y : ";
		char answer;
		cin >> answer;
		if (answer == 'y'){
			newFileWrite(doctor, getSizeFile());
			cout << "Data is Change";
		}



	}

	system("PAUSE");
}

void changeCity(){

	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change FirstName.";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		cout << "File Dont Open\n";
	}
	else{

		cout << "Enter ID Doctor : ";
		int ID;
		cin >> ID;

		Doctor *doctor = new Doctor[getSizeFile()];
		
		file.read((char*)doctor,sizeof(Doctor) * getSizeFile());

		for (int i = 0; i < getSizeFile(); i++) {
			if (ID == doctor[i].ID){
				printDoctor(doctor[i]);
				cout << "if you want to change City Doctor then Please press button Enter\n";
				char answer; cin >> answer;
				if (answer == 'y'){
					cout << "Enter New City";
					cin >> doctor[i].city;
				}
			}
		}


		cout << "if you want to change data then press button y : ";
		char answer; cin >> answer;
		if (answer == 'y') {
			newFileWrite(doctor, getSizeFile());
			cout << "Data was Change!\n";
		}


	}
	system("PAUSE");
}

void changePersonCode()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Change PersonCode.";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Doctors.dat",ios::binary);

	if (!file){
		cout << "file dont open!\n ";
	}
	else{
		int ID;
		cout << "Please Enter ID : ";
		cin >> ID;

		Doctor *doctor = new Doctor[getSizeFile()];
		file.read((char*)doctor, sizeof(Doctor)* getSizeFile());
		file.close();

		for (int i = 0; i < getSizeFile(); i++){

			if (ID == doctor[i].ID){
				cout << "Do you Want change Person-Code this Doctor, press button y ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					cout << "Please Enter Person-Code (Format 124567-29309) : ";
					do{
						cin >> doctor[i].personCode;
						if (checkCodeFile(doctor[i].personCode)|| checkMistakeCode(doctor[i].personCode)){
							cout << "Person code is not agree\n";
							cout << "Format : 141155-05847\n";
							cout << "Please Repeat Enter : ";
						}

					} while (checkCodeFile(doctor[i].personCode) || checkMistakeCode(doctor[i].personCode));

				}
			}

			
			

			
		}

		cout << "Do you Want to Change Data? (y/n) : ";
		char answer;
		cin >> answer;
		if (answer == 'y'){
			newFileWrite(doctor, getSizeFile());
			cout << "Data Is Change!";
		}

	}
	system("PAUSE");
}


void newFileWrite(Doctor *doctor, int size)
{
	ofstream newFile;
	newFile.open("Doctors.dat", ios::binary);
	for (int i = 0; i < size; i++){
		newFile.write((char*)&doctor[i], sizeof(Doctor));
	}
	newFile.close();
}

/*

	Delete
	 
*/

void deleteDoctorByID()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Delete Doctor.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		cout << "File Is Wrong\n";
	}
	else{
		Doctor *doctor = new Doctor[getSizeFile()];

		file.read((char*)doctor, sizeof(Doctor)* getSizeFile());
		file.close();

		int ID;
		int size = getSizeFile();

		cout << "Please Enter ID : ";
		cin >> ID;

		ofstream newFile;
		newFile.open("Doctors.dat", ios::binary);
		
		bool check = false;
		for (int i = 0; i < size; i++)
		{
			if (ID == doctor[i].ID){
				printDoctor(doctor[i]);
				cout << "\nDo You Want Delete This Doctors , if Yes then Answer y : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					cout << "Doctor is Delete!\n";
					writeBackUp(doctor[i]);
					check = true;
					system("PAUSE");
				}
				else{
					newFile.write((char*)&doctor[i],sizeof(Doctor));
				}

			}
			else{
				newFile.write((char*)&doctor[i], sizeof(Doctor));
			}
		}

		newFile.close();
		if (check == false){
			cout << "Doctor With ID " << ID << " dont Find! ";
		}







	}

	system("Pause");
}

void deleteDoctorByCode()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Delete Doctor.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Doctors.dat", ios::binary);
	if (!file){
		cout << "File is Wrong!\n";
	}
	else{
		Doctor *doctor = new Doctor[getSizeFile()];

		file.read((char*)doctor, sizeof(Doctor) * getSizeFile());
		file.close();
		int size = getSizeFile();
		char personCode[13];
		cin >> personCode;

		ofstream newFile;
		newFile.open("Doctors.dat",ios::binary);
		bool check = false;
		for (int i = 0; i < size; i++){
			if (strcmp(doctor[i].personCode, personCode) == 0){
				
				printDoctor(doctor[i]);
				cout << "\nDo You Want Delete This Doctors , if Yes then y : ";
				char answer;
				cin >> answer;
				if (answer == 'y'){
					cout << "Doctor is Delete!\n";
					writeBackUp(doctor[i]);
					check = true;
					system("PAUSE");
				}
				else{
					newFile.write((char*)&doctor[i], sizeof(Doctor));
				}

			}
			else{
				newFile.write((char*)&doctor[i],sizeof(Doctor));
			}
		}
		newFile.close();
		if (check == false) {
			cout << "Doctor dont Found!\n";
		}





	}

	system("PAUSE");
}

/*

	Find	

*/

void findDoctorID()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Find Doctor.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	cout << "Please Enter ID :";
	unsigned int ID;
	cin >> ID;

	Doctor doctor = findDoctor(ID);

	if (doctor.ID != -1){
		printDoctor(doctor);
	}
	else{
		cout << "Doctor with ID " << ID << " is not found ";
	}

	system("PAUSE");
}

void findDoctorCode()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Find Doctor.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	cout << "Please Enter Person-Code. Format 123498-98234 : ";
	char personCode[13];
	cin >> personCode;

	Doctor doctor = findDoctor(personCode);

	if (doctor.ID != -1){
		printDoctor(doctor);
	}
	else{
		cout << "Doctor With Person-Code, " << personCode << "Is not Found!";
	}
	system("PAUSE");
}

/*

	filtr

*/


void filtrDoctorPost()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Filtr Post.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	cout << "Please Enter Post : ";
	char post[10];
	cin >> post;
	filtPost(post);
	system("PAUSE");
}

void filtrDoctorCity()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Filtr City.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	cout << "Please Enter Name City : ";
	char city[12];
	cin >> city;

	filtrCity(city);
	system("PAUSE");
}

void sortedLastName()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Sorted LastName Doctor.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	ifstream file;
	file.open("Doctors.dat", ios::binary);
	if (!file){
		cout << "File is Wrong!\n";
	}
	else{
		int size = getSizeFile();
		Doctor *doctor = new Doctor[size];

		file.read((char*)doctor, sizeof(Doctor) * size);
		file.close();

		
		bool check = true;
		for (int i = 0; i < size - 1 && check; i++){
			check = false;
			for (int j = 0; j < size - i - 1; j++){
				if (tolower(doctor[j].lastName[0]) > tolower(doctor[j + 1].lastName[0])){
					check = true;
					swap(doctor[j], doctor[j + 1]);
				}
			}
		}

		printHeader();
		for (int i = 0; i < size; i++){
			printContent(doctor[i]);
		}

	}

	file.close();
	system("PAUSE");
}
//проверить
void sortedFirstName()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Sorted FirstName Doctor.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Doctors.dat", ios::binary);
	if (!file){
		cout << "File is Wrong!\n";
	}
	else{
		int size = getSizeFile();
		Doctor *doctor = new Doctor[size];

		file.read((char*)doctor, sizeof(Doctor)* size);
		file.close();

		//bool check = true;
		for (int i = 0 ; i < size - 1 ; i++){
			//check = false;
			for (int j = 0; j < size - i - 1; j++){
				if (tolower(doctor[j ].firstName[0]) > tolower(doctor[j+1].firstName[0])){
					//check = true;
					swap(doctor[j], doctor[j+1]);
				}
			}
		}

		printHeader();
		for (int i = 0; i < size; i++){
			printContent(doctor[i]);
		}

	}

	file.close();
	system("PAUSE");
}


/*

	Private Function

*/
int getSizeFile()
{
	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		file.close();
		return 0;
	}
	else{

		file.seekg(0, ios::end);
		int size = file.tellg();
		size /= sizeof(Doctor);
		file.seekg(0, ios::beg);
		file.close();
		return size;

	}
}



bool checkDoctorCity(char city[12])
{
	ifstream file;
	file.open("Doctor.dat", ios::binary);

	Doctor doc;
	
	while (file.read((char*)&doc, sizeof(Doctor)))
	{

		if (strcmp(city, doc.city) == 0){
			return true;
		}
	}

	return false;

}
bool checkDoctorPost(char post[10])
{
	ifstream file;
	file.open("Doctors.dat", ios::binary);
	Doctor *doc = new Doctor[getSizeFile()];

	file.read((char*)doc, getSizeFile() * sizeof(Doctor));

	for (int i = 0; i < getSizeFile(); i++)
	{
		if (strcmp(post, doc[i].post) == 0){
			return true;
		}
	}

	return false;
}
bool checkCodeFile(char code[13])
{
	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		return false;
	}
	else{
		Doctor doctor;
		while (file.read((char*)&doctor, sizeof(Doctor))){
			if (strcmp(code, doctor.personCode) == 0){
				return true;
			}
		}

		return false;
	}
}


Doctor findDoctor(int ID)
{
	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		Doctor doctor = { -1, "", "", "", "", "" };
		return  doctor;
	}
	else{
		Doctor doctor;
		while (file.read((char*)&doctor, sizeof(Doctor))){
			if (ID == doctor.ID){
				return doctor;
			}
		}

		doctor = { -1, "", "", "", "", "" };
		return doctor;
		
	}
}

Doctor findDoctor(char code[13])
{
	ifstream file;
	file.open("Doctors.dat", ios::binary);

	if (!file){
		Doctor doctor = { -1, "", "", "", "", "" };
		return  doctor;
	}
	else{
		Doctor doctor;
		while (file.read((char*)&doctor, sizeof(Doctor))){
			if (strcmp(code,doctor.personCode) == 0){
				return doctor;
			}
		}

		doctor = { -1, "", "", "", "", "" };
		return doctor;

	}
}


void showAllData()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t Show Doctors.\n";
	printHeadLine();
	cout << "\n\n\n\n";
	ifstream file;
	file.open("Doctors.dat", ios::binary);
	if (!file){
		cout << "Error";
	}
	else{
		printHeader();
		Doctor doctor;
		while (file.read((char*)&doctor, sizeof(Doctor))){
			printContent(doctor);
		}
	}
	file.close();
	system("PAUSE");
}
/*

	New Func

*/

void writeBackUp(Doctor doctor)
{
	ofstream file;
	file.open("DoctorsBackUp.dat", ios::binary | ios::app);
	//if (!file) {
		//cout << "File is Wrong\n";
	//}
	//else{
		file.write((char*)&doctor,sizeof(Doctor));
	//	cout << "File Was Write!\n";
	//}

	file.close();
}

int getDoctorBackupFile()
{
	ifstream file;
	file.open("DoctorsBackUp.dat",ios::binary);

	if (!file){
		return 0;
	}
	else{
		file.seekg(0,ios::end);
		int size = file.tellg();
		file.seekg(0,ios::beg);

		return size / sizeof(Doctor);
	}
	
}

int getMaxDoctorBackUpID()
{
	ifstream file;
	file.open("DoctorsBackUp.dat",ios::binary);
	if (!file){
		return 0;
	}
	else{
		int size = getDoctorBackupFile();
		if (size == 0){
			return 0;
		}
		else{
			Doctor *doctor = new Doctor[size];
			file.read((char*)doctor,sizeof(Doctor) * size);
			file.close();
			int maxID = doctor[0].ID;
			for (int i = 1; i < size; i++) {
				if (doctor[i].ID > maxID){
					maxID = doctor[i].ID;
				}
			}

			return maxID;
		}

		

	}
}

int getMaxDoctorID()
{
	ifstream file;
	file.open("Doctors.dat",ios::binary);
	if (!file){
		return 0;
	}
	else{
		int size = getSizeFile();
		if (size == 0){
			return 0;
		}
		else{
			Doctor *doctor = new Doctor[size];
			file.read((char*)doctor,sizeof(Doctor) * size);
			file.close();
			int maxID = doctor[0].ID;
			for (int i = 1; i < size; i++){
				if (doctor[i].ID > maxID){
					maxID = doctor[i].ID;
				}
			}

			return maxID;
			
		}
	}
	
}

void showBackUpDoc()
{
	ifstream file;
	file.open("DoctorsBackUp.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong\n";
	}
	else{
		if (getDoctorBackupFile() == 0){
			cout << "File is Empty!\n";
		}
		else{
			Doctor doctor;
			printHeader();
			while (file.read((char*)&doctor, sizeof(Doctor))){
				printContent(doctor);
			}

		}
	}
	file.close();
	system("PAUSE");
	
}

Doctor getBackUpDoctor(int ID)
{
	ifstream file;
	file.open("DoctorsBackUp.dat", ios::binary);
	if (!file){
		return Doctor{ -1, "", "", "", "", "" };
	}
	else{
		Doctor doctor;
		while (file.read((char*)&doctor, sizeof(Doctor))){
			if (ID == doctor.ID){
				return doctor;
			}
		}

		return Doctor{ -1, "", "", "", "", "" };
	}


}

Doctor getBackUpDoctor(char code[13])
{

	ifstream file;
	file.open("DoctorsBackUp.dat", ios::binary);
	if (!file){
		return Doctor{ -1, "", "", "", "", "" };
	}
	else{
		Doctor doctor;
		while (file.read((char*)&doctor, sizeof(Doctor))){
			if (strcmp(code,doctor.personCode) == 0){
				return doctor;
			}
		}

		return Doctor{ -1, "", "", "", "", "" };
	}
}

void findBackUpDoctorID()
{
	system("cls");
	printHeadLines();
	cout << "\t\t\t\t Find BackUp Patient.\n";
	printHeadLines();
	cout << "\n\n\n\n";

	cout << "Please Enter ID Doctor : ";
	int ID;
	cin >> ID;

	Doctor doctor = getBackUpDoctor(ID);
	if (doctor.ID == -1){
		cout << "Dont Found!\n";
	}
	else{
		printDoctor(doctor);
	}


	system("PAUSE");
}
void findBackUpDoctorCode()
{
	system("cls");
	printHeadLines();
	cout << "\t\t\t\t Find BackUp Patient.\n";
	printHeadLines();
	cout << "\n\n\n\n";

	char code[13];

	cout << "Please Enter Person Code : ";
	cin >> code;

	Doctor doctor = getBackUpDoctor(code);

	if (doctor.ID == -1){
		cout << "Dont Found!\n";
	}
	else{
		printDoctor(doctor);
	}
	system("PAUSE");
}

void printHeadLines()
{
	for (int i = 0; i < 80; i++)
	{
		cout << "-";
	}
}

void returnOldDoctor()
{
	ifstream file;
	file.open("DoctorsBackUp.dat", ios::binary);
	if (!file){
		cout << "File Is Wrong!\n";
	}
	else{
		int size = getDoctorBackupFile();
		Doctor *doctor = new Doctor[size];
		file.read((char*)doctor, sizeof(Doctor)* size);
		file.close();

		cout << "Please Enter ID Doctor : ";
		int ID;
		cin >> ID;

		Doctor fdoctor = getBackUpDoctor(ID);
		if (fdoctor.ID == -1){
			cout << "Dont Found!\n";
		}
		else{
			printDoctor(fdoctor);
			cout << "Do you Want Return This Doctor (y/n) ? : ";
			char answer;
			cin >> answer;

			if (answer == 'y'){
				ofstream file1, file2;
				file1.open("Doctors.dat",ios::binary|ios::app);
				file1.write((char*)&fdoctor, sizeof(Doctor));
				file1.close();

				file2.open("DoctorsBackUp.dat",ios::binary);
				for (int i = 0; i < size; i++){
					if (doctor[i].ID != fdoctor.ID){
						file2.write((char*)&doctor[i], sizeof(Doctor));
					}
				}
				file2.close();


				cout << "Data Is change!\n";

			}
			else{
				cout << "Data Dont Change!\n";
			}

		}

	}

	system("PAUSE");
}