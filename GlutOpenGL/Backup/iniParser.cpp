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

void write_settings(char *key, int val)
{
	fstream ini(f_wrt, ios::out | ios::in);

	string temp, text_below;

	if (ini.is_open())
	{
		while (!ini.eof()) {
			getline(ini, temp, ' ');					// Get supposed key from file string

			if (temp == string(key))
			{
				int offset = (int)ini.tellg();			// Save position after needed key

				getline(ini, temp);						// Move 'g' pointer to the next line
				text_below += '\n';
				while (!ini.eof()) {					// Copy text below
					getline(ini, temp);
					text_below += temp;
					if (!ini.eof()) text_below += '\n';
				}
				
				ini.clear();							// Wipe fmt flags(eofbit)
				ini.seekp(offset, ini.beg);				// Move 'p' pointer to position after needed key
				
				ini << val;								// Rewrite
				ini << text_below;
				break;
			}
			getline(ini, temp);							// Go to the next string
		}
	}

	ini.close();
}