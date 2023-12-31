# Coolmath Games SDK native extension for Defold

A native extension for [Defold](https://defold.com) to use the Coolmath Games SDK.

This extension uses [JsToDef](https://github.com/AGulev/jstodef) to send messages from JavaScript to Lua.

## Installation

You can use this library in your own project by adding this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/). Open your game.project file and in the dependencies field under project add:

https://github.com/fabtjar/defold-coolmathgames-sdk/archive/refs/heads/main.zip

Or point to the ZIP file of a [specific release](https://github.com/fabtjar/defold-coolmathgames-sdk/releases).

### JsToDef

[JsToDef](https://github.com/AGulev/jstodef) will also be needed. Open your game.project file and in the dependencies field under project add:

https://github.com/AGulev/jstodef/archive/master.zip

Or point to the ZIP file of a [specific release](https://github.com/AGulev/jstodef/releases).

## API

```lua
-- When the game first loads.
coolmath_games.game_event("start")

-- When the user starts a new level.
coolmath_games.game_event("start", "1")

-- When the user replays a level.
coolmath_games.game_event("replay", "1")

-- Trigger midroll ads.
coolmath_games.ad_break()

-- Trigger reward ads.
coolmath_games.reward_ads()

-- Register to the JsToDef listener.
jstodef.add_listener(function(self, message_id, message)  
    if message_id == "CoolmathGames_adBreakStart" then
        -- Add the logic to pause the game and sound here.
    elseif message_id == "CoolmathGames_adBreakComplete" then
        -- Add the logic to resume the game and sound here.
    end
end)
```
