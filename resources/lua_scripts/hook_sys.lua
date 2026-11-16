local hookSys = {}
hookSys.hooks = {}


function hookSys.add(themeName, hookName, func)
    local theme = hookSys.hooks[themeName]

    if not theme then
        theme = { funcList = {}, nameList = {}, map = {}, hooksCount = 0 }
        hookSys.hooks[themeName] = theme
    end

    local idx = theme.map[hookName]
    if idx then
        theme.funcList[idx] = func
        return
    end

    theme.hooksCount = theme.hooksCount + 1
    local newIdx     = theme.hooksCount

    theme.nameList[newIdx] = hookName
    theme.funcList[newIdx] = func
    theme.map[hookName]    = newIdx
end


function hookSys.call(themeName, ...)
    local theme = hookSys.hooks[themeName]

    if not theme then
        return
    end

    local list  = theme.funcList
    local count = theme.hooksCount

    for i = 1, count do
        list[i](...)
    end
end


function hookSys.del(themeName, hookName)
    local theme = hookSys.hooks[themeName]

    if not theme then
        return
    end

    local idx = theme.map[hookName]
    if not idx then
        return
    end

    local count = theme.hooksCount

    if idx ~= count then
        local lastHookName  = theme.nameList[count]
        theme.funcList[idx] = theme.funcList[count]
        theme.nameList[idx] = lastHookName
        theme.map[lastHookName] = idx
    end

    theme.funcList[count] = nil
    theme.nameList[count] = nil
    theme.map[hookName]   = nil
    theme.hooksCount      = count - 1

end

return hookSys