#pragma once

#include <functional>
#include <iterator>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>

namespace AudioSync {

class UI_Base {
public:
  virtual void informate(const std::string& info) const = 0;
  virtual void warning(const std::string& msg) const = 0;
  virtual ~UI_Base() = default;

public:
  static std::unique_ptr<UI_Base> getUI();

public:
  template<class T, class Result = decltype(*std::begin(std::declval<T>()))&>
  Result selectFrom(const T&);

protected:
  class ForwardIteratorType {
  private:
    const void* const value;
    std::function<ForwardIteratorType()> f_next;

  public:
    template<class It>
    ForwardIteratorType(It iter)
        : value(static_cast<const void*>(&(*iter))) {
      // TODO: Maybe generate many "functions" for equals It
      f_next = [this]() -> ForwardIteratorType {
        return { std::next(*reinterpret_cast<const It*>(value)) };
      };
    }
  };

public:
  virtual ForwardIteratorType selectFromArray(
      const ForwardIteratorType from,
      const ForwardIteratorType to
  ) = 0;

private:
  //    static std::unique_ptr<UI_Base>
};

}  // namespace AudioSync
