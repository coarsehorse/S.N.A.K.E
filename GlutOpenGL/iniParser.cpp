#include "iniParser.h"

int parse_settings(const char *str)
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

		if (map_i == set_map.end()) return -5;
		else return map_i->second;
	}
	else return -1;
}

void write_settings(const char *key, int val)
{
	fstream ini(f_name, ios::out | ios::in);

	string temp, text_below;

	if (ini.is_open())
	{
		while (!ini.eof()) {
			getline(ini, temp, ' ');					// Get supposed key from file string

			if (temp == string(key))
			{
				while (true) { // Move through the spaces
					char tmp = (char)ini.peek();
					if (tmp != ' ') break;
					else ini.seekg(1, ini.cur);
				}

				int offset = (int)ini.tellg();			// Save position after needed key

				getline(ini, temp);						// Move 'g' pointer to the next line
				int dig_old_val = temp.length();

				while (!ini.eof()) {					// Copy text below
					getline(ini, temp);
					text_below += temp;
					if (!ini.eof()) text_below += '\n';
				}

				ini.clear();							// Wipe fmt flags(eofbit)
				ini.seekp(offset, ini.beg);				// Move 'p' pointer to position after needed key
				
				int dig_new_val = 0;

				if (val < 10) dig_new_val = 1;
				else if (val < 100) dig_new_val = 2;
				else if (val < 1000) dig_new_val = 3;

				ini << val;						// Rewrite

				if (dig_new_val < dig_old_val)
					for (int i = 0; i < dig_old_val - dig_new_val; i++) ini << ' ';
				ini << '\n';
				ini << text_below;
				
				break;
			}
			getline(ini, temp);							// Go to the next string
		}
	}

	ini.close();
}