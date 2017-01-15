#include "trello++/client.h"
#include "trello++/error.h"

#include <cpr/session.h>
#include <sstream>
#include <cassert>

namespace trello {

Client::Client(const std::string &app_key, const std::string &token,
               const std::string &api)
    : m_key(app_key), m_token(token), m_api_url(api) {}

Client::~Client() {}

std::unique_ptr<Response> Client::request(const Request &request) {
  return request.request();
}

std::shared_ptr<Client> create(const std::string &app_key,
                               const std::string &token) {
  return std::make_shared<Client>(app_key, token);
}
}

/*cpr::Response Client::request(const HttpMethod method, const std::string
&path,
                              cpr::Parameters *p) const {
  assert(path != "" && path != "/");

  std::string url = m_api_url + (path[0] == '/' ? "" : "/") + path;

  cpr::Session session;
  session.SetUrl(url);

  cpr::Parameters params;
  if (p) {
    params = *p;
  }

  params.AddParameter(cpr::Parameter("key", m_key));
  if (m_token != "")
    params.AddParameter(cpr::Parameter("token", m_token));

  session.SetParameters(params);
  cpr::Response res;

  switch (method) {
  case Client::Get:
    res = session.Get();
    break;
  case Client::Post:
    res = session.Post();
  case Client::Put:
    res = session.Put();
  case Client::Delete:
    res = session.Delete();
  }

  return res;
}

std::shared_ptr<Client> create(const std::string &app_key,
                               const std::string &token) {
  return std::make_shared<Client>(app_key, token);
}*/
