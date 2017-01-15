#pragma once
#include <cstdint>
#include "trello++/enum_flags.h"

namespace trello {

enum class Http { Get, Post, Put, Delete };

ENUM_FLAGS(BoardFilter)
enum class BoardFilter {
  no_filter = 0 << 0,
  all = 1 << 0,
  closed = 1 << 1,
  members = 1 << 2,
  open = 1 << 3,
  organiation = 1 << 4,
  pinned = 1 << 5,
  pub = 1 << 6,
  starred = 1 << 7,
  unpinned = 1 << 8
};

ENUM_FLAGS(BoardField)
enum class BoardField {
  no_fields = 0 << 0,
  all = 1 << 0,
  closed = 1 << 1,
  dateLastActivity = 1 << 2,
  dateLastView = 1 << 3,
  desc = 1 << 4,
  descData = 1 << 5,
  idOrganization = 1 << 6,
  invitations = 1 << 7,
  invited = 1 << 8,
  labelNames = 1 << 9,
  memberships = 1 << 10,
  name = 1 << 11,
  pinned = 1 << 12,
  powerUps = 1 << 13,
  prefs = 1 << 14,
  shortLink = 1 << 15,
  shortUrl = 1 << 16,
  starred = 1 << 17,
  subscribed = 1 << 18,
  url = 1 << 19,
};
}