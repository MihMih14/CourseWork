#include"Doctors.h"
#include"Patient.h"
#include"CardPatient.h"
#include<iostream>
using namespace std;
void doctorMenu();
void doctorChangeMenu();
void deleteMenu();
void sortedMenu();
void filtrMenu();
void findMenu();

void patientMenu();
void findPatientMenu();
void filtrPatientMenu();
void changePatientMenu();
void sortedPatientMenu();
void deletePatientMenu();

void cardMenu();
void cardChangeMenu();
void cardFindMenu();
void cardFiltrMenu();
void cardSortedMenu();
void cardDeleteMenu();

void backUpDoctorMenu();
void backUpPatientMenu();

void aboutUs();

int main()
{
	
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\tMain Menu.\n";
		printHeadLine();
		cout << "\n\n\n\n";
		cout << "\t\t\t\t1. Doctor.\n";
		cout << "\t\t\t\t2. Patient.\n";
		cout << "\t\t\t\t3. Card. \n";
		cout << "\t\t\t\t4. About Us.\n";
		cout << "\t\t\t\t5. Exit. \n\n";

		cout << "\t\t\t\tEnter Menu : ";
		char answer;
		cin >> answer;

		switch (answer)
		{
		case '1':doctorMenu(); break;
		case '2':patientMenu(); break;
		case '3':cardMenu(); break;
		case '4':aboutUs(); break;
		case '5':check = false; break;
		default: break;
		}
	} while (check);
	

	

	

	system("Pause");
	return 0;
}




void patientMenu()
{
	bool check = true;


	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Patient Menu.\n";
		printHeadLine();
		cout << "\n\n\n\n";
		
		cout << "\t\t\t\t1. Add Patient.\n";
		cout << "\t\t\t\t2. Find Patient.\n";
		cout << "\t\t\t\t3. Show All Patient.\n";
		cout << "\t\t\t\t4. Filtr Patient.\n";
		cout << "\t\t\t\t5. Sorted Patient.\n";
		cout << "\t\t\t\t6. Change Patient.\n";
		cout << "\t\t\t\t7. Delete Patient.\n";
		cout << "\t\t\t\t8. Back-Up.\n";
		cout << "\t\t\t\t9. <-Main Menu\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer)
		{
		case '1':fillPatient(); break;
		case '2':findPatientMenu(); break;
		case '3':showAllPatient(); break;
		case '4':filtrPatientMenu(); break;
		case '5':sortedPatientMenu(); break;
		case '6':changePatientMenu(); break;
		case '7':deletePatientMenu(); break;
		case '8':backUpPatientMenu(); break;
		case '9':check = false; break;
		default: break;
		}

	} while (check);
}
void changePatientMenu()
{
	bool check = true;

	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Change Patient.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Change FirtsName.\n";
		cout << "\t\t\t\t2. Change LastName. \n";
		cout << "\t\t\t\t3. Change City.\n";
		cout << "\t\t\t\t4. Change PersonCode.\n";
		cout << "\t\t\t\t5. Change Sex.\n";
		cout << "\t\t\t\t6. <-Patient\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";

		char answer;
		cin >> answer;
		
		switch (answer)
		{
		case '1':changePatientFirstName(); break;
		case '2':changePatientLastName(); break;
		case '3':changePatientCity(); break;
		case '4':changePatientPersonCode(); break;
		case '5':changeSex(); break;
		case '6':check = false; break;
		default:break;
		}

	} while (check);

}
void findPatientMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Find Patient.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Find Patient By ID.\n";
		cout << "\t\t\t\t2. Find Patient By Person-Code.\n";
		cout << "\t\t\t\t3. <-Patient.\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer)
		{
		case '1': findPatientByID(); break;
		case '2': findPatientByCode(); break;
		case '3': check = false; break;
		default:break;
		}
	} while (check);
}
void filtrPatientMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Filtr Patient.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Filtr By Man\n";
		cout << "\t\t\t\t2. Filtr By Woman\n";
		cout << "\t\t\t\t3. Filtr By City\n";
		cout << "\t\t\t\t4. <-Patient\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer){
		case '1':filtrByMan(); break;
		case '2':filtrByWomen(); break;
		case '3':filtrPatientCity(); break;
		case '4': check = false; break;
		default:break;
		}
	} while (check);
}
void sortedPatientMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Sorted Patient.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Sorted By FirtsName.\n";
		cout << "\t\t\t\t2. Sorted By LastName.\n";
		cout << "\t\t\t\t3. <-Patient.\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;
		switch (answer)
		{
		case '1': sortedByFirstName(); break;
		case '2': sortedByLastName(); break;
		case '3': check = false; break;
		default:break;
		}

	} while (check);
}
void deletePatientMenu()
{
	bool check = true;

	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Delete Patient.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Delete Patient By ID.\n";
		cout << "\t\t\t\t2. Delete Patient By Person-Code.\n";
		cout << "\t\t\t\t3. <-Patient.\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";

		char answer;
		cin >> answer;

		switch (answer)
		{
		case '1': deletePacientByID(); break;
		case '2': deletePacientByCode(); break;
		case '3': check = false; break;
		default:break;
		}

	} while (check);
}

void doctorMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t  Doctor Menu.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Add Doctor.\n";
		cout << "\t\t\t\t2. Change Data.\n";
		cout << "\t\t\t\t3. Delete Doctor.\n";
		cout << "\t\t\t\t4. Sorted.\n";
		cout << "\t\t\t\t5. Filtration.\n";
		cout << "\t\t\t\t6. Find Doctor\n";
		cout << "\t\t\t\t7. Show All Data\n";
		cout << "\t\t\t\t8. Back-Up.\n";
		cout << "\t\t\t\t9. <-Doctor\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer){
		case '1': fillDoctor(); break;
		case '2': doctorChangeMenu(); break;
		case '3': deleteMenu(); break;
		case '4': sortedMenu(); break;
		case '5': filtrMenu(); break;
		case '6': findMenu(); break;
		case '7': showAllData(); break;
		case '8': backUpDoctorMenu(); break;
		case '9': check = false; break;
		default: break;
		}

	} while (check);
}
void doctorChangeMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Change Doctor.\n";
		printHeadLine();
		cout << "\n\n\n\n";

	
		cout << "\t\t\t\t1. Change FirstName.\n";
		cout << "\t\t\t\t2. Change LastName.\n";
		cout << "\t\t\t\t3. Change PersonCode\n";
		cout << "\t\t\t\t4. Change Post\n";
		cout << "\t\t\t\t5. Change City\n";
		cout << "\t\t\t\t6. <-Doctor\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";

		char answer;
		cin >> answer;

		switch (answer){
		case '1': changeFirstName(); break;
		case '2': changeLastName(); break;
		case '3': changePersonCode(); break;
		case '4': changePost(); break;
		case '5': changeCity(); break;
		case '6': check = false; break;
		default: break;
		}
	} while (check);

}
void deleteMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Delete Doctor.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1.Delete By ID.\n";
		cout << "\t\t\t\t2.Delete By PersonCode.\n";
		cout << "\t\t\t\t3.<-Doctor.\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer){
		case '1': deleteDoctorByID(); break;
		case '2': deleteDoctorByCode(); break;
		case '3': check = false; break;
		default: break;
		}
	} while (check);
}
void sortedMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Sorted Doctor.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Sorted FirstName..\n";
		cout << "\t\t\t\t2. Sorted LastName.\n";
		cout << "\t\t\t\t3. <-Doctor.\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer){
		case '1':sortedFirstName(); break;
		case '2':sortedLastName(); break;
		case '3': check = false; break;
		default: break;
		}
	} while (check);
}
void filtrMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\tFiltr Doctor.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Filtr Post\n";
		cout << "\t\t\t\t2. Filtr City\n";
		cout << "\t\t\t\t3. <-Doctor\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;
		switch (answer){
		case '1': filtrDoctorPost(); break;
		case '2': filtrDoctorCity(); break;
		case '3': check = false; break;
		default: break;
		}
	} while (check);
}
void findMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Find Doctor.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Find Doctor By ID\n";
		cout << "\t\t\t\t2. Find Doctor By Code\n";
		cout << "\t\t\t\t3. <-Doctor\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";

		char answer;
		cin >> answer;

		switch (answer){
		case '1':findDoctorID(); break;
		case '2':findDoctorCode(); break;
		case '3': check = false; break;
		default: break;
		}
	} while (check);
	
}

void cardMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Card Menu.\n";
		printHeadLine();
		cout << "\n\n\n\n";
		cout << "\t\t\t\t1. Add Card.\n";
		cout << "\t\t\t\t2. Find Card.\n";
		cout << "\t\t\t\t3. Show All Card.\n";
		cout << "\t\t\t\t4. Filtr Card.\n";
		cout << "\t\t\t\t5. Sorted Card.\n";
		cout << "\t\t\t\t6. Change Card.\n";
		cout << "\t\t\t\t7. Delete Card.\n";
		cout << "\t\t\t\t8. <-Main Menu\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer)
		{
		case '1':addBill(); break;
		case '2':findCardByAccountNum(); break;
		case '3':showAllCard(); break;
		case '4':cardFiltrMenu(); break;
		case '5':cardSortedMenu(); break;
		case '6':cardChangeMenu(); break;
		case '7':deleteBill(); break;
		case '8':check = false; break;
		default: break;
		}

	} while (check);
}
void cardChangeMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Change Card.\n";
		printHeadLine();
		cout << "\n\n\n\n";

		cout << "\t\t\t\t1. Change Doctor ID.\n";
		cout << "\t\t\t\t2. Change Patient ID.\n";
		cout << "\t\t\t\t3. Change Diagnoz.\n";
		cout << "\t\t\t\t4. Change Paid.\n";
		cout << "\t\t\t\t5. Change Price\n";
		cout << "\t\t\t\t6. <-Card\n\n";

		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer){
		case '1': changeDoctorID(); break;
		case '2': changePatientID(); break;
		case '3': changeDiagnoz(); break;
		case '4': changePaid(); break;
		case '5': changePrice(); break;
		case '6': check = false; break;
		default: break;
		}

	} while (check);
}

void cardFiltrMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Filtr Bill.\n";
		printHeadLine();

		cout << "\n\n\n\n";
		cout << "\t\t\t\t1. Filtr By Bill\n";
		cout << "\t\t\t\t2. Filtr By Pay Bill\n";
		cout << "\t\t\t\t3. <-Card\n\n";

		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;
		switch (answer)
		{
		case '1': filtrBill(); break;
		case '2': filtrPayBill(); break;
		case '3': check = false; break;
		default: break;
		}

	} while (check);
}

void cardSortedMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Sorted Bill.\n";
		printHeadLine();
		cout << "\n\n\n\n";
		cout << "\t\t\t\t1. Sorted Price\n";
		cout << "\t\t\t\t2. <-Card\n\n";

		cout << "\t\t\t\tEnter Number Menu : ";
		char answer;
		cin >> answer;

		switch (answer){
		case '1': sortedPrice(); break;
		case '2': check = false; break;
		default:break;
		}


	} while (check);
}

void backUpDoctorMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Back Up Menu.\n";
		printHeadLine();
		cout << "\n\n\n\n";
		cout << "\t\t\t\t1. Find Doctor ID.\n";
		cout << "\t\t\t\t2. Find Doctor PersonCode.\n";
		cout << "\t\t\t\t3. Show All Doctor.\n";
		cout << "\t\t\t\t4. Return Doctor out BackUp.\n";
		cout << "\t\t\t\t5. <-Doctor\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";

		char answer;
		cin >> answer;

		switch (answer)
		{
		case '1':findBackUpDoctorID(); break;
		case '2':findBackUpDoctorCode(); break;
		case '3':showBackUpDoc(); break;
		case '4':returnOldDoctor(); break;
		case '5':check = false;
		default: break;
			
		}
		
		

	} while (check);
}

void backUpPatientMenu()
{
	bool check = true;
	do{
		system("cls");
		printHeadLine();
		cout << "\t\t\t\t Back Up Menu.\n";
		printHeadLine();
		cout << "\n\n\n\n";
		cout << "\t\t\t\t1. Find Patient ID.\n";
		cout << "\t\t\t\t2. Find Patient PersonCode.\n";
		cout << "\t\t\t\t3. Show All Patient.\n";
		cout << "\t\t\t\t4. Return Patient out BackUp.\n";
		cout << "\t\t\t\t5. <-Patient\n\n";
		cout << "\t\t\t\tEnter Number Menu : ";

		char answer;
		cin >> answer;

		switch (answer)
		{
		case '1':findBackUpPatientID(); break;
		case '2':findBackUpPatientCode(); break;
		case '3':showBackUpPat(); break;
		case '4':returnOldPatient(); break;
		case '5':check = false;
		default: break;

		}



	} while (check);
}


void aboutUs()
{
	system("cls");
	printHeadLine();
	cout << "\t\t\t\t About Us.\n";
	printHeadLine();
	cout << "\n\n\n\n";

	cout << "\t\t\t\t* Mihail Krasilnikov *\n";
	cout << "\t\t\t\t*       4503BD       *\n";
	cout << "\t\t\t\t*        2016        *\n";
	cout << "\t\t\t\t*        TSI         *\n";



	system("PAUSE");
}