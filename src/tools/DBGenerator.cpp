#include "DBGenerator.hpp"

std::string db::DBGenerator::GenerateScheme() {
  using SField = Field<std::string>;
  using IField = Field<int32_t>;
  // clang-format off
  auto query = Table {tables::VNames[tables::ircut_schedule]}
      .AddField(IField {ircut::VInts[ircut::id], static_cast<uint8_t>(FieldOption::NOT_NULL)})
      .AddField(IField {ircut::VInts[ircut::timeshift], static_cast<uint8_t>(FieldOption::NOT_NULL)})
      .AddField(IField {ircut::VInts[ircut::mode], static_cast<uint8_t>(FieldOption::NOT_NULL)})
      .GenerateTable()
      .InsertInto(
        std::pair {db::ircut::VInts[db::ircut::id], 1},
        std::pair {db::ircut::VInts[db::ircut::timeshift], 20},
        std::pair {db::ircut::VInts[db::ircut::mode], 0})
      .InsertInto(
        std::pair {db::ircut::VInts[db::ircut::id], 2},
        std::pair {db::ircut::VInts[db::ircut::timeshift], 50},
        std::pair {db::ircut::VInts[db::ircut::mode], 1})
      .InsertInto(
        std::pair {db::ircut::VInts[db::ircut::id], 3},
        std::pair {db::ircut::VInts[db::ircut::timeshift], 30},
        std::pair {db::ircut::VInts[db::ircut::mode], 1})
      .InsertInto(
        std::pair {db::ircut::VInts[db::ircut::id], 4},
        std::pair {db::ircut::VInts[db::ircut::timeshift], 40},
        std::pair {db::ircut::VInts[db::ircut::mode], 0})
      .ToQuery();
  
  // clang-format on
  return query;
}