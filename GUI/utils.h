#pragma once
#include <iostream>
#include <sstream>
#include <Windows.h>
using namespace std;

string color(string s, int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    cout << s;
    SetConsoleTextAttribute(hConsole, 15);
    return " ";
}

string logo() {
	string logo = R"(
 _____                   __       __        
|     |_.---.-.--------.|  |--.--|  |.---.-.
|       |  _  |        ||  _  |  _  ||  _  |
|_______|___._|__|__|__||_____|_____||___._|
@ vNULL 0.0.0
)";
	return logo;
}
class Eval {
public:
    string extractStr(string text, int args) {
        string raw[8]{};
        istringstream ss(text);

        string word;

        for (int i = 0; ss >> word; i++) {
            raw[i] = word;
        }

        return raw[args];
    }
    int extractInt(string text, int args) {
        string raw[8]{};
        istringstream ss(text);

        string word;

        for (int i = 0; ss >> word; i++) {
            raw[i] = word;
        }
        int value = stoi(raw[args]);
        return value;
    }
    bool confirm(string text, int args, string test) {
        bool confirmed = false;
        string raw[8]{};
        istringstream ss(text);

        string word;

        for (int i = 0; ss >> word; i++) {
            raw[i] = word;
        }
        if (raw[args] == test) {
            confirmed = true;
        }
        else {
            confirmed = false;
        }
        return confirmed;
    }
};

class Exceptions {
    Eval eval_exc;
public:
    /**
    unknownCmd        0
    missingArgs       1
    invalidArgs       2
    dimensionLimit    3
    isNegetive        4
    unknownCoords     5
    **/
    void getError(int error, string s, int args, string additional) {
        switch (error) {
        case 0:
            color("Unknown or invalid command: \n\t" + s, 12);
            break;
        case 1:
            color("Missing arguments: \n\t" + additional, 12);
            break;
        case 2:
            color("Invalid arguments: \n\t" + eval_exc.extractStr(s, args), 12);
            break;
        case 3:
            color("Reached dimension limit. \n\t" + s, 12);
            break;
        case 4:
            color("Dimensions provided are negetive in value: " + s, 12);
            break;
        case 5:
            color("Unknown coordinates: \t\n" + s, 12);
            break;
        }
    }
};