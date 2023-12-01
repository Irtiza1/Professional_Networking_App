#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <string.h>
#include "User.h"
using namespace std;
#ifndef PERSON_H
#define PERSON_H

struct Person_structure {
	User_structure u1;
	string dateOfBirth;
	string gender;
	string leisureActivity;
	string jobTitle;
	string companyName;
	string skills;
	string schooleducation;
	string collegeEducation;
	string graduation;
	string masters;
	string phd;
	string jobExperience;
};

class Person :public User {
	private:
		struct Person_structure p1;
	public:
		Person() {
		}

		//setters and getters of data structure

		void set_dateOfBirth(const string dob) {
			p1.dateOfBirth = dob;
		}
		string get_dateOfBirth() const {
			return p1.dateOfBirth;
		}

		void set_gender(const string gender) {
			this->p1.gender = gender;
		}
		string get_gender()const {
			return p1.gender;
		}

		void set_leisureactivity(const string leisureactivity) {
			p1.leisureActivity = leisureactivity;
		}
		string get_leisureactivity()const {
			return p1.leisureActivity;
		}

		void set_jobTitle(const string jobTitle) {
			this->p1.jobTitle = jobTitle;
		}
		string get_jobTitle()const {
			return p1.jobTitle;
		}

		void set_companyName(const string companyName) {
			this->p1.companyName = companyName;
		}
		string get_companyName()const {
			return p1.companyName;
		}

		//setters and getters of education structure
		void set_schoolEDucation(const string schoolEducation) {
			p1.schooleducation = schoolEducation;
		}
		string get_schoolEDucation()const {
			return p1.collegeEducation;
		}
		void set_collegeEDucation(const string collegeEducation) {
			this->p1.collegeEducation = collegeEducation;
		}
		string get_collegeEDucation()const {
			return p1.collegeEducation;
		}

		void set_graduation(const string graduation) {
			this->p1.graduation = graduation;
		}
		string get_graduation()const {
			return p1.graduation;
		}

		void set_masters(const string masters) {
			this->p1.masters = masters;
		}
		string get_masters()const {
			return p1.masters;
		}

		void set_phd(const string phd) {
			this->p1.phd = phd;
		}
		string get_phd()const {
			return p1.phd;
		}

		void set_jobExperience(const string jobexperience) {
			this->p1.jobExperience = jobexperience;
		}
		string get_jobExperience()const {
			return p1.jobExperience;
		}


		//setters and getters others
		void set_skills(const string skills) {
			this->p1.skills = skills;
		}
		string get_skills()const {
			return p1.skills;
		}
		// This Fucntion will show Connections
		void view_connection_request() {
			string id, name, shtbio, industry, country;
			int choice;
			string filename = p1.u1.ID + "_request_received.txt";
			const char* filenameN = filename.c_str();
			const char* filenameO = "temp2.txt";

			string filename2 = p1.u1.ID + "_connection.txt";
			string filename3;
			bool check1 = false, check2 = false;

			ofstream temp1;
			temp1.open("temp1.txt");
			ofstream temp_remove;
			temp_remove.open("temp_remove.txt");
			ifstream read;
			read.open(filename);
			//below line checks if the files is empty.
			if (read.peek() == ifstream::traits_type::eof()) {
				cout << "No connection request.\n" << endl;
			} else {
				if (read.is_open()) {
					cout << "YOU HAVE RECEIVED CONNECTION REQUEST FROM......\n";
					getline(read, id);
					getline(read, name);
					getline(read, shtbio);
					getline(read, industry);
					getline(read, country);
					while (!read.eof()) {
						filename3 = id + "_connection.txt";
						cout << name << "		ID:" << id << endl
						     << shtbio << endl
						     << industry << endl
						     << country << endl;
						cout << "1.Connect\n2.Remove request\n3.Skip\n";
						cin >> choice;
						fflush(stdin);

						if (choice == 1) {
							check1=true;
							ofstream write_connections_requestee;
							write_connections_requestee.open(filename2, ios::binary | ios::app);
							if (write_connections_requestee.is_open()) {
								write_connections_requestee << id << endl;
								write_connections_requestee << name << endl;
								write_connections_requestee << shtbio << endl;
								write_connections_requestee << industry << endl;
								write_connections_requestee << country << endl;
							} else {
								cout << "unexpected error in building connection.\n";
							}
							write_connections_requestee.close();

							//cout << "writing in requester's file\n";
							ofstream write_connections_requester;
							write_connections_requester.open(filename3, ios::binary | ios::app);
							if (write_connections_requester.is_open()) {
								write_connections_requester << p1.u1.ID<< endl;
								write_connections_requester << p1.u1.name << endl;
								write_connections_requester << p1.u1.shortBoi << endl;
								write_connections_requester << p1.u1.industry<< endl;
								write_connections_requester << p1.u1.country << endl;
							} else {
								cout << "unexpected error in writing in requester's file.\n";
							}
							write_connections_requester.close();
							cout << "You are now connected with " << name << endl;
							temp1 << id << endl;


						} else if (choice == 2) {
							check2=true;
							temp_remove<<id<<endl;
						} else if (choice == 3) {
							//yahan kuch likhnay ki zarorat nhi
						}
						fflush(stdin);
						getline(read, id);
						getline(read, name);
						getline(read, shtbio);
						getline(read, industry);
						getline(read, country);
					}

				} else {
					cout << "error in loading your connection\n";
				}
			}
			read.close();
			temp1.close();
			temp_remove.close();

			if(check1==true) {
				removing_data_from_rr(check1,filename);
			}
			if(check2==true) {
				removing_request(check2,filename);
			}
		
		}
		void removing_data_from_rr(bool check1,string filename) {
			const char* filenameN = (p1.u1.ID + "_request_received.txt").c_str();
			const char* filenameO = "temp2.txt";
			string id,name,shtbio,industry,country;
			ifstream tem;
			ifstream read;
			string tempID,tempID2;
			ofstream temp2;
			if(check1==true) {
				tem.open("temp1.txt");
				if(tem.is_open()) {
					getline(tem,tempID);
					while(!tem.eof()) {
						read.open(filename);
						if(read.is_open()) {
							getline(read, id);
							getline(read, name);
							getline(read, shtbio);
							getline(read, industry);
							getline(read, country);
							while(!read.eof()) {
								if(tempID==id) {
									tempID2=tempID;
									break;
								}
								getline(read, id);
								getline(read, name);
								getline(read, shtbio);
								getline(read, industry);
								getline(read, country);
							}
						} else {
							cout<<"error opening read.txt\n";
						}
						read.close();

						read.open(filename);
						temp2.open("temp2.txt");

						if(read.is_open()) {
							getline(read, id);
							getline(read, name);
							getline(read, shtbio);
							getline(read, industry);
							getline(read, country);
							while(!read.eof()) {
								if(id!=tempID2) {
									temp2<<id<<endl;
									temp2<<name<<endl;
									temp2<<shtbio<<endl;
									temp2<<industry<<endl;
									temp2<<country<<endl;
								}
								getline(read, id);
								getline(read, name);
								getline(read, shtbio);
								getline(read, industry);
								getline(read, country);
							}
						} else {
							cout<<"error opening read.txt 2\n";
						}
						read.close();
						temp2.close();
						remove(filenameN);
						rename(filenameO,filenameN);

						getline(tem,tempID);
					}
				} else {
					cout<<"error opening temp1.txt\n";
				}
			}
			tem.close();
		}
		// This Fucntion will Remove request from requests file
		void removing_request(bool check2,string filename) {
			const char* filenameN = (p1.u1.ID + "_request_received.txt").c_str();
			const char* filenameO = "temp2.txt";
			string id,name,shtbio,industry,country;
			ifstream tem;
			ifstream read;
			string tempID,tempID2;
			ofstream temp2;
			if(check2==true) {
				tem.open("temp_remove.txt");
				if(tem.is_open()) {
					getline(tem,tempID);
					while(!tem.eof()) {
						read.open(filename);
						if(read.is_open()) {
							getline(read, id);
							getline(read, name);
							getline(read, shtbio);
							getline(read, industry);
							getline(read, country);
							while(!read.eof()) {
								if(tempID==id) {
									tempID2=tempID;
									break;
								}
								getline(read, id);
								getline(read, name);
								getline(read, shtbio);
								getline(read, industry);
								getline(read, country);
							}
						} else {
							cout<<"error opening read.txt\n";
						}
						read.close();

						read.open(filename);
						temp2.open("temp2.txt");

						if(read.is_open()) {
							getline(read, id);
							getline(read, name);
							getline(read, shtbio);
							getline(read, industry);
							getline(read, country);
							while(!read.eof()) {
								if(id!=tempID2) {
									temp2<<id<<endl;
									temp2<<name<<endl;
									temp2<<shtbio<<endl;
									temp2<<industry<<endl;
									temp2<<country<<endl;
								}
								getline(read, id);
								getline(read, name);
								getline(read, shtbio);
								getline(read, industry);
								getline(read, country);
							}
						} else {
							cout<<"error opening read.txt 2\n";
						}
						read.close();
						temp2.close();
						remove(filenameN);
						rename(filenameO,filenameN);

						getline(tem,tempID);
					}
				} else {
					cout<<"error opening temp1.txt\n";
				}
			}
			tem.close();
		}
		// This Fucntion will send request for making connection
		void sending_connection_request() {
			string id;
			string name, id_for_request, bio, shortBIo, city, country, industry;
			cout << "enter id of person to make connetion :";
			cin >> id;

			bool connection_check = false;
			bool personfound = false;

			//verifying if connection is made already
			ifstream reading_connection_file;
			string filename1 = p1.u1.ID + "_connection.txt";
			string readID;
			reading_connection_file.open(filename1);
			if (reading_connection_file.is_open()) {
				getline(reading_connection_file, readID);
				while (!reading_connection_file.eof()) {
					if (readID == id) {
						connection_check = true;
						break;
					} else {
						getline(reading_connection_file, readID);
					}
				}
			} else {
				cout << "error opening your connection file while verification\n";
			}
			reading_connection_file.close();

			//verifying if person exists or not

			ifstream reading_all_person_file;
			reading_all_person_file.open("All_Persons.txt");
			if(reading_all_person_file.is_open()) {
				getline(reading_all_person_file,readID);
				while(!reading_all_person_file.eof()) {
					if (readID == id) {
						personfound = true;
						break;
					} else {
						getline(reading_all_person_file, readID);
					}
				}
			} else {
				cout<<"error opening all person.txt\n";
			}

			if(connection_check==true) {
				cout<<"person already connected\n";
			}
			if(personfound==false) {
				cout<<"person doesnot exist\n";
			}
			if(p1.u1.ID==id) {
				cout<<"You cannot send request to yourself\n";
			}

			//now will start looking for this id in all person file
			if (connection_check == false && personfound==true && id!=p1.u1.ID) {
				ifstream read;
				read.open("All_Persons.txt");
				if (read.is_open()) {
					cout << "wait searching...\n";
					getline(read, id_for_request);
					//cout << "read "<<id_for_request<<endl;
					while (!read.eof()) {
						if (id_for_request == id) {
							//cout << "reached in if of writing\n";
							ofstream write_in_requestee;
							id = id + "_request_received.txt";//naming format
							write_in_requestee.open(id, ios::binary | ios::app);

							if (write_in_requestee.is_open()) {
								write_in_requestee << p1.u1.ID << endl;
								write_in_requestee << p1.u1.name << endl;
								write_in_requestee << p1.u1.shortBoi << endl;
								write_in_requestee << p1.u1.industry << endl;
								write_in_requestee << p1.u1.country << endl;
								cout << "Request has been sent successfully\n";
							} else {
								cout << "error in sending request\n";
							}
							write_in_requestee.close();
							break;

						} else {
							read >> id_for_request;
						}
						//cout << "read " << id_for_request << endl;

					}
				} else {
					cout << "error in opening the All person file\n";
				}
				read.close();
			}

		}
		// This Fucntion will implement messaging functionality
		void chat_with_connections() {
			string id, name, shtbio, industry, country;
			string input_id,filename2;
			string message;
			int flag_found=0;
			cout<<"Enter the ID of person you want to chat with\n";
			cin>>input_id;
			string filename=p1.u1.ID + "_connection.txt";
			ifstream read_connection_file;
			read_connection_file.open(filename);
			if(!read_connection_file.is_open()) {
				cout<<"You dont have any connections yet\n";
			} else {
				//read previous msg form file
				//cout<<"Pervious chat : \n"
				getline(read_connection_file, id);
				getline(read_connection_file, name);
				getline(read_connection_file, shtbio);
				getline(read_connection_file, industry);
				getline(read_connection_file, country);
				while(!read_connection_file.eof()) {
					if(input_id==id) {
						flag_found=1;
						if(p1.u1.ID>input_id) {
							filename2=p1.u1.ID + "_" +input_id+ "_conversation.txt";
						} else {
							filename2=input_id+ "_" + p1.u1.ID+ "_conversation.txt";
						}
						ofstream write_connection_file;
						ifstream read;
						read.open(filename2);
						cout<<"Previous chat\n";
						if(read.peek() == ifstream::traits_type::eof()) {
							cout<<"Start new conversation\n";
						} else {
							getline(read,message);
							while(!read.eof()) {
								cout<<message<<endl;
								getline(read,message);

							}
						}
						write_connection_file.open(filename2,ios::binary | ios::app);
						int ch=0;
						while(ch==0) {
							cout<<"Enter message here\n";
							cin.ignore();
							cin.clear();
							//fflush(stdin);
							getline(cin, p1.u1.message);
							//cout<<p1.u1.message;
							//cin>>message;
							write_connection_file<<p1.u1.ID<<" : "<<p1.u1.message<<endl;
							cout<<"Message sent successfully\n";
							cout<<"Press 0 to message again OR 1 to end\n";
							cin>>ch;
						}
						write_connection_file.close();
						break;
					}

					else {
						getline(read_connection_file, id);
						getline(read_connection_file, name);
						getline(read_connection_file, shtbio);
						getline(read_connection_file, industry);
						getline(read_connection_file, country);
					}
				}
				if(flag_found==0)
					cout<<"No such ID in your connections\n";
				read_connection_file.close();
			}
		}
		// This Fucntion will remove connections
		void remove_connection() {
			bool check1=false;
			bool check2=false;
			string iid,nname,sshtbio,iindustry,ccountry;
			string filename=p1.u1.ID+"_connection.txt";
			const char* filenameN = filename.c_str();
			const char* filenameO = "temp_for_removing_connection.txt";
			string id_to_remove;
			cout<<"Enter ID of person you want to remove:";
			cin>>id_to_remove;

			string filename2=id_to_remove+"_connection.txt";
			const char* filenameN2 = filename2.c_str();
			const char* filenameO2 = "temp_for_removing_connection2.txt";

			if(id_to_remove!=p1.u1.ID) {

				ifstream read_connection;
				ofstream write_in_new;
				ifstream read_connection2;
				ofstream write_in_new2;
				read_connection2.open(filename2);
				read_connection.open(filename);
				write_in_new.open("temp_for_removing_connection.txt");
				write_in_new2.open("temp_for_removing_connection2.txt");
				if(read_connection.is_open()) {
					getline(read_connection,iid);
					getline(read_connection, nname);
					getline(read_connection, sshtbio);
					getline(read_connection,iindustry);
					getline(read_connection,ccountry);
					while (!read_connection.eof()) {
						if(id_to_remove!=iid) {
							//cout<<"wrote data of:"<<iid<<endl;
							write_in_new<<iid<<endl;
							write_in_new<<nname<<endl;
							write_in_new<<sshtbio<<endl;
							write_in_new<<iindustry<<endl;
							write_in_new<<ccountry<<endl;

						}
						if(id_to_remove==iid) {
							check1==true;
						}
						getline(read_connection,iid);
						getline(read_connection, nname);
						getline(read_connection, sshtbio);
						getline(read_connection,iindustry);
						getline(read_connection,ccountry);
					}
				} else {
					cout<<"Cannot open your connection.txt\n";
				}
				if(read_connection2.is_open()) {
					getline(read_connection2,iid);
					getline(read_connection2, nname);
					getline(read_connection2, sshtbio);
					getline(read_connection2,iindustry);
					getline(read_connection2,ccountry);
					while (!read_connection2.eof()) {
						if(id_to_remove!=iid) {
							//cout<<"wrote data of:"<<iid<<endl;
							write_in_new2<<iid<<endl;
							write_in_new2<<nname<<endl;
							write_in_new2<<sshtbio<<endl;
							write_in_new2<<iindustry<<endl;
							write_in_new2<<ccountry<<endl;

						}
						if(id_to_remove==iid) {
							check2==true;
						}
						getline(read_connection2,iid);
						getline(read_connection2, nname);
						getline(read_connection2, sshtbio);
						getline(read_connection2,iindustry);
						getline(read_connection2,ccountry);
					}
				} else {
					cout<<"Cannot open connection.txt\n";
				}
				write_in_new.close();
				read_connection.close();
				remove(filenameN);
				rename(filenameO,filenameN);
				write_in_new2.close();
				read_connection2.close();
				remove(filenameN2);
				rename(filenameO2,filenameN2);
				if(check1==true&&check2==true) {
					cout<<"The person has been removed successfully.\n";
				} else {
					cout<<"The person isnot in your connection.\n";
				}
			} else {
				cout<<"You have entered your own ID dumb.\n";
			}

		}
		// This Fucntion will show connection
		int show_connection() {
			string iid,nname,sshtbio,iindustry,ccountry;
			ifstream read;
			string file_name = p1.u1.ID + "_connection.txt";
			read.open(file_name);
			if(read.is_open()) {
				getline(read,iid);
				getline(read, nname);
				getline(read, sshtbio);
				getline(read,iindustry);
				getline(read,ccountry);
				while (!read.eof()) {
					cout<<"ID : "<<iid<<endl;
					cout << nname << endl;
					cout << sshtbio << endl;
					cout<<iindustry<<endl;
					cout<<ccountry<<endl;
					getline(read,iid);
					getline(read, nname);
					getline(read, sshtbio);
					getline(read,iindustry);
					getline(read,ccountry);
				}
			} else {
				cout<<"cannot open file\n";
			}
			read.close();
			int a;
			cout<<"1.Chat with someone\n2.Remove a connection\n3.Back\n";
			cin>>a;
			if(a==1) {
				chat_with_connections();
			} else if(a==2) {
				remove_connection();
			} else if(a==3) {
				return 1;
			} else {
				cout<<"Invalid option.\n";
			}
			return 0; 
		}
		// This Fucntion will manage networks
		int manage_network() {
			int choice;
			for(;;) {
				cout<<"1.View connection request\n2.Send a request\n3.View my connection\n4.Back\n";
				cout<<"Your choice :";
				cin>>choice;
				if(choice==1) {
					view_connection_request();
				} else if(choice==2) {
					sending_connection_request();
				} else if(choice==3) {
					show_connection();
				} else if(choice==4) {
					return 1;
				} else {
					cout<<"Invalide input\n";
				}
			}
		}
		// This Fucntion will work on login functionality
		bool log_in() {
			string bio;
			bool check=false;
			string email, password;
			cout << "email :";
			cin >> email;
			email = "Email : " + email;

			cout << "password :";
			cin >> password;
			password = "Password : " + password;

			ifstream read;
			read.open("All_Persons.txt");

			getline(read, p1.u1.name);
			getline(read, p1.u1.ID);
			getline(read, p1.u1.about);
			getline(read, bio);
			getline(read, p1.u1.shortBoi);
			getline(read, p1.u1.city);
			getline(read, p1.u1.country);
			getline(read, p1.u1.industry);
			getline(read, p1.u1.contactnumber);
			getline(read, p1.u1.email);
			getline(read, p1.dateOfBirth);
			getline(read, p1.gender);
			getline(read, p1.leisureActivity);
			getline(read, p1.jobTitle);
			getline(read, p1.jobExperience);
			getline(read, p1.companyName);
			getline(read, p1.skills);
			getline(read, p1.schooleducation);
			getline(read, p1.collegeEducation);
			getline(read, p1.graduation);
			getline(read, p1.masters);
			getline(read, p1.phd);
			getline(read, p1.leisureActivity);
			getline(read, p1.u1.password);

			if (read.is_open()) {
				cout << "Verifying details in the system\n\n";
				while (!read.eof()) {
					if (email == p1.u1.email && password == p1.u1.password) {
						cout << "Welcome back "<<p1.u1.name << endl;
						check = true;
						return true;
						break;

					} else {
						getline(read, p1.u1.name);
						getline(read, p1.u1.ID);
						getline(read, p1.u1.about);
						getline(read, p1.u1.shortBoi);
						getline(read, bio);
						getline(read, p1.u1.city);
						getline(read, p1.u1.country);
						getline(read, p1.u1.industry);
						getline(read, p1.u1.contactnumber);
						getline(read, p1.u1.email);
						getline(read, p1.dateOfBirth);
						getline(read, p1.gender);
						getline(read, p1.leisureActivity);
						getline(read, p1.jobTitle);
						getline(read, p1.jobExperience);
						getline(read, p1.companyName);
						getline(read, p1.skills);
						getline(read, p1.schooleducation);
						getline(read, p1.collegeEducation);
						getline(read, p1.graduation);
						getline(read, p1.masters);
						getline(read, p1.phd);
						getline(read, p1.leisureActivity);
						getline(read, p1.u1.password);
					}
				}
				if (check == false) {
					cout << "No account exist for this email and password . Enter correct email and password." << endl;
					return false;
				}

				//this is for testing that whether the function is reading information properly
				//cout << p1.u1.email << endl
				//<< p1.u1.password << endl;
				cout << p1.u1.ID << endl;
				cout << get_ID()<<endl;
				//now further more we will make a function 0f interface for the flow of program
				read.close();

			}
			return true;
		}
		// This Fucntion will edit profile
		void editProfile() {
			int ans;
			string dob, gen, lA, jT, compName, s, schEdu, colEdu, grad, mas, p, jE, nam, abt, BIO, cty, cntry, ind, e;
			int contact;
			do {
				cout << "1-date Of Birth\n2-gender\n3-leisure Activity\n4-job Title\n5-company Name\n6-skills" << endl;
				cout << "7-school education\n8-college Education\n9-graduation\n10-masters\n11-phd\n12-job Experience" << endl;
				cout << "13-name\n14-about\n15-Biograpgy\n16-city\n17-country\n18-industry\n19-contact no\n20-email\n-1 exit" << endl;
				cin >> ans;
				switch (ans) {
					case 1:
						//		string dob;
						cin >> dob;
						set_dateOfBirth(dob);
						break;
					case 2:
						//		string gen;
						cin >> gen;
						set_gender(gen);
						break;
					case 3:
						//		string lA;
						cin >> lA;
						set_leisureactivity(lA);
						break;
					case 4:
						//	string jT;
						cin >> jT;
						set_jobTitle(jT);
						break;
					case 5:
						///	string compName;
						cin >> compName;
						set_companyName(compName);
						break;
					case 6:
						//	string skills;
						cin >> s;
						set_skills(s);
						break;
					case 7:
						//	string schEdu;
						cin >> schEdu;
						set_schoolEDucation(schEdu);
						break;
					case 8:
						//	string colEdu;
						cin >> colEdu;
						set_collegeEDucation(colEdu);
						break;
					case 9:
						//	string grad;
						cin >> grad;
						set_graduation(grad);
						break;
					case 10:
						//	string mas;
						cin >> mas;
						set_masters(mas);
						break;
					case 11:
						//	string p;
						cin >> p;
						set_phd(p);
						break;
					case 12:
						//string jE;
						cin >> jE;
						set_jobExperience(jE);
						break;
					case 13:
						//string nam;
						cin >> nam;
						set_name(nam);
						break;
					case 14:
						//string abt;
						cin >> abt;
						set_about(abt);
						break;
					case 15:
						//string BIO;
						cin >> BIO;
						set_shortBio(BIO);
						break;
					case 16:
						//string cty;
						cin >> cty;
						set_city(cty);
						break;
					case 17:
						//string cntry;
						cin >> cntry;
						set_country(cntry);
						break;
					case 18:
						//string ind;
						cin >> ind;
						set_industry(ind);
						break;
					case 19:
						//string contact;
						cin >> contact;
						set_contactnumber(contact);
						break;
					case 20:
						//string email;
						cin >> e;
						set_email(e);
						break;
					case -1:
						exit(1);
						break;
					default:
						cout << "invalid option!" << endl;
				}
			} while (ans != -1);
		}
		// This Fucntion view profile
		void viewProfile() {
			cout << "Name: " << p1.u1.name << endl;
			cout << "ID : " <<p1.u1.ID << endl;
			cout << "About: " <<p1.u1.about << endl;
			cout << "Bio: " << p1.u1.shortBoi << endl;
			cout << "City: " << p1.u1.city << endl;
			cout << "Country: " << p1.u1.country << endl;
			cout << "Industry: " << p1.u1.industry << endl;
			cout << "Contact Number: " << p1.u1.contactnumber << endl;
			cout << "Email: " << p1.u1.email << endl;
			cout << "Date of Birth: " << p1.dateOfBirth<< endl;
			cout << "Gender: " << p1.gender << endl;
			cout << "Extra-curriculars: " << p1.leisureActivity << endl;
			cout << "Job: " << p1.jobTitle << endl;
			cout << "Job Experience: " << p1.jobExperience<< endl;
			cout << "Company: " << p1.companyName << endl;
			cout << "Skills: " <<p1.skills << endl;
			cout << "School: " << p1.schooleducation << endl;
			cout << "College: " << p1.collegeEducation << endl;
			cout << "Graduation: " << p1.graduation << endl;
			cout << "Masters: " << p1.masters << endl;
			cout << "Ph.D: " << p1.phd << endl;
		}
		// This Fucntion will add data to file
		void Add_to_file() {
			ofstream write;
			write.open("All_Persons.txt", ios::binary | ios::app);
			write << "Name : " << get_name() << endl;
			write << get_ID() << endl;
			write << "About : " << get_about() << endl;
			write << "Bio : " << get_bio() << endl;
			write << "Short Bio : " << get_shortBio() << endl;
			write << "City : " << get_city() << endl;
			write << "Country : " << get_country() << endl;
			write << "Industry : " << get_industry() << endl;
			write << "Contact Number : " << get_contactnumber() << endl;
			write << "Email : " << get_email() << endl;
			write << "Date of Birth : " << get_dateOfBirth() << endl;
			write << "Gender : " << get_gender() << endl;
			write << "Extra-curriculars : " << get_leisureactivity() << endl;
			write << "Job title : " << get_jobTitle() << endl;
			write << "Job Experience : " << get_jobExperience() << endl;
			write << "Company : " << get_companyName() << endl;
			write << "Skills : " << get_skills() << endl;
			write << "School : " << get_schoolEDucation() << endl;
			write << "College : " << get_collegeEDucation() << endl;
			write << "Graduation : " << get_graduation() << endl;
			write << "Masters : " << get_masters() << endl;
			write << "Ph.D : " << get_phd() << endl;
			write << "Leisure activity : " << get_leisureactivity() << endl;
			write << "Password : " << get_password() << endl;
			//Similar to the above work, we will write every attribute into file , or only those that are of our need
			write.close();
			cout << "Data Saved to file\n";
		}
		// This Fucntion will read data from file
		void Read_from_file() {
			ifstream read;
			read.open("All_Persons.txt");
			getline(read, p1.u1.name);
			getline(read, p1.u1.ID);
			getline(read, p1.u1.about);
			getline(read, p1.u1.bio);
			getline(read, p1.u1.shortBoi);
			getline(read, p1.u1.city);
			getline(read, p1.u1.country);
			getline(read, p1.u1.industry);
			getline(read, p1.u1.contactnumber);
			getline(read, p1.u1.email);
			getline(read, p1.dateOfBirth);
			getline(read, p1.gender);
			getline(read, p1.leisureActivity);
			getline(read, p1.jobTitle);
			getline(read, p1.jobExperience);
			getline(read, p1.companyName);
			getline(read, p1.skills);
			getline(read, p1.schooleducation);
			getline(read, p1.collegeEducation);
			getline(read, p1.graduation);
			getline(read, p1.masters);
			getline(read, p1.phd);
			getline(read, p1.leisureActivity);
			getline(read, p1.u1.password);
			while (!read.eof()) {
				cout << p1.u1.name << endl;
				cout << p1.u1.ID << endl;
				cout << p1.u1.about << endl;
				cout << p1.u1.shortBoi << endl;
				cout << p1.u1.city << endl;
				cout << p1.u1.country << endl;
				cout << p1.u1.industry << endl;
				cout << p1.u1.contactnumber << endl;
				cout << p1.u1.email << endl;
				cout << p1.dateOfBirth<< endl;
				cout << p1.gender << endl;
				cout << p1.leisureActivity << endl;
				cout << p1.jobTitle << endl;
				cout << p1.jobExperience<< endl;
				cout << p1.companyName << endl;
				cout << p1.skills << endl;
				cout << p1.schooleducation << endl;
				cout << p1.collegeEducation << endl;
				cout << p1.graduation << endl;
				cout << p1.masters << endl;
				cout << p1.phd << endl;
				getline(read, p1.u1.name);
				getline(read, p1.u1.ID);
				getline(read, p1.u1.about);
				getline(read, p1.u1.shortBoi);
				getline(read, p1.u1.shortBoi);
				getline(read, p1.u1.city);
				getline(read, p1.u1.country);
				getline(read, p1.u1.industry);
				getline(read, p1.u1.contactnumber);
				getline(read, p1.u1.email);
				getline(read, p1.dateOfBirth);
				getline(read, p1.gender);
				getline(read, p1.leisureActivity);
				getline(read, p1.jobTitle);
				getline(read, p1.jobExperience);
				getline(read, p1.companyName);
				getline(read, p1.skills);
				getline(read, p1.schooleducation);
				getline(read, p1.collegeEducation);
				getline(read, p1.graduation);
				getline(read, p1.masters);
				getline(read, p1.phd);
				getline(read, p1.leisureActivity);
				getline(read, p1.u1.password);
			}
			read.close();
		}
        // This Fucntion will search for person
		void search_for_person_in_all_persons_file() {
			cout << "Enter name to search :";
			string s;
			//int id;
			fflush(stdin);
			getline(cin,s);
			s = "Name : " + s;
			ifstream read;
			bool flag=false;
			string nname,iid,about,bio,shtbio,ccity,ccountry,iindustry,contact,eemail,dob,ggender,leisure,jotit,jobexp,comname;
			string skil,school,ccollege,grad,master,pphd,ppassword;
			read.open("All_Persons.txt");
			if(read.is_open()){
			getline(read, nname);
			getline(read, iid);
			getline(read, about);
			getline(read, bio);
			getline(read, shtbio);
			getline(read, ccity);
			getline(read, ccountry);
			getline(read, iindustry);
			getline(read, contact);
			getline(read, eemail);
			getline(read, dob);
			getline(read, ggender);
			getline(read, leisure);
			getline(read, jotit);
			getline(read, jobexp);
			getline(read, comname);
			getline(read, skil);
			getline(read, school);
			getline(read, ccollege);
			getline(read, grad);
			getline(read, master);
			getline(read, pphd);
			getline(read, leisure);
			getline(read, ppassword);

			while (!read.eof()) {
				if (nname == s) {
					flag=true;
					cout << nname << endl;
					cout << iid << endl;
					cout << about << endl;
					cout<<bio<<endl;
					cout << shtbio << endl;
					cout << ccity << endl;
					cout << ccountry << endl;
					cout << iindustry << endl;
					cout << contact << endl;
					cout << eemail << endl;
					cout << dob<< endl;
					cout << ggender << endl;
					cout << leisure << endl;
					cout << jotit << endl;
					cout << jobexp<< endl;
					cout << comname << endl;
					cout << skil << endl;
					cout << school << endl;
					cout << ccollege << endl;
					cout << grad << endl;
					cout << master << endl;
					cout << pphd << endl;
					//cout<< leisure<<endl;
				}
			getline(read, nname);
			getline(read, iid);
			getline(read, about);
			getline(read, bio);
			getline(read, shtbio);
			getline(read, ccity);
			getline(read, ccountry);
			getline(read, iindustry);
			getline(read, contact);
			getline(read, eemail);
			getline(read, dob);
			getline(read, ggender);
			getline(read, leisure);
			getline(read, jotit);
			getline(read, jobexp);
			getline(read, comname);
			getline(read, skil);
			getline(read, school);
			getline(read, ccollege);
			getline(read, grad);
			getline(read, master);
			getline(read, pphd);
			getline(read, leisure);
			getline(read, ppassword);
			}
			read.close();
			}else {
				cout<<"Cannot open file.\n";
			}
			if(flag==false){
				cout<<"No result found.\n";
			}
		}
		// This Fucntion will post on users wall
		void post_on_my_wall() {
			cout << "Enter the text block you want to post\n";
			fflush(stdin);
			fflush(stdin);
			getline(cin, p1.u1.post);
			string final_post = "Post : " + p1.u1.post;
			string file_name = p1.u1.ID + "_posts.txt";
			ofstream write_post;
			write_post.open(file_name, ios::binary | ios::app);
			write_post << final_post << endl;
			cout << "post written successfully\n";
			write_post.close();
		}
	    // This Fucntion will allow person to view his wall
		void view_my_wall() {
			ifstream read_wall;
			string file_name = p1.u1.ID + "_posts.txt";
			read_wall.open(file_name);
			if (!read_wall.is_open()) {
				cout << "no posts yet\n";
			} else {
				getline(read_wall, p1.u1.post);
				while (!read_wall.eof()) {
					cout << p1.u1.post << endl;
					getline(read_wall, p1.u1.post);
				}

				read_wall.close();
			}
		}
		// This Fucntion will allow person to view his newsfeed
		void view_my_newsfeed() {
			string iid;
			int post_count = 0;
			int flag_file = 0;
			string file_name1 = p1.u1.ID + "_connection.txt";
			ifstream read_connections;
			ifstream read_connections_post;
			read_connections.open(file_name1);
			if (!read_connections.is_open()) {
				cout << "Can't view your newsfeed cuz your dont have any connections\n";
			} else {
				while (!read_connections.eof()) {
					getline(read_connections,iid);
					string file_name2 = iid + "_posts.txt";
					//cout<<file_name2<<endl;
					read_connections_post.open(file_name2);
					if (!read_connections_post.is_open()) {
						//cout<<"cant open file cuz its not ID\n";
						flag_file = 0;
					} else {
						flag_file = 1;
					}
					if (flag_file == 1) {

						while (!read_connections_post.eof()) {
							if (post_count > 5) {
								break;
							}
							getline(read_connections_post, p1.u1.post);
							//cout<<p1.u1.post.size();
							if (p1.u1.post.size() > 0) {
								cout << "Post by ID : " << iid << "\t";
								cout << p1.u1.post << endl <<endl;
								post_count++;
								//getline(read_connections_post,p1.u1.post);
								//break;
							}
						}
					} else {
						//cout<<"flag_file is 0\n";
					}
					read_connections_post.close();

				}

			}
		}
		// This Fucntion wil allow person to search and apply on jobs by a given company
		void search_and_apply_for_jobs() {
			string name,postion,sal,req,id;
			string qualification;
			int flag=0;
			int ch;
			cout<<"Enter the name of Company you want to search for job\n";
			fflush(stdin);
			getline(cin,name);
			string filename= "Jobs_by_"+name+".txt";
			ifstream read;
			read.open(filename);
			if(!read.is_open()) {
				cout<<"Given company has no jobs opening as yet;\n";
			} else {
				cout<<"Following are the jobs posted by this company : \n";
				getline(read,id);
				getline(read,postion);
				getline(read,sal);
				getline(read,req);
				while(!read.eof()) {
					cout<<"Job ID : "<<id<<endl;
					cout<<"Postion required : "<<postion<<endl;
					cout<<"Salary offered : "<<sal<<endl;
					cout<<"Requiremnets/detials : "<<req<<endl;
					cout<<"1. Apply\n2. Next\n";
					cin>>ch;
					if(ch==1) {
						flag=1;
						cout<<"Enter follwoing : \n";
						cout<<"Qualification : ";
						fflush(stdin);
						getline(cin,qualification);
						cout<<"Past Experience : ";
						fflush(stdin);
						getline(cin,p1.jobExperience);
						cout<<"Relevant skill set : ";
						fflush(stdin);
						getline(cin,p1.skills);
						ofstream write;
						string filename1="Applications_for_" + name + ".txt";
						write.open(filename1,ios :: binary | ios :: app);
						write<<p1.u1.ID<<endl;
						write<<id<<endl;
						write<<qualification<<endl;
						write<<p1.jobExperience<<endl;
						write<<p1.skills<<endl;
						write.close();
						break;
					}
					getline(read,id);
					getline(read,postion);
					getline(read,sal);
					getline(read,req);
				}
				if(flag==1)
					cout<<"Applied successfully\n";
			}
			read.close();
		}
};

#endif

