#include "iniParser.h"

int parse_settings(char *str)
{
	map<string, int> set_map;
	map<string, int>::iterator map_i;

	ifstream ini(f_name, ios::in);

	if (ini.is_open()) {

		string key, val;

		while (!ini.eof()) {
			getline(ini, key, ' ');
			getline(ini, val);
			set_map.insert(pair<string, int>(key, atoi(val.c_str())));
		}

		ini.close();

		map_i = set_map.find(string(str));

		if (map_i == set_map.end()) return -1;
		else return map_i->second;
	}
	else return -1;
}