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

int main(int argc, char* argv[])
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	SetConsoleOutputCP(CP_UTF8);
#elif NF_PLATFORM == NF_PLATFORM_LINUX
#endif
    try
    {
        NFCmdLine::NFParser cmdParser;

        /**
         * @brief exceltobin ${EXCEL2BIN_MMO} --src=${RESDB_EXCELMMO_PATH}/achievement.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AchievementAchievement  --excel_sheetname=achievement  --proto_msgname=E_AchievementAchievement  --start_row=4 --dst=${PROTOCGEN_FILE_PATH}/;
         */
        cmdParser.Add<std::string>("work", 'w', "work", false, "work");
        cmdParser.Add<std::string>("src", 's', "src excel", false, "achievement.xlsx");
        cmdParser.Add<std::string>("dst", 'd', "dst dir path", false, "dir");
        cmdParser.Add<std::string>("proto_ds", 'o', "proto_ds file", false, "achievement.proto.ds");
        cmdParser.Add<std::string>("proto_packagename", 'p', "package name", false, "proto_ff");
        cmdParser.Add<std::string>("proto_msgname", 'm', "msg name", false, "E_AchievementAchievement");
        cmdParser.Add<std::string>("proto_sheet_msgname", 'x', "sheet msg name", false, "Sheet_AchievementAchievement");
        cmdParser.Add<std::string>("excel_sheetname", 'n', "sheet name", false, "achievement");
        cmdParser.Add<std::string>("start_row", 'l', "start_row", false, "4");

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
