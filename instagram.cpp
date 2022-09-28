#include <iomanip>
#include <iostream>
#include <unordered_map>
#include "instagram.h"

using namespace std;

void displayStories(Story *stories, int mode, int numStories) {
    if (mode != -1) {
        for (int index = 0; index < numStories; index++) {
            Story *story = (stories + index);
            if (story->score == mode) {
                cout << endl;
                cout << story->title << endl;
                cout << story->url << endl;
            }
        }
    } else {
        static int FIVE_STORIES = 5;
        for (int index = 0; index < FIVE_STORIES; index++) {
            Story *story = (stories + index);
            cout << endl;
            cout << story->title << endl;
            cout << story->url << endl;
        }
    }
}

int findMode(Story *stories, int numStories) {
    int scores[numStories];
    for (int index = 0; index < numStories; index++) {
        Story *story = stories + index;
        scores[index] = story->score;
    }
    unordered_map<int, int> frequencies;
    for (int index = 0; index < numStories; index++) {
        Story *story = stories + index;
        frequencies[story->score]++;
    }
    int mode = 0;
    int maxFrequency = 0;
    for (int index = 0; index < numStories; index++) {
        int score = (stories + index)->score;
        if (frequencies[score] > maxFrequency) {
            mode = score;
            maxFrequency = frequencies[score];
        }
    }
    return maxFrequency == 1 ? -1 : mode;
}

Story *readFile(ifstream &storiesFile, int numStories) {
    Story *stories = new Story[numStories];
    for (int index = 0; index < numStories; index++) {
        Story *story = stories + index;
        getline(storiesFile, story->title);
        getline(storiesFile, story->url);
        string line;
        getline(storiesFile, line);
        story->score = stoi(line);
    }
    return stories;
}

int main() {
    string fileName;
    cout << "Please enter stories file name: ";
    cin >> fileName;
    ifstream storiesFile;
    storiesFile.open(fileName);
    string line;
    getline(storiesFile, line);
    int numStories = stoi(line);
    Story *stories = readFile(storiesFile, numStories);
    int mode = findMode(stories, numStories);
    cout << "Mode: ";
    if (mode != -1) {
        cout << mode << endl;
    } else {
        cout << "No mode was found." << endl;
    }
    displayStories(stories, mode, numStories);
    delete [] stories;
}
