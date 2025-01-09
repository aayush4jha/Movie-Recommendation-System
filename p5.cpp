#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;

// Base class for common movie properties
class Movie {
protected:
    string name;
    int releaseYear;

public:
    Movie(string n, int year) : name(n), releaseYear(year) {}

    virtual void display() const = 0; 
    ~Movie() {};
};

// Class to store movie details for liked movies
class LikedMovie : public Movie {
private:
    string leadActor;
    string director;  
    float rating;

public:
   LikedMovie(string n, string actor, string dir, int year, float r)
                 : Movie(n, year), leadActor(actor), director(dir), rating(r) {}

    void display() const override  {
        cout << "- Name: " << name << ", Lead Actor: " << leadActor
             << ", Director: " << director
             << ", Release Year: " << releaseYear
             << ", Rating: " << rating << "/10" << endl;
    }
};

// Class to store movie details for the watchlist
class WatchlistMovie : public Movie {
public:
    WatchlistMovie(string n, int year) : Movie(n, year) {}

    void display() const override  {
        cout << "- Name: " << name << ", Release Year: " << releaseYear << endl;
    }
};

// Profile class that manages liked movies and watchlist
class Profile {
private:
    string userID;
    vector<LikedMovie> likedMovies;
    vector<WatchlistMovie> watchlist;

public:
    Profile(string id) : userID(id) {}  
    void addLikedMovie();  
    void addToWatchlist(); 
    void displayLikedMovies();  
    void displayWatchlist();  
    void display();  
};

// Function to add a liked movie
void Profile::addLikedMovie() {
    string name, leadActor, director;
    int releaseYear;
    float rating;

    cout << "Enter movie name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter lead actor name: ";
    getline(cin, leadActor);
    cout << "Enter director name: ";
    getline(cin, director);  
    cout << "Enter release year: ";
    cin >> releaseYear;
    cout << "Enter rating (out of 10): ";
    cin >> rating;

    likedMovies.emplace_back(name, leadActor, director, releaseYear, rating);
    cout << "Movie added to liked movies list!" << endl;
}

// Function to add a movie to the watchlist
void Profile::addToWatchlist() {
    string name;
    int releaseYear;

    cout << "Enter movie name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter release year: ";
    cin >> releaseYear;

    watchlist.emplace_back(name, releaseYear);
    cout << "Movie added to watchlist!" << endl;
}

// Function to display liked movies
void Profile::displayLikedMovies() {
    if (likedMovies.empty()) {
        cout << "No liked movies to display." << endl;
        return;
    }

    cout << "Liked Movies:" << endl;
    for (const auto& movie : likedMovies) {
        movie.display();
    }
}

// Function to display watchlist
void Profile::displayWatchlist() {
    if (watchlist.empty()) {
        cout << "No movies in watchlist to display." << endl;
        return;
    }

    cout << "Upcoming Movies Watchlist:" << endl;
    for (const auto& movie : watchlist) {
        movie.display();
    }
}

// Function to display the profile
void Profile::display() {
    cout << "Profile (UserID: " << userID << ")" << endl;
    displayLikedMovies();
    displayWatchlist();
}


// Recommendation class
class Recommendation {
private:
    unordered_map<string, string> genreFiles;

public:

    Recommendation() {
        genreFiles["Comedy"] = "C:/Users/tarun/OneDrive/Desktop/project/comedy.txt";
        genreFiles["Action"] = "C:/Users/tarun/OneDrive/Desktop/project/action.txt";
        genreFiles["Horror"] = "C:/Users/tarun/OneDrive/Desktop/project/horror.txt";
        genreFiles["Thriller"] = "C:/Users/tarun/OneDrive/Desktop/project/thriller.txt";
        genreFiles["Romance"] = "C:/Users/tarun/OneDrive/Desktop/project/romance.txt";
        genreFiles["Sci-Fi"] = "C:/Users/tarun/OneDrive/Desktop/project/sci_fi.txt";
        genreFiles["Fantasy"] = "C:/Users/tarun/OneDrive/Desktop/project/fantasy.txt";
        genreFiles["Adventure"] = "C:/Users/tarun/OneDrive/Desktop/project/adventure.txt";
    }

    void displayGenreMovies(const string& genre);  
    void displayBollywoodMovies();  
    void displayWebShows();  
    void displayOscarWinningMovies(); 
    void displayUpcomingMovies();  
    void display();  
};

// Function to display movies for a given genre
void Recommendation::displayGenreMovies(const string& genre) {
    if (genreFiles.find(genre) != genreFiles.end()) {
        
        ifstream file(genreFiles[genre]);
        if (!file) {
            cout << "Error opening file for " << genre << endl;
            return;
        }
        string movie;
        while (getline(file, movie)) {
            cout << "- " << movie << endl;
        }
        file.close();
    } else {
        cout << "No recommendations available for " << genre << endl;
    }
}

// Function to display Bollywood movies
void Recommendation::displayBollywoodMovies() {
    cout << "Displaying Bollywood movies" << endl;
    ifstream file("C:/Users/tarun/OneDrive/Desktop/project/last2decades.txt");
    if (!file) {
        cout << "Error opening Bollywood movies file." << endl;
        return;
    }
    string movie;
    while (getline(file, movie)) {
        cout << "- " << movie << endl;
    }
    file.close();
}

// Function to display Web Shows
void Recommendation::displayWebShows() {
    cout << "Displaying Web Shows " << endl;
    ifstream file("C:/Users/tarun/OneDrive/Desktop/project/webshows.txt");
    if (!file) {
        cout << "Error opening Web Shows file." << endl;
        return;
    }
    string show;
    while (getline(file, show)) {
        cout << "- " << show << endl;
    }
    file.close();
}

// Function to display Oscar-winning movies
void Recommendation::displayOscarWinningMovies() {
    cout << "Displaying Oscar-winning movies " << endl;
    ifstream file("C:/Users/tarun/OneDrive/Desktop/project/oscarwin.txt");
    if (!file) {
        cout << "Error opening Oscar-winning movies file." << endl;
        return;
    }
    string movie;
    while (getline(file, movie)) {
        cout << "- " << movie << endl;
    }
    file.close();
}

// Function to display upcoming shows and movies
void Recommendation::displayUpcomingMovies() {
    cout << "Displaying upcoming shows and movies " << endl;
    ifstream file("C:/Users/tarun/OneDrive/Desktop/project/upcomingmovies.txt");
    if (!file) {
        cout << "Error opening upcoming movies file." << endl;
        return;
    }
    string movie;
    while (getline(file, movie)) {
        cout << "- " << movie << endl;
    }
    file.close();
}

// Function to display the available recommendation options
void Recommendation::display() {
    cout << "Available Recommendations:" << endl;
    cout << "1. Genres (Available genres are:";

    for (const auto& pair : genreFiles) {
        cout << " " << pair.first << ",";
    }
    
    cout << ")\n2. Bollywood Movies\n3. Web Shows\n4. Oscar Winning Movies\n5. Upcoming Shows and Movies\n";
}

int main() {
    unordered_map<string, Profile*> profiles; 
    Recommendation recommendations;

    string title = "Movie Recommendation System";
    

    while (true) {
        cout << "\n"  << "==============================    " << title << "    =======================================\n" << endl;
        cout << "1. Create Profile\n2. Search Profile\n3. See Recommendations\n4. Exit\n" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        cout << endl; 

        switch (choice) {
        case 1: {
            string id;
            cout << "Enter UserID: ";
            cin >> id;
            profiles[id] = new Profile(id);
            cout << "\nProfile created successfully!\n" << endl;
            break;
        }

        case 2: {
            string id;
            cout << "Enter UserID: ";
            cin >> id;
            cout << endl;
            if (profiles.find(id) != profiles.end()) {
                Profile* profile = profiles[id];
                int subChoice;
                while (true) {
                    cout << "1. Add Liked Movie\n2. Add to Watchlist\n3. Display Profile\n4. Go Back\n" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    cout << endl;
                    switch (subChoice) {
                    case 1:
                        profile->addLikedMovie();
                        cout << endl;
                        break;
                    case 2:
                        profile->addToWatchlist();
                        cout << endl;
                        break;
                    case 3:
                        profile->display();
                        cout << endl;
                        break;
                    case 4:
                        break; 
                    default:
                        cout << "Invalid choice. Try again.\n" << endl;
                    }
                    if (subChoice == 4) break;
                }
            } else {
                cout << "Profile not found!\n" << endl;
            }
            break;
        }

        case 3:
            recommendations.display();
            cout << endl;
            int recommendationChoice;
            cout << "Enter choice for recommendations: ";
            cin >> recommendationChoice;
            cout << endl;
            switch (recommendationChoice) {
            case 1: {
                string genre;
                cout << "Enter genre (Comedy, Action, Horror, etc.): ";
                cin >> genre;
                cout << endl;
                recommendations.displayGenreMovies(genre);
                cout << endl;
                break;
            }
            case 2:
                recommendations.displayBollywoodMovies();
                cout << endl;
                break;
            case 3:
                recommendations.displayWebShows();
                cout << endl;
                break;
            case 4:
                recommendations.displayOscarWinningMovies();
                cout << endl;
                break;
            case 5:
                recommendations.displayUpcomingMovies();
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Try again.\n" << endl;
            }
            break;

        case 4:
            cout << "Exiting program.\n" << endl;
            for (auto& pair : profiles) {
                delete pair.second;
            }

            return 0;
            
        default:
            cout << "Invalid choice. Try again.\n" << endl;
        }
    }
}
