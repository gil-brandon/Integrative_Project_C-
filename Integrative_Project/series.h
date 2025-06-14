// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#ifndef SERIES_H
#define SERIES_H

#include "Videos.h"
#include "episodes.h" // Composition relationship with episodes

class series: public Videos { // Inherit from Videos class
private: // Private members to store series details
    int n_seasons;
    int n_episodes;
    vector<episodes> episodeList; // Vector to store episodes of the series
public:
    series();
    // Constructor with parameters
    series(string _id, string _name, int _length, string _genre, float _rating, int _n_rating, int _n_seasons, int _n_episodes);
    // Getters and Setters
    void setN_seasons(int _n_seasons);
    int getN_seasons();
    void setN_episodes(int _n_episodes);
    int getN_episodes();
    void addEpisode(episodes& ep); // Method to add episodes to the series
    vector<episodes> getAllEpisodes(); // Method to get all episodes
    // Override info method to display series details
    void info() override;
    // Method to display episodes information
    episodes info_episodes();

};

#endif //SERIES_H