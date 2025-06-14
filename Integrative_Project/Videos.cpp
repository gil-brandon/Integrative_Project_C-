// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#include "Videos.h"

// Constructors

Videos::Videos() {
    id = "0";
    name = "Unknown";
    length = 0;
    genre = "Unknown";
    rating = 0.0;
    n_rating = 0;
}

Videos::Videos(string _id, string _name, int _length, string _genre, float _rating, int _n_rating) {
    name = _name;
    id = _id;
    length = _length;
    genre = _genre;
    rating = _rating;
    n_rating = _n_rating;
}

// Getters and Setters

string Videos::getId() {
    return id;
}

void Videos::setId(string _id) {
    id = _id;
}

string Videos::getName() {
    return name;
}

void Videos::setName(string _name) {
    name = _name;
}

int Videos::getLength() {
    return length;
}

void Videos::setLength(int _length) {
    length = _length;
}

string Videos::getGenre() {
    return genre;
}

void Videos::setGenre(string _genre) {
    genre = _genre;
}

float Videos::getRating() {
    return rating;
}

void Videos::setRating(float _rating) {
    rating = _rating;
}

int Videos::getN_rating() {
    return n_rating;
}

void Videos::setN_rating(int _n_rsting) {
    n_rating = _n_rsting;
}

// Method to display video information

void Videos::info() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Length: " << length << " minutes" << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << " (" << n_rating << " ratings)" << endl;
}