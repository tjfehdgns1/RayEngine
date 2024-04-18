#include <stdio.h>

#include "include/luajit/lauxlib.h"
#include "include/luajit/lua.h"
#include "include/luajit/lualib.h"
#include "raylib.h"

int main(void) {
  const int screenWidth = 1280;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "RayEngine");
  SetTargetFPS(60);

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  luaL_dofile(L, "init.lua");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    EndDrawing();
  }

  lua_close(L);
  CloseWindow();
  return 0;
}