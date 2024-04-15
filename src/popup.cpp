#include "../inc/popup.hpp"
#include "../inc/button.hpp"
#include <raylib.h>
#include <stdexcept>

void popup::run() {
  const int screenWidth = 500;
  const int screenHeight = 250;

  bool should_quit = false;

  if (!this->debug_log)
    SetTraceLogLevel(LOG_NONE);

  InitWindow(screenWidth, screenHeight, this->title.c_str());
  SetTargetFPS(60);

  while (!WindowShouldClose() and !should_quit) {
    BeginDrawing();

    ClearBackground(this->bg_col);

    DrawText(this->title.c_str(), 30, 30, 18, this->fg_col);
    DrawText(this->context.c_str(), 30, 60, 35, this->fg_col);

    switch (this->type) {
    case YES_NO: {
      button yes_btn(Rectangle{0, 200, 248, 50}, this->btn_col1, "YES",
                     this->fg_col, 20, 110, 210, this->btn_col2);
      button no_btn(Rectangle{252, 200, 245, 50}, this->btn_col1, "NO",
                    this->fg_col, 20, 362, 210, this->btn_col2);
      if (yes_btn.isClicked()) {
        this->actions.at("yes").first();
        if (this->actions.at("yes").second) {
          should_quit = true;
        }
      }
      if (no_btn.isClicked()) {
        this->actions.at("no").first();
        if (this->actions.at("no").second) {
          should_quit = true;
        }
      }
      break;
    }
    case OK_CANCEL: {
      button ok_btn(Rectangle{0, 200, 248, 50}, this->btn_col1, "OK",
                    this->fg_col, 20, 110, 210, this->btn_col2);
      button cancel_btn(Rectangle{252, 200, 245, 50}, this->btn_col1, "CANCEL",
                        this->fg_col, 20, 332, 210, this->btn_col2);
      if (ok_btn.isClicked()) {
        this->actions.at("ok").first();
        if (this->actions.at("ok").second) {
          should_quit = true;
        }
      }
      if (cancel_btn.isClicked()) {
        this->actions.at("cancel").first();
        if (this->actions.at("cancel").second) {
          should_quit = true;
        }
      }
      break;
    }
    case OK: {
      button ok_btn(Rectangle{0, 200, 500, 50}, this->btn_col1, "OK",
                    this->fg_col, 20, 230, 210, this->btn_col2);
      if (ok_btn.isClicked()) {
        this->actions.at("ok").first();
        if (this->actions.at("ok").second) {
          should_quit = true;
        }
      }
      break;
    }
    case RETRY_CANCEL: {
      button retry_btn(Rectangle{0, 200, 248, 50}, this->btn_col1, "RETRY",
                    this->fg_col, 20, 80, 210, this->btn_col2);
      button cancel_btn(Rectangle{252, 200, 245, 50}, this->btn_col1, "CANCEL",
                        this->fg_col, 20, 332, 210, this->btn_col2);
      if (retry_btn.isClicked()) {
        this->actions.at("retry").first();
        if (this->actions.at("retry").second) {
          should_quit = true;
        }
      }
      if (cancel_btn.isClicked()) {
        this->actions.at("cancel").first();
        if (this->actions.at("cancel").second) {
          should_quit = true;
        }
      }
      break;
    }
    default:
      if (this->debug_log) {
        throw std::invalid_argument("Unknown Popup type on popup::run()");
      }
      break;
    }

    EndDrawing();
  }

  CloseWindow();
}
