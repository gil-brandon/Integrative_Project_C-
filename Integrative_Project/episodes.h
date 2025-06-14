// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#ifndef EPISODES_H
#define EPISODES_H

#include <string>
#include <iostream>
using namespace std;

class episodes {
private: // Private members to store episode details
    string id;
    string name;
    int length;
    float rating;
    int n_rating;
public:
    episodes();
    // Constructor with parameters
    episodes(string _id, string _name, int _length, float _rating, int _n_rating);
    void setId(int _id);
    string getId();
    void setName(string _name);
    string getName();
    void setLength(int _length);
    int getLength();
    void setRating(float _rating);
    float getRating();
    void setN_rating(int _n_rating);
    int getN_rating();
    // Method to display episode information
    void info_episodes();
};

#endif //EPISODES_H