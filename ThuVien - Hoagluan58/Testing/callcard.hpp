#ifndef CALLCARD_HPP
#define CALLCARD_HPP
#include "json.hpp"
#include "date.hpp"

using json = nlohmann::json;

struct CallCard{
	std::string bookID;
	DATE borrowDate;
	DATE returnDate;
	char status;
};
typedef struct CallCard CALLCARD;

struct ListOfCallCard {
	CALLCARD data;
	struct ListOfCallCard *pNext;
};
typedef struct ListOfCallCard LISTOFCALLCARD;

struct List {
	LISTOFCALLCARD *pTail;
	LISTOFCALLCARD *pHead;
};
typedef struct List LIST;

#endif