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

int main(int argc, char* argv[])
{
    try
    {
        NFCmdLine::NFParser cmdParser;

        cmdParser.Add<std::string>("src", 's', "src excel", false, "excel");
        cmdParser.Add<std::string>("dst", 'd', "dst dir path", false, "dir");
        cmdParser.Add<std::string>("work", 'w', "work", false, "work");

        cmdParser.Usage();

        cmdParser.ParseCheck(argc, argv);

        std::string src_excel = cmdParser.Get<std::string>("src");
        std::string dst_path = cmdParser.Get<std::string>("dst");
        std::string work = cmdParser.Get<std::string>("work");

        try {
            if (work == "exceltomakefile")
            {
                ExcelToMakeFile(src_excel, dst_path);
            }
        }
        catch (XlsException& e)
        {
            std::cout << e.what() << std::endl;
            NFSLEEP(1000);
            exit(0);
        }
    }
    catch (NFCmdLine::NFCmdLine_Error& e)
    {
        std::cout << e.what() << std::endl;
        NFSLEEP(1000);
        exit(0);
    }
}
