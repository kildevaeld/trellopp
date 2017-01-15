
#include <trello++/client.h>
#include <trello++/member.h>

using trello::BoardFilter;
using trello::BoardField;
using trello::BoardOptions;
int main() {

  std::string key;
  std::string token;

  if (const char *ekey = std::getenv("TRELLO_KEY")) {
    key = ekey;
  }

  if (const char *etoken = std::getenv("TRELLO_TOKEN")) {
    token = etoken;
  }

  auto client = trello::create(key, token);

  trello::Member m(client);

  BoardOptions o;

  // o /*.with(BoardFilter::all)*/.with(BoardField::name | BoardField::url);

  auto boards = m.boards("me", o);

  for (auto i : boards) {
    std::cout << i << std::endl;
  }

  return 0;
}