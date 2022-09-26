#include "effect_s.h"

namespace proto_ff_s {

effecteffect_s::effecteffect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int effecteffect_s::CreateInit() {
	effectId = (int32_t)0;
	effectType = (int32_t)0;
	effectAudio = (int32_t)0;
	return 0;
}

int effecteffect_s::ResumeInit() {
	return 0;
}

void effecteffect_s::write_to_pbmsg(::proto_ff::effecteffect & msg) const {
	msg.set_effectid((int32_t)effectId);
	msg.set_effecttype((int32_t)effectType);
	msg.set_econtent((const char*)eContent.Get());
	msg.set_effectaudio((int32_t)effectAudio);
		msg.add_eparam((int32_t)eparam[i]);
	}
}

void effecteffect_s::read_from_pbmsg(const ::proto_ff::effecteffect & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct effecteffect_s));
	effectId = msg.effectid();
	effectType = msg.effecttype();
	eContent.Copy(msg.econtent());
	effectAudio = msg.effectaudio();
		eparam[i] = msg.eparam(i);
	}
}

Sheet_effecteffect_s::Sheet_effecteffect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_effecteffect_s::CreateInit() {
	return 0;
}

int Sheet_effecteffect_s::ResumeInit() {
	return 0;
}

void Sheet_effecteffect_s::write_to_pbmsg(::proto_ff::Sheet_effecteffect & msg) const {
	for(int32_t i = 0; i < (int32_t)effecteffect_List.GetSize() && i < effecteffect_List.GetMaxSize(); ++i) {
		::proto_ff::effecteffect* temp_effecteffect_list = msg.add_effecteffect_list();
		effecteffect_List[i].write_to_pbmsg(*temp_effecteffect_list);
	}
}

void Sheet_effecteffect_s::read_from_pbmsg(const ::proto_ff::Sheet_effecteffect & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_effecteffect_s));
	effecteffect_List.SetSize(msg.effecteffect_list_size() > effecteffect_List.GetMaxSize() ? effecteffect_List.GetMaxSize() : msg.effecteffect_list_size());
	for(int32_t i = 0; i < (int32_t)effecteffect_List.GetSize(); ++i) {
		const ::proto_ff::effecteffect & temp_effecteffect_list = msg.effecteffect_list(i);
		effecteffect_List[i].read_from_pbmsg(temp_effecteffect_list);
	}
}

}