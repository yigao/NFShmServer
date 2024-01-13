TutorialModule = TutorialModule or {}

function TutorialModule.Init()
    NFLogError(NF_LOG_SYSTEMLOG, 0, "TutorialModule.Init")
    --10s执行一次定时器
    LuaNFrame.AddTimer("TutorialModule.OnTimer", 10)
    TutorialModule.idCount = 0
end

function TutorialModule.Execute()

end

function TutorialModule.Shut()
    NFLogError(NF_LOG_SYSTEMLOG, 0, "TutorialModule.Shut")
end

function TutorialModule.OnTimer()
    TutorialModule.idCount = TutorialModule.idCount + 1
    NFLogError(NF_LOG_SYSTEMLOG, 0, "TutorialModule.OnTimer TutorialModule.idCount:{}", TutorialModule.idCount)
    NFLogError(NF_LOG_SYSTEMLOG, 0, "TutorialModule.OnTimer TutorialModule.idCount:{}********************", TutorialModule.idCount)
end