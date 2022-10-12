#include "mount_s.h"

namespace proto_ff_s {

mountmountuseattrDesc_s::mountmountuseattrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mountmountuseattrDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int mountmountuseattrDesc_s::ResumeInit() {
	return 0;
}

void mountmountuseattrDesc_s::write_to_pbmsg(::proto_ff::mountmountuseattrDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void mountmountuseattrDesc_s::read_from_pbmsg(const ::proto_ff::mountmountuseattrDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mountmountuseattrDesc_s));
	type = msg.type();
	value = msg.value();
}

mountmount_s::mountmount_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mountmount_s::CreateInit() {
	mountId = (int64_t)0;
	quality = (int32_t)0;
	occupation = (int64_t)0;
	speedNum = (int32_t)0;
	needItem = (int64_t)0;
	starLv = (int32_t)0;
	starNumber = (int32_t)0;
	sourceLink = (int32_t)0;
	upAttributeId = (int64_t)0;
	return 0;
}

int mountmount_s::ResumeInit() {
	return 0;
}

void mountmount_s::write_to_pbmsg(::proto_ff::mountmount & msg) const {
	msg.set_mountid((int64_t)mountId);
	msg.set_name((const char*)name.Get());
	msg.set_quality((int32_t)quality);
	msg.set_occupation((int64_t)occupation);
	msg.set_speednum((int32_t)speedNum);
	msg.set_needitem((int64_t)needItem);
	msg.set_itemnum((const char*)ItemNum.Get());
	msg.set_starlv((int32_t)starLv);
	msg.set_starnumber((int32_t)starNumber);
	msg.set_sourcelink((int32_t)sourceLink);
	msg.set_upattributeid((int64_t)upAttributeId);
	for(int32_t i = 0; i < (int32_t)useattr.GetSize() && i < useattr.GetMaxSize(); ++i) {
		::proto_ff::mountmountuseattrDesc* temp_useattr = msg.add_useattr();
		useattr[i].write_to_pbmsg(*temp_useattr);
	}
}

void mountmount_s::read_from_pbmsg(const ::proto_ff::mountmount & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mountmount_s));
	mountId = msg.mountid();
	name.Copy(msg.name());
	quality = msg.quality();
	occupation = msg.occupation();
	speedNum = msg.speednum();
	needItem = msg.needitem();
	ItemNum.Copy(msg.itemnum());
	starLv = msg.starlv();
	starNumber = msg.starnumber();
	sourceLink = msg.sourcelink();
	upAttributeId = msg.upattributeid();
	useattr.SetSize(msg.useattr_size() > useattr.GetMaxSize() ? useattr.GetMaxSize() : msg.useattr_size());
	for(int32_t i = 0; i < (int32_t)useattr.GetSize(); ++i) {
		const ::proto_ff::mountmountuseattrDesc & temp_useattr = msg.useattr(i);
		useattr[i].read_from_pbmsg(temp_useattr);
	}
}

Sheet_mountmount_s::Sheet_mountmount_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_mountmount_s::CreateInit() {
	return 0;
}

int Sheet_mountmount_s::ResumeInit() {
	return 0;
}

void Sheet_mountmount_s::write_to_pbmsg(::proto_ff::Sheet_mountmount & msg) const {
	for(int32_t i = 0; i < (int32_t)mountmount_List.GetSize() && i < mountmount_List.GetMaxSize(); ++i) {
		::proto_ff::mountmount* temp_mountmount_list = msg.add_mountmount_list();
		mountmount_List[i].write_to_pbmsg(*temp_mountmount_list);
	}
}

void Sheet_mountmount_s::read_from_pbmsg(const ::proto_ff::Sheet_mountmount & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_mountmount_s));
	mountmount_List.SetSize(msg.mountmount_list_size() > mountmount_List.GetMaxSize() ? mountmount_List.GetMaxSize() : msg.mountmount_list_size());
	for(int32_t i = 0; i < (int32_t)mountmount_List.GetSize(); ++i) {
		const ::proto_ff::mountmount & temp_mountmount_list = msg.mountmount_list(i);
		mountmount_List[i].read_from_pbmsg(temp_mountmount_list);
	}
}

mountstarUpupAttributeDesc_s::mountstarUpupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mountstarUpupAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int mountstarUpupAttributeDesc_s::ResumeInit() {
	return 0;
}

void mountstarUpupAttributeDesc_s::write_to_pbmsg(::proto_ff::mountstarUpupAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void mountstarUpupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::mountstarUpupAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mountstarUpupAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

mountstarUp_s::mountstarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mountstarUp_s::CreateInit() {
	ID = (int32_t)0;
	upAttributeId = (int64_t)0;
	starID = (int32_t)0;
	return 0;
}

int mountstarUp_s::ResumeInit() {
	return 0;
}

void mountstarUp_s::write_to_pbmsg(::proto_ff::mountstarUp & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_upattributeid((int64_t)upAttributeId);
	msg.set_starid((int32_t)starID);
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize() && i < upAttribute.GetMaxSize(); ++i) {
		::proto_ff::mountstarUpupAttributeDesc* temp_upattribute = msg.add_upattribute();
		upAttribute[i].write_to_pbmsg(*temp_upattribute);
	}
}

void mountstarUp_s::read_from_pbmsg(const ::proto_ff::mountstarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mountstarUp_s));
	ID = msg.id();
	upAttributeId = msg.upattributeid();
	starID = msg.starid();
	upAttribute.SetSize(msg.upattribute_size() > upAttribute.GetMaxSize() ? upAttribute.GetMaxSize() : msg.upattribute_size());
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize(); ++i) {
		const ::proto_ff::mountstarUpupAttributeDesc & temp_upattribute = msg.upattribute(i);
		upAttribute[i].read_from_pbmsg(temp_upattribute);
	}
}

Sheet_mountstarUp_s::Sheet_mountstarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_mountstarUp_s::CreateInit() {
	return 0;
}

int Sheet_mountstarUp_s::ResumeInit() {
	return 0;
}

void Sheet_mountstarUp_s::write_to_pbmsg(::proto_ff::Sheet_mountstarUp & msg) const {
	for(int32_t i = 0; i < (int32_t)mountstarUp_List.GetSize() && i < mountstarUp_List.GetMaxSize(); ++i) {
		::proto_ff::mountstarUp* temp_mountstarup_list = msg.add_mountstarup_list();
		mountstarUp_List[i].write_to_pbmsg(*temp_mountstarup_list);
	}
}

void Sheet_mountstarUp_s::read_from_pbmsg(const ::proto_ff::Sheet_mountstarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_mountstarUp_s));
	mountstarUp_List.SetSize(msg.mountstarup_list_size() > mountstarUp_List.GetMaxSize() ? mountstarUp_List.GetMaxSize() : msg.mountstarup_list_size());
	for(int32_t i = 0; i < (int32_t)mountstarUp_List.GetSize(); ++i) {
		const ::proto_ff::mountstarUp & temp_mountstarup_list = msg.mountstarup_list(i);
		mountstarUp_List[i].read_from_pbmsg(temp_mountstarup_list);
	}
}

}