#pragma once
#include <exception>
namespace trello {

enum Error { Unknown };

class Exception : public std::exception {

public:
  Exception(const char *what, const Error code = Unknown)
      : m_what(what), m_code(code) {}
  ~Exception() throw() {}

  const char *what() const throw() { return m_what; }
  const Error code() const throw() { return m_code; }

  const char *m_what;
  const Error m_code = Unknown;
};
}