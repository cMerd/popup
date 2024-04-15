#pragma once

#include <map>
#include <raylib.h>
#include <string>
#include <utility>

enum POPUP_TYPE { YES_NO = 0, OK_CANCEL = 1, OK = 2, RETRY_CANCEL = 3 };

class popup {
public:
  std::string title;
  std::string context;
  std::map<std::string, std::pair<void (*)(), bool>> actions;
  POPUP_TYPE type;
  bool debug_log;
  Color bg_col;
  Color fg_col;
  Color btn_col1, btn_col2;
  void run();
};
