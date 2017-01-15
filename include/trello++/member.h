#pragma once
#include "trello++/client.h"
#include "trello++/board.h"
#include "trello++/board_options.h"
#include <memory>
#include <vector>

namespace trello {

class Member final {

public:
  Member(std::shared_ptr<Client> client);
  Member(const Member &other);
  Member &operator=(const Member &other);
  ~Member() {}
  std::vector<Board> boards(const std::string &idOrName = "",
                            const BoardOptions &options = BoardOptions());

private:
  std::shared_ptr<Client> m_client;
};
}