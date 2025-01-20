#pragma once 

#include <vector>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdlib>
#include <sys/types.h>

using namespace std;

string executeCommand(vector<string> input);
string executeCommand(vector<string> input, bool background);
void checkBackgroundProcesses();
string executeCommand(string input, vector<string> commands);
