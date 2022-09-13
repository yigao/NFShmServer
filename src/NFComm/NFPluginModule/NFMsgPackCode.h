// -------------------------------------------------------------------------
//    @FileName         :    NFCodec.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                    O\ = /O
//                ____/`---'\____
//              .   ' \\| |// `.
//               / \\||| : |||// \
//             / _||||| -:- |||||- \
//               | | \\\ - /// | |
//            | \_| ''\---/'' | |
//              \ .-\__ `-` ___/-. /
//           ___`. .' /--.--\ `. . __
//        ."" '< `.___\_<|>_/___.' >'"".
//       | | : `- \`.;`\ _ /`;.`/ - ` : | |
//         \ \ `-. \_ __\ /__ _/ .-` / /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
//
// .............................................
//          佛祖保佑             永无BUG
//
// -------------------------------------------------------------------------
#pragma once

#include "common/msgpack.hpp"

struct msgpack_codec {
	const static size_t init_size = 2 * 1024;

	template<typename... Args>
	static msgpack::sbuffer pack_args(Args&&... args) {
		msgpack::sbuffer buffer(init_size);
		msgpack::pack(buffer, std::forward_as_tuple(std::forward<Args>(args)...));
		return buffer;
	}

	template<typename Arg, typename... Args,
		typename = typename std::enable_if<std::is_enum<Arg>::value>::type>
		static std::string pack_args_str(Arg arg, Args&&... args) {
		msgpack::sbuffer buffer(init_size);
		msgpack::pack(buffer, std::forward_as_tuple((int)arg, std::forward<Args>(args)...));
		return std::string(buffer.data(), buffer.size());
	}

	template<typename T>
	msgpack::sbuffer pack(T&& t) const {
		msgpack::sbuffer buffer;
		msgpack::pack(buffer, std::forward<T>(t));
		return buffer;
	}

	template<typename T>
	T unpack(char const* data, size_t length) {
		try {
			msgpack::unpack(&msg_, data, length);
			return msg_.get().as<T>();
		}
		catch (...) { throw std::invalid_argument("unpack failed: Args not match!"); }
	}

private:
	msgpack::unpacked msg_;
};
