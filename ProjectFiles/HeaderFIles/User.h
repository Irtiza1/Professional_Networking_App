#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
#ifndef USER_H
#define USER_H
struct User_structure
{
	string name;
	string about;
	string shortBoi;
	string city;
	string country;
	string industry;
	string contactnumber;
	string email;
	string password;
	string ID;
	string post;
	string message;
	string bio;
};

class User {
private:
	struct User_structure u1;
public:
	User() {}
	void set_ID(const string ID) {
		this->u1.ID = ID;
	}
	void set_bio(const string bio){
		this->u1.bio=bio;
	}
	string get_bio()const{
		return u1.bio;
	}
	string get_ID()const {
		return u1.ID;
	}
	void set_name(const string name) {
		this->u1.name = name;
	}
	string get_name()const {
		return u1.name;
	}

	void set_about(const string about) {
		this->u1.about = about;
	}
	string get_about()const {
		return u1.about;
	}

	void set_shortBio(const string shortBio) {
		this->u1.about = shortBio;
	}
	string get_shortBio() const {
		return u1.shortBoi;
	}

	void set_city(const string city) {
		this->u1.city = city;
	}
	string get_city()const {
		return u1.city;

	}

	void set_country(const string country) {
		this->u1.country = country;
	}
	string get_country()const {
		return u1.country;
	}

	void set_industry(const string industry) {
		this->u1.industry = industry;
	}
	string get_industry()const {
		return u1.industry;
	}

	void set_contactnumber(const int contactnumber) {
		this->u1.contactnumber = contactnumber;
	}
	string get_contactnumber()const {
		return u1.contactnumber;
	}

	void set_email(const string email) {
		this->u1.email = email;
	}
	string get_email()const {
		return u1.email;
	}
	void set_password(const string password) {
		this->u1.password = password;
	}
	string get_password()const {
		return u1.password;
	}

	virtual void Add_to_file() = 0;
	virtual void Read_from_file() = 0; //These funcs will have implementation in derived classes!
	virtual void post_on_my_wall()=0;
	virtual void view_my_wall()=0;
	virtual bool log_in()=0;

};

#endif
