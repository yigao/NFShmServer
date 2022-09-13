#pragma once



#include "common/spdlog/details/file_helper.h"
#include "common/spdlog/details/null_mutex.h"
#include "common/spdlog/fmt/fmt.h"
#include "common/spdlog/sinks/base_sink.h"

#include "NFComm/NFCore/NFFileUtility.h"

#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <mutex>
#include <string>

namespace spdlog
{
	namespace sinks
	{

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#elif _LINUX
#include <stdarg.h>
#include <sys/stat.h>
#endif

#ifdef _WIN32
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#else
#define ACCESS access
#define MKDIR(a) mkdir((a),0755)
#endif

		/*
		* Default generator of daily log file names.
		*/
		struct my_date_and_hour_file_name_calculator
		{
			//
			// return file pre-dir and name and its extension:
			//
			// "mylog.txt" => ("", "mylog", ".txt")
			// "mylog" => ("", "mylog", "")
			// "mylog." => ("", "mylog.", "")
			// "/dir1/dir2/mylog.txt" => ("/dir1/dir2/", "mylog", ".txt")
			//
			// the starting dot in filenames is ignored (hidden files):
			//
			// ".mylog" => ("", ".mylog". "")
			// "my_folder/.mylog" => ("my_folder/", ".mylog", "")
			// "my_folder/.mylog.txt" => ("my_folder/", ".mylog", ".txt")
			static std::tuple<filename_t, filename_t, filename_t> split_by_dir_and_extenstion(const spdlog::filename_t& fname)
			{
				auto ext_index = fname.rfind('.');

				// no valid extension found - return whole path and empty string as extension
				if (ext_index == filename_t::npos || ext_index == 0 || ext_index == fname.size() - 1)
				{
					return std::make_tuple(spdlog::filename_t(), fname, spdlog::filename_t());
				}

				// treat cases like "/etc/rc.d/somelogfile or "/abc/.hiddenfile"
				auto folder_index = fname.rfind(details::os::folder_sep);

				if (folder_index != fname.npos && folder_index >= ext_index - 1)
				{
					return std::make_tuple(fname.substr(0, folder_index), fname.substr(folder_index + 1), spdlog::filename_t());
				}

				// finally - return a valid base and extension tuple
				return std::make_tuple(fname.substr(0, folder_index), fname.substr(folder_index + 1, ext_index - folder_index - 1), fname.substr(ext_index));
			}

			// Create filename for the form pre_dir/filename.YYYY-MM-DD_hh-mm.ext
			static filename_t calc_filename(const filename_t& filename)
			{
				std::tm tm = spdlog::details::os::localtime();
				filename_t pre_dir, basename, ext;
				std::tie(pre_dir, basename, ext) = split_by_dir_and_extenstion(filename);
				std::conditional<std::is_same<filename_t::value_type, char>::value, fmt::memory_buffer, fmt::wmemory_buffer>::type w;
				auto dir_path = fmt::format(SPDLOG_FILENAME_T("{}{}{:04d}{:02d}{:02d}{}"), pre_dir, spdlog::details::os::folder_sep, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, spdlog::details::os::folder_sep);

				//CHECK if directory is already existed
				char tmp_dir_path[MAX_PATH] = { 0 };
				for (size_t i = 0; i < dir_path.length(); ++i)
				{
					tmp_dir_path[i] = dir_path[i];
					if (tmp_dir_path[i] == spdlog::details::os::folder_sep)
					{
						if (ACCESS(tmp_dir_path, 0) == -1)
						{
							int32_t ret = MKDIR(tmp_dir_path);
							if (ret != 0)
							{
								assert(0);
							}
						}
					}
				}

				fmt::format_to(
					w, SPDLOG_FILENAME_T("{}{}_{:04d}_{:02d}_{:02d}_{:02d}{}"), dir_path, basename, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, ext);
				return fmt::to_string(w);
			}

