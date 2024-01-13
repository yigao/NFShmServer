Tutorial = { }

function Tutorial.load_script_file()
	register_module(TutorialModule, "TutorialModule")
end

--加载所有的module
LuaNFrame.InsertLoadFunc(Tutorial.load_script_file)