// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#include "movies.h"

// Constructors

movies::movies() {
    id = "0";
    name = "Unknown";
    length = 0;
    genre = "Unknown";
    rating = 0.0;
    n_rating = 0;
}

movies::movies(string _id, string _name, int _length, string _genre, float _rating, int _n_rating) {
    id = _id;
    name = _name;
    length = _length;
    genre = _genre;
    rating = _rating;
    n_rating = _n_rating;
}

// Override info method

void movies::info() {
    cout << "***********************************" << endl;
    cout << "ID: " << id << endl;
    cout << name <<" " << length << " minutes" << endl;
    cout << "Genre: " << genre << " | Rating: " << rating << " (" << n_rating << " ratings)" << endl;
}