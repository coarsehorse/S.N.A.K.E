#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>

#pragma once
#ifndef INIPARSER_H
#define INIPARSER_H

#define f_name "settings.ini"
#define f_wrt "wrTest.txt"

using namespace std;

int parse_settings(char *key);
void write_settings(char *key, int val);

#endif