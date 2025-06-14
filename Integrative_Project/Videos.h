// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#ifndef VIDEOS_H
#define VIDEOS_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Videos {
protected: // Protected members to allow derived classes to access them
    string id;
    string name;
    int length;
    string genre;
    float rating;
    int n_rating;
public: // Public members for access from outside the class
    Videos();
    Videos(string _id, string _name, int _length, string _genre, float _rating, int _n_rating);
    // Getters and Setters
    string getId();
    void setId(string _id);
    string getName();
    void setName(string _name);
    int getLength();
    void setLength(int _length);
    string getGenre();
    void setGenre(string _genre);
    float getRating();
    void setRating(float _rating);
    int getN_rating();
    void setN_rating(int _n_rating);
    virtual void info() = 0; // Pure virtual function to make Videos an abstract class
};

#endif //VIDEOS_H