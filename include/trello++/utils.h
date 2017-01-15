#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "trello++/trellotypes.h"
namespace trello {

/*! note: separator cannot contain null characters
 */
std::string join(const std::vector<std::string> &elements,
                 const std::string &separator = ",");

void split(const char pChr, std::vector<std::string> &pRet,
           const std::string &pPath);

std::string bfilter_to_string(BoardFilter flag);
std::string bfield_to_string(BoardField flag);
}