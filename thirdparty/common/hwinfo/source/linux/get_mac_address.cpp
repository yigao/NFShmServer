#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include "hwinfo/hw_info.h"
bool get_mac_address_by_ioctl(std::string &mac_address)
{
    mac_address.clear();

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        return (false);
    }

    struct ifreq ifr;
    strncpy(ifr.ifr_name, "eth0", sizeof(ifr.ifr_name) - 1);
    bool ret = (ioctl(sock, SIOCGIFHWADDR, &ifr) >= 0);

    close(sock);

    const char hex[] =
        {
            '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char mac[16] = {0};
    for (int index = 0; index < 6; ++index)
    {
        size_t value = ifr.ifr_hwaddr.sa_data[index] & 0xFF;
        mac[2 * index + 0] = hex[value / 16];
        mac[2 * index + 1] = hex[value % 16];
    }
    std::string(mac).swap(mac_address);
    return (ret);
}

bool get_mac_address(std::string &mac_address)
{
    if (get_mac_address_by_ioctl(mac_address))
    {
        return (true);
    }
    return (false);
}
