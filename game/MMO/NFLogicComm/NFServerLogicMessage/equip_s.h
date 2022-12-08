#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "equip.pb.h"
#include "equip_s.h"

namespace proto_ff_s {

	struct equipequipattributeDesc_s : public NFDescStoreSeqOP {
		equipequipattributeDesc_s();
		virtual ~equipequipattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t valueMin;
		int32_t type;
		int32_t valueMax;

		virtual void write_to_pbmsg(::proto_ff::equipequipattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipequipattributeDesc & msg);
		static ::proto_ff::equipequipattributeDesc* new_pbmsg(){ return new ::proto_ff::equipequipattributeDesc(); }
		static ::proto_ff::equipequipattributeDesc make_pbmsg(){ return ::proto_ff::equipequipattributeDesc(); }
	};
	typedef struct equipequipattributeDesc_s equipequipattributeDesc_t;

	struct equipequipgodAttributeDesc_s : public NFDescStoreSeqOP {
		equipequipgodAttributeDesc_s();
		virtual ~equipequipgodAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t valueMin;
		int32_t type;
		int32_t valueMax;

		virtual void write_to_pbmsg(::proto_ff::equipequipgodAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipequipgodAttributeDesc & msg);
		static ::proto_ff::equipequipgodAttributeDesc* new_pbmsg(){ return new ::proto_ff::equipequipgodAttributeDesc(); }
		static ::proto_ff::equipequipgodAttributeDesc make_pbmsg(){ return ::proto_ff::equipequipgodAttributeDesc(); }
	};
	typedef struct equipequipgodAttributeDesc_s equipequipgodAttributeDesc_t;

	struct equipequip_s : public NFDescStoreSeqOP {
		equipequip_s();
		virtual ~equipequip_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFShmString<60> name;
		int32_t wearQuality;
		int32_t position;
		NFShmString<60> profession;
		int32_t professionLv;
		int32_t level;
		int32_t quality;
		int32_t star;
		int32_t refineAttributeDown;
		int32_t refineAttributeUp;
		NFShmString<60> refineAttribute_typeLibrary;
		NFShmString<60> refineAttribute_valueMin;
		NFShmString<60> refineAttribute_valueMax;
		int32_t blueStarNum;
		NFShmString<60> blueStar_type;
		NFShmString<60> blueStar_lv;
		NFShmString<60> blueStar_number;
		int32_t isCanbind;
		int32_t isTradeBind;
		int32_t sellPrice;
		NFShmString<60> icon;
		int32_t time;
		int32_t broadcast;
		NFShmString<60> meltingResult;
		int32_t specialAttributeDown;
		int32_t specialAttributeUp;
		NFShmString<60> specialAttribute_typeLibrary;
		NFShmString<60> specialAttribute_valueMin;
		NFShmString<60> specialAttribute_valueMax;
		NFShmString<60> skillId;
		NFArray<struct equipequipattributeDesc_s, 3> attribute;
		NFArray<struct equipequipgodAttributeDesc_s, 2> godAttribute;

		virtual void write_to_pbmsg(::proto_ff::equipequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipequip & msg);
		static ::proto_ff::equipequip* new_pbmsg(){ return new ::proto_ff::equipequip(); }
		static ::proto_ff::equipequip make_pbmsg(){ return ::proto_ff::equipequip(); }
	};
	typedef struct equipequip_s equipequip_t;

