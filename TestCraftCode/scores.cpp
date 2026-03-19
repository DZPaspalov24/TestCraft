#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "menu.h"

using namespace std;

struct TestRecord {
    string test;
    int score;
    int grade;
};

void scoresPage() {
    system("cls");
    cout << "================ SCORE BOARD ================\n\n";

    ifstream file("scores.txt");
    if (!file) {
        cout << "No scores recorded yet." << endl;
        int back;
        cout << "Press 1 to return: ";
        cin >> back;
        return;
    }

    map<string, vector<TestRecord>> players;
    string name, test;
    int score, grade;

    while (file >> name >> test >> score >> grade) {
        players[name].push_back({ test, score, grade });
    }
    file.close();

    if (players.empty()) {
        cout << "No scores found." << endl;
        return;
    }

    for (auto& p : players) {
        cout << p.first << endl;

        int totalGrade = 0;

        for (auto& t : p.second) {
            cout << "   " << t.test << " | Score: " << t.score
                << " | Grade: " << t.grade << endl;
            totalGrade += t.grade;
        }

        double avg = (double)totalGrade / p.second.size();
        cout << "   Average Grade: " << avg << endl;
    }

    cout << "============= LEADERBOARD =============\n";

    vector<pair<string, double>> ranking;
    for (auto& p : players) {
        int totalGrade = 0;
        for (auto& t : p.second) totalGrade += t.grade;
        double avg = (double)totalGrade / p.second.size();
        ranking.push_back({ p.first, avg });
    }

    sort(ranking.begin(), ranking.end(),
        [](auto& a, auto& b) { return a.second > b.second; });

    for (int i = 0; i < (int)ranking.size(); i++) {
        cout << i + 1 << ". " << ranking[i].first
            << " | Average Grade: " << ranking[i].second << endl;
    }

    int back;
    cout << "Press 1 to return: ";
    cin >> back;
    while (true) {
        if (back == 1) {
            return;
        }
        else {
            cout << "Invalid input. Chose again: ";
            cin >> back;
        }
    }
}