#include <iostream>
#include <filesystem>
#include <string>
//eeee
namespace fs = std::filesystem;
using namespace std;

void replaceNames(string&, string&, string&); 

int main() {
    //give path
    string folder = "C:/Users/Mordred/Desktop/test"; 
    //original part substring whatever to be replaced
    string oldPart = "a070";         
    //new replacement
    string newPart = "a071";      
    //lets go
    replaceNames(folder, oldPart, newPart);
    cout << "it worked" << endl; 

    return 0;
}

void replaceNames(string& folder, string& oldPart, string& newPart) {

    //iterate through each file 
    for (auto& current : fs::directory_iterator(folder)) {

        //make sure the file isnt silly 
        if (current.is_regular_file()) {

            //create path for file
            string fileName = current.path().filename().string();

            //look for old part of string to replace
            int location = fileName.find(oldPart);

            //if the location matches
            if (location != string::npos) { //string::npos returns -1, indicates no matches found 
                
                //replace name
                fileName.replace(location, oldPart.length(), newPart);

                //make new path
                fs::path newPath = current.path().parent_path() / fileName;

                //rename entire file
                fs::rename(current.path(), newPath);
            }
        }
    }
}