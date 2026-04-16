/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> freq;

    // input + count votes
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        freq[name]++;
    }

    string winner = "";
    int maxVotes = 0;

    // find winner
    for (auto &p : freq) {
        string name = p.first;
        int votes = p.second;

        if (votes > maxVotes) {
            maxVotes = votes;
            winner = name;
        }
        else if (votes == maxVotes && name < winner) {
            winner = name; // lexicographically smaller
        }
    }

    cout << winner << " " << maxVotes;

    return 0;
}