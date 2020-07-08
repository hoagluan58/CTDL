#ifndef READER_HPP
#define READER_HPP
#include "json.hpp"
#include "callcard.hpp"

using json = nlohmann::json;

typedef struct {
	int id;
	std::string lastName;
	std::string firstName;
	std::string gender;
	bool status;
	LIST l; //con trỏ trỏ đến danh sách mượn trả
}Reader;
typedef struct Reader READER;

struct ListOfReader {
	Reader data;
	struct ListOfReader *pLeft;
	struct ListOfReader *pRight;
};
typedef struct ListOfReader *ListOfReaderPtr;

typedef ListOfReader *Tree;

#endif