# trellopp
c++11 wrapper for the Trello API

### Under Development

## Usage

```c++
#include <iostream>
#include <trello++/trello++.h>

using trello::BoardFilter;
using trello::BoardField;
using trello::BoardOptions;

int main () {

  
  auto client = trello::create(key, token);
  
  trello::Member m(client);
  
  BoardOptions o;
  o.with(BoardFilter::starred | BoardFilter::pub)
  .with(BoardField::name | BoardField::shortUrl);
  
  auto boards = m.boards("me", o);

  for (auto board: boards) {
    std::cout << board << std::endl;
  }

  return 0;
}

```
