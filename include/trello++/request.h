#pragma once
#include <string>
#include <memory>
#include "trello++/trellotypes.h"
#include "trello++/response.h"
#include "trello++/board_options.h"
//#include "cpr/cpr.h"
namespace cpr {
class Session;
}

namespace trello {

class Request {

public:
  Request(const std::string &api_url, const std::string &app_key,
          const std::string &token);
  ~Request();
  void set_option(const std::string &path);
  // void set_option(Filter filter);
  // void set_option(BoardField field);
  void set_option(Http method);
  void set_option(const BoardOptions &options);
  std::unique_ptr<Response> request() const;

private:
  std::string m_api_url;
  std::string m_app_key;
  std::string m_token;
  // Filter m_filter = Filter::no_filter;
  // BoardField m_bfield = BoardField::all;
  BoardOptions m_board_options;
  Http m_method = Http::Get;
  cpr::Session *m_session;
};
}