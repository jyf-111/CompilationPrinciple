-- the debug mode
if is_mode("debug") then

	-- enable the debug symbols
	set_symbols("debug")
	-- disable optimization
	set_optimize("none")
end
-- the release mode
if is_mode("release") then
	-- set the symbols visibility: hidden
	set_symbols("hidden")
	-- enable fastest optimization
	set_optimize("fastest")
	-- strip all symbols
	set_strip("all")
end
-- add target
target("wordanalysis")
after_build(function(target)
	import("core.project.task")
	task.run("project", { kind = "compile_commands", outputdir = "build" })
end)

-- set kind
set_kind("binary")
add_includedirs("wordanalysis/include")
-- add files
add_files("wordanalysis/src/*.cpp")