	struct Sheet_equipequip_s : public NFDescStoreSeqOP {
		Sheet_equipequip_s();
		virtual ~Sheet_equipequip_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipequip_s, 20> equipequip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipequip & msg);
		static ::proto_ff::Sheet_equipequip* new_pbmsg(){ return new ::proto_ff::Sheet_equipequip(); }
		static ::proto_ff::Sheet_equipequip make_pbmsg(){ return ::proto_ff::Sheet_equipequip(); }
	};
	typedef struct Sheet_equipequip_s Sheet_equipequip_t;

	struct equipstrongtypeDesc_s : public NFDescStoreSeqOP {
		equipstrongtypeDesc_s();
		virtual ~equipstrongtypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<60> num;
		int32_t id;

		virtual void write_to_pbmsg(::proto_ff::equipstrongtypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstrongtypeDesc & msg);
		static ::proto_ff::equipstrongtypeDesc* new_pbmsg(){ return new ::proto_ff::equipstrongtypeDesc(); }
		static ::proto_ff::equipstrongtypeDesc make_pbmsg(){ return ::proto_ff::equipstrongtypeDesc(); }
	};
	typedef struct equipstrongtypeDesc_s equipstrongtypeDesc_t;

	struct equipstrong_s : public NFDescStoreSeqOP {
		equipstrong_s();
		virtual ~equipstrong_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t position;
		int32_t wearQuality;
		int32_t srtongUp;
		NFArray<struct equipstrongtypeDesc_s, 2> type;

		virtual void write_to_pbmsg(::proto_ff::equipstrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstrong & msg);
		static ::proto_ff::equipstrong* new_pbmsg(){ return new ::proto_ff::equipstrong(); }
		static ::proto_ff::equipstrong make_pbmsg(){ return ::proto_ff::equipstrong(); }
	};
	typedef struct equipstrong_s equipstrong_t;

	struct Sheet_equipstrong_s : public NFDescStoreSeqOP {
		Sheet_equipstrong_s();
		virtual ~Sheet_equipstrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipstrong_s, 400> equipstrong_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipstrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipstrong & msg);
		static ::proto_ff::Sheet_equipstrong* new_pbmsg(){ return new ::proto_ff::Sheet_equipstrong(); }
		static ::proto_ff::Sheet_equipstrong make_pbmsg(){ return ::proto_ff::Sheet_equipstrong(); }
	};
	typedef struct Sheet_equipstrong_s Sheet_equipstrong_t;

	struct equipstrongexp_s : public NFDescStoreSeqOP {
		equipstrongexp_s();
		virtual ~equipstrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Lv;
		int32_t gold;
		NFArray<int32_t, 2> costItem;
		NFArray<NFShmString<60>, 2> positionType;
		NFArray<int32_t, 2> costNum;

		virtual void write_to_pbmsg(::proto_ff::equipstrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstrongexp & msg);
		static ::proto_ff::equipstrongexp* new_pbmsg(){ return new ::proto_ff::equipstrongexp(); }
		static ::proto_ff::equipstrongexp make_pbmsg(){ return ::proto_ff::equipstrongexp(); }
	};
	typedef struct equipstrongexp_s equipstrongexp_t;

	struct Sheet_equipstrongexp_s : public NFDescStoreSeqOP {
		Sheet_equipstrongexp_s();
		virtual ~Sheet_equipstrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipstrongexp_s, 800> equipstrongexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipstrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipstrongexp & msg);
		static ::proto_ff::Sheet_equipstrongexp* new_pbmsg(){ return new ::proto_ff::Sheet_equipstrongexp(); }
		static ::proto_ff::Sheet_equipstrongexp make_pbmsg(){ return ::proto_ff::Sheet_equipstrongexp(); }
	};
	typedef struct Sheet_equipstrongexp_s Sheet_equipstrongexp_t;

	struct equipstrongtotalattributeDesc_s : public NFDescStoreSeqOP {
		equipstrongtotalattributeDesc_s();
		virtual ~equipstrongtotalattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::equipstrongtotalattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstrongtotalattributeDesc & msg);
		static ::proto_ff::equipstrongtotalattributeDesc* new_pbmsg(){ return new ::proto_ff::equipstrongtotalattributeDesc(); }
		static ::proto_ff::equipstrongtotalattributeDesc make_pbmsg(){ return ::proto_ff::equipstrongtotalattributeDesc(); }
	};
	typedef struct equipstrongtotalattributeDesc_s equipstrongtotalattributeDesc_t;

	struct equipstrongtotal_s : public NFDescStoreSeqOP {
		equipstrongtotal_s();
		virtual ~equipstrongtotal_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t idType;
		int32_t idNum;
		NFArray<struct equipstrongtotalattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::equipstrongtotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstrongtotal & msg);
		static ::proto_ff::equipstrongtotal* new_pbmsg(){ return new ::proto_ff::equipstrongtotal(); }
		static ::proto_ff::equipstrongtotal make_pbmsg(){ return ::proto_ff::equipstrongtotal(); }
	};
	typedef struct equipstrongtotal_s equipstrongtotal_t;

	struct Sheet_equipstrongtotal_s : public NFDescStoreSeqOP {
		Sheet_equipstrongtotal_s();
		virtual ~Sheet_equipstrongtotal_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipstrongtotal_s, 300> equipstrongtotal_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipstrongtotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipstrongtotal & msg);
		static ::proto_ff::Sheet_equipstrongtotal* new_pbmsg(){ return new ::proto_ff::Sheet_equipstrongtotal(); }
		static ::proto_ff::Sheet_equipstrongtotal make_pbmsg(){ return ::proto_ff::Sheet_equipstrongtotal(); }
	};
	typedef struct Sheet_equipstrongtotal_s Sheet_equipstrongtotal_t;

	struct equipgem_s : public NFDescStoreSeqOP {
		equipgem_s();
		virtual ~equipgem_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t position;
		NFShmString<60> gemType;
		int32_t speciallyGemType;
		int32_t payUnlockItem;
		int32_t payUnlockNnm;
		NFArray<int32_t, 5> gemUnlock;

		virtual void write_to_pbmsg(::proto_ff::equipgem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipgem & msg);
		static ::proto_ff::equipgem* new_pbmsg(){ return new ::proto_ff::equipgem(); }
		static ::proto_ff::equipgem make_pbmsg(){ return ::proto_ff::equipgem(); }
	};
	typedef struct equipgem_s equipgem_t;

	struct Sheet_equipgem_s : public NFDescStoreSeqOP {
		Sheet_equipgem_s();
		virtual ~Sheet_equipgem_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipgem_s, 20> equipgem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipgem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipgem & msg);
		static ::proto_ff::Sheet_equipgem* new_pbmsg(){ return new ::proto_ff::Sheet_equipgem(); }
		static ::proto_ff::Sheet_equipgem make_pbmsg(){ return ::proto_ff::Sheet_equipgem(); }
	};
	typedef struct Sheet_equipgem_s Sheet_equipgem_t;

	struct equipstoveattattributeDesc_s : public NFDescStoreSeqOP {
		equipstoveattattributeDesc_s();
		virtual ~equipstoveattattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::equipstoveattattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstoveattattributeDesc & msg);
		static ::proto_ff::equipstoveattattributeDesc* new_pbmsg(){ return new ::proto_ff::equipstoveattattributeDesc(); }
		static ::proto_ff::equipstoveattattributeDesc make_pbmsg(){ return ::proto_ff::equipstoveattattributeDesc(); }
	};
	typedef struct equipstoveattattributeDesc_s equipstoveattattributeDesc_t;

	struct equipstoveatt_s : public NFDescStoreSeqOP {
		equipstoveatt_s();
		virtual ~equipstoveatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int64_t exp;
		NFArray<struct equipstoveattattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::equipstoveatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstoveatt & msg);
		static ::proto_ff::equipstoveatt* new_pbmsg(){ return new ::proto_ff::equipstoveatt(); }
		static ::proto_ff::equipstoveatt make_pbmsg(){ return ::proto_ff::equipstoveatt(); }
	};
	typedef struct equipstoveatt_s equipstoveatt_t;

	struct Sheet_equipstoveatt_s : public NFDescStoreSeqOP {
		Sheet_equipstoveatt_s();
		virtual ~Sheet_equipstoveatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipstoveatt_s, 2000> equipstoveatt_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipstoveatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipstoveatt & msg);
		static ::proto_ff::Sheet_equipstoveatt* new_pbmsg(){ return new ::proto_ff::Sheet_equipstoveatt(); }
		static ::proto_ff::Sheet_equipstoveatt make_pbmsg(){ return ::proto_ff::Sheet_equipstoveatt(); }
	};
	typedef struct Sheet_equipstoveatt_s Sheet_equipstoveatt_t;

	struct equipstoveexp_s : public NFDescStoreSeqOP {
		equipstoveexp_s();
		virtual ~equipstoveexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t exp;
		int32_t wearQuality;
		int32_t quality;

		virtual void write_to_pbmsg(::proto_ff::equipstoveexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstoveexp & msg);
		static ::proto_ff::equipstoveexp* new_pbmsg(){ return new ::proto_ff::equipstoveexp(); }
		static ::proto_ff::equipstoveexp make_pbmsg(){ return ::proto_ff::equipstoveexp(); }
	};
	typedef struct equipstoveexp_s equipstoveexp_t;

	struct Sheet_equipstoveexp_s : public NFDescStoreSeqOP {
		Sheet_equipstoveexp_s();
		virtual ~Sheet_equipstoveexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipstoveexp_s, 200> equipstoveexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipstoveexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipstoveexp & msg);
		static ::proto_ff::Sheet_equipstoveexp* new_pbmsg(){ return new ::proto_ff::Sheet_equipstoveexp(); }
		static ::proto_ff::Sheet_equipstoveexp make_pbmsg(){ return ::proto_ff::Sheet_equipstoveexp(); }
	};
	typedef struct Sheet_equipstoveexp_s Sheet_equipstoveexp_t;

	struct equipgrade_s : public NFDescStoreSeqOP {
		equipgrade_s();
		virtual ~equipgrade_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ID;

		virtual void write_to_pbmsg(::proto_ff::equipgrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipgrade & msg);
		static ::proto_ff::equipgrade* new_pbmsg(){ return new ::proto_ff::equipgrade(); }
		static ::proto_ff::equipgrade make_pbmsg(){ return ::proto_ff::equipgrade(); }
	};
	typedef struct equipgrade_s equipgrade_t;

	struct Sheet_equipgrade_s : public NFDescStoreSeqOP {
		Sheet_equipgrade_s();
		virtual ~Sheet_equipgrade_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipgrade_s, 40> equipgrade_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipgrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipgrade & msg);
		static ::proto_ff::Sheet_equipgrade* new_pbmsg(){ return new ::proto_ff::Sheet_equipgrade(); }
		static ::proto_ff::Sheet_equipgrade make_pbmsg(){ return ::proto_ff::Sheet_equipgrade(); }
	};
	typedef struct Sheet_equipgrade_s Sheet_equipgrade_t;

}

