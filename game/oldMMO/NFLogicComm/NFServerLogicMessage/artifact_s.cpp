#include "artifact_s.h"

namespace proto_ff_s {

artifactartifactattributeDesc_s::artifactartifactattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int artifactartifactattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int artifactartifactattributeDesc_s::ResumeInit() {
	return 0;
}

void artifactartifactattributeDesc_s::write_to_pbmsg(::proto_ff::artifactartifactattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void artifactartifactattributeDesc_s::read_from_pbmsg(const ::proto_ff::artifactartifactattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct artifactartifactattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

artifactartifact_s::artifactartifact_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int artifactartifact_s::CreateInit() {
	id = (int64_t)0;
	professionID = (int32_t)0;
	quality = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	skill = (int64_t)0;
	artifactType = (int32_t)0;
	return 0;
}

int artifactartifact_s::ResumeInit() {
	return 0;
}

void artifactartifact_s::write_to_pbmsg(::proto_ff::artifactartifact & msg) const {
	msg.set_id((int64_t)id);
	msg.set_resource((const char*)resource.Get());
	msg.set_previewres((const char*)previewRes.Get());
	msg.set_professionid((int32_t)professionID);
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_quality((int32_t)quality);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	msg.set_skill((int64_t)skill);
	msg.set_skillui((const char*)skillUi.Get());
	msg.set_artifacttype((int32_t)artifactType);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::artifactartifactattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void artifactartifact_s::read_from_pbmsg(const ::proto_ff::artifactartifact & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct artifactartifact_s));
	id = msg.id();
	resource.Copy(msg.resource());
	previewRes.Copy(msg.previewres());
	professionID = msg.professionid();
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	quality = msg.quality();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	skill = msg.skill();
	skillUi.Copy(msg.skillui());
	artifactType = msg.artifacttype();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::artifactartifactattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_artifactartifact_s::Sheet_artifactartifact_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_artifactartifact_s::CreateInit() {
	return 0;
}

int Sheet_artifactartifact_s::ResumeInit() {
	return 0;
}

void Sheet_artifactartifact_s::write_to_pbmsg(::proto_ff::Sheet_artifactartifact & msg) const {
	for(int32_t i = 0; i < (int32_t)artifactartifact_List.GetSize() && i < artifactartifact_List.GetMaxSize(); ++i) {
		::proto_ff::artifactartifact* temp_artifactartifact_list = msg.add_artifactartifact_list();
		artifactartifact_List[i].write_to_pbmsg(*temp_artifactartifact_list);
	}
}

void Sheet_artifactartifact_s::read_from_pbmsg(const ::proto_ff::Sheet_artifactartifact & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_artifactartifact_s));
	artifactartifact_List.SetSize(msg.artifactartifact_list_size() > artifactartifact_List.GetMaxSize() ? artifactartifact_List.GetMaxSize() : msg.artifactartifact_list_size());
	for(int32_t i = 0; i < (int32_t)artifactartifact_List.GetSize(); ++i) {
		const ::proto_ff::artifactartifact & temp_artifactartifact_list = msg.artifactartifact_list(i);
		artifactartifact_List[i].read_from_pbmsg(temp_artifactartifact_list);
	}
}

}