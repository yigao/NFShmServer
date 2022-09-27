#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "equip.pb.h"
#include "equip_s.h"

namespace proto_ff_s {

	struct equipequipattributeDesc_s : public NFDescStoreSeqOP {
		equipequipattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t valueMin;
		int32_t valueMax;

		virtual void write_to_pbmsg(::proto_ff::equipequipattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipequipattributeDesc & msg);
		static ::proto_ff::equipequipattributeDesc* new_pbmsg(){ return new ::proto_ff::equipequipattributeDesc(); }
		static ::proto_ff::equipequipattributeDesc make_pbmsg(){ return ::proto_ff::equipequipattributeDesc(); }
	};
	typedef struct equipequipattributeDesc_s equipequipattributeDesc_t;

	struct equipequip_s : public NFDescStoreSeqOP {
		equipequip_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> name;
		int32_t wearQuality;
		int32_t position;
		NFSizeString<60> profession;
		int32_t professionLv;
		int32_t level;
		int32_t quality;
		int32_t star;
		int32_t refineAttributeDown;
		int32_t refineAttributeUp;
		NFSizeString<60> refineAttribute_typeLibrary;
		NFSizeString<60> refineAttribute_valueMin;
		NFSizeString<60> refineAttribute_valueMax;
		int32_t blueStarNum;
		NFSizeString<60> blueStar_type;
		NFSizeString<60> blueStar_lv;
		NFSizeString<60> blueStar_number;
		int32_t isCanbind;
		int32_t isTradeBind;
		int32_t sellPrice;
		NFSizeString<60> icon;
		int32_t time;
		int32_t Combat;
		int32_t broadcast;
		NFSizeString<60> meltingResult;
		NFArray<int32_t, 2> attribute_type;
		NFArray<struct equipequipattributeDesc_s, 2> attribute;

		virtual void write_to_pbmsg(::proto_ff::equipequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipequip & msg);
		static ::proto_ff::equipequip* new_pbmsg(){ return new ::proto_ff::equipequip(); }
		static ::proto_ff::equipequip make_pbmsg(){ return ::proto_ff::equipequip(); }
	};
	typedef struct equipequip_s equipequip_t;

