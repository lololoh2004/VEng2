-- C THINGS PORT
-- THIS IS ONLY FOR FUN

return {
    -- ALIAS PART
    include = function(moduleName)
        return require(moduleName)
    end,
    define = function(name, val)
        _G[name] = val
    end
}