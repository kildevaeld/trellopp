#pragma once
#include "trello++/trellotypes.h"
#include "trello++/defines.h"
#include <iostream>
namespace cpr {
class Parameters;
}

namespace trello {

class BoardOptions {
  BoardFilter m_bfilter = BoardFilter::no_filter;
  BoardField m_bfield = BoardField::no_fields;

public:
  void set_option(BoardFilter filter) { m_bfilter = filter; }
  void set_option(BoardField field) { m_bfield = field; }

  template <typename Ts> BoardOptions &with(Ts &&ts) {
    this->set_option(TRELLO_FWD(ts));
    return *this;
  }

  void fill_params(cpr::Parameters &params) const;
};
}