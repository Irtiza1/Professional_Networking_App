#include<iostream>
#include<string>
#include<fstream>
#include <cstdio>
#include <sstream>
#include<vector>
#include "User.h"
using namespace std;
#ifndef COMPANY_H
#define COMPANY_H

struct Company_structure {
	User_structure u1;
	string website;
	string sectorType;
	string foundedDate;
};
struct Job {
	string job_id;
	string postion;
	string salary;
	string requirements_detials;
};

class Company :public User {
	private:
		struct Company_structure c1;
		struct Job j1;
	public:
		//default constructor
		Company() {
			c1.website = "No input yet";
			c1.sectorType = "No input yet";
			c1.foundedDate = "No input yet";
		}
		//setters and getters
		void set_postion(const string postion) {
			this->j1.postion=postion;
		}
		string get_postion() {
			return j1.postion;
		}
		void set_salary(const string salary) {
			this->j1.salary=salary;
		}
		string get_salary() {
			return j1.salary;
		}
		void set_requirements(const string req) {
			j1.requirements_detials=req;
		}
		string get_requirements() {
			return j1.requirements_detials;
		}
		void set_website(const string website) {
			this->c1.website = website;
		}
		string get_website()const {
			return this->c1.website;
		}
		void set_sectorType(const string sectorType) {
			this->c1.sectorType = sectorType;
		}
		string get_sectorType()const {
			return this->c1.sectorType;
		}
		void set_foundedDate(const string foundedDate) {
			this->c1.foundedDate = foundedDate;
		}
		string get_foundedDate()const {
			return this->c1.foundedDate;
		}
// This function will add data to file
		void Add_to_file() {
			ofstream write;
			write.open("All_Companies.txt", ios::binary | ios::app);
			write << get_ID() << endl;
			fflush(stdin);
			cout<<"hi"<<get_name()<<endl;
			write << get_name() << endl;
			write << get_about() << endl;
			write << get_shortBio() << endl;
			write << get_website() << endl;
			write << get_sectorType() << endl;
			write << get_foundedDate() << endl;
			write << get_city() << endl;
			write << get_country() << endl;
			write << get_industry() << endl;
			write << get_contactnumber() << endl;
			write << get_email()<<endl;
			write << get_password()<<endl;
			write.close();
			cout << "Data Saved to file\n";
		}
// This function will read data from file
		void Read_from_file() {
			ifstream read;
			read.open("All_Companies.txt");
			getline(read, c1.u1.ID);
			getline(read, c1.u1.name);
			getline(read, c1.u1.about);
			getline(read, c1.u1.shortBoi);
			getline(read, c1.website);
			getline(read, c1.sectorType);
			getline(read, c1.foundedDate);
			getline(read, c1.u1.city);
			getline(read, c1.u1.country);
			getline(read, c1.u1.industry);
			getline(read, c1.u1.contactnumber);
			while (!read.eof()) {
				cout <<"ID : "<< c1.u1.ID << endl;
				cout <<"Name : "<< c1.u1.name << endl;
				cout <<"About : "<< c1.u1.about << endl;
				cout <<"Short bio : "<< c1.u1.shortBoi << endl;
				cout <<"Website : "<< c1.website << endl;
				cout <<"Sector : "<< c1.sectorType << endl;
				cout <<"Founded on : "<< c1.foundedDate << endl;
				cout <<"City : " <<c1.u1.city << endl;
				cout <<"Country : "<< c1.u1.country << endl;
				cout <<"Industry : "<< c1.u1.industry << endl;
				cout <<"Contact no. : "<< c1.u1.contactnumber << endl;
				getline(read, c1.u1.ID);
				getline(read, c1.u1.name);
				getline(read, c1.u1.about);
				getline(read, c1.u1.shortBoi);
				getline(read, c1.website);
				getline(read, c1.sectorType);
				getline(read, c1.foundedDate);
				getline(read, c1.u1.city);
				getline(read, c1.u1.country);
				getline(read, c1.u1.industry);
				getline(read, c1.u1.contactnumber);
			}
			read.close();
		}
// This function will search for company
		void search_for_company_in_all_company_file() {
			string name;
			bool flag=false;
			//string s;
			cout << "enter name to search :";
			getline(cin,name);
			//s = "Name : " + s;
			string ID,nname,about,shortBoi,website,sectorType,foundedDate,city,country,industry,contactnumber;
			ifstream read;
			read.open("All_Companies.txt");
			if(read.is_open()) {
				getline(read, ID);
				getline(read, nname);
				getline(read, about);
				getline(read, shortBoi);
				getline(read, website);
				getline(read, sectorType);
				getline(read, foundedDate);
				getline(read, city);
				getline(read, country);
				getline(read, industry);
				getline(read, contactnumber);
				while (!read.eof()) {
					if (nname == name) {
						flag=true;
						cout <<"ID : "<< ID << endl;
						cout <<"Name : "<< name << endl;
						cout <<"About : "<< about << endl;
						cout <<"Short bio : "<< shortBoi << endl;
						cout <<"Website : "<< website << endl;
						cout <<"Sector : "<< sectorType << endl;
						cout <<"Founded on : "<< foundedDate << endl;
						cout <<"City : " <<city << endl;
						cout <<"Country : "<< country << endl;
						cout <<"Industry : "<< industry << endl;
						cout <<"Contact no. : "<< contactnumber << endl;
						break;
					} else {
						getline(read, ID);
						getline(read, nname);
						getline(read, about);
						getline(read, shortBoi);
						getline(read, website);
						getline(read, sectorType);
						getline(read, foundedDate);
						getline(read, city);
						getline(read, country);
						getline(read, industry);
						getline(read, contactnumber);
					}
				}
				read.close();
			} else {
				cout<<"Cannot open file.\n";
			}
			if(flag==false) {
				cout<<"No result found.\n";
			}

		}
// This function will take data input
		void input_Company_Data() {
			cout << "id: ";
			cin >> c1.u1.ID;
			cout << endl;
			cout << "Name : ";
			getline(cin, c1.u1.name);
			cout << endl;
			cout << "About : ";
			getline(cin, c1.u1.about);
			cout << endl;
			cout << "Short Bio : ";
			getline(cin, c1.u1.shortBoi);
			cout << endl;
			cout << "Website : ";
			getline(cin, c1.website);
			cout << endl;
			cout << "Sector type : ";
			getline(cin, c1.sectorType);
			cout << endl;
			cout << "Founded Date : ";
			getline(cin, c1.foundedDate);
			cout << endl;
			cout << "City : ";
			getline(cin, c1.u1.city);
			cout << endl;
			cout << "Country : ";
			getline(cin, c1.u1.country);
			cout << endl;
			cout << "Industry : ";
			getline(cin, c1.u1.industry);
			cout << endl;
			cout << "Contact number : ";
			cin >> c1.u1.contactnumber;
		}
// This function will log in company
		bool log_in() {
			bool check=false;
			string email,pass;
			cout<<"Email : ";
			cin>>email;
			cout<<"Password : ";
			cin>>pass;
			ifstream read;
			read.open("All_Companies.txt");
			getline(read,c1.u1.ID);
			getline(read,c1.u1.name);
			getline(read,c1.u1.about);
			getline(read,c1.u1.shortBoi);
			getline(read,c1.website);
			getline(read,c1.sectorType);
			getline(read,c1.foundedDate);
			getline(read,c1.u1.city);
			getline(read,c1.u1.country);
			getline(read,c1.u1.industry);
			getline(read,c1.u1.contactnumber);
			getline(read,c1.u1.email);
			getline(read,c1.u1.password);
			if(read.is_open()) {
				cout<<"Verifying company details , please wait\n";
				while(!read.eof()) {
					if(email==c1.u1.email && pass==c1.u1.password) {
						check=true;
						cout<<"Welcome Back ! "<<c1.u1.name<<endl;
						return true;
						break;
					} else {
						getline(read,c1.u1.ID);
						getline(read,c1.u1.name);
						getline(read,c1.u1.about);
						getline(read,c1.u1.shortBoi);
						getline(read,c1.website);
						getline(read,c1.sectorType);
						getline(read,c1.foundedDate);
						getline(read,c1.u1.city);
						getline(read,c1.u1.country);
						getline(read,c1.u1.industry);
						getline(read,c1.u1.contactnumber);
						getline(read,c1.u1.email);
						getline(read,c1.u1.password);
					}
				}
			} else {
				cout<<"Umable to open All company file\n";
			}
			read.close();
			if(check==false) {
				cout<<"No such account exist\n";
				return false;
			}
			return  true;
		}
//  This function will post on company wall
		void post_on_my_wall() {
			cout<<"Enter the text you want to post\n";
			fflush(stdin);
			getline(cin,c1.u1.post);
			string filename= c1.u1.name + "_company_posts.txt";
			ofstream write_post;
			write_post.open(filename, ios::binary | ios::app);
			write_post<<c1.u1.post<<endl;
			cout<<"Post written successfuly\n";
			write_post.close();
		}
// This function will view company wall
		void view_my_wall() {
			ifstream read_wall;
			string filename= c1.u1.name + "_company_posts.txt";
			read_wall.open(filename);
			if(!read_wall.is_open()) {
				cout<<"You havent posted anything yet\n";
			} else {
				getline(read_wall,c1.u1.post);
				while(!read_wall.eof()) {
					if(c1.u1.post.size()>0)
						cout<<"Post : "<<c1.u1.post<<endl;
					getline(read_wall,c1.u1.post);
				}
			}

		}
// This function will post jobs from a company
		void post_job() {
			cout<<"Lets post job\n";
			string filename= "Jobs_by_"+c1.u1.name+".txt";
			ofstream write;
			cout<<"Fill out following \n";
			cout<<"Job ID : ";
			fflush(stdin);
			getline(cin,j1.job_id);
			cout<<"Required Postion : ";
			fflush(stdin);
			getline(cin,j1.postion);
			cout<<"Salary offered : ";
			fflush(stdin);
			getline(cin,j1.salary);
			cout<<"Requirements/other details : ";
			fflush(stdin);
			getline(cin,j1.requirements_detials);
			write.open(filename, ios :: binary | ios :: app);
			write<<j1.job_id<<endl;
			write<<j1.postion<<endl;
			write<<j1.salary<<endl;
			write<<j1.requirements_detials<<endl;
			write.close();
		}
// This function will view jobs posted by a company
		void view_jobs_posted() {
			string filename= "Jobs_by_"+c1.u1.name+".txt";
			ifstream read;
			read.open(filename);
			if(!read.is_open()) {
				cout<<"no jobs posted yet\n";
			} else {
				cout<<"Viewing jobs posted : \n";
				getline(read,j1.job_id);
				getline(read,j1.postion);
				getline(read,j1.salary);
				getline(read,j1.requirements_detials);
				while(!read.eof()) {
					cout<<"Job ID : "<<j1.job_id<<endl;
					cout<<"Required postion : "<<j1.postion<<endl;
					cout<<"Salary offered : "<<j1.salary<<endl;
					cout<<"Requiremetns/other details : "<<j1.requirements_detials<<endl;
					getline(read,j1.job_id);
					getline(read,j1.postion);
					getline(read,j1.salary);
					getline(read,j1.requirements_detials);
				}
			}
			read.close();
		}
// This function will view applications for jobs by a company
		void view_applications_for_job() {
			ofstream write_employee;
			string emp_file="Employees_of_"+c1.u1.name+".txt";
			write_employee.open(emp_file,ios :: binary | ios :: app);
			string qualification,exp,skill,person_id,person_id1,comp_id,temp_id;
			ifstream read_application;
			int count=check_num_of_applicants();
			int count_track=0;
			int ch,pos;
			int flag=0;
			string filename="Applications_for_" + c1.u1.name + ".txt";
			read_application.open(filename);
			if(!read_application.is_open()) {
				cout<<"No applications yet\n";
			} else {
				cout<<"Following are applications\n";
				//	cout<<filename<<endl;
				getline(read_application,person_id);
				getline(read_application,comp_id);
				getline(read_application,qualification);
				getline(read_application,exp);
				getline(read_application,skill);
				//	cout<<"out while\n";
				while(!read_application.eof()) {
					//	cout<<"in while\n";
					cout<<"Applicant ID : "<<person_id<<endl;
					cout<<"Job ID applied for : "<<comp_id<<endl;
					temp_id=comp_id;
					cout<<"Qualification : "<<qualification<<endl;
					cout<<"Past experience : "<<exp<<endl;
					cout<<"Relevant skill set : "<<skill<<endl;
					read_application.close();
					cout<<"Choose : \n1.Accept\t2.Reject\n";
					count_track++;
					cin>>ch;
					if(ch==1) {
						ifstream read_application1;
						ofstream write_temp;
						string filename1="Applications_temp.txt";
						write_temp.open(filename1, ios :: binary | ios :: app);
						read_application1.open(filename);
						if(!read_application1.is_open()) {
							cout<<"Cant open this file\n";
						} else {
							//	cout<<"In else\n";
							getline(read_application1,person_id1);
							getline(read_application1,comp_id);
							getline(read_application1,qualification);
							getline(read_application1,exp);
							getline(read_application1,skill);
							while(!read_application1.eof()) {
								if(person_id==person_id1) {
									write_employee<<person_id1<<endl;
									write_employee<<comp_id<<endl;
									write_employee<<qualification<<endl;
									write_employee<<exp<<endl;
									write_employee<<skill<<endl;
									getline(read_application1,person_id1);
									getline(read_application1,comp_id);
									getline(read_application1,qualification);
									getline(read_application1,exp);
									getline(read_application1,skill);
									continue;
								} else {
									//	cout<<"In write else\n";
									write_temp<<person_id1<<endl;
									write_temp<<comp_id<<endl;
									write_temp<<qualification<<endl;
									write_temp<<exp<<endl;
									write_temp<<skill<<endl;
								}
								//	cout<<"After write else\n";
								getline(read_application1,person_id1);
								getline(read_application1,comp_id);
								getline(read_application1,qualification);
								getline(read_application1,exp);
								getline(read_application1,skill);
							}
							read_application1.close();
							write_temp.close();
							const char* oldname="Applications_temp.txt";
							string new_name_abc = string("Applications_for_") + c1.u1.name + ".txt";
							const char* new_name=new_name_abc.c_str();
							if(!remove(new_name))cout<<"file removed\n";
							rename(oldname,new_name);
						}
						//Removing from job file
						ifstream read_job;
						ofstream write_job;
						string filenaam="Jobs_by_" + c1.u1.name + ".txt";
						string filenaam1="temp_jobs.txt";
						read_job.open(filenaam);
						write_job.open(filenaam1,ios :: binary|ios :: app);
						getline(read_job,j1.job_id);
						getline(read_job,j1.postion);
						getline(read_job,j1.salary);
						getline(read_job,j1.requirements_detials);
						while(!read_job.eof()) {
							//	cout<<j1.job_id;
							//	cout<<temp_id;
							//		cout<<"up while\n";
							if(j1.job_id==temp_id) {
								//			cout<<"in in while\n";
								getline(read_job,j1.job_id);
								getline(read_job,j1.postion);
								getline(read_job,j1.salary);
								getline(read_job,j1.requirements_detials);
								continue;
							} else {
								//		cout<<"in this else\n";
								write_job<<j1.job_id<<endl;
								write_job<<j1.postion<<endl;
								write_job<<j1.salary<<endl;
								write_job<<j1.requirements_detials<<endl;
								getline(read_job,j1.job_id);
								getline(read_job,j1.postion);
								getline(read_job,j1.salary);
								getline(read_job,j1.requirements_detials);

							}

						}
						//	cout<<"ousdsadasd\n";
						read_job.close();
						write_job.close();
						const char* oldname1="temp_jobs.txt";
						string new_name_abc1 = string("Jobs_by_") + c1.u1.name + ".txt";
						const char* new_name1=new_name_abc1.c_str();
						//	cout<<new_name1<<endl;
						if(!remove(new_name1))cout<<"removed file\n";
						rename(oldname1,new_name1);
						write_employee.close();
					} else {
						//if rejected, only canditate would be remove from applications file and job would still be there in jobs file
						ifstream read_application1;
						ofstream write_temp;
						string filename1="Applications_temp.txt";
						write_temp.open(filename1, ios :: binary | ios :: app);
						read_application1.open(filename);
						if(!read_application1.is_open()) {
							cout<<"Cant open this file\n";
						} else {
							//	cout<<"In else\n";
							getline(read_application1,person_id1);
							getline(read_application1,comp_id);
							getline(read_application1,qualification);
							getline(read_application1,exp);
							getline(read_application1,skill);
							while(!read_application1.eof()) {
								if(person_id==person_id1) {
									getline(read_application1,person_id1);
									getline(read_application1,comp_id);
									getline(read_application1,qualification);
									getline(read_application1,exp);
									getline(read_application1,skill);
									continue;
								} else {
									//		cout<<"In write else\n";
									write_temp<<person_id1<<endl;
									write_temp<<comp_id<<endl;
									write_temp<<qualification<<endl;
									write_temp<<exp<<endl;
									write_temp<<skill<<endl;
								}
								//	cout<<"After write else\n";
								getline(read_application1,person_id1);
								getline(read_application1,comp_id);
								getline(read_application1,qualification);
								getline(read_application1,exp);
								getline(read_application1,skill);
							}
							read_application1.close();
							write_temp.close();
							const char* oldname="Applications_temp.txt";
							string new_name_abc = string("Applications_for_") + c1.u1.name + ".txt";
							const char* new_name=new_name_abc.c_str();
							if(!remove(new_name))cout<<"file removed\n";
							rename(oldname,new_name);
						}
					}
					//	cout<<"here\n";
					if(count_track<=count)
						read_application.open(filename);
					count_track++;
					//read_application.seekg(pos);
					getline(read_application,person_id);
					getline(read_application,comp_id);
					getline(read_application,qualification);
					getline(read_application,exp);
					getline(read_application,skill);
				}
			}




		}
// This function will check number of applicants for jobs
		int check_num_of_applicants() {
			string qualification,exp,skill,person_id,person_id1;
			string filename="Applications_for_" + c1.u1.name + ".txt";
			int count=0;
			ifstream read;
			read.open(filename);
			getline(read,person_id);
			getline(read,c1.u1.ID);
			getline(read,qualification);
			getline(read,exp);
			getline(read,skill);
			count++;
			while(!read.eof()) {
				getline(read,person_id);
				getline(read,c1.u1.ID);
				getline(read,qualification);
				getline(read,exp);
				getline(read,skill);
				count++;
			}
			read.close();
			cout<<count;
			return count;
		}
// This function will view employees hired by a company
		void view_employees() {
			ifstream read_employee;
			string emp_file="Employees_of_"+c1.u1.name+".txt";
			read_employee.open(emp_file);
			string qualification,exp,skill,person_id,person_id1,comp_id,temp_id;
			if(!read_employee.is_open()) {
				cout<<"No employees yet\n";
			} else {
				getline(read_employee,person_id1);
				getline(read_employee,comp_id);
				getline(read_employee,qualification);
				getline(read_employee,exp);
				getline(read_employee,skill);
				while (!read_employee.eof()) {
					cout<<"Employee ID : "<<person_id1<<endl;
					cout<<"Job ID : "<<comp_id<<endl;
					cout<<"Qualification : "<<qualification<<endl;
					cout<<"Experience : "<<exp<<endl;
					cout<<"Skill : "<<skill<<endl;
					getline(read_employee,person_id1);
					getline(read_employee,comp_id);
					getline(read_employee,qualification);
					getline(read_employee,exp);
					getline(read_employee,skill);
				}
				read_employee.close();

			}
		}
};
#endif