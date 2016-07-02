
struct Patient{
	int ID;
	char firstName[18];
	char lastName[18];
	char personCode[13];
	char city[12];
	bool sex;
};






void printPatient(Patient patient);

char* getSex(Patient patient);

void printHeader();

void printContent(Patient patient);

int getPatientSizeFile();

void newFileWrite(Patient *patient, int size);
int setID();

bool checkPatientMistakeCode(char code[13]);
bool checkPersonCodeFile(char code[13]);
bool checkMistakeCode(char code[13]);
void fillPatient();

Patient getPatient(int ID);
Patient getPatient(char personCode[13]);

void findPatientByID();
void findPatientByCode();



void filtrByMan();

void showAllPatient();

void filtrByWomen();


void filtrCity(char city[12]);

void filtrPatientCity();

int countMan();

int countWomen();

void sortedByFirstName();

void sortedByLastName();
void deletePacient(int ID);

void deletePacient(char code[13]);


void deletePacientByID();

void deletePacientByCode();

void changePatientPersonCode();

void changePatientFirstName();

void changePatientCity();

void changeSex();

void printPatientLine();
void changePatientLastName();

//New func

void writeBackUp(Patient patient);

int getPatientBackupFile();

int getMaxPatientBackUpID();

int getMaxPatientID();

void showBackUpPat();

Patient getBackUpPatient(int ID);
Patient getBackUpPatient(char code[13]);

void findBackUpPatientID();
void findBackUpPatientCode();
void printHeadsLines();

void returnOldPatient();