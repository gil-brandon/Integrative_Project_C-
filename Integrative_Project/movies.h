// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#ifndef MOVIES_H
#define MOVIES_H

#include "Videos.h"

class movies: public Videos { // Inherit from Videos class
public:
    movies();
    // Default constructor
    movies(string _id, string _name, int _length, string _genre, float _rating, int _n_rating);
    // Override info method to display movie details
    void info() override;
};

#endif //MOVIES_H