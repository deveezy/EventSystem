#include "DBManager.hpp"

#ifndef _WIN32
  #include <unistd.h>
#endif

#include <fstream>
#include <stdexcept>
#include <string>
#include <type_traits>

#include "../common/Datatypes.hpp"
#include "DBGenerator.hpp"
#include "Macro.hpp"

using namespace db;

DBManager::DBManager() {
  if (!isDbFileExists() || sqlite3_open(k_db_file_path.c_str(), &m_db)) { ResetDatabase(); }
}

bool DBManager::isDbFileExists() {
  //  std::filesystem::path dbFilePath {DB_FILE_PATH};
  //  return std::filesystem::exists(dbFilePath);
  std::ifstream settingsFile(k_db_file_path, std::ios::binary);
  if (!settingsFile.is_open()) return false;
  settingsFile.close();
  return true;
}

inline sqlite3_stmt *DBManager::prepare(const std::string &_sql) {
  sqlite3_stmt *stmt = nullptr;
  if (sqlite3_prepare_v2(m_db, _sql.c_str(), -1, &stmt, 0)) {
    sqlite3_finalize(stmt);
    throw std::runtime_error {sqlite3_errmsg(m_db)};
  }
  return stmt;
}

void DBManager::ResetDatabase() {
#ifdef _WIN32
  _unlink(k_db_file_path.c_str());
#else
  unlink(k_db_file_path.c_str());
#endif
  if (sqlite3_open(k_db_file_path.c_str(), &m_db)) Throw(sqlite3_errmsg(m_db));
  const auto schheme_query = DBGenerator::GenerateScheme();
  char *error              = nullptr;
  if (sqlite3_exec(m_db, schheme_query.c_str(), nullptr, nullptr, &error)) {
    std::string err {error};
    sqlite3_free(error);
    Throw(err);
  };
}