// -------------------------------------------------------------------------
//    @FileName         :    NFEmailSenderTest.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/8
//    @Email			:    445267987@qq.com
//    @Module           :    NFEmailSenderTest
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <iostream>
#include <mutex>
#include <atomic>
#include "NFComm/NFPluginModule/NFEmailSender.h"

void TestEmailSender()
{

    CSmtpSendMail sendMail;
    sendMail.SetSmtpServer("mangguoyi445@163.com","QQLMFJBVAMYDAOQQ","smtp.163.com", "465");
    sendMail.SetSendName("Server Dump Info");
    sendMail.SetSendMail("mangguoyi445@163.com");
    sendMail.AddRecvMail("445267987@qq.com");
    sendMail.SetSubject("TEST SUBJECT");
    sendMail.SetBodyContent("fack you");
    if (!sendMail.SendMail())
    {
        std::cout << "mail error" << std::endl;
    }
    else
    {
        std::cout << "mail ok!"<<std::endl;
    }
}
