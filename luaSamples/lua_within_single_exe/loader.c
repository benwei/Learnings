/* source: http://stackoverflow.com/questions/19416981/running-luajit-object-file-from-c */
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static int test_myadd(lua_State *L)
{
    int status;
    int x = 4, y=6, sum = 0;
    lua_getglobal(L, "myadd");
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);
    status = lua_pcall(L, 2, 1, 0); /* 2 param, 1 result */
    if (status) {
        fprintf(stderr, "myadd error: %s\n", lua_tostring(L, -1));
        return 1;
    }
    if (!lua_isnumber(L, -1)) {
        fprintf(stderr, "myadd result must return a number\n");
    }

    sum = lua_tointeger(L, -1);
    lua_pop(L,1);
    fprintf(stdout, "myadd(%d,%d) --> sum: %d\n", x, y, sum);
    return 0;
}

int main(int argc, char **argv)
{
    int status;
    /* both of following initial method works well */
#ifdef USING_luaL
    lua_State *L = luaL_newstate();
#else
    lua_State *L = lua_open();
#endif
    luaL_openlibs(L);
    lua_getglobal(L, "require");
    lua_pushliteral(L, "main");
    status = lua_pcall(L, 1, 0, 0);
    if (status) {
        fprintf(stderr, "Error: %s\n", lua_tostring(L, -1));
        return 1;
    }

    //luaL_dofile(L, "main.lua");
    test_myadd(L);
    lua_close(L);
    return 0;
}
