#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

void replaceInFileNames(const string& folderPath, const string& oldSubstring, const string& newSubstring) {
    for (auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            // Extract the file name from the path
            string fileName = entry.path().filename().string();

            // Check if the old substring is present in the file name
            size_t pos = fileName.find(oldSubstring);
            if (pos != string::npos) {
                // Replace the old substring with the new one
                fileName.replace(pos, oldSubstring.length(), newSubstring);

                // Create the new file path
                fs::path newPath = entry.path().parent_path() / fileName;

                // Rename the file
                fs::rename(entry.path(), newPath);
            }
        }
    }
}

int main() {
    string folderPath = "C:/Users/Mordred/Desktop/test";  // Update with your folder path
    string oldSubstring = "a071";           // Specify the substring to be replaced
    string newSubstring = "a072";           // Specify the new substring

    try {
        replaceInFileNames(folderPath, oldSubstring, newSubstring);
        cout << "File names successfully updated." << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}