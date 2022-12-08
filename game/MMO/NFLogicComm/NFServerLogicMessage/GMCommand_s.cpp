#include "GMCommand_s.h"

namespace proto_ff_s {

GMCommandGMCommand_s::GMCommandGMCommand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GMCommandGMCommand_s::CreateInit() {
	ID = (int32_t)0;
	ParamCount = (int32_t)0;
	return 0;
}

int GMCommandGMCommand_s::ResumeInit() {
	return 0;
}

void GMCommandGMCommand_s::write_to_pbmsg(::proto_ff::GMCommandGMCommand & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_key((const char*)Key.Get());
	msg.set_paramcount((int32_t)ParamCount);
	msg.set_des((const char*)Des.Get());
}

void GMCommandGMCommand_s::read_from_pbmsg(const ::proto_ff::GMCommandGMCommand & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GMCommandGMCommand_s));
	ID = msg.id();
	Key.Copy(msg.key());
	ParamCount = msg.paramcount();
	Des.Copy(msg.des());
}

Sheet_GMCommandGMCommand_s::Sheet_GMCommandGMCommand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GMCommandGMCommand_s::CreateInit() {
	return 0;
}

int Sheet_GMCommandGMCommand_s::ResumeInit() {
	return 0;
}

void Sheet_GMCommandGMCommand_s::write_to_pbmsg(::proto_ff::Sheet_GMCommandGMCommand & msg) const {
	for(int32_t i = 0; i < (int32_t)GMCommandGMCommand_List.GetSize() && i < GMCommandGMCommand_List.GetMaxSize(); ++i) {
		::proto_ff::GMCommandGMCommand* temp_gmcommandgmcommand_list = msg.add_gmcommandgmcommand_list();
		GMCommandGMCommand_List[i].write_to_pbmsg(*temp_gmcommandgmcommand_list);
	}
}

void Sheet_GMCommandGMCommand_s::read_from_pbmsg(const ::proto_ff::Sheet_GMCommandGMCommand & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GMCommandGMCommand_s));
	GMCommandGMCommand_List.SetSize(msg.gmcommandgmcommand_list_size() > GMCommandGMCommand_List.GetMaxSize() ? GMCommandGMCommand_List.GetMaxSize() : msg.gmcommandgmcommand_list_size());
	for(int32_t i = 0; i < (int32_t)GMCommandGMCommand_List.GetSize(); ++i) {
		const ::proto_ff::GMCommandGMCommand & temp_gmcommandgmcommand_list = msg.gmcommandgmcommand_list(i);
		GMCommandGMCommand_List[i].read_from_pbmsg(temp_gmcommandgmcommand_list);
	}
}

}