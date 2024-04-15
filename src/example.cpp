#include "./../inc/popup.hpp"
#include <iostream>

void ok_act() { std::cout << "[INFO]: OK button pressed." << std::endl; }
void yes_act() { std::cout << "[INFO]: YES button pressed." << std::endl; }
void no_act() { std::cout << "[INFO]: NO button pressed." << std::endl; }
void cancel_act() { std::cout << "[INFO]: CANCEL button pressed." << std::endl; }
void retry_act() { std::cout << "[INFO]: RETRY button pressed." << std::endl; }

int main() {
  popup win;
  win.title = "Popup";
  win.context = "Info: Popup test";
  win.type = POPUP_TYPE::YES_NO;
  win.debug_log = false;
  win.bg_col = Color{33, 33, 33, 255};
  win.fg_col = Color{200, 200, 200, 255};
  win.btn_col1 = Color{44, 44, 44, 255};
  win.btn_col2 = Color{66, 66, 66, 255};
  win.actions["ok"].first = ok_act;
  win.actions["ok"].second = true;
  win.actions["yes"].first = yes_act;
  win.actions["yes"].second = false;
  win.actions["no"].first = no_act;
  win.actions["no"].second = true;
  win.actions["cancel"].first = cancel_act;
  win.actions["cancel"].second = false;
  win.actions["retry"].first = retry_act;
  win.actions["retry"].second = true;
  win.run();
  return 0;
}
