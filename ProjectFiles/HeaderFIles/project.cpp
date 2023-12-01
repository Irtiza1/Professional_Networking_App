#include<iostream>
#include<string>
#include "User.h"
#include "Person.h"
#include "Company.h"
#include<vector>
#include<cstdio>

using namespace std;

//validation fuctions
bool isPasswordValid(string);
bool check_string(string s);
bool sign_up_of_person();
bool sign_up_of_company();
void User_Interface();


int main(){
	User_Interface();
	return 0;
}

//This function will check the validity of password
bool isPasswordValid(string password) {
	// Password should be at least 8 characters long
	if (password.length() < 8) {
		return false;
	}

	// Check if password contains at least one uppercase letter, one lowercase letter and one digit
	bool hasUppercase = false;
	bool hasLowercase = false;
	bool hasDigit = false;

	for (int i = 0; i < password.length(); i++) {
		if (isupper(password[i])) { 
			hasUppercase = true;
		} else if (islower(password[i])) {
			hasLowercase = true;
		} else if (isdigit(password[i])) {
			hasDigit = true;
		}
	}

	if (!hasUppercase || !hasLowercase || !hasDigit) {
		return false;
	}

	return true;
}
//This function will check string
bool check_string(string s) {
	bool check = false;
	for (int i = 0; i < s.length(); i++) {
		if (!isalpha(s[i])) {
			check = true;
		}
	}
	if (check == true) {
		return false;
	}
	return true;
}
// This function will sign up a person
bool sign_up_of_person() {
	//read ID from file "ID" then assign to user then write user's data in file then write incremented ID in file of "ID"

	int IDint;
	string IDstring, email, password, first_name, last_name, country, city, jobTitle, company, industry;
	bool dot_present = false, rate_present = false;

	//reading  ID from file "ID.txt"
	ifstream read;
	read.open("ID.txt");
	if (!read.is_open()) {
		cout << "ID error\n";
		return false;
	} else {
		cout << "Reading ID from file\n";
		read >> IDstring;
		cout << "ID:" << IDstring << endl;
	}
	read.close();

	//incrementing ID by typecasting into int
	IDint = stoi(IDstring);
	IDint++;
	IDstring = to_string(IDint);


	Person person;

	//ID of person has been set
	person.set_ID(IDstring);

	do {

		cout << "Email:";
		cin >> email;
		for (int i = 0; i < email.length(); i++) {
			if (email[i] == '@') {
				rate_present = true;
			}
			if (email[i] == '.') {
				dot_present = true;
			}
		}
		if (dot_present == false || rate_present == false) {
			cout << "invalid mail,enter again\n";
		}
	} while (dot_present == false || rate_present == false);
	person.set_email(email);


	do {
		cout << "Password(Password should be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit.):";
		cin >> password;

		if (isPasswordValid(password) == false) {
			cout << "Invalid Format.Enter again.\n";
		}
	} while (isPasswordValid(password) == false);
	person.set_password(password);
	do {
		cout << "Fist name:";
		cin >> first_name;
		if (check_string(first_name) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(first_name) == false);


	do {
		cout << "Last Name:";
		cin >> last_name;
		if (check_string(last_name) == false) {
			if (check_string(first_name) == false) {
				cout << "Invalid character\n";
			}
		}
	} while (check_string(last_name) == false);

	string fname = first_name + " " + last_name;
	person.set_name(fname);
	

	do {
		cout << "Country:";
		cin >> country;
		if (check_string(country) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(country) == false);
	person.set_country(country);

	do {
		cout << "City:";
		cin >> city;
		if (check_string(city) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(city) == false);
	person.set_city(city);
	

	do {
		cout << "Most recent job title:";
		cin >> jobTitle;
		if (check_string(jobTitle) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(jobTitle) == false);
	person.set_jobTitle(jobTitle);

	do {
		cout << "Most recent company:";
		cin >> company;
		if (check_string(company) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(company) == false);
	person.set_companyName(company);

	do {
		cout << "Enter your industry:";
		cin >> industry;
		if (check_string(industry) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(industry) == false);
	person.set_industry(industry);

	//adding person to file
	person.Add_to_file();

	//writing incremented ID in file "ID"
	ofstream writeID;
	writeID.open("ID.txt");
	writeID << IDint;
	writeID.close();

	//makind request_recieve file
	string request_file_name;
	request_file_name = IDstring + "_request_received.txt";
	ofstream requestfile;
	requestfile.open(request_file_name);
	requestfile.close();

	//making connection file
	string connection_file_name;
	connection_file_name = IDstring + "_connection.txt";
	ofstream connectionfile;
	connectionfile.open(connection_file_name);
	connectionfile.close();
	return true;
}
// This function will sign up a company
bool sign_up_of_company() {
	int IDint;
	string name, IDstring, email, password, first_name,  country, city, founded, sector, industry;
	bool dot_present = false, rate_present = false;

	//reading  ID from file "ID.txt"
	ifstream read;
	read.open("ID.txt");
	if (!read.is_open()) {
		cout << "ID error\n";
		return false;
	} else {
		cout << "Reading ID from file\n";
		read >> IDstring;
		cout << "ID:" << IDstring << endl;
	}
	read.close();

	IDint = stoi(IDstring);
	IDint++;
	IDstring = to_string(IDint);


	Company company;

	company.set_ID(IDstring);

	do {

		cout << "Email:";
		cin >> email;
		for (int i = 0; i < email.length(); i++) {
			if (email[i] == '@') {
				rate_present = true;
			}
			if (email[i] == '.') {
				dot_present = true;
			}
		}
		if (dot_present == false || rate_present == false) {
			cout << "invalid mail,enter again\n";
		}
	} while (dot_present == false || rate_present == false);

	company.set_email(email);

	do {
		cout << "Password(Password should be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit.):";
		cin >> password;

		if (isPasswordValid(password) == false) {
			cout << "Invalid Format.Enter again.\n";
		}
	} while (isPasswordValid(password) == false);

	company.set_password(password);
	

	do {
		cout << "Name:";
		fflush(stdin);
		getline(cin,first_name);
		if (check_string(first_name) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(first_name) == false);


	company.set_name(first_name);

	

	do {
		cout << "Country:";
		cin >> country;
		if (check_string(country) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(country) == false);
	company.set_country(country);

	do {
		cout << "City:";
		cin >> city;
		if (check_string(city) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(city) == false);
	company.set_city(city);
	

	do {
		cout << "Sector type :";
		cin >> sector;
		if (check_string(sector) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(sector) == false);
	company.set_sectorType(sector);


	cout << "Founded date :";
	cin >> founded;
	company.set_foundedDate(founded);

	do {
		cout << "Enter your industry:";
		cin >> industry;
		if (check_string(industry) == false) {
			cout << "Invalid character\n";
		}
	} while (check_string(industry) == false);
	company.set_industry(industry);

	company.Add_to_file();
	ofstream writeID;
	writeID.open("ID.txt");
	writeID << IDint;
	writeID.close();

return true;

}
// This fucntion is the main interface of our program/app
void User_Interface(){
	int ans;
	logout:
	cout<<"----------------WELCOME----------------------"<<endl;
	//for(;;){
		cout<<"1-User Account"<<endl;
		cout<<"2-Company Account\nAns: ";
		cout<<endl;
		cin>>ans;

		try{
			if(ans==1){
			//person
			flag:
			Person person;
			cout<<"1-Create Person Account(If you didn't have account)"<<endl;
			cout<<"2-Login Person Account(If your account already exist)\nAns: ";
			cout<<endl;
			cin>>ans;
				try{
					if(ans==2){
						try{	
							if(person.log_in()){
								do{
									cout<<"1-View Profile\n2-Search For People\n3-Manage Network\n4-Create Post\n5-View Post\n6-View Newsfeed\n7-Search Jobs\n9-Logout\nAns: ";
									cin>>ans;
									cout<<endl;
									try{
										if(ans==1){
											person.viewProfile();
										}
										else if(ans==2){
											person.search_for_person_in_all_persons_file();
										}
										else if(ans==3){
											person.manage_network();
										}
										else if(ans==4){
											person.post_on_my_wall();
										}
										else if(ans==5){
											person.view_my_wall();
										}
										else if(ans==6){
											person.view_my_newsfeed();
										}
										else if(ans==7){
											person.search_and_apply_for_jobs();
										}
										else if(ans==9){
											exit(1);
										}
										else{
											throw 5;
										}
									}
									catch(int){
										cout<<"Error 404"<<endl;
									}
								}while(ans!=9);
							}
							else{
								throw 3;
							}
						}
						catch(int){
							cout<<"Person ID is Invalid"<<endl;
							goto flag;
						}

					}
					else if(ans==1){
						try{
							if(sign_up_of_person()){
								cout<<"Thanks for signing up!.Now you need to login with your Email"<<endl;
								goto flag;
							}
							else{
								throw 12;
							}	
						}
						catch(int){
							cout<<"Sign up failed"<<endl;
							goto flag;
						}
					}
					else
					throw 2;

				}
				catch(int){
					cout<<"Error 404......"<<endl;
				}
			}
			else if(ans==2){
			//company
			FLAG:
			Company company;
			cout<<"1-Create Company Account(If you didn't have account)"<<endl;
			cout<<"2-Login Company Account(If your account already exist)"<<endl;
			cin>>ans;
				try{

					if(ans==2){
						try{
							if (company.log_in()){
								do{
									cout<<"1-View Profile\n2-Search For Company\n3-editjob post\n4-Create Post\n5-View Post\n6-View job post\n7-create Jobs\n8-view job application\n9-view employees\n10-Logout\nAns: ";
									cin>>ans;
									cout<<endl;
									try{
										if(ans==1){
											company.Read_from_file();
										}
										else if(ans==2){
											company.search_for_company_in_all_company_file();
										}
										else if(ans==3){
											
										}
										else if(ans==4){
										company.post_on_my_wall();
										}
										else if(ans==5){
											company.view_my_wall();
										}
										else if(ans==6){
											company.view_jobs_posted();
										}
										else if(ans==7){
											company.post_job();
										}
										else if(ans==8){
											company.view_applications_for_job();
										}
										else if(ans==9){
											company.view_employees();
										}
										else if(ans==10){
											cout<<"Logged out successfully.\n";
											exit(1);
										}
										else{
											throw 5;
										}
									}
									catch(int){
										cout<<"Error 404"<<endl;
									}
								}while(ans!=10);
							}
							else{
								throw 50;
							}
						}
						catch(int){
							cout<<"Company ID is invalid"<<endl;
							goto FLAG;
						}
					}
					else if(ans==1){
						try{
							if(sign_up_of_company()){
								cout<<"Thanks for signing up!.Now you need to login with your Email"<<endl;
								goto FLAG;
							}
							else{
								throw 10;
							}
						}
						catch(int){
							cout<<"sign up failed"<<endl;
							goto FLAG;

						}

					}
					else
					throw 2;

				}
				catch(int){
					cout<<"Error 405.............."<<endl;
				}
			}
			else{
				throw 1;
			}
		}
		catch(int){
			cout<<"Error 406........"<<endl;
		}
}