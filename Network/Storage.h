#pragma once

#include <string>
#include <vector>

using namespace std;

class Storage{

public:
    void storeFile(string title, string content);
    string getFile(string title);
    vector<string> getStoredFiles();
    void deleteFile(string title);
    void updateFile(string title, string content);
};