#include "redirections.h"
#include "execute.h"

bool handleRedirections(vector<string> input){
  vector<string> toExecute;
  for(int i=0; i<input.size(); i++){
    if(input[i] == ">"){
      string filename = input[i+1];
      string ouput = executeCommand(toExecute);
      ofstream WriteFile(filename);
      WriteFile << ouput;
      WriteFile.close();
      return true;
    }else if(input[i] == ">>"){
      string filename = input[i+1];
      string ouput = executeCommand(toExecute);
      ofstream WriteFile(filename, ios::app);
      WriteFile << ouput;
      WriteFile.close();
      return true;
    }else{
      toExecute.push_back(input[i]);
    }
  }
  return false;
}
