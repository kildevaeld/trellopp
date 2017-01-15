#include "trello++/board_options.h"
#include "trello++/utils.h"
#include <cpr/parameters.h>

#include <iostream>

namespace trello {

void BoardOptions::fill_params(cpr::Parameters &params) const {

  if (m_bfilter != BoardFilter::no_filter) {
    params.AddParameter(cpr::Parameter("filter", bfilter_to_string(m_bfilter)));
  }

  if (!(flags(m_bfield & BoardField::no_fields) ||
        m_bfield == BoardField::no_fields)) {
    params.AddParameter(cpr::Parameter("fields", bfield_to_string(m_bfield)));
  }
}
}