/*Alien Dictionary
Difficulty: HardAccuracy: 47.81%Submissions: 237K+Points: 8
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;

string findOrder(vector<string>& words) {
    unordered_map<char, vector<char>> adj;
    unordered_map<char, int> indegree;

    // initialize indegree for all unique chars
    for (auto word : words) {
        for (char ch : word) {
            indegree[ch] = 0;
        }
    }

    // build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string a = words[i];
        string b = words[i + 1];

        int len = min(a.size(), b.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                adj[a[j]].push_back(b[j]);
                indegree[b[j]]++;
                found = true;
                break;
            }
        }

        // invalid case: prefix issue
        if (!found && a.size() > b.size()) {
            return "";
        }
    }

    // Kahn's Algorithm
    queue<char> q;
    for (auto it : indegree) {
        if (it.second == 0) {
            q.push(it.first);
        }
    }

    string result;

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        result += node;

        for (char nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    // cycle check
    if (result.size() != indegree.size()) {
        return "";
    }

    return result;
}

int main() {
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string ans = findOrder(words);

    if (ans == "") cout << "Invalid (cycle)\n";
    else cout << ans;
}