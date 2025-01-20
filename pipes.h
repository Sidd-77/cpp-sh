#pragma once 

#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

string handlePipes(vector<string> input);
