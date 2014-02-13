/* source: http://stackoverflow.com/questions/19416981/running-luajit-object-file-from-c */
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

int main(int argc, char **argv)
{
  int status;
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  lua_getglobal(L, "require");
  lua_pushliteral(L, "main");
  status = lua_pcall(L, 1, 0, 0);
  if (status) {
      fprintf(stderr, "Error: %s\n", lua_tostring(L, -1));
      return 1;
    }
  return 0;
}
