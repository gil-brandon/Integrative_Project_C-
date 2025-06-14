// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

#include "series.h"

// Constructors

series::series() {
    id = "0";
    name = "Stranger Things";
    length = 0;
    genre = "Science Fiction";
    rating = 0;
    n_rating = 0.0;
    n_seasons = 0;
    n_episodes = 0;
}

series::series(string _id, string _name, int _length, string _genre, float _rating, int _n_rating, int _n_seasons, int _n_episodes) {
    id = _id;
    name = _name;
    length = _length;
    genre = _genre;
    rating = _rating;
    n_rating = _n_rating;
    n_seasons = _n_seasons;
    n_episodes = _n_episodes;
}

// Getters and setters

int series::getN_seasons() {
    return n_seasons;
}

void series::setN_seasons(int _n_seasons) {
    n_seasons = _n_seasons;
}

int series::getN_episodes() {
    return n_episodes;
}

void series::setN_episodes(int _n_episodes) {
    n_episodes = _n_episodes;
}

void series::addEpisode(episodes& ep) { // Method to add an episode to the series
    episodeList.push_back(ep);
}

vector<episodes> series::getAllEpisodes() { // Method to get all episodes of the series
    return episodeList;
}

// Override info method

void series::info() {
    cout << "***********************************" << endl;
    cout << "ID: " << id << endl;
    cout << name << " " << length << " minutes" << " | " << n_seasons << " seasons with " << n_episodes << " episodes" << endl;
    cout << "Genre: " << genre << " | Rating: " << rating << " (" << n_rating << " ratings)" << endl;
}

// Method to display episodes information

episodes series::info_episodes() {
    for (episodes& ep : episodeList) {
        ep.info_episodes();
    }
    return episodes();
}