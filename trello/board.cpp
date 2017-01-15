#include "trello++/board.h"

namespace trello {

time_t from_iso(const std::string &data) {
  int y, M, d, h, m;
  float s;
  sscanf(data.c_str(), "%d-%d-%dT%d:%d:%fZ", &y, &M, &d, &h, &m, &s);

  std::tm time;
  time.tm_year = y - 1900; // Year since 1900
  time.tm_mon = M - 1;     // 0-11
  time.tm_mday = d;        // 1-31
  time.tm_hour = h;        // 0-23
  time.tm_min = m;         // 0-59
  time.tm_sec = (int)s;    // 0-61 (0-60 in C++11)
  return std::mktime(&time);
}

std::string to_iso(time_t time) {
  std::tm *ptm = std::localtime(&time);
  char buffer[32];
  // Format: Mo, 15.06.2009 20:20:00
  std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
  return std::string(buffer);
}

std::string to_string(const nlohmann::json &json, const std::string &prop) {
  if (json.find(prop) != json.end() && json[prop].is_string())
    return json[prop];

  return std::string();
}

bool to_bool(const nlohmann::json &json, const std::string &prop) {
  if (json.find(prop) != json.end() && json[prop].is_boolean())
    return json[prop];

  return false;
}

class BoardPrivate {

public:
  BoardPrivate() {}

  std::string id;
  std::string name;
  std::string desc;

  time_t dateLastActivity;
  time_t dateLastView;

  std::string descData;
  std::string idOrganization;
  // invitations;
  bool invited;
  // labelNames;
  // memberships;
  // pinned;
  // powerUps;
  // prefs;
  std::string shortLink;
  std::string shortUrl;
  bool starred;
  bool subscribed;
  std::string url;
  bool closed;
};

Board::Board() : d_ptr(new BoardPrivate) {}

Board::Board(const Board &other) : d_ptr(other.d_ptr) {}

Board &Board::operator=(const Board &other) {
  if (&other == this) {
    return *this;
  }

  d_ptr = other.d_ptr;

  return *this;
}

bool Board::unmarshall(const nlohmann::json &json) {

  d_ptr->id = to_string(json, "id");
  d_ptr->name = to_string(json, "name");
  d_ptr->desc = to_string(json, "desc");
  d_ptr->closed = to_bool(json, "closed");

  std::string date;
  if ((date = to_string(json, "dateLastActivity")) != "")
    d_ptr->dateLastActivity = from_iso(date);

  if ((date = to_string(json, "dateLastView")) != "")
    d_ptr->dateLastActivity = from_iso(date);

  d_ptr->shortLink = to_string(json, "shortLink");
  d_ptr->shortUrl = to_string(json, "shortUrl");
  d_ptr->url = to_string(json, "url");
  d_ptr->subscribed = to_bool(json, "subscribed");
  d_ptr->starred = to_bool(json, "starred");
  d_ptr->invited = to_bool(json, "invited");

  return true;
}

Board::~Board() {}

std::string Board::id() const { return d_ptr->id; }
std::string Board::name() const { return d_ptr->name; }

std::ostream &operator<<(std::ostream &os, const Board &board) {
  os << "Board(id=" << board.id() << ", name=" << board.name() << ")";
  return os;
}
}