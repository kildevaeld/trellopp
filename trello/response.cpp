#include "trello++/response.h"

namespace trello {

Response::Response(const nlohmann::json &json) : m_json(std::move(json)) {}
}