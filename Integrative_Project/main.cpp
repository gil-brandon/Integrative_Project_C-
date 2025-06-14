// Gil Brandon Garcia Contreras - A01254164
// Valeria Gonzalez Nava - A00842141

// We include all the necessary headers and libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Videos.h"
#include "movies.h"
#include "series.h"
#include "episodes.h"
using namespace std;

// We define the variables
string r;
vector<Videos*> catalog;
int length, n_rating, seasons, episodesTotal;
string name, genre, type, id, ep_id, line;
float rating;

int main() {
    while (true) { // Main loop for the program
        // Menu display
        cout << "1. Load data file" << endl;
        cout << "2. Show all the videos." << endl;
        cout << "3. Show the videos with a specific rating or from a specific genre." << endl;
        cout << "4. Show the episodes of a specific series with a specific rating." << endl;
        cout << "5. Show the movies with a specific rating." << endl;
        cout << "6. Rate a video." << endl;
        cout << "7. Save data file." << endl;
        cout << "8. Exit." << endl;
        cin >> r;
        // Functionality 1
        if (r == "1") {
            // Load data from the file
            ifstream file("C://Users//gbgar//Desktop//Programar//POOCLion//Integrative_Project//Catalog.txt");
            // Check if the file opened successfully
            if (!file) {
                cout << "Error opening file." << endl;
            }
            else {
                cout << "File opened successfully." << endl;
            }
            // Read the file line by line
            while (getline(file, line)) {
                // Parse the line to extract video information
                stringstream ss(line);
                ss >> type;
                // Check the type of video
                if (type == "M") {
                    // Add movie to the catalog
                    ss >> id >> name >> length >> genre >> rating >> n_rating;
                    catalog.push_back(new movies(id, name, length, genre, rating, n_rating));
                    cout << "Added movie " << name << "." << endl;
                }
                else if (type == "S") {
                    // Add series to the catalog
                    ss >> id >> name >> length >> genre >> rating >> n_rating >> seasons >> episodesTotal;
                    catalog.push_back(new series(id, name, length, genre, rating, n_rating, seasons, episodesTotal));
                    cout << "Added series " << name << "." << endl;
                }
                else if (type == "E") {
                    // Add episode to a series
                    ss >> id >> ep_id >> name >> length >> rating >> n_rating;
                    episodes e(ep_id, name, length, rating, n_rating);
                    // Find the series to which the episode belongs
                    for (Videos* v : catalog) {
                        series* s = dynamic_cast<series*>(v); // Dynamic cast to check if v is a series
                        if (s && s->getId() == id) {
                            s->addEpisode(e); // Add the episode to the series
                            cout << "Added episode " << name <<" to series " << s->getName() << "." << endl;
                            break;
                        }
                    }
                }
            }
            // Close the file after reading
            file.close();
            cout << "Data loaded successfully." << endl;
        // Functionality  2
        } else if (r == "2") {
            // Show all videos in the catalog
            for (Videos* v : catalog) {
                v->info();
            }
        // Functionality 3
        } else if (r == "3") {
            cout << "Search by: " << endl;
            cout << "1. Rating" << endl;
            cout << "2. Genre" << endl;
            cout << "3. Both" << endl;
            cin >> r;
            rating = -1;
            if (r == "1" || r == "3") {
                // Ask for rating
                cout << "Enter a rating: ";
                cin >> rating;
            }
            if (r == "2" || r == "3") {
                // Ask for genre
                cout << "Enter a genre: " << endl;
                vector<string> genres = {};
                for (Videos* g : catalog) {
                    if (find(genres.begin(), genres.end(), g->getGenre()) == genres.end()) {
                        genres.push_back(g->getGenre()); // Add genre to the vector if not already present
                        cout << g->getGenre() << endl; // Display available genres
                    }
                }
                cin >> genre;
            }
            for (Videos* v : catalog) {
                if (r == "1" && v->getRating() >= rating) {
                    v->info();
                } else if (r == "2" && v->getGenre() == genre) {
                    v->info();
                } else if (r == "3" && v->getRating() >= rating && v->getGenre() == genre) {
                    v->info();
                }
            }
        // Functionality 4
        } else if (r == "4") {
            // Ask for series ID or name and rating
            cout << "Enter series ID or name: ";
            cin >> id;
            cout << "Enter episode rating: ";
            cin >> rating;
            // Check if the series exists in the catalog
            for (Videos* v : catalog) {
                series* s = dynamic_cast<series*>(v); // Dynamic cast to check if v is a series
                if (s && (s->getId() == id || s->getName() == id)) {
                    cout << s->getName() << " matching episodes: " << endl;
                    for (episodes& ep : s->getAllEpisodes()) { // Get all episodes of the series
                        if (ep.getRating() >= rating) {
                            ep.info_episodes();
                        }
                    }
                    break;
                }
            }
        // Functionality 5
        } else if (r == "5") {
            // Ask for the rating
            cout << "Enter a rating: ";
            cin >> rating;
            // Check if the movie exist in the catalog
            for (Videos* v : catalog) {
                movies* m = dynamic_cast<movies*>(v); // Dynamic cast to check if v is a movie
                if (m && m->getRating() >= rating) {
                    m->info();
                }
            }
        // Functionality 6
        } else if (r == "6") {
            // Ask for video ID or name and rating
            cout << "Enter video ID or name: ";
            cin >> id;
            rating = -1;
            while (rating < 0 || rating > 5) { // Validate rating input
                cout << "Enter a valid rating (0-5): ";
                cin >> rating;
            }
            // Check if the video exists in the catalog
            for (Videos* v : catalog) {
                if (v->getId() == id || v->getName() == id) {
                    // Calculate the rating of the video
                    int count = v->getN_rating()+1;
                    float avg = v->getRating();
                    float newAvg = (avg * (count-1) + rating) / (count);
                    v->setRating(newAvg); // Update the rating
                    v->setN_rating(count); // Update the number of ratings
                    cout << "Rating updated. New average: " << newAvg << " (" << count << " ratings)." << endl;
                    break;
                }
            }
        // Functionality 7
        } else if (r == "7") {
            // Save the progress to a file
            ofstream file("C://Users//gbgar//Desktop//Programar//POOCLion//Integrative_Project//Catalog.txt");
            // Check if the file opened successfully
            if (!file) {
                cout << "Error saving file." << endl;
            }
            // Write the catalog to the file
            for (Videos* v : catalog) {
                if (movies* m = dynamic_cast<movies*>(v)) {
                    file << "M " << m->getId() << " " << m->getName() << " "
                            << m->getLength() << " " << m->getGenre() << " "
                            << m->getRating() << " " << m->getN_rating() << endl;
                }
                else if (series* s = dynamic_cast<series*>(v)) {
                    file << "S " << s->getId() << " " << s->getName() << " "
                            << s->getLength() << " " << s->getGenre() << " "
                            << s->getRating() << " " << s->getN_rating() << " "
                            << s->getN_seasons() << " " << s->getN_episodes() << endl;
                    for (episodes& ep : s->getAllEpisodes()) {
                        file << "E " << s->getId() << " " << ep.getId() << " "
                                << ep.getName() << " " << ep.getLength() << " "
                                << ep.getRating() << " " << ep.getN_rating() << endl;
                    }
                }
            }
            // Close the file
            file.close();
            cout << "File saved successfully" << endl;
        // Functionality 8
        } else if (r== "8") {
            // Exit the program
            cout << "Thanks for using the program :D" << endl;
            break;
        // Invalid option
        } else {
            cout << "Invalid option." << endl;
        }
        cout << "***********************************" << endl;
        cout << "Input any key to continue." << endl;
        cin >> r;
    }
    return 0;
}

















