struct Doctor {
	int ID;
	char firstName[16];
	char lastName[16];
	char personCode[13];
	char post[10];
	char city[12];

};


int setID();


void fillDoctor();
/*

View

*/


void printHeadLine();
void printHeader();

void printDoctor(Doctor doctor);

void printContent(Doctor doctor);

void printLine();

void filtPost(char post[10]);

/*

ChangeDoctors

*/

void changeFirstName();
void changeLastName();

void changePost();

void changeCity();

void changePersonCode();


void newFileWrite(Doctor *doctor, int size);

/*

Delete
Поменять! Примечание: Имеется функция по записи.
*/

void deleteDoctorByID();

void deleteDoctorByCode();

/*

Find

*/

void findDoctorID();

void findDoctorCode();

/*

filtr

*/


void filtrDoctorPost();
void filtrDoctorCity();

void sortedLastName();
void sortedFirstName();
//проверить
void sortedAge();

/*

Private Function

*/
int getSizeFile();

bool checkMistakeCode(char code[13]);
bool checkDoctorCity(char city[12]);
bool checkDoctorPost(char post[10]); 
bool checkCodeFile(char code[13]);

void showAllData();
Doctor findDoctor(int ID);

Doctor findDoctor(char code[13]);


//new

void writeBackUp(Doctor doctor);

int getDoctorBackupFile();

int getMaxDoctorBackUpID();

int getMaxDoctorID();

void showBackUpDoc();

Doctor getBackUpDoctor(int ID);

Doctor getBackUpDoctor(char code[13]);
void findBackUpDoctorID();
void findBackUpDoctorCode();

void printHeadLines();

void returnOldDoctor();


