local ffi = require("ffi")

ffi.cdef[[
void openSocket(int port);
]]

local lib = ffi.load("./socket_fun.so")

lib.openSocket(8080)
