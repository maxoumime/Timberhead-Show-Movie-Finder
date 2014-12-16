#pragma once

class Storage{

public:
    void storeFile(String title, String content);
    String getFile(String title);
    vector<String> getStoredFiles();
    void deleteFile(String title);
    void updateFile(String title, String content);
};