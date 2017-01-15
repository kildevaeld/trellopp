#include "trello++/member.h"
#include "trello++/json.h"
#include "trello++/error.h"

#include "cpr/cpr.h"
#include <sstream>
#include <iostream>

namespace trello {

Member::Member(std::shared_ptr<Client> client) : m_client(client) {}

Member::Member(const Member &other) {}
Member &Member::operator=(const Member &other) {
  if (this != &other) {
    m_client = other.m_client;
  }

  return *this;
}

std::vector<Board> Member::boards(const std::string &idOrName,
                                  const BoardOptions &options) {

  std::string path =
      "/members/" + (idOrName == "" ? "me" : idOrName) + "/boards";

  auto res = m_client->request(Http::Get, path, options);

  return res->unmarshall<Board>();
}
}