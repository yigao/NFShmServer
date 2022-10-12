#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "role.pb.h"
#include "role_s.h"

namespace proto_ff_s {

	struct rolebornitemDesc_s : public NFDescStoreSeqOP {
		rolebornitemDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int64_t name;

		virtual void write_to_pbmsg(::proto_ff::rolebornitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolebornitemDesc & msg);
		static ::proto_ff::rolebornitemDesc* new_pbmsg(){ return new ::proto_ff::rolebornitemDesc(); }
		static ::proto_ff::rolebornitemDesc make_pbmsg(){ return ::proto_ff::rolebornitemDesc(); }
	};
	typedef struct rolebornitemDesc_s rolebornitemDesc_t;

	struct rolebornmailDesc_s : public NFDescStoreSeqOP {
		rolebornmailDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int64_t name;

		virtual void write_to_pbmsg(::proto_ff::rolebornmailDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolebornmailDesc & msg);
		static ::proto_ff::rolebornmailDesc* new_pbmsg(){ return new ::proto_ff::rolebornmailDesc(); }
		static ::proto_ff::rolebornmailDesc make_pbmsg(){ return ::proto_ff::rolebornmailDesc(); }
	};
	typedef struct rolebornmailDesc_s rolebornmailDesc_t;

	struct roleborn_s : public NFDescStoreSeqOP {
		roleborn_s();
		int CreateInit();
		int ResumeInit();
		int64_t bornID;
		int32_t professionID;
		NFSizeString<60> professionName;
		NFSizeString<300> placement;
		int32_t gender;
		int32_t bornLevel;
		int32_t bornTitle;
		int64_t diamond;
		int64_t bindDiamond;
		int64_t gold;
		int64_t mapID;
		int32_t birthFace;
		NFSizeString<60> icons;
		NFSizeString<60> loginAvata;
		NFSizeString<60> newweapon;
		NFSizeString<60> newclothing;
		NFSizeString<60> weaponAvata;
		NFSizeString<60> roleAvata;
		int64_t carryWeapons;
		int64_t carryArmor;
		int64_t carryCloak;
		int64_t carryShoes;
		int64_t carryNecklace;
		int64_t carryAmulet;
		int64_t carryBracer;
		int64_t carryRing;
		int64_t carryFashionWeapons;
		int64_t carryFashionArmor;
		int64_t carryWings;
		int32_t mSpeed;
		int32_t view;
		int32_t radius;
		int64_t sheny;
		int64_t shenw;
		NFArray<int32_t, 4> actBuff;
		NFArray<struct rolebornitemDesc_s, 35> item;
		NFArray<int64_t, 6> actSkill;
		NFArray<struct rolebornmailDesc_s, 1> mail;

		virtual void write_to_pbmsg(::proto_ff::roleborn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleborn & msg);
		static ::proto_ff::roleborn* new_pbmsg(){ return new ::proto_ff::roleborn(); }
		static ::proto_ff::roleborn make_pbmsg(){ return ::proto_ff::roleborn(); }
	};
	typedef struct roleborn_s roleborn_t;

	struct Sheet_roleborn_s : public NFDescStoreSeqOP {
		Sheet_roleborn_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleborn_s, 20> roleborn_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleborn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleborn & msg);
		static ::proto_ff::Sheet_roleborn* new_pbmsg(){ return new ::proto_ff::Sheet_roleborn(); }
		static ::proto_ff::Sheet_roleborn make_pbmsg(){ return ::proto_ff::Sheet_roleborn(); }
	};
	typedef struct Sheet_roleborn_s Sheet_roleborn_t;

	struct rolewarriorattributeDesc_s : public NFDescStoreSeqOP {
		rolewarriorattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::rolewarriorattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolewarriorattributeDesc & msg);
		static ::proto_ff::rolewarriorattributeDesc* new_pbmsg(){ return new ::proto_ff::rolewarriorattributeDesc(); }
		static ::proto_ff::rolewarriorattributeDesc make_pbmsg(){ return ::proto_ff::rolewarriorattributeDesc(); }
	};
	typedef struct rolewarriorattributeDesc_s rolewarriorattributeDesc_t;

	struct rolewarrior_s : public NFDescStoreSeqOP {
		rolewarrior_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct rolewarriorattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::rolewarrior & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolewarrior & msg);
		static ::proto_ff::rolewarrior* new_pbmsg(){ return new ::proto_ff::rolewarrior(); }
		static ::proto_ff::rolewarrior make_pbmsg(){ return ::proto_ff::rolewarrior(); }
	};
	typedef struct rolewarrior_s rolewarrior_t;

	struct Sheet_rolewarrior_s : public NFDescStoreSeqOP {
		Sheet_rolewarrior_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rolewarrior_s, 2000> rolewarrior_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rolewarrior & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rolewarrior & msg);
		static ::proto_ff::Sheet_rolewarrior* new_pbmsg(){ return new ::proto_ff::Sheet_rolewarrior(); }
		static ::proto_ff::Sheet_rolewarrior make_pbmsg(){ return ::proto_ff::Sheet_rolewarrior(); }
	};
	typedef struct Sheet_rolewarrior_s Sheet_rolewarrior_t;

	struct rolemasterattributeDesc_s : public NFDescStoreSeqOP {
		rolemasterattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::rolemasterattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolemasterattributeDesc & msg);
		static ::proto_ff::rolemasterattributeDesc* new_pbmsg(){ return new ::proto_ff::rolemasterattributeDesc(); }
		static ::proto_ff::rolemasterattributeDesc make_pbmsg(){ return ::proto_ff::rolemasterattributeDesc(); }
	};
	typedef struct rolemasterattributeDesc_s rolemasterattributeDesc_t;

	struct rolemaster_s : public NFDescStoreSeqOP {
		rolemaster_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct rolemasterattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::rolemaster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolemaster & msg);
		static ::proto_ff::rolemaster* new_pbmsg(){ return new ::proto_ff::rolemaster(); }
		static ::proto_ff::rolemaster make_pbmsg(){ return ::proto_ff::rolemaster(); }
	};
	typedef struct rolemaster_s rolemaster_t;

	struct Sheet_rolemaster_s : public NFDescStoreSeqOP {
		Sheet_rolemaster_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rolemaster_s, 2000> rolemaster_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rolemaster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rolemaster & msg);
		static ::proto_ff::Sheet_rolemaster* new_pbmsg(){ return new ::proto_ff::Sheet_rolemaster(); }
		static ::proto_ff::Sheet_rolemaster make_pbmsg(){ return ::proto_ff::Sheet_rolemaster(); }
	};
	typedef struct Sheet_rolemaster_s Sheet_rolemaster_t;

	struct roleassassinattributeDesc_s : public NFDescStoreSeqOP {
		roleassassinattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::roleassassinattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleassassinattributeDesc & msg);
		static ::proto_ff::roleassassinattributeDesc* new_pbmsg(){ return new ::proto_ff::roleassassinattributeDesc(); }
		static ::proto_ff::roleassassinattributeDesc make_pbmsg(){ return ::proto_ff::roleassassinattributeDesc(); }
	};
	typedef struct roleassassinattributeDesc_s roleassassinattributeDesc_t;

	struct roleassassin_s : public NFDescStoreSeqOP {
		roleassassin_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct roleassassinattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::roleassassin & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleassassin & msg);
		static ::proto_ff::roleassassin* new_pbmsg(){ return new ::proto_ff::roleassassin(); }
		static ::proto_ff::roleassassin make_pbmsg(){ return ::proto_ff::roleassassin(); }
	};
	typedef struct roleassassin_s roleassassin_t;

	struct Sheet_roleassassin_s : public NFDescStoreSeqOP {
		Sheet_roleassassin_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleassassin_s, 2000> roleassassin_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleassassin & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleassassin & msg);
		static ::proto_ff::Sheet_roleassassin* new_pbmsg(){ return new ::proto_ff::Sheet_roleassassin(); }
		static ::proto_ff::Sheet_roleassassin make_pbmsg(){ return ::proto_ff::Sheet_roleassassin(); }
	};
	typedef struct Sheet_roleassassin_s Sheet_roleassassin_t;

	struct roleshooterattributeDesc_s : public NFDescStoreSeqOP {
		roleshooterattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::roleshooterattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleshooterattributeDesc & msg);
		static ::proto_ff::roleshooterattributeDesc* new_pbmsg(){ return new ::proto_ff::roleshooterattributeDesc(); }
		static ::proto_ff::roleshooterattributeDesc make_pbmsg(){ return ::proto_ff::roleshooterattributeDesc(); }
	};
	typedef struct roleshooterattributeDesc_s roleshooterattributeDesc_t;

	struct roleshooter_s : public NFDescStoreSeqOP {
		roleshooter_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct roleshooterattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::roleshooter & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleshooter & msg);
		static ::proto_ff::roleshooter* new_pbmsg(){ return new ::proto_ff::roleshooter(); }
		static ::proto_ff::roleshooter make_pbmsg(){ return ::proto_ff::roleshooter(); }
	};
	typedef struct roleshooter_s roleshooter_t;

	struct Sheet_roleshooter_s : public NFDescStoreSeqOP {
		Sheet_roleshooter_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleshooter_s, 2000> roleshooter_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleshooter & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleshooter & msg);
		static ::proto_ff::Sheet_roleshooter* new_pbmsg(){ return new ::proto_ff::Sheet_roleshooter(); }
		static ::proto_ff::Sheet_roleshooter make_pbmsg(){ return ::proto_ff::Sheet_roleshooter(); }
	};
	typedef struct Sheet_roleshooter_s Sheet_roleshooter_t;

	struct roleexp_s : public NFDescStoreSeqOP {
		roleexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int64_t exp;
		int32_t skillPoint;

		virtual void write_to_pbmsg(::proto_ff::roleexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleexp & msg);
		static ::proto_ff::roleexp* new_pbmsg(){ return new ::proto_ff::roleexp(); }
		static ::proto_ff::roleexp make_pbmsg(){ return ::proto_ff::roleexp(); }
	};
	typedef struct roleexp_s roleexp_t;

	struct Sheet_roleexp_s : public NFDescStoreSeqOP {
		Sheet_roleexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleexp_s, 2000> roleexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleexp & msg);
		static ::proto_ff::Sheet_roleexp* new_pbmsg(){ return new ::proto_ff::Sheet_roleexp(); }
		static ::proto_ff::Sheet_roleexp make_pbmsg(){ return ::proto_ff::Sheet_roleexp(); }
	};
	typedef struct Sheet_roleexp_s Sheet_roleexp_t;

	struct roleskillType_s : public NFDescStoreSeqOP {
		roleskillType_s();
		int CreateInit();
		int ResumeInit();
		int64_t skillId;
		int32_t skillType;

		virtual void write_to_pbmsg(::proto_ff::roleskillType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleskillType & msg);
		static ::proto_ff::roleskillType* new_pbmsg(){ return new ::proto_ff::roleskillType(); }
		static ::proto_ff::roleskillType make_pbmsg(){ return ::proto_ff::roleskillType(); }
	};
	typedef struct roleskillType_s roleskillType_t;

	struct Sheet_roleskillType_s : public NFDescStoreSeqOP {
		Sheet_roleskillType_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleskillType_s, 200> roleskillType_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleskillType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleskillType & msg);
		static ::proto_ff::Sheet_roleskillType* new_pbmsg(){ return new ::proto_ff::Sheet_roleskillType(); }
		static ::proto_ff::Sheet_roleskillType make_pbmsg(){ return ::proto_ff::Sheet_roleskillType(); }
	};
	typedef struct Sheet_roleskillType_s Sheet_roleskillType_t;

	struct roleaddSkill_s : public NFDescStoreSeqOP {
		roleaddSkill_s();
		int CreateInit();
		int ResumeInit();
		int32_t Id;
		int64_t skillId;

		virtual void write_to_pbmsg(::proto_ff::roleaddSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleaddSkill & msg);
		static ::proto_ff::roleaddSkill* new_pbmsg(){ return new ::proto_ff::roleaddSkill(); }
		static ::proto_ff::roleaddSkill make_pbmsg(){ return ::proto_ff::roleaddSkill(); }
	};
	typedef struct roleaddSkill_s roleaddSkill_t;

	struct Sheet_roleaddSkill_s : public NFDescStoreSeqOP {
		Sheet_roleaddSkill_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleaddSkill_s, 20> roleaddSkill_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleaddSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleaddSkill & msg);
		static ::proto_ff::Sheet_roleaddSkill* new_pbmsg(){ return new ::proto_ff::Sheet_roleaddSkill(); }
		static ::proto_ff::Sheet_roleaddSkill make_pbmsg(){ return ::proto_ff::Sheet_roleaddSkill(); }
	};
	typedef struct Sheet_roleaddSkill_s Sheet_roleaddSkill_t;

	struct roleworldexp_s : public NFDescStoreSeqOP {
		roleworldexp_s();
		int CreateInit();
		int ResumeInit();
		int64_t lv;
		int32_t worldExp;

		virtual void write_to_pbmsg(::proto_ff::roleworldexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleworldexp & msg);
		static ::proto_ff::roleworldexp* new_pbmsg(){ return new ::proto_ff::roleworldexp(); }
		static ::proto_ff::roleworldexp make_pbmsg(){ return ::proto_ff::roleworldexp(); }
	};
	typedef struct roleworldexp_s roleworldexp_t;

	struct Sheet_roleworldexp_s : public NFDescStoreSeqOP {
		Sheet_roleworldexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleworldexp_s, 600> roleworldexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleworldexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleworldexp & msg);
		static ::proto_ff::Sheet_roleworldexp* new_pbmsg(){ return new ::proto_ff::Sheet_roleworldexp(); }
		static ::proto_ff::Sheet_roleworldexp make_pbmsg(){ return ::proto_ff::Sheet_roleworldexp(); }
	};
	typedef struct Sheet_roleworldexp_s Sheet_roleworldexp_t;

}

