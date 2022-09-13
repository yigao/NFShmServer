// -------------------------------------------------------------------------
//    @FileName         :    NFIniReader.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <cstdio>
#include <map>
#include <set>
#include <string>

#include "NFPlatform.h"

class _NFExport NFINIReader
{
public:
	explicit NFINIReader()
	{
		memset(m_last_error, 0, sizeof(m_last_error));
	}

	~NFINIReader()
	{
	}

	/// @brief 解析文件
	/// @return 0 成功
	/// @return <0 失败
	/// @note 每次调用会清除上一次的解析结果
	int32_t Parse(const std::string& filename);

	void Clear();

	/// @brief 获取string类型字段的值，字段未配置时使用默认值
	std::string Get(const std::string& section, const std::string& name,
	                const std::string& default_value);

	// Get an integer (long) value from INI file, returning default_value
	// if not found or not a valid integer (decimal "1234", "-1234",
	// or hex "0x4d2").
	int32_t GetInt32(const std::string& section, const std::string& name,
	                 int32_t default_value);

	uint32_t GetUInt32(const std::string& section, const std::string& name,
	                   uint32_t default_value);

	int64_t GetInt64(const std::string& section, const std::string& name,
	                 int64_t default_value);

	uint64_t GetUInt64(const std::string& section, const std::string& name,
	                   uint64_t default_value);

	// Get a real (floating point double) value from INI file, returning
	// default_value if not found or not a valid floating point value
	// according to strtod().
	double GetReal(const std::string& section, const std::string& name, double default_value);

	// Get a boolean value from INI file, returning default_value
	// if not found or if not a valid true/false value. Valid true
	// values are "true", "yes", "on", "1", and valid false values are
	// "false", "no", "off", "0" (not case sensitive).
	bool GetBoolean(const std::string& section, const std::string& name, bool default_value);

	// Returns all the section names from the INI file, in alphabetical order,
	// but in the original casing
	const std::set<std::string>& GetSections() const;

	// Returns all the field names from a section in the INI file, in
	// alphabetical order, but in the original casing. Returns an
	// empty set if the field name is unknown
	std::set<std::string> GetFields(const std::string& section);

	/// @brief 返回最后错误字符串描述
	/// @return 最后一次错误的信息
	const char* GetLastError() const
	{
		return m_last_error;
	}

private:
	int32_t ParseFile(FILE* file);

private:
	char m_last_error[256];
	std::set<std::string> m_sections;
	std::map<std::string, std::map<std::string, std::string>> m_fields;
};

