#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>

#pragma once
#ifndef INIPARSER_H
#define INIPARSER_H

#define f_name "settings.ini"

using namespace std;

int parse_settings(const char *key);
void write_settings(const char *key, int val);

#endif