#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::vector<std::string> SplitString(const std::string &_str, char _separator);

/// \brief Создает enum Ename со значениями аргументов и std::vector Vname из их строчных представлений
#define CreateEnumStrings(name, ...)    \
  enum E##name : uint8_t {__VA_ARGS__}; \
  const std::vector<std::string> V##name = SplitString(#__VA_ARGS__, ',')

#define CreateEnumClassStrings(name, ...)     \
  enum class E##name : uint8_t {__VA_ARGS__}; \
  const std::vector<std::string> V##name = SplitString(#__VA_ARGS__, ',')

#define MakeEnum(name, ...) \
  enum E##name : uint8_t { __VA_ARGS__ }

#define MakeEnumClass(name, ...) \
  enum class E##name : uint8_t { __VA_ARGS__ }

#define MakeCountedEnum(name, ...) \
  enum E##name : uint8_t { __VA_ARGS__, E##name##_count }

#define MakeCountedEnumClass(name, ...) \
  enum class E##name : uint8_t { __VA_ARGS__, E##name##_count }

#define Throw(err_string)                                                                        \
  throw std::runtime_error {                                                                     \
    std::string {err_string} + "\n\t" + __PRETTY_FUNCTION__ + "\n\tFILE: " + __FILE__ " LINE " + \
        std::to_string(__LINE__).c_str()                                                         \
  }

#define ThrowErr(type, err_string)                                                               \
  throw type {                                                                                   \
    std::string {err_string} + "\n\t" + __PRETTY_FUNCTION__ + "\n\tFILE: " + __FILE__ " LINE " + \
        std::to_string(__LINE__).c_str()                                                         \
  }

#define PairStringEnum(EnumClass, EnumValue) \
  { #EnumValue, EnumClass::EnumValue }

#define SINGLETONE(Class)                                                       \
private:                                                                        \
  Class();                                                                      \
  Class(const Class &) = delete;                                                \
  Class &operator=(const Class &) = delete;                                     \
                                                                                \
public:                                                                         \
  static Class &Get() {                                                         \
    static std::unique_ptr<Class> instance = std::unique_ptr<Class>(new Class); \
    return *instance;                                                           \
  }                                                                             \
                                                                                \
private:
