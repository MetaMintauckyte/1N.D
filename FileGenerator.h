
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cctype>
#include <chrono>
#include <list>

using std::string;
using std::cout;
using std::ofstream;
using std::cout;

using std::vector;
using std::map;
using std::mt19937;


typedef std::uniform_int_distribution<int>  int_distribution;
using hrClock = std::chrono::high_resolution_clock;

struct asmuo {
    string vardas, pavarde;
};

char lytis();
int rand_number();
asmuo gen_map(char lytis);
void generator_of_students(int studentai, string file_name);
