#include <string>
#include <fstream>

// Story struct, store metadata of the story from the file
struct Story {
    std::string title;
    std::string url;
    int score;
};

Story *readFile(std::ifstream &storiesFile, int numStories);
int findMode(Story *stories, int numStories);
void displayStories(Story *stories, int mode, int numStories);
