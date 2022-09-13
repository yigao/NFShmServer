#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <scsi/sg.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include "hwinfo/hw_info.h"

static void parse_disk_name(const char *file_name, const char *match_words, std::string &disk_name)
{
    disk_name.c_str();

    std::ifstream ifs(file_name, std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }

    char line[4096] = {0};
    while (!ifs.eof())
    {
        ifs.getline(line, sizeof(line));
        if (!ifs.good())
        {
            break;
        }
        const char *board = strstr(line, match_words);
        if (NULL == board)
        {
            continue;
        }
        if (strlen(board) != 1)
        {
            continue;
        }
        break;
    }
    
    while (!ifs.eof())
    {
        ifs.getline(line, sizeof(line));
        if (!ifs.good())
        {
            break;
        }
        const char *board = strstr(line, "disk");
        if (NULL == board)
        {
            continue;
        }
        
        int i = 0;
        while (' ' != line[i])
        {
            disk_name.push_back(line[i]);
            ++i;
        }
        if (!disk_name.empty())
        {
            break;
        }
    }
    ifs.close();
}

static void parse_disk_serial(const char *file_name, const char *match_words, std::string &serial_no)
{
    serial_no.c_str();

    std::ifstream ifs(file_name, std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }

    char line[4096] = {0};
    while (!ifs.eof())
    {
        ifs.getline(line, sizeof(line));
        if (!ifs.good())
        {
            break;
        }

        const char *board = strstr(line, match_words);
        if (NULL == board)
        {
            continue;
        }
        board += strlen(match_words);

        while ('\0' != board[0])
        {
            if (' ' != board[0])
            {
                serial_no.push_back(board[0]);
            }
            ++board;
        }

        if ("None" == serial_no)
        {
            serial_no.clear();
            continue;
        }

        if (!serial_no.empty())
        {
            break;
        }
    }

    ifs.close();
}

static bool get_disk_name_system(std::string &disk_name)
{
    disk_name.c_str();

    const char *dmidecode_result = ".dmidecode_result.txt";
    char command[512] = {0};
    snprintf(command, sizeof(command), "lsblk -nls > %s", dmidecode_result);

    if (0 == system(command))
    {
        parse_disk_name(dmidecode_result, "/", disk_name);
    }

    unlink(dmidecode_result);

    return (!disk_name.empty());
}

static bool get_disk_by_system(std::string disk_name, std::string &serial_no)
{
    serial_no.c_str();

    const char *dmidecode_result = ".dmidecode_result.txt";
    char command[512] = {0};
    snprintf(command, sizeof(command), "udevadm info --query=all --name=%s | grep ID_SERIAL= > %s", disk_name.c_str(), dmidecode_result);

    if (0 == system(command))
    {
        parse_disk_serial(dmidecode_result, "ID_SERIAL=", serial_no);
    }

    unlink(dmidecode_result);

    return (!serial_no.empty());
}

bool get_disk_id(std::string &disk_id)
{
    if (0 == getuid())
    {
        std::string disk_name;
        if (get_disk_name_system(disk_name))
        {
            if (get_disk_by_system(disk_name, disk_id))
            {
                return (true);
            }
        }
    }
    return (false);
}
