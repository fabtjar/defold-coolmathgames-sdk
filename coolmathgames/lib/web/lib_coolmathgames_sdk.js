// https://kripken.github.io/emscripten-site/docs/porting/connecting_cpp_and_javascript/Interacting-with-code.html

var LibCoolmathGamesSdk = {

    CoolmathGamesSdkJs_cmgGameEvent: function(cm_game_evt, cm_game_lvl) {
        cm_game_evt = UTF8ToString(cm_game_evt);
        cm_game_lvl = UTF8ToString(cm_game_lvl);
        if (parent.cmgGameEvent) {
            if (cm_game_lvl) {
                parent.cmgGameEvent(cm_game_evt, cm_game_lvl);
            } else {
                parent.cmgGameEvent(cm_game_evt);
            }
        }
    },

    CoolmathGamesSdkJs_cmgAdBreak: function() {
        cmgAdBreak();
    },

    CoolmathGamesSdkJs_cmgRewardAds: function() {
        cmgRewardAds()
    },

}

mergeInto(LibraryManager.library, LibCoolmathGamesSdk);
