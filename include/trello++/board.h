#pragma once
#include <memory>
#include "trello++/json.h"
#include "trello++/board_options.h"

namespace trello {

class BoardPrivate;

class Board {

public:
  Board();
  Board(const Board &other);
  Board &operator=(const Board &other);
  bool unmarshall(const nlohmann::json &json);

  ~Board();

  std::string id() const;
  std::string name() const;

private:
  friend std::ostream &operator<<(std::ostream &os, const Board &board);
  std::shared_ptr<BoardPrivate> d_ptr;
};

std::ostream &operator<<(std::ostream &os, const Board &board);
}