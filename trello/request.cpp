#include "trello++/request.h"
#include <cpr/session.h>
#include "trello++/error.h"

namespace trello {

Request::Request(const std::string &api_url, const std::string &app_key,
                 const std::string &token)
    : m_api_url(api_url), m_app_key(app_key), m_token(token),
      m_session(new cpr::Session()) {}

Request::~Request() { delete m_session; }

void Request::set_option(const std::string &path) {
  assert(path != "" && path != "/");
  std::string url = m_api_url + (path[0] == '/' ? "" : "/") + path;
  m_session->SetUrl(url);
}

// void Request::set_option(Filter filter) { m_filter = filter; }
// void Request::set_option(BoardField field) { m_bfield = field; }
void Request::set_option(const BoardOptions &options) {
  m_board_options = options;
}
void Request::set_option(Http method) { m_method = method; }

std::unique_ptr<Response> Request::request() const {

  cpr::Parameters params;

  params.AddParameter(cpr::Parameter("key", m_app_key));
  if (m_token != "")
    params.AddParameter(cpr::Parameter("token", m_token));

  m_board_options.fill_params(params);

  m_session->SetParameters(params);

  cpr::Response res;

  switch (m_method) {
  case Http::Get:
    res = m_session->Get();
    break;
  case Http::Post:
    res = m_session->Post();
  case Http::Put:
    res = m_session->Put();
  case Http::Delete:
    res = m_session->Delete();
  }

  if (res.status_code >= 400) {
    throw Exception(res.text.c_str());
  }

  auto json = nlohmann::json::parse(res.text);
  return std::unique_ptr<Response>(new Response(std::move(json)));
}
}