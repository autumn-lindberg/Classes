// Name: Autumn Valls
// Course: CS260
// Project: Project 1
#pragma once
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

class Song {
	private:
		char * artist;
		char * title;
		float length;
		int likes;
	public:
		// getters
		char * getArtist() const;
		char * getTitle() const;
		float getLength() const;
		int getLikes() const;
		// setters
		void setArtist(char * newArtist);
		void setTitle(char * newTitle);
		void setLenth(float newLength);
		void setLikes(int newLikes);
		// constructors
		Song();
		Song(const Song & src);
		Song(char * artist, char * title, float length, int likes);
		// destructor
		~Song();
		// overloaded operators
		const Song & operator = (const Song & src);
		friend ostream & operator << (ostream & out, const Song & src);
};

// overloaded operators
bool operator < (const Song & a, const Song & b);
bool operator > (const Song & a, const Song & b);
