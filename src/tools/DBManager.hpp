#pragma once

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "../common/Datatypes.hpp"
#include "DBGenerator.hpp"
#include "Macro.hpp"

extern "C" {

#include "../sqlite/sqlite3.h"
}

#define GDatabase db::DBManager::Get()

namespace db {
class DBManager {
  SINGLETONE(DBManager)
public:
  ~DBManager() = default;


  void ResetDatabase();

private:
  bool isDbFileExists();

  sqlite3_stmt *prepare(const std::string &sql);

private:
  const std::string k_db_file_path {"/home/devpc/dev/projects/EventSystem/DB/nexus.db"};
  sqlite3 *m_db = nullptr;
};
}  // namespace db