#define EXTENSION_NAME CoolmathGames
#define LIB_NAME "CoolmathGames"
#define MODULE_NAME "coolmath_games"

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)


extern "C" {
    void CoolmathGamesSdkJs_cmgGameEvent(const char* cm_game_evt, const char* cm_game_lvl);
    void CoolmathGamesSdkJs_cmgAdBreak();
    void CoolmathGamesSdkJs_cmgRewardAds();
}

static int CoolmathGamesSdkJs_cmgGameEventLua(lua_State* L){
    DM_LUA_STACK_CHECK(L, 0);
    const char* cm_game_evt = luaL_checkstring(L, 1);
    const char* cm_game_lvl = nullptr;
    if (lua_type(L, 2) == LUA_TSTRING) {
        cm_game_lvl = luaL_checkstring(L, 2);
    }
    CoolmathGamesSdkJs_cmgGameEvent(cm_game_evt, cm_game_lvl);
    return 0;
}

static int CoolmathGamesSdkJs_cmgAdBreakLua(lua_State* L){
    DM_LUA_STACK_CHECK(L, 0);
    CoolmathGamesSdkJs_cmgAdBreak();
    return 0;
}

static int CoolmathGamesSdkJs_cmgRewardAdsLua(lua_State* L){
    DM_LUA_STACK_CHECK(L, 0);
    CoolmathGamesSdkJs_cmgRewardAds();
    return 0;
}

static const luaL_reg Module_methods[] =
{
    {"game_event", CoolmathGamesSdkJs_cmgGameEventLua},
    {"ad_break", CoolmathGamesSdkJs_cmgAdBreakLua},
    {"reward_ads", CoolmathGamesSdkJs_cmgRewardAdsLua},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result InitializeCoolmathGamesSdk(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeCoolmathGamesSdk(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

#else // unsupported platforms

dmExtension::Result InitializeCoolmathGamesSdk(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeCoolmathGamesSdk(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

#endif

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, InitializeCoolmathGamesSdk, 0, 0, FinalizeCoolmathGamesSdk)
