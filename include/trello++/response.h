#pragma once

#include "trello++/json.h"
#include "trello++/error.h"

namespace trello {

class Response {

private:
  friend class Request;
  Response(const nlohmann::json &json);

public:
  template <class T> bool unmarshall(T &t) const { return t.unmarshal(m_json); }
  template <class T> std::vector<T> unmarshall() const {
    std::vector<T> out;

    int len = m_json.size();
    for (int i = 0; i < len; i++) {
      nlohmann::json j = m_json[i];
      T res;
      if (!res.unmarshall(j)) {
        throw Exception("could not unmarshall");
      }
      out.emplace_back(std::move(res));
    }

    return out;
  }

private:
  nlohmann::json m_json;
};
}