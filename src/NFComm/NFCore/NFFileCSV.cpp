// -------------------------------------------------------------------------
//    @FileName         :    NFFileCSV.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFileCSV.cpp
//
// -------------------------------------------------------------------------

#include "NFFileCSV.h"

bool NFFileCSV::ReadCsvFile(const std::string& szFileName, std::vector<std::vector<std::string>>& table)
{
    FILE * pFile = ::fopen(szFileName.c_str(),"r");
    if (pFile == NULL)
    {
        //system("pwd");

        //int nError = errno;
        //printf(strerror(nError));
        return false;
    }


#define ADD_TEXT(table,row,col,buf,len)                       \
{	                                                          \
	if(row>=(int)table.size())                                     \
	{                                                         \
		table.resize(row+1);                                  \
	}                                                         \
	if(col >= (int)table[row].size())                              \
	{                                                         \
		table[row].resize(col+1);                             \
	}                                                         \
	buf[len] = 0;                                             \
	table[row][col] += buf;                                   \
	len = 0;                                                  \
}

    const int buff_max = 1024;
    char context[buff_max]; //文件内容
    int file_len = 0;

    char buf[buff_max]={0}; //保存每个列的内容
    int len = 0;       //本列有效长度
    int DquoteNum = 0;  //双引号数量
    int row = 0;	    //行
    int col = 0;       //列

    while( (file_len = ::fread(context,1,sizeof(context)-1,pFile))>0)
    {
        int ch = 0;  //读取一个字符
        for(int i=0;i<file_len && (ch=context[i]) != 0;i++)
        {
            switch(ch)
            {
                case  ',': //逗号
                {
                    if(DquoteNum%2==0) //为偶数，所有双引号匹配
                    {
                        ADD_TEXT(table,row,col,buf,len);
                        col++;
                        DquoteNum = 0;
                        continue;
                    }
                }
                    break;
                case '\n':  //换行
                {
                    if(DquoteNum%2==0)  //为偶数，所有双引号匹配
                    {
                        ADD_TEXT(table,row,col,buf,len);
                        col = 0;
                        DquoteNum = 0;
                        row++;
                        continue;
                    }
                }
                    break;
                case ' ':  //空格
                case '\t': //tab键
                {
                    if(DquoteNum == 0 ) //本列不是以双引号开头，所以不能包含空格
                    {
                        continue;
                    }
                }
                    break;
                case  '"':  //双引号
                {
                    DquoteNum++;

                    if(DquoteNum == 1) //开头的双引号忽略
                    {
                        len=0; //去掉第一个双引号前的字符
                        continue;
                    }
                    else if(DquoteNum % 2 == 0)
                    {
                        //当一列中带有特殊字符:逗号，空格，换行，双引号时，本列以双引号开头及双引号结尾,分为两种情况:
                        //1) "本列不带有双引号,只带其他特殊字符"
                        //   ^                                 ^
                        // DquoteNum=1 (不进该分支)       DquoteNum=2 忽略

                        //2) "本列带有需要转义的双引号("")"
                        //   ^                         ^^
                        // DquoteNum=1 (不进该分支)    2,3 第二个忽略,第三个保留，

                        continue;
                    }
                }
                    break;

                default:
                    break;
            }

            if( len==(int)sizeof(buf)-1) //缓存区已满
            {
                ADD_TEXT(table,row,col,buf,len);
            }

            buf[len++] = ch;

        }
    }

    //需要处理最后一列
    if(len>0)
    {
        ADD_TEXT(table,row,col,buf,len);
    }

    ::fclose(pFile);

    return true;
}

bool NFFileCSV::WriteCsvFile(const std::string& szFileName ,const std::vector<std::vector<std::string>>& table)
{
    FILE * pFile = ::fopen(szFileName.c_str(),"w");
    if(pFile == NULL)
    {
        return false;
    }

    //保存需要写到文件中去的内容，缓存满的时候才真正写文件，避免多次写文件，性能低下
    const int buff_max = 1024;

    char context[buff_max]; //文件内容
    int file_len = 0;

#define WRITE_CHAR(ch)                                                       \
{                                                                           \
	if(file_len>=(int)sizeof(context)-1)                                          \
	{                                                                        \
	if((int)::fwrite(context,1,file_len,pFile) !=file_len ){ return false;}     \
	file_len = 0;                                                          \
	}                                                                        \
	context[file_len++] = ch;                                                \
}

#define WRITE_STR( str ,len )                                                              \
{                                                                                          \
	if( len >= (int)sizeof(context)-1 || len + file_len >= (int)sizeof(context)-1)                   \
	{                                                                                      \
	if(file_len > 0)                                                                 \
	{                                                                                \
	if((int)::fwrite(context,1,file_len,pFile) !=file_len ) { return false; }       \
	file_len = 0;                                                              \
	}                                                                                \
	if(len > 0)                                                                      \
	{                                                                                \
	if((int)::fwrite(str,1,len,pFile) != len ) { return false; }                    \
	}                                                                                \
	}                                                                                      \
	else if( len > 0)                                                                      \
	{                                                                                      \
	memcpy(context+file_len,str,len);                                                   \
	file_len += len;                                                                    \
	}	                                                                                   \
}


    for(size_t row =0; row<table.size();row++)
    {
        const std::vector<std::string> & vectRow = table[row];
        for(size_t col=0; col < vectRow.size();col++)
        {
            //处理每一列
            if(col != 0)
            {
                WRITE_CHAR( ',');  //不是首列，先增加逗号分隔符
            }
            const char * ptr = vectRow[col].c_str();
            if (ptr != NULL ) //-V547
            {
                const char * ptrSrc = ptr;
                char ch;
                bool bHaveSeparate = false; //是否有特殊字符
                for(;(ch = * ptr ) != 0; ptr++)
                {
                    if(bHaveSeparate==false)
                    {
                        if((ch == '"' || ch==',' || ch=='\n' || ch == ' ' || ch== '\t'))
                        {
                            WRITE_CHAR( '"');  //增加列开头的双引号
                            WRITE_STR(ptrSrc,(ptr-ptrSrc));
                            bHaveSeparate = true;
                        }
                        else
                        {
                            continue;  //目前为止，还不知道本列是否含有特殊字符
                        }
                    }

                    WRITE_CHAR( ch );
                    //本字符是双引号，需要增加一个
                    if(ch == '"')
                    {
                        WRITE_CHAR( '"');
                    }
                }

                if( bHaveSeparate ) //有殊字符
                {
                    WRITE_CHAR('"'); //增加双引号
                }
                else
                {
                    //写本列内容
                    WRITE_STR(ptrSrc,(ptr-ptrSrc));
                }
            }
        }
        //增加换行符
        WRITE_CHAR(  '\n' );
    }

    if(file_len>0)
    {
        if((int)::fwrite(context,1,file_len,pFile) !=file_len )
        {
            //写文件出错了
            return false;
        }
        file_len = 0;
    }

    ::fclose(pFile);

    return true;
}

