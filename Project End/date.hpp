#ifndef DATE_HPP
#define DATE_HPP
#include "json.hpp"

using json = nlohmann::json;

struct date {
	int realDay;
	int realMonth;
	int realYear;
};
typedef struct date DATE;

#endif

