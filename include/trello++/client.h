#pragma once
#include <string>
#include <future>
#include "trello++/request.h"
#include "trello++/defines.h"
namespace cpr {
class Parameters;
class Response;
}

namespace trello {

namespace priv {

template <typename T> void set_option(Request &request, T &&t) {
  request.set_option(TRELLO_FWD(t));
}

template <typename T, typename... Ts>
void set_option(Request &request, T &&t, Ts &&... ts) {
  set_option(request, TRELLO_FWD(t));
  set_option(request, TRELLO_FWD(ts)...);
}

} // namespace priv

class Client {

public:
  Client(const std::string &app_key, const std::string &token,
         const std::string &api = "https://api.trello.com/1");
  ~Client();
  template <typename... Ts> std::unique_ptr<Response> request(Ts &&... ts) {
    Request req(m_api_url, m_key, m_token);
    priv::set_option(req, TRELLO_FWD(ts)...);
    return req.request();
  }

  std::unique_ptr<Response> request(const Request &request);

private:
  // cpr::Response request(const Client::HttpMethod method,
  //                      const std::string &path,
  //                      cpr::Parameters *p = nullptr) const;

  friend class Member;
  std::string m_key;
  std::string m_token;
  std::string m_api_url;
};

std::shared_ptr<Client> create(const std::string &app_key,
                               const std::string &token);
}