// -------------------------------------------------------------------------
//    @FileName         :    main.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-19
//    @Email			:    445267987@qq.com
//    @Module           :    main
//
// -------------------------------------------------------------------------

#include "Common.h"
#include "ExcelToMakefile.h"
#include "ExcelToProto.h"
#include "ExcelToBin.h"
#include "ExcelToTxt.h"
#include "ExcelToTxtGen.h"
#include "ExcelParseAllCheck.h"
#include "ExcelToStruct.h"

int main(int argc, char* argv[])
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	SetConsoleOutputCP(CP_UTF8);
	HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE);    //获得控制台句柄
	COORD NewSize = GetLargestConsoleWindowSize(HOUT);//获得控制台最大坐标，坐标以字符数为单位
	NewSize.X -= 1;
	NewSize.Y -= 1;    //可以不加，不加时显示滚动条
	SetConsoleScreenBufferSize(HOUT, NewSize); //设置控制台缓冲区大小

	SMALL_RECT DisplayArea = { 0,0,0,0 };
	DisplayArea.Right = NewSize.X;
	DisplayArea.Bottom = NewSize.Y;
	SetConsoleWindowInfo(HOUT, TRUE, &DisplayArea);    //设置控制台大小

	//控制台已经最大化，但是初始位置不在屏幕左上角，添加如下代码
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);    //窗体最大化
#elif NF_PLATFORM == NF_PLATFORM_LINUX
#endif
    try
    {
        NFCmdLine::NFParser cmdParser;

        cmdParser.Add<std::string>("work", 'w', "work", false, "work");
        cmdParser.Add<std::string>("src", 's', "src excel", false, "achievement.xlsx");
        cmdParser.Add<std::string>("dst", 'd', "dst dir path", false, "dir");
        cmdParser.Add<std::string>("proto_ds", 'o', "proto_ds file", false, "achievement.proto.ds");

        cmdParser.Usage();

        cmdParser.ParseCheck(argc, argv);

        std::string work = cmdParser.Get<std::string>("work");

        if (work == "exceltomakefile")
        {
            std::string src_file = cmdParser.Get<std::string>("src");
            std::string dst_path = cmdParser.Get<std::string>("dst");
            NFStringUtility::Trim(src_file);
            NFStringUtility::Trim(dst_path);

            std::vector<std::string> vecFile;
            NFStringUtility::Split(src_file, " ", &vecFile);
            ExcelToMakeFile(vecFile, dst_path);
        }
        else if (work == "exceltoproto")
        {
            std::string excel = cmdParser.Get<std::string>("src");
            std::string out_path = cmdParser.Get<std::string>("dst");
            NFStringUtility::Trim(excel);
            NFStringUtility::Trim(out_path);

            int ret = ExcelToProto::Instance()->Init(excel, out_path);
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToProto Init Failed");
                NFSLEEP(1000);
                exit(-1);
            }

            ret = ExcelToProto::Instance()->HandleExcel();
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToProto HandleExcel Failed");
                NFSLEEP(1000);
                exit(-1);
            }
            ExcelToProto::ReleaseInstance();
        }
        else if (work == "exceltobin")
        {
            std::string excel = cmdParser.Get<std::string>("src");
            std::string out_path = cmdParser.Get<std::string>("dst");
            std::string proto_ds = cmdParser.Get<std::string>("proto_ds");
            NFStringUtility::Trim(excel);
            NFStringUtility::Trim(out_path);
            NFStringUtility::Trim(proto_ds);

            int ret = ExcelToBin::Instance()->Init(excel, out_path, proto_ds);
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToBin Init Failed");
                NFSLEEP(1000);
                exit(-1);
            }

            ret = ExcelToBin::Instance()->HandleExcel();
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToBin HandleExcel Failed");
                NFSLEEP(1000);
                exit(-1);
            }
            ExcelToBin::ReleaseInstance();
        }
        else if (work == "exceltostruct")
        {
            std::string proto_filename = cmdParser.Get<std::string>("src");
            std::string out_path = cmdParser.Get<std::string>("dst");
            std::string proto_ds = cmdParser.Get<std::string>("proto_ds");
            NFStringUtility::Trim(proto_filename);
            NFStringUtility::Trim(out_path);
            NFStringUtility::Trim(proto_ds);

            int ret = ExcelToStruct::Instance()->Init(proto_filename, out_path, proto_ds);
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToStruct Init Failed");
                NFSLEEP(1000);
                exit(-1);
            }

            ret = ExcelToStruct::Instance()->WriteToStruct();
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToStruct HandleExcel Failed");
                NFSLEEP(1000);
                exit(-1);
            }
            ExcelToStruct::ReleaseInstance();
        }
        else if (work == "exceltotxt")
        {
            std::string excel = cmdParser.Get<std::string>("src");
            std::string out_path = cmdParser.Get<std::string>("dst");
            NFStringUtility::Trim(excel);
            NFStringUtility::Trim(out_path);

            int ret = ExcelToTxt::Instance()->Init(excel, out_path);
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToTxt Init Failed");
                NFSLEEP(1000);
                exit(-1);
            }

            ret = ExcelToTxt::Instance()->HandleExcel();
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToTxt HandleExcel Failed");
                NFSLEEP(1000);
                exit(-1);
            }

            ExcelToTxt::ReleaseInstance();
        }
        else if (work == "exceltotxtgen")
        {
            std::string excel = cmdParser.Get<std::string>("src");
            std::string out_path = cmdParser.Get<std::string>("dst");
            NFStringUtility::Trim(excel);
            NFStringUtility::Trim(out_path);

            int ret = ExcelToTxtGen::Instance()->Init(excel, out_path, false);
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToTxtGen Init Failed");
                NFSLEEP(1000);
                exit(-1);
            }

            ret = ExcelToTxtGen::Instance()->HandleExcel();
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToTxtGen HandleExcel Failed");
                NFSLEEP(1000);
                exit(-1);
            }

            ExcelToTxtGen::ReleaseInstance();
        }
        else if (work == "allcheck")
        {
            uint64_t startTime = NFGetSecondTime();
            std::string list = cmdParser.Get<std::string>("src");
            int iRet = ExcelParseAllCheck::Instance()->CheckExcel(list);
            if (iRet != 0)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "All Excel Check Failed..............UseTime:{}", NFGetSecondTime() - startTime);
                NFSLEEP(1000);
                exit(-1);
            }
            else {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "All Excel Check Success, No Error, No Warning.............UseTime:{}", NFGetSecondTime()-startTime);
            }

            ExcelParseAllCheck::ReleaseInstance();
        }
#if NF_PLATFORM == NF_PLATFORM_WIN
        else
        {
		    uint64_t startTime = NFGetSecondTime();
            std::string list = "./list.txt"; // cmdParser.Get<std::string>("src");
		    int iRet = ExcelParseAllCheck::Instance()->CheckExcel(list);
		    if (iRet != 0)
		    {
			    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "All Excel Check Failed..............UseTime:{}", NFGetSecondTime() - startTime);
		    }
		    else {
			    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "All Excel Check Success, No Error, No Warning.............UseTime:{}", NFGetSecondTime() - startTime);
		    }

            ExcelParseAllCheck::Instance()->ReleaseInstance();

		    std::string end;
		    std::cout << "please input some........end the program";
		    std::cin >> end;
        }
#endif
    }
    catch (NFCmdLine::NFCmdLine_Error& e)
    {
        std::cout << e.what() << std::endl;
        NFSLEEP(1000);
        exit(-1);
    }
}