			// Create filename for the form pre_dir/filename.YYYY-MM-DD_hh-mm.ext
			static filename_t link_filename(const filename_t& filename)
			{
				//std::tm tm = spdlog::details::os::localtime();
				filename_t pre_dir, basename, ext;
				std::tie(pre_dir, basename, ext) = split_by_dir_and_extenstion(filename);
				std::conditional<std::is_same<filename_t::value_type, char>::value, fmt::memory_buffer, fmt::wmemory_buffer>::type w;
				auto dir_path = fmt::format(SPDLOG_FILENAME_T("{}{}"), pre_dir, spdlog::details::os::folder_sep);

				//CHECK if directory is already existed
				char tmp_dir_path[MAX_PATH] = { 0 };
				for (size_t i = 0; i < dir_path.length(); ++i)
				{
					tmp_dir_path[i] = dir_path[i];
					if (tmp_dir_path[i] == spdlog::details::os::folder_sep)
					{
						if (ACCESS(tmp_dir_path, 0) == -1)
						{
							int32_t ret = MKDIR(tmp_dir_path);
							if (ret != 0)
							{
								assert(0);
							}
						}
					}
				}

				fmt::format_to(
					w, SPDLOG_FILENAME_T("{}{}{}"), dir_path, basename, ext);
				return fmt::to_string(w);
			}
		};

		/*
		* Rotating file sink based on date and hour. rotates at Hour:00:00
		* Target path is Date/filename_hour.ext
		*/
		template<class Mutex, class FileNameCalc = my_date_and_hour_file_name_calculator>
		class my_date_and_hour_file_sink final : public base_sink<Mutex>
		{
		public:
			// create daily file sink which rotates on given time
			my_date_and_hour_file_sink(filename_t base_filename)
				: _base_filename(std::move(base_filename))
			{
				_rotation_tp = _next_rotation_tp();

				filename_t filename = FileNameCalc::calc_filename(_base_filename);
				filename_t link_filename = FileNameCalc::link_filename(_base_filename);
				filename_t absolute_filename = NFFileUtility::GetAbsolutePathName(filename);
				filename_t absolute_link_filename = NFFileUtility::GetAbsolutePathName(link_filename);

				_file_helper.open(filename);

				NFFileUtility::CreateLink(absolute_filename, absolute_link_filename);
			}

		protected:
			void sink_it_(const details::log_msg& msg) override
			{
				if (std::chrono::system_clock::now() >= _rotation_tp)
				{
					filename_t filename = FileNameCalc::calc_filename(_base_filename);
					filename_t link_filename = FileNameCalc::link_filename(_base_filename);
					filename_t absolute_filename = NFFileUtility::GetAbsolutePathName(filename);
					filename_t absolute_link_filename = NFFileUtility::GetAbsolutePathName(link_filename);

					_file_helper.open(filename);

					NFFileUtility::CreateLink(absolute_filename, absolute_link_filename);
					_rotation_tp = _next_rotation_tp();
				}

				fmt::memory_buffer formatted;
				sink::formatter_->format(msg, formatted);
				_file_helper.write(formatted);
			}

			void flush_() override
			{
				_file_helper.flush();
			}

		private:
			std::chrono::system_clock::time_point _next_rotation_tp()
			{
				auto now = std::chrono::system_clock::now();
				now += std::chrono::hours(1);
				time_t tnow = std::chrono::system_clock::to_time_t(now);
				tm date = spdlog::details::os::localtime(tnow);
				date.tm_min = 0;
				date.tm_sec = 0;
				auto rotation_time = std::chrono::system_clock::from_time_t(std::mktime(&date));
				return rotation_time;
			}

			filename_t _base_filename;
			std::chrono::system_clock::time_point _rotation_tp;
			details::file_helper _file_helper;
		};

		using my_date_and_hour_file_sink_mt = my_date_and_hour_file_sink<std::mutex>;
		using my_date_and_hour_file_sink_st = my_date_and_hour_file_sink<details::null_mutex>;

	} // namespace sinks
} // namespace spdlog

