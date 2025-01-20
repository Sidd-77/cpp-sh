#include <cstdlib>
#include <iostream>
#include <vector>
#include <filesystem>
#include "cd.h"
#include "execute.h"
#include "inputParser.h"
#include "redirections.h"
#include "pipes.h"

using namespace std;

string getPathFromHome(){
  int i=0;
  string str = filesystem::current_path();
  int count = 0;
  while(i < str.size() && count != 3){
    if(str[i] == '/') count++;
    i++;
  }
  string dir = str.substr(i);
  return dir;
}

void showHelp() {
  cout << "===== Shell Help =====\n";
  cout << "This shell supports the following commands and features:\n\n";
  cout << "  cd <dir>       - Change directory to <dir>\n";
  cout << "  help           - Display this help message\n";
  cout << "  checkbg        - Check the status of background processes\n";
  cout << "  <cmd> &        - Run <cmd> in the background\n";
  cout << "  <cmd> | <cmd>  - Pipe output of one command to another\n";
  cout << "  <cmd> > file   - Redirect output to file (overwrite)\n";
  cout << "  <cmd> >> file  - Redirect output to file (append)\n";
  cout << "  exit           - Exits the shell\n";
  cout << "======================\n";
}

string handleCommand(vector<string> input){
  if(input.empty()) return "";
  if(input[0] == "cd") {
    if(input.size()==1) return "Path not provided...\n";
    changeDir(input[1]);
    return "";
  }
  if(input[0] == "checkbg"){
    checkBackgroundProcesses();
    return "";
  }
  if(input[0] == "help"){
    showHelp();
    return "";
  }
  if(handleRedirections(input)) return "Data written to file... \n";
  if(input[input.size()-1] == "&") return executeCommand(input, true);
  string output = handlePipes(input);
  return output;
}

int main (int argc, char *argv[]) {
  while(true){
    cout<<"[~/"<<getPathFromHome()<<"]$ ";
    string input;
    getline(cin, input);
    if(input == "exit") break;
    vector<string> parsedInput = parser(input);
    cout << handleCommand(parsedInput);
  }

  return 0;
}
