#pragma once

#include <stdexcept>
#include <string>
#include <vector>

#include "Macro.hpp"

/**
 *  <------------------------------- ДЛЯ РАБОТЫ С БАЗОЙ  ------------------------------->
 *
 *  Для создания таблицы необходимо:
 *     - Добавить имя этой таблицы в db::tables::CreateEnumStrings(Names) (желательно в конец).
 *
 *     - Добавить имя поля в db::<logic_scope>::CreateEnumStrings, пример из существующих:
 *          Для таблицы global_settings logic_scope будет = global, 
 *          в котором есть перечисления для чилсовых и текстовых представлений полей таблицы. Например: 
 *       CreateEnumStrings(Ints, ntp_is_enabled, daylight_time_is_enabled, etc..., EGlobalIntegers_count);
 *       CreateEnumStrings(Strings, camera_name, camera_location, etc..., EGlobalStrings_count);
 *       Это необходимо, чтобы безболезненно обращаться к конкретным полям конкретной таблицы, 
 *       а также для удобного, при необходимости, изменения название полей
 *
 *     - В метод GenerateScheme добавить код, который отвечает за создание структуры таблицы. 
 *        Метод AddField принимает объект класса Field, который имеет 4 параметра, 
 *        но два из них имеют параметры по умолчанию. Эти два параметра отвечают за добавление к полю 
 *        таблицы значения по умолчанию, то есть если у поля не будет такого значения, 
 *        то можно не указывать эти два параметра, если будут, то 3-й параметер будет true, 
 *        а 4-й значение поля по умолчанию.
 *        Первый параметр принимает название поля, второй - его аттрибуты: 
 *        FieldNoFlags, FieldNotNull, FieldUnique, которые работают по принципу побитового или (|).
 *        Например:
 *     ```
 *     result += Table {tables::VNames[tables::web_users]}
 *                 .AddField(IField {"id", FieldNotNull}) 
 *                 .AddField(SField {web_users::VStrings[web_users::username], FieldNotNull | FieldUnique})
 *                 .AddField(SField {web_users::VStrings[web_users::password], FieldNotNull})
 *                 .AddField(IField {web_users::VInts[web_users::role], FieldNotNull, true, 0})
 *                 .AddField(IField {web_users::VInts[web_users::can_write], FieldNotNull, true, 0})
 *                 .GenerateTable()
 *                    std::pair {web_users::VInts[web_users::id], 1},
 *                    std::pair {web_users::VStrings[web_users::username], std::string {"admin"}})
 *                 .ToQuery();
 *     ```
 *   // IField представляет собой поле таблицы типа int
 *   // SField представляет собой поле таблицы типа text(string)
 *   // VInts - числовые поля таблицы.
 *   // VStrings - текстовые поля таблицы.
 *   // ToQuery - необходимо, чтобы преобразовать сгенерированную таблицу в строку sql запроса.
 *   // result здесь выступает строкой, в которую добавляются отдельные sql запросы, 
 *   // чтобы потом за один запрос сгенерировать всю базу.
 *   // GenerateTable() необходим, чтобы разграничить создание таблицы и вставку в неё данных.
 * 
 */

namespace db {
class DBGenerator {
private:
  static std::string GenerateScheme();
  friend class DBManager;
};

namespace tables {
CreateEnumStrings(Names, ircut_schedule, record_settings, web_users, unwrap_configs,
    onvif_media_profiles, global_settings, image_configurations, snmp_v1v2_users, snmp_v3_users,
    snmp_traps, snmp_trap_address, video_sources, video_encoders, audio_sources, audio_encoders,
    ptz_configurations, meta_configurations, onvif_users);
}
namespace video_source {
CreateEnumStrings(Ints, id, token, pos_x, pos_y, width, height);
CreateEnumStrings(Strings, name);
}  // namespace video_source

namespace audio_source {
CreateEnumStrings(Ints, id, token);
CreateEnumStrings(Strings, name);
}  // namespace audio_source
namespace audio_encoder {
CreateEnumStrings(Ints, id, token, bitrate, sample_rate, gain, volume, sound_mode, codec, is_enable,
    is_audio_enhancer_enabled);
CreateEnumStrings(Strings, name);
}  // namespace audio_encoder

namespace ptz_conf {
CreateEnumStrings(Ints, id, token, pan, tilt, zoom, zoom_min, zoom_max, focus, focus_min, focus_max,
    focus_group_period, focus_group_velocity, zoom_group_period, zoom_group_velocity);
CreateEnumStrings(Strings, name);
}  // namespace ptz_conf

namespace meta_conf {
CreateEnumStrings(Ints, id, token);
CreateEnumStrings(Strings, name);
}  // namespace meta_conf

namespace global {
CreateEnumStrings(Ints, ntp_is_enabled, daylight_time_is_enabled, snmp_port, snmp_trap_port,
    http_port, https_port, rtsp_port, websocket_port, logging_is_enabled, dhcp_is_enabled,
    EGlobalIntegers_count, is_onvif_discovery);
CreateEnumStrings(Strings, nexus_version, camera_name, camera_location, ntp_address, timezone,
    EGlobalStrings_count);
}  // namespace global

namespace onvif {
CreateEnumStrings(Ints, id, is_fixed, venc_id, EOnvifProfileIntegers_count);
CreateEnumStrings(Strings, name, token, EOnvifProfileStrings_count);
}  // namespace onvif

namespace onvif_media {
CreateEnumStrings(Ints, id, token, is_fixed, v_source_id, v_enc_id, a_source_id, a_enc_id,
    ptz_conf_id, meta_conf_id, is_multicast_enabled);
CreateEnumStrings(Strings, name);
}  // namespace onvif_media

namespace video_encoder {
CreateEnumStrings(Ints, id, token, codec, resolution, framerate_limit, bitrate_limit, h26x_profile,
    gop_length, gop_mode, quality_min_qp, quality_max_qp, quality_fix_iqp, quality_fix_pqp,
    quality_fix_jpeg_factor, rate_control_mode, is_rtsp_enabled, is_ws_enabled, is_fisheye_enabled,
    is_active, is_audio_active, multicast_port, EVencIntegers_count, is_multicast_enabled);
CreateEnumStrings(Strings, name, multicast_ip);
}  // namespace video_encoder

namespace image_conf {
CreateEnumStrings(Ints, blc_is_enabled, blc_val_b, blc_val_gb, blc_val_gr, blc_val_r, hue,
    brightness, saturation, contrast, lightness, exposure_mode, exposure_shutter_time,
    exposure_aperture, exposure_isp_gain, exposure_sensor_gain, ir_cut_filter_mode, sharpness,
    wdr_is_enabled, wdr_mode, wdr_strength, wdr_bright_limit, wdr_dark_limit, white_balance_mode,
    white_balance_cr_gain, white_balance_cb_gain, white_balance_cgr_gain, white_balance_cgb_gain,
    hlc_is_enabled, is_flip, is_mirror, rotate_angle, hdr_type, noise_reduction_2d,
    noise_reduction_3d, noise_reduction_2d_mode, noise_reduction_3d_mode, anti_flicker_mode,
    anti_flicker_frequency, anti_flicker, anti_fog, anti_fog_mode, EVideoSourceConfIntegers_count);
}  // namespace image_conf

namespace web_users {
CreateEnumStrings(Ints, id, role, can_write);
CreateEnumStrings(Strings, username, password);
}  // namespace web_users

namespace onvif_users {
CreateEnumStrings(Ints, id, token);
CreateEnumStrings(Strings, username, password, user_level);
}  // namespace onvif_users

namespace record {
CreateEnumStrings(Ints, id, rec_enabled, rec_mode);
}

namespace ircut {
CreateEnumStrings(Ints, id, timeshift, mode);
}

namespace unwrap {
CreateEnumStrings(Ints, id, mode, mount, inner_radius, outer_radius, offset_x, offset_y, angle);
}

namespace snmp {
namespace v3_users {
CreateEnumStrings(Ints, id, is_read, is_write, is_notify, auth_protocol, priv_protocol, user_level);
CreateEnumStrings(Strings, name, password);
}  // namespace v3_users
namespace v1v2_users {
CreateEnumStrings(Ints, id, is_write);
CreateEnumStrings(Strings, community);
}  // namespace v1v2_users

namespace traps {
CreateEnumStrings(Ints, id, min_ram, min_rom_cam, min_rom_sd, cpu_load);
}

namespace trap_address {
CreateEnumStrings(Ints, id);
CreateEnumStrings(Strings, ip);
}  // namespace trap_address
}  // namespace snmp

enum class FieldOption : uint8_t {
  NO_FLAGS = 0,
  NOT_NULL = 1,
  UNIQUE   = 1 << 1 /*, Primary = 1 << 2 */,
};

template <typename T = int32_t>
class Field {
public:
  std::string name;
  enum { INTEGER, STRING } type;
  std::string def_val;
  uint8_t options;
  bool has_def_val;
  explicit Field(const std::string &_name,
      uint8_t _options = static_cast<uint8_t>(FieldOption::NO_FLAGS), bool _has_def_val = false,
      T _def = {})
      : name(_name)
      , options(_options)
      , has_def_val(_has_def_val) {
    if constexpr (!std::is_same_v<decltype(_def), std::string>) {
      def_val = std::to_string(_def);
      type    = INTEGER;
    } else {
      def_val = _def;
      type    = STRING;
    }
  };
};

class Table {
public:
  explicit Table(const std::string &_name) : name(_name) {
    query += "CREATE TABLE IF NOT EXISTS \"" + _name + "\" (";
  }

public:
  template <typename T>
  Table &AddField(Field<T> &&_field) {
    if (_field.name == "id") is_primary_key_exists = true;
    query += " \"" + _field.name + "\" ";
    switch (_field.type) {
      case db::Field<T>::INTEGER: query += "INTEGER "; break;
      case db::Field<T>::STRING: query += "TEXT "; break;
    }
    if (_field.options & static_cast<uint8_t>(FieldOption::NOT_NULL)) query += "NOT NULL ";
    if (_field.options & static_cast<uint8_t>(FieldOption::UNIQUE)) query += "UNIQUE ";
    const std::string s = _field.type == Field<T>::STRING ? "'" : "";
    if (_field.has_def_val) query += "DEFAULT " + s + _field.def_val + s;
    query += ",";
    return *this;
  }

  Table &GenerateTable() {
    if (is_primary_key_exists) query += " PRIMARY KEY(\"id\" AUTOINCREMENT)";
    else {
      if (!query.empty() && query.back() == ',') query.pop_back();
    }
    query += " );\n";
    table_exists = true;
    return *this;
  }

  void Insert(std::string &_fields, std::string &_values) {}

  template <typename T, typename... Args>
  void Insert(std::string &_fields, std::string &_values, const std::pair<std::string, T> &_first,
      const Args &..._rest) {
    _fields += "\"" + _first.first + "\",";
    if constexpr (std::is_same_v<T, std::string>) _values += "\"" + _first.second + "\",";
    else
      _values += std::to_string(_first.second) + ",";
    Insert(_fields, _values, _rest...);
  }

  template <typename T, typename... Args>
  Table &InsertInto(const T &_first, const Args &..._args) {
    if (!table_exists) throw std::logic_error("Cannot insert data into table. Create table first.");
    std::string q {"INSERT INTO \"" + name + "\" ("};
    std::string fields;
    std::string values;
    Insert(fields, values, _first, _args...);
    fields.pop_back();
    values.pop_back();
    q += fields + ") VALUES (" + values + ");\n";
    query += q;
    return *this;
  }

  Table &InsertInto() {
    if (!table_exists) throw std::logic_error("Cannot insert data into table. Create table first.");

    query += "INSERT INTO " + name + " DEFAULT VALUES;\n";
    return *this;
  }

  const std::string &ToQuery() const { return query; };

private:
  std::string query {};
  const std::string name {};
  bool is_primary_key_exists = false;
  bool table_exists          = false;
};

}  // namespace db
