// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#include "episodes.h"

// Constructors

episodes::episodes() {
    id = "0";
    name = "Unknown";
    length = 0;
    rating = 0.0;
    n_rating = 0;
}

episodes::episodes(string _id, string _name, int _length, float _rating, int _n_rating) {
    id = _id;
    name = _name;
    length = _length;
    rating = _rating;
    n_rating = _n_rating;
}

// Getters and Setters

string episodes::getId() {
    return id;
}

void episodes::setId(int _id) {
    id = _id;
}

string episodes::getName() {
    return name;
}

void episodes::setName(string _name) {
    name = _name;
}

int episodes::getLength() {
    return length;
}

void episodes::setLength(int _length) {
    length = _length;
}

float episodes::getRating() {
    return rating;
}

void episodes::setRating(float _rating) {
    rating = _rating;
}

int episodes::getN_rating() {
    return n_rating;
}

void episodes::setN_rating(int _n_rsting) {
    n_rating = _n_rsting;
}

// Method to display episode information

void episodes::info_episodes() {
    cout << "***********************************" << endl;
    cout << "Episode ID: " << id << endl;
    cout << name << " " << length << " minutes" << endl;
    cout << "Rating: " << rating << " (" << n_rating << " ratings)" << endl;
}