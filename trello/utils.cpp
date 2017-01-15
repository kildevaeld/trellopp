#include "trello++/utils.h"

namespace trello {

/*! note: separator cannot contain null characters
 */
std::string join(const std::vector<std::string> &elements,
                 const std::string &separator) {
  switch (elements.size()) {
  case 0:
    return "";
  case 1:
    return elements[0];
  default:
    std::ostringstream os;
    std::copy(elements.begin(), elements.end() - 1,
              std::ostream_iterator<std::string>(os, separator.c_str()));
    os << *elements.rbegin();
    return os.str();
  }
}

void split(const char pChr, std::vector<std::string> &pRet,
           const std::string &pPath) {
  std::string::const_iterator cur = pPath.begin();
  std::string::const_iterator beg = pPath.begin();
  bool added = false;
  while (cur < pPath.end()) {
    if (*cur == pChr) {
      pRet.insert(pRet.end(), std::string(beg, cur));
      beg = ++cur;
      added = true;
    } else {
      cur++;
    }
  }

  pRet.insert(pRet.end(), std::string(beg, cur));
}

std::string bfilter_to_string(BoardFilter flag) {
  std::vector<std::string> filters;
  if (flags(flag & BoardFilter::all)) {
    filters.emplace_back("all");
  }
  if (flags(flag & BoardFilter::open)) {
    filters.emplace_back("open");
  }
  if (flags(flag & BoardFilter::closed)) {
    filters.emplace_back("closed");
  }
  if (flags(flag & BoardFilter::members)) {
    filters.emplace_back("members");
  }
  if (flags(flag & BoardFilter::organiation)) {
    filters.emplace_back("orginazation");
  }
  if (flags(flag & BoardFilter::pinned)) {
    filters.emplace_back("pinned");
  }
  if (flags(flag & BoardFilter::pub)) {
    filters.emplace_back("public");
  }
  if (flags(flag & BoardFilter::starred)) {
    filters.emplace_back("starred");
  }
  if (flags(flag & BoardFilter::unpinned)) {
    filters.emplace_back("unpinned");
  }
  return join(filters);
}

std::string bfield_to_string(BoardField flag) {
  std::vector<std::string> fields;
  if (flags(flag & BoardField::all)) {
    fields.emplace_back("all");
  }
  if (flags(flag & BoardField::name)) {
    fields.emplace_back("name");
  }

  return join(fields);
}
}