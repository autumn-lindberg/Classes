#include "party.h"
using namespace std;

// constructors
Party::Party() {
	this->name = new char[2];
	strcpy(this->name, " ");
	this->numPeople = 0;
	this->accomodation = 'n';
	this->promos = false;
	this->email = new char[2];
	strcpy(this->email, " ");
}
Party::Party(const Party & src) {
	if (src.name) {
		this->name = new char[strlen(src.name) + 1];
		strcpy(this->name, src.name);
	}
	else this->name = nullptr;
	this->numPeople = src.numPeople;
	this->accomodation = src.accomodation;
	this->promos = src.promos;
	if (src.email) {
		this->email = new char[strlen(src.email) + 1];
		strcpy(this->email, src.email);
	}
	else this->email = nullptr;
}
Party::Party(char * name, int people, char accomodation, bool promos, char * email) {
	if (name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else this->name = nullptr;
	this->numPeople = people;
	this->accomodation = accomodation;
	his->promos = promos;
	if (email) {
		this->email = new char[strlen(email) + 1];
		strcpy(this->email, email);
	}
	else this->email = nullptr;
}
// destructor
Party::~Party() {
	if (this->name) {
		delete [] this->name;
		this->name = nullptr;
	}
	this->numPeople = 0;
	this->accomodation = 'n';
	this->promos = false;
	if (this->email) {
		delete [] this->email;
		this->email = nullptr;
	}
}
// overloaded operators (assignment and output)
Party & Party::operator = (const Party & src) {
	// don't self-copy
	if (this != &src) {
		if (this->name) delete [] this->name;
		if (this->email) delete [] this->email;
		if (src.name) {
			this->name = new char[strlen(src.name) + 1];
			strcpy(this->name, src.name);
		}
		else this->name = nullptr;
		if (src.email) {
			this->email = new char[strlen(src.email) + 1];
			strcpy(this->email, src.email);
		}
		else this->email = nullptr;
		this->numPeople = src.numPeople;
		this->accomodation = src.accomodation;
		this->promos = src.promos;
	}
	return *this;
}
ostream & operator << (ostream & out, const Party & src) {
	src.display();
	return out;
}
// getters
char * Party::getName() const {
	if (!(this->name)) return nullptr;
	else {
		char * nameCopy = new char[strlen(this->name) + 1];
		strcpy(nameCopy, this->name);
		return nameCopy;
	}
}
int Party::getNumPeople() const {
	return this->numPeople;
}
char Party::getAccomodation() const {
	return this->accomodation;
}
bool Party::getPromos() const {
	return this->promos;
}
char * Party::getEmail() const {
	if (!(this->email)) return nullptr;
	else {
		char * emailCopy = new char[strlen(this->email) + 1];
		strcpy(emailCopy, this->email);
		return emailCopy;
	}
}
// setters
void Party::setName(char * name) {
	if (this->name) delete [] this->name;
	if (!name) this->name = nullptr;
	else {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}
void Party::setEmail(char * email) {
	if (this->email) delete [] this->email;
	if (!email) this->email = nullptr;
	else {
		this->email = new char[strlen(email) + 1];
		strcpy(this->email, email);
	}
}
void Party::setNumPeople(int people) {
	this->numPeople = numPeople;
}
void Party::setAccomodation(char accomodation) {
	this->accomodation = accomodation;
}
void Party::setPromos(bool promo) {
	this->promos = promos;
}
// display
void Party::display() const {
	cout << left;
	cout << setw(19) << this->name;
	cout << setw(6) << this->numPeople;
	cout << setw(20);
	if (this->accomodation == 'N') {
		cout << "NO ACCOMODATIONS";
	}
	if (this->accomodation == 'W') {
		cout << "CORKAGE FEE";
	}
	if (this->accomodation == 'C') {
		cout << "BYO CAKE FEE";
	}
	if (this->accomodation == 'H') {
		cout << "HIGH CHAIR NEEDED";
	}
	cout << setw(6);
	if (this->promos) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	cout << setw(25) << this->email;
	cout << endl;
}
