struct CardPatiet{
	int AccountNumber;
	int Doc_ID;
	int Pat_ID;
	char diagnoz[16];
	float price;
	bool Paid;

};



void sortedPrice();

void printCardHeader();

void printCard(CardPatiet card);

char* getPaid(bool paid);

void printCardLine();

void addBill();


void showAllBill(int ID);
void showAllDoctorPatient(int ID);

void showPatientBillID();

void showDoctorBillID();

void showAllCard();
/*
ID
*/

void setDoctorID(CardPatiet *card);

void setPatientID(CardPatiet *card);

int setAccountNumber();


/*
Check
*/

bool checkPatientID(int ID);

bool checkDoctorID(int ID);

bool checkAccount(int account);

/*
filtr
*/

void filtrPayBill();

void filtrBill();

/*

count

*/

int getSizeCardFile();

int countBill();

int countPayBill();

/*
find
*/

CardPatiet getCardPatient(int accountNumber);

void findCardByAccountNum();


/*
delete
*/
void deleteBill();

void newFileWrite(CardPatiet *card, int size);

void changeDoctorID();

void changePatientID();

void changeDiagnoz();

void changePrice();

void changePaid();

//new

//end

int countVisitDoctor(int ID);
int countClient(int ID);