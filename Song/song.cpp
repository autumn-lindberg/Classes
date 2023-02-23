// Name: Autumn Valls
// Course: CS260
// Project: Project 1
#include "song.h"
using namespace std;

// getters
char * Song::getArtist() const {
	if (this->artist) {
		char * returnArtist = new char[strlen(this->artist) + 1];
		strcpy(returnArtist, this->artist);
		return returnArtist;
	}
	else return nullptr;
}
char * Song::getTitle() const {
	if (this->title) {
		char * returnTitle = new char[strlen(this->title) + 1];
		strcpy(returnTitle, this->title);
		return returnTitle;
	}
	else return nullptr;
}
float Song::getLength() const {
	return this->length;
}
int Song::getLikes() const {
	return this->likes;
}
// setters
void Song::setArtist(char * newArtist) {
	if (this->artist) delete [] this->artist;
	this->artist = new char[strlen(newArtist) + 1];
	strcpy(this->artist, newArtist);
}
void Song::setTitle(char * newTitle) {
	if (this->artist) delete [] this->title;
	this->title = new char[strlen(newTitle) + 1];
	strcpy(this->title, newTitle);
}
void Song::setLenth(float newLength) {
	this->length = newLength;
}
void Song::setLikes(int newLikes) {
	this->likes = newLikes;
}
// constructors
Song::Song() : artist(nullptr), title(nullptr), length(0.0), likes(0){}
Song::Song(const Song & src) {
	if (src.artist) {
		this->artist = new char[strlen(src.artist) + 1];
		strcpy(this->artist, src.artist);
	}
	else this->title = nullptr;
	if (src.title) {
		this->title = new char[strlen(src.title) + 1];
		strcpy(this->title, src.title);
	}
	else this->title = nullptr;
	this->length = src.length;
	this->likes = src.likes;
}
Song::Song(char * artist, char * title, float length, int likes) {
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
	this->length = length;
	this->likes = likes;
}
// destructor
Song::~Song() {
	if (this->artist) {
		delete [] this->artist;
		this->artist = nullptr;
	}
	if (this->title) {
		delete [] this->title;
		this->title = nullptr;
	}
	this->length = 0.0;
	this->likes = 0;
}
// overloaded operators
const Song & Song::operator = (const Song & src) {
	if (this != &src) {
		// destructor code
		if (this->title) {
			delete [] this->title;
			this->title = nullptr;
		}
		if (this->artist) {
			delete [] this->artist;
			this->artist = nullptr;
		}
		this->length = 0.0;
		this->likes = 0;
		// copy constructor code
		if (src.artist) {
			this->artist = new char[strlen(src.artist) + 1];
			strcpy(this->artist, src.artist);
		}
		else this->artist = nullptr;
		if (src.title) {
			this->title = new char[strlen(src.title) + 1];
			strcpy(this->title, src.title);
		}
		else this->title = nullptr;
		this->length = src.length;
		this->likes = src.likes;
	}
	return *this;
}
ostream & operator << (ostream & out, const Song & src) {
	char * tempArtist = src.getArtist();
	char * tempTitle  = src.getTitle();
	if (tempArtist) {
		out << setw(20) << tempArtist;
	}
	else out << setw(20) << "NOT SET";
	if (tempTitle) {
		out << setw(25) << tempTitle;
	}
	else out << setw(35) << "NOT SET";
	out << setw(10) << src.getLength();
	out << setw(15) << src.getLikes();
	if (tempArtist) {
		delete [] tempArtist;
		tempArtist = nullptr;
	}
	if (tempTitle) {
		delete [] tempTitle;
		tempTitle = nullptr;
	}
	return out;
}
bool operator > (const Song & a, const Song & b) {
	if (a.getLikes() > b.getLikes()) {
		return true;
	}
	else return false;
}
bool operator < (const Song & a, const Song & b) {
	if (a.getLikes() < b.getLikes()) {
		return true;
	}
	else return false;
}
