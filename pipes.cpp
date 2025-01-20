#include "pipes.h"
#include "execute.h"

vector<vector<string>> seprateCommands(vector<string> input){
  vector<vector<string>> commands;
  vector<string> curCommand;

  for(int i=0; i<input.size(); i++){
    if(input[i] == "|"){
      commands.push_back(curCommand);
      curCommand.clear();
    }else{
      curCommand.push_back(input[i]);
    }
  }
  commands.push_back(curCommand);

  return commands;
}


string handlePipes(vector<string> input) {
  vector<vector<string>> commands = seprateCommands(input);
  if (commands.size() == 1) return executeCommand(commands[0]);

  string output;

  for(int i=0; i<commands.size(); i++){
    output = executeCommand(output, commands[i]);
  }

  return output;
}


