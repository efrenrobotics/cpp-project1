#include <string>
#include <fstream>

struct Story {
    std::string title;
    std::string url;
    int score;
};

Story *readFile(std::ifstream &storiesFile, int numStories);
int findMode(Story *stories, int numStories);
void displayStories(Story *stories, int mode, int numStories);