	struct Sheet_equipequip_s : public NFDescStoreSeqOP {
		Sheet_equipequip_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipequip_s, 4000> equipequip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipequip & msg);
		static ::proto_ff::Sheet_equipequip* new_pbmsg(){ return new ::proto_ff::Sheet_equipequip(); }
		static ::proto_ff::Sheet_equipequip make_pbmsg(){ return ::proto_ff::Sheet_equipequip(); }
	};
	typedef struct Sheet_equipequip_s Sheet_equipequip_t;

	struct equipstrongtypeDesc_s : public NFDescStoreSeqOP {
		equipstrongtypeDesc_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<60> num;
		int32_t id;

		virtual void write_to_pbmsg(::proto_ff::equipstrongtypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstrongtypeDesc & msg);
		static ::proto_ff::equipstrongtypeDesc* new_pbmsg(){ return new ::proto_ff::equipstrongtypeDesc(); }
		static ::proto_ff::equipstrongtypeDesc make_pbmsg(){ return ::proto_ff::equipstrongtypeDesc(); }
	};
	typedef struct equipstrongtypeDesc_s equipstrongtypeDesc_t;

	struct equipstrong_s : public NFDescStoreSeqOP {
		equipstrong_s();
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
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipstrong_s, 200> equipstrong_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipstrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipstrong & msg);
		static ::proto_ff::Sheet_equipstrong* new_pbmsg(){ return new ::proto_ff::Sheet_equipstrong(); }
		static ::proto_ff::Sheet_equipstrong make_pbmsg(){ return ::proto_ff::Sheet_equipstrong(); }
	};
	typedef struct Sheet_equipstrong_s Sheet_equipstrong_t;

	struct equipgemfinedateDesc_s : public NFDescStoreSeqOP {
		equipgemfinedateDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t Id;

		virtual void write_to_pbmsg(::proto_ff::equipgemfinedateDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipgemfinedateDesc & msg);
		static ::proto_ff::equipgemfinedateDesc* new_pbmsg(){ return new ::proto_ff::equipgemfinedateDesc(); }
		static ::proto_ff::equipgemfinedateDesc make_pbmsg(){ return ::proto_ff::equipgemfinedateDesc(); }
	};
	typedef struct equipgemfinedateDesc_s equipgemfinedateDesc_t;

	struct equipgemfine_s : public NFDescStoreSeqOP {
		equipgemfine_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t position;
		int32_t wearQuality;
		int32_t gemUp;
		int32_t gemNumber;
		NFArray<struct equipgemfinedateDesc_s, 3> date;

		virtual void write_to_pbmsg(::proto_ff::equipgemfine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipgemfine & msg);
		static ::proto_ff::equipgemfine* new_pbmsg(){ return new ::proto_ff::equipgemfine(); }
		static ::proto_ff::equipgemfine make_pbmsg(){ return ::proto_ff::equipgemfine(); }
	};
	typedef struct equipgemfine_s equipgemfine_t;

	struct Sheet_equipgemfine_s : public NFDescStoreSeqOP {
		Sheet_equipgemfine_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipgemfine_s, 200> equipgemfine_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipgemfine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipgemfine & msg);
		static ::proto_ff::Sheet_equipgemfine* new_pbmsg(){ return new ::proto_ff::Sheet_equipgemfine(); }
		static ::proto_ff::Sheet_equipgemfine make_pbmsg(){ return ::proto_ff::Sheet_equipgemfine(); }
	};
	typedef struct Sheet_equipgemfine_s Sheet_equipgemfine_t;

	struct equipgem_s : public NFDescStoreSeqOP {
		equipgem_s();
		int CreateInit();
		int ResumeInit();
		int32_t position;
		int32_t gemType;
		int32_t VipUnlock;
		NFArray<int32_t, 5> gemUnlock;

		virtual void write_to_pbmsg(::proto_ff::equipgem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipgem & msg);
		static ::proto_ff::equipgem* new_pbmsg(){ return new ::proto_ff::equipgem(); }
		static ::proto_ff::equipgem make_pbmsg(){ return ::proto_ff::equipgem(); }
	};
	typedef struct equipgem_s equipgem_t;

	struct Sheet_equipgem_s : public NFDescStoreSeqOP {
		Sheet_equipgem_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipgem_s, 20> equipgem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipgem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipgem & msg);
		static ::proto_ff::Sheet_equipgem* new_pbmsg(){ return new ::proto_ff::Sheet_equipgem(); }
		static ::proto_ff::Sheet_equipgem make_pbmsg(){ return ::proto_ff::Sheet_equipgem(); }
	};
	typedef struct Sheet_equipgem_s Sheet_equipgem_t;

	struct equipatt_s : public NFDescStoreSeqOP {
		equipatt_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t idType;
		int32_t idNum;
		NFSizeString<60> att;

		virtual void write_to_pbmsg(::proto_ff::equipatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipatt & msg);
		static ::proto_ff::equipatt* new_pbmsg(){ return new ::proto_ff::equipatt(); }
		static ::proto_ff::equipatt make_pbmsg(){ return ::proto_ff::equipatt(); }
	};
	typedef struct equipatt_s equipatt_t;

	struct Sheet_equipatt_s : public NFDescStoreSeqOP {
		Sheet_equipatt_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipatt_s, 200> equipatt_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipatt & msg);
		static ::proto_ff::Sheet_equipatt* new_pbmsg(){ return new ::proto_ff::Sheet_equipatt(); }
		static ::proto_ff::Sheet_equipatt make_pbmsg(){ return ::proto_ff::Sheet_equipatt(); }
	};
	typedef struct Sheet_equipatt_s Sheet_equipatt_t;

	struct equipsuitattributeDesc_s : public NFDescStoreSeqOP {
		equipsuitattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t sctivation;

		virtual void write_to_pbmsg(::proto_ff::equipsuitattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipsuitattributeDesc & msg);
		static ::proto_ff::equipsuitattributeDesc* new_pbmsg(){ return new ::proto_ff::equipsuitattributeDesc(); }
		static ::proto_ff::equipsuitattributeDesc make_pbmsg(){ return ::proto_ff::equipsuitattributeDesc(); }
	};
	typedef struct equipsuitattributeDesc_s equipsuitattributeDesc_t;

	struct equipsuit_s : public NFDescStoreSeqOP {
		equipsuit_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> profession;
		int32_t suitLv;
		int32_t level;
		int32_t colour;
		NFSizeString<60> afterName;
		int32_t suiteValue;
		NFArray<struct equipsuitattributeDesc_s, 3> attribute;
		NFArray<NFSizeString<60>, 10> position;

		virtual void write_to_pbmsg(::proto_ff::equipsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipsuit & msg);
		static ::proto_ff::equipsuit* new_pbmsg(){ return new ::proto_ff::equipsuit(); }
		static ::proto_ff::equipsuit make_pbmsg(){ return ::proto_ff::equipsuit(); }
	};
	typedef struct equipsuit_s equipsuit_t;

	struct Sheet_equipsuit_s : public NFDescStoreSeqOP {
		Sheet_equipsuit_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipsuit_s, 120> equipsuit_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipsuit & msg);
		static ::proto_ff::Sheet_equipsuit* new_pbmsg(){ return new ::proto_ff::Sheet_equipsuit(); }
		static ::proto_ff::Sheet_equipsuit make_pbmsg(){ return ::proto_ff::Sheet_equipsuit(); }
	};
	typedef struct Sheet_equipsuit_s Sheet_equipsuit_t;

	struct equipclear_s : public NFDescStoreSeqOP {
		equipclear_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t position;
		int32_t Lv;
		NFSizeString<60> value;
		NFArray<int64_t, 15> teamId;

		virtual void write_to_pbmsg(::proto_ff::equipclear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipclear & msg);
		static ::proto_ff::equipclear* new_pbmsg(){ return new ::proto_ff::equipclear(); }
		static ::proto_ff::equipclear make_pbmsg(){ return ::proto_ff::equipclear(); }
	};
	typedef struct equipclear_s equipclear_t;

	struct Sheet_equipclear_s : public NFDescStoreSeqOP {
		Sheet_equipclear_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipclear_s, 20> equipclear_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipclear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipclear & msg);
		static ::proto_ff::Sheet_equipclear* new_pbmsg(){ return new ::proto_ff::Sheet_equipclear(); }
		static ::proto_ff::Sheet_equipclear make_pbmsg(){ return ::proto_ff::Sheet_equipclear(); }
	};
	typedef struct Sheet_equipclear_s Sheet_equipclear_t;

	struct equipstrongexp_s : public NFDescStoreSeqOP {
		equipstrongexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t Lv;
		int32_t gold;
		int32_t exp;
		int64_t expUp;

		virtual void write_to_pbmsg(::proto_ff::equipstrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipstrongexp & msg);
		static ::proto_ff::equipstrongexp* new_pbmsg(){ return new ::proto_ff::equipstrongexp(); }
		static ::proto_ff::equipstrongexp make_pbmsg(){ return ::proto_ff::equipstrongexp(); }
	};
	typedef struct equipstrongexp_s equipstrongexp_t;

	struct Sheet_equipstrongexp_s : public NFDescStoreSeqOP {
		Sheet_equipstrongexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipstrongexp_s, 800> equipstrongexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipstrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipstrongexp & msg);
		static ::proto_ff::Sheet_equipstrongexp* new_pbmsg(){ return new ::proto_ff::Sheet_equipstrongexp(); }
		static ::proto_ff::Sheet_equipstrongexp make_pbmsg(){ return ::proto_ff::Sheet_equipstrongexp(); }
	};
	typedef struct Sheet_equipstrongexp_s Sheet_equipstrongexp_t;

	struct equipgemfineexp_s : public NFDescStoreSeqOP {
		equipgemfineexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t Lv;
		int64_t expUp;

		virtual void write_to_pbmsg(::proto_ff::equipgemfineexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipgemfineexp & msg);
		static ::proto_ff::equipgemfineexp* new_pbmsg(){ return new ::proto_ff::equipgemfineexp(); }
		static ::proto_ff::equipgemfineexp make_pbmsg(){ return ::proto_ff::equipgemfineexp(); }
	};
	typedef struct equipgemfineexp_s equipgemfineexp_t;

	struct Sheet_equipgemfineexp_s : public NFDescStoreSeqOP {
		Sheet_equipgemfineexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipgemfineexp_s, 300> equipgemfineexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipgemfineexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipgemfineexp & msg);
		static ::proto_ff::Sheet_equipgemfineexp* new_pbmsg(){ return new ::proto_ff::Sheet_equipgemfineexp(); }
		static ::proto_ff::Sheet_equipgemfineexp make_pbmsg(){ return ::proto_ff::Sheet_equipgemfineexp(); }
	};
	typedef struct Sheet_equipgemfineexp_s Sheet_equipgemfineexp_t;

	struct equipclearteamSectionDesc_s : public NFDescStoreSeqOP {
		equipclearteamSectionDesc_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<60> down;
		int32_t p;
		NFSizeString<60> type;
		NFSizeString<60> up;
		NFSizeString<60> g;

		virtual void write_to_pbmsg(::proto_ff::equipclearteamSectionDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipclearteamSectionDesc & msg);
		static ::proto_ff::equipclearteamSectionDesc* new_pbmsg(){ return new ::proto_ff::equipclearteamSectionDesc(); }
		static ::proto_ff::equipclearteamSectionDesc make_pbmsg(){ return ::proto_ff::equipclearteamSectionDesc(); }
	};
	typedef struct equipclearteamSectionDesc_s equipclearteamSectionDesc_t;

	struct equipclearteam_s : public NFDescStoreSeqOP {
		equipclearteam_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t combat;
		int64_t shengId;
		int32_t shengNum;
		int64_t consumeId;
		NFSizeString<60> consumeNum;
		NFSizeString<60> lockingId;
		NFSizeString<60> lockingNum;
		NFArray<struct equipclearteamSectionDesc_s, 8> Section;

		virtual void write_to_pbmsg(::proto_ff::equipclearteam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipclearteam & msg);
		static ::proto_ff::equipclearteam* new_pbmsg(){ return new ::proto_ff::equipclearteam(); }
		static ::proto_ff::equipclearteam make_pbmsg(){ return ::proto_ff::equipclearteam(); }
	};
	typedef struct equipclearteam_s equipclearteam_t;

	struct Sheet_equipclearteam_s : public NFDescStoreSeqOP {
		Sheet_equipclearteam_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipclearteam_s, 200> equipclearteam_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipclearteam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipclearteam & msg);
		static ::proto_ff::Sheet_equipclearteam* new_pbmsg(){ return new ::proto_ff::Sheet_equipclearteam(); }
		static ::proto_ff::Sheet_equipclearteam make_pbmsg(){ return ::proto_ff::Sheet_equipclearteam(); }
	};
	typedef struct Sheet_equipclearteam_s Sheet_equipclearteam_t;

	struct equipawakeningawakenDesc_s : public NFDescStoreSeqOP {
		equipawakeningawakenDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Item;
		int32_t Num;

		virtual void write_to_pbmsg(::proto_ff::equipawakeningawakenDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipawakeningawakenDesc & msg);
		static ::proto_ff::equipawakeningawakenDesc* new_pbmsg(){ return new ::proto_ff::equipawakeningawakenDesc(); }
		static ::proto_ff::equipawakeningawakenDesc make_pbmsg(){ return ::proto_ff::equipawakeningawakenDesc(); }
	};
	typedef struct equipawakeningawakenDesc_s equipawakeningawakenDesc_t;

	struct equipawakening_s : public NFDescStoreSeqOP {
		equipawakening_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t position;
		int32_t awakenLv;
		int32_t needWearQuality;
		int32_t strong;
		int32_t attribute;
		NFArray<struct equipawakeningawakenDesc_s, 2> awaken;

		virtual void write_to_pbmsg(::proto_ff::equipawakening & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipawakening & msg);
		static ::proto_ff::equipawakening* new_pbmsg(){ return new ::proto_ff::equipawakening(); }
		static ::proto_ff::equipawakening make_pbmsg(){ return ::proto_ff::equipawakening(); }
	};
	typedef struct equipawakening_s equipawakening_t;

	struct Sheet_equipawakening_s : public NFDescStoreSeqOP {
		Sheet_equipawakening_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipawakening_s, 700> equipawakening_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipawakening & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipawakening & msg);
		static ::proto_ff::Sheet_equipawakening* new_pbmsg(){ return new ::proto_ff::Sheet_equipawakening(); }
		static ::proto_ff::Sheet_equipawakening make_pbmsg(){ return ::proto_ff::Sheet_equipawakening(); }
	};
	typedef struct Sheet_equipawakening_s Sheet_equipawakening_t;

	struct equipenchantingtypeDesc_s : public NFDescStoreSeqOP {
		equipenchantingtypeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int32_t id;

		virtual void write_to_pbmsg(::proto_ff::equipenchantingtypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipenchantingtypeDesc & msg);
		static ::proto_ff::equipenchantingtypeDesc* new_pbmsg(){ return new ::proto_ff::equipenchantingtypeDesc(); }
		static ::proto_ff::equipenchantingtypeDesc make_pbmsg(){ return ::proto_ff::equipenchantingtypeDesc(); }
	};
	typedef struct equipenchantingtypeDesc_s equipenchantingtypeDesc_t;

	struct equipenchantingenchantDesc_s : public NFDescStoreSeqOP {
		equipenchantingenchantDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Item;
		int32_t Num;

		virtual void write_to_pbmsg(::proto_ff::equipenchantingenchantDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipenchantingenchantDesc & msg);
		static ::proto_ff::equipenchantingenchantDesc* new_pbmsg(){ return new ::proto_ff::equipenchantingenchantDesc(); }
		static ::proto_ff::equipenchantingenchantDesc make_pbmsg(){ return ::proto_ff::equipenchantingenchantDesc(); }
	};
	typedef struct equipenchantingenchantDesc_s equipenchantingenchantDesc_t;

	struct equipenchanting_s : public NFDescStoreSeqOP {
		equipenchanting_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t position;
		int32_t enchantLv;
		int32_t needWearQuality;
		int32_t equip;
		NFArray<struct equipenchantingtypeDesc_s, 3> type;
		NFArray<struct equipenchantingenchantDesc_s, 2> enchant;

		virtual void write_to_pbmsg(::proto_ff::equipenchanting & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipenchanting & msg);
		static ::proto_ff::equipenchanting* new_pbmsg(){ return new ::proto_ff::equipenchanting(); }
		static ::proto_ff::equipenchanting make_pbmsg(){ return ::proto_ff::equipenchanting(); }
	};
	typedef struct equipenchanting_s equipenchanting_t;

	struct Sheet_equipenchanting_s : public NFDescStoreSeqOP {
		Sheet_equipenchanting_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipenchanting_s, 700> equipenchanting_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipenchanting & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipenchanting & msg);
		static ::proto_ff::Sheet_equipenchanting* new_pbmsg(){ return new ::proto_ff::Sheet_equipenchanting(); }
		static ::proto_ff::Sheet_equipenchanting make_pbmsg(){ return ::proto_ff::Sheet_equipenchanting(); }
	};
	typedef struct Sheet_equipenchanting_s Sheet_equipenchanting_t;

	struct equipmarryattributeDesc_s : public NFDescStoreSeqOP {
		equipmarryattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::equipmarryattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipmarryattributeDesc & msg);
		static ::proto_ff::equipmarryattributeDesc* new_pbmsg(){ return new ::proto_ff::equipmarryattributeDesc(); }
		static ::proto_ff::equipmarryattributeDesc make_pbmsg(){ return ::proto_ff::equipmarryattributeDesc(); }
	};
	typedef struct equipmarryattributeDesc_s equipmarryattributeDesc_t;

	struct equipmarry_s : public NFDescStoreSeqOP {
		equipmarry_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t lv;
		int32_t position;
		int32_t type;
		int64_t materialID;
		int32_t materialEXP;
		int32_t need;
		NFArray<struct equipmarryattributeDesc_s, 6> attribute;

		virtual void write_to_pbmsg(::proto_ff::equipmarry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipmarry & msg);
		static ::proto_ff::equipmarry* new_pbmsg(){ return new ::proto_ff::equipmarry(); }
		static ::proto_ff::equipmarry make_pbmsg(){ return ::proto_ff::equipmarry(); }
	};
	typedef struct equipmarry_s equipmarry_t;

	struct Sheet_equipmarry_s : public NFDescStoreSeqOP {
		Sheet_equipmarry_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipmarry_s, 1000> equipmarry_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipmarry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipmarry & msg);
		static ::proto_ff::Sheet_equipmarry* new_pbmsg(){ return new ::proto_ff::Sheet_equipmarry(); }
		static ::proto_ff::Sheet_equipmarry make_pbmsg(){ return ::proto_ff::Sheet_equipmarry(); }
	};
	typedef struct Sheet_equipmarry_s Sheet_equipmarry_t;

}

