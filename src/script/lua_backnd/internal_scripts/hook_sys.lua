local hookSys = {}
hookSys.hooks = {}

function hookSys.add(themeName, hookID, hook)
    hookSys.hooks[themeName] = hookSys.hooks[themeName] or {}

    hookSys.hooks[themeName][hookID] = hook
end

function hookSys.call(themeName)
    local hookTable = hookSys.hooks[themeName]

    if hookTable then
        for _, hook in pairs(hookTable) do
            hook()
        end
    end
end

function hookSys.del(themeName, hookID)
    local themePath = hookSys.hooks[themeName]

    if not themePath then
        return
    end
    themePath[hookID] = nil
end