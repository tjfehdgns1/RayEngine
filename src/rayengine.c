#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
#include "raylib.h"

int main(void) {
  const int screenWidth = 1280;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "RayEngine");
  SetTargetFPS(60);

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  luaL_dofile(L, "game.lua");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    lua_getglobal(L, "update");
    lua_pushnumber(L, GetFrameTime());
    lua_call(L, 1, 0);
    DrawText("Simple text", screenWidth / 2, screenHeight / 2, 64, BLACK);

    EndDrawing();
  }
  lua_close(L);
  CloseWindow();
  return 0;
}