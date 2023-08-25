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

int main(int argc, char* argv[])
{
    try
    {
        NFCmdLine::NFParser cmdParser;

        cmdParser.Add<std::string>("work", 'w', "work", false, "work");
        cmdParser.Add<std::string>("src", 's', "src excel", false, "excel");
        cmdParser.Add<std::string>("dst", 'd', "dst dir path", false, "dir");

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
                exit(0);
            }

            ret = ExcelToProto::Instance()->HandleExcel();
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ExcelToProto HandleExcel Failed");
                NFSLEEP(1000);
                exit(0);
            }
        }
    }
    catch (NFCmdLine::NFCmdLine_Error& e)
    {
        std::cout << e.what() << std::endl;
        NFSLEEP(1000);
        exit(-1);
    }
}
