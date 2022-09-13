// -------------------------------------------------------------------------
//    @FileName         :    NFNaming.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNaming.cpp
//
// -------------------------------------------------------------------------


#include "NFNaming.h"
#include "NFComm/NFCore/NFCommon.h"

int32_t NFNaming::MakeName(int64_t app_id,
                         const std::string& service_dir,
                         const std::string& service,
                         std::string* name)
{
    std::ostringstream out_stream;
    out_stream << "/" << app_id;
    if (false == service_dir.empty() && service_dir[0] != '/') {
        out_stream << "/";
    }
    out_stream << service_dir;
    if (true == service_dir.empty() || service_dir[service_dir.size() - 1] != '/') {
        out_stream << "/";
    }
    out_stream << service;
    name->assign(out_stream.str());
    for (size_t p = name->find("//"); p != std::string::npos; p = name->find("//", p)) {
        name->erase(p, 1);
    }
    return 0;
}

int32_t NFNaming::MakeTbusppUrl(const std::string& name, int64_t inst_id, std::string* url)
{
    url->assign("tbuspp://");
    for (uint32_t idx = 1 ; idx < name.size() ; ++idx) {
        if ('/' == name[idx]) {
            url->append(1, '.');
        } else {
            url->append(1, name[idx]);
        }
    }
    url->append("/" + NFCommon::tostr(inst_id));
    return 0;
}

int32_t NFNaming::FormatNameStr(std::string* name)
{
    if (NULL == name || name->empty()) {
        return -1;
    }
    // 如果name不含有'/'则将'.'转为'/'
    if (std::string::npos == name->find('/')) {
        auto pos = name->find('.');
        while (std::string::npos != pos) {
            name->at(pos) = '/';
            pos = name->find('.', pos);
        }
    }
    // 开始处没有'/'，则补上
    if (name->at(0) != '/') {
        name->insert(0, 1, '/');
    }
    // 结尾处有'/'，则去掉
    if (name->size() > 1 && name->at(name->size() - 1) == '/') {
        name->erase(name->size() - 1, 1);
    }
    return 0;
}


