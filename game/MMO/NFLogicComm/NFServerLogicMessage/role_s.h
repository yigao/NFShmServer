#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "role.pb.h"
#include "role_s.h"

namespace proto_ff_s {

	struct rolebornitemDesc_s : public NFDescStoreSeqOP {
		rolebornitemDesc_s();
		virtual ~rolebornitemDesc_s(){}
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
		virtual ~rolebornmailDesc_s(){}
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
		virtual ~roleborn_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t bornID;
		int32_t professionID;
		NFShmString<60> professionName;
		NFShmString<60> placement;
		int32_t gender;
		int32_t bornLevel;
		int32_t bornTitle;
		int64_t diamond;
		int64_t bindDiamond;
		int64_t gold;
		int64_t mapID;
		int32_t birthFace;
		NFShmString<60> icons;
		NFShmString<60> loginAvata;
		NFShmString<60> newweapon;
		NFShmString<60> newclothing;
		NFShmString<60> weaponAvata;
		NFShmString<60> roleAvata;
		int32_t hairColor;
		int32_t clothesColor;
		int32_t skinColor;
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
		int32_t group;
		int64_t sheny;
		int64_t shenw;
		NFArray<int32_t, 4> actBuff;
		NFArray<struct rolebornitemDesc_s, 35> item;
		NFArray<int64_t, 12> actSkill;
		NFArray<struct rolebornmailDesc_s, 1> mail;

		virtual void write_to_pbmsg(::proto_ff::roleborn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleborn & msg);
		static ::proto_ff::roleborn* new_pbmsg(){ return new ::proto_ff::roleborn(); }
		static ::proto_ff::roleborn make_pbmsg(){ return ::proto_ff::roleborn(); }
	};
	typedef struct roleborn_s roleborn_t;

	struct Sheet_roleborn_s : public NFDescStoreSeqOP {
		Sheet_roleborn_s();
		virtual ~Sheet_roleborn_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleborn_s, 20> roleborn_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleborn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleborn & msg);
		static ::proto_ff::Sheet_roleborn* new_pbmsg(){ return new ::proto_ff::Sheet_roleborn(); }
		static ::proto_ff::Sheet_roleborn make_pbmsg(){ return ::proto_ff::Sheet_roleborn(); }
	};
	typedef struct Sheet_roleborn_s Sheet_roleborn_t;

	struct rolemasterMaleattributeDesc_s : public NFDescStoreSeqOP {
		rolemasterMaleattributeDesc_s();
		virtual ~rolemasterMaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::rolemasterMaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolemasterMaleattributeDesc & msg);
		static ::proto_ff::rolemasterMaleattributeDesc* new_pbmsg(){ return new ::proto_ff::rolemasterMaleattributeDesc(); }
		static ::proto_ff::rolemasterMaleattributeDesc make_pbmsg(){ return ::proto_ff::rolemasterMaleattributeDesc(); }
	};
	typedef struct rolemasterMaleattributeDesc_s rolemasterMaleattributeDesc_t;

	struct rolemasterMale_s : public NFDescStoreSeqOP {
		rolemasterMale_s();
		virtual ~rolemasterMale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct rolemasterMaleattributeDesc_s, 70> attribute;

		virtual void write_to_pbmsg(::proto_ff::rolemasterMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolemasterMale & msg);
		static ::proto_ff::rolemasterMale* new_pbmsg(){ return new ::proto_ff::rolemasterMale(); }
		static ::proto_ff::rolemasterMale make_pbmsg(){ return ::proto_ff::rolemasterMale(); }
	};
	typedef struct rolemasterMale_s rolemasterMale_t;

	struct Sheet_rolemasterMale_s : public NFDescStoreSeqOP {
		Sheet_rolemasterMale_s();
		virtual ~Sheet_rolemasterMale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct rolemasterMale_s, 2000> rolemasterMale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rolemasterMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rolemasterMale & msg);
		static ::proto_ff::Sheet_rolemasterMale* new_pbmsg(){ return new ::proto_ff::Sheet_rolemasterMale(); }
		static ::proto_ff::Sheet_rolemasterMale make_pbmsg(){ return ::proto_ff::Sheet_rolemasterMale(); }
	};
	typedef struct Sheet_rolemasterMale_s Sheet_rolemasterMale_t;

	struct rolemasterFemaleattributeDesc_s : public NFDescStoreSeqOP {
		rolemasterFemaleattributeDesc_s();
		virtual ~rolemasterFemaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::rolemasterFemaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolemasterFemaleattributeDesc & msg);
		static ::proto_ff::rolemasterFemaleattributeDesc* new_pbmsg(){ return new ::proto_ff::rolemasterFemaleattributeDesc(); }
		static ::proto_ff::rolemasterFemaleattributeDesc make_pbmsg(){ return ::proto_ff::rolemasterFemaleattributeDesc(); }
	};
	typedef struct rolemasterFemaleattributeDesc_s rolemasterFemaleattributeDesc_t;

	struct rolemasterFemale_s : public NFDescStoreSeqOP {
		rolemasterFemale_s();
		virtual ~rolemasterFemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct rolemasterFemaleattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::rolemasterFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolemasterFemale & msg);
		static ::proto_ff::rolemasterFemale* new_pbmsg(){ return new ::proto_ff::rolemasterFemale(); }
		static ::proto_ff::rolemasterFemale make_pbmsg(){ return ::proto_ff::rolemasterFemale(); }
	};
	typedef struct rolemasterFemale_s rolemasterFemale_t;

	struct Sheet_rolemasterFemale_s : public NFDescStoreSeqOP {
		Sheet_rolemasterFemale_s();
		virtual ~Sheet_rolemasterFemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct rolemasterFemale_s, 2000> rolemasterFemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rolemasterFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rolemasterFemale & msg);
		static ::proto_ff::Sheet_rolemasterFemale* new_pbmsg(){ return new ::proto_ff::Sheet_rolemasterFemale(); }
		static ::proto_ff::Sheet_rolemasterFemale make_pbmsg(){ return ::proto_ff::Sheet_rolemasterFemale(); }
	};
	typedef struct Sheet_rolemasterFemale_s Sheet_rolemasterFemale_t;

	struct rolesickleMaleattributeDesc_s : public NFDescStoreSeqOP {
		rolesickleMaleattributeDesc_s();
		virtual ~rolesickleMaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::rolesickleMaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolesickleMaleattributeDesc & msg);
		static ::proto_ff::rolesickleMaleattributeDesc* new_pbmsg(){ return new ::proto_ff::rolesickleMaleattributeDesc(); }
		static ::proto_ff::rolesickleMaleattributeDesc make_pbmsg(){ return ::proto_ff::rolesickleMaleattributeDesc(); }
	};
	typedef struct rolesickleMaleattributeDesc_s rolesickleMaleattributeDesc_t;

	struct rolesickleMale_s : public NFDescStoreSeqOP {
		rolesickleMale_s();
		virtual ~rolesickleMale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct rolesickleMaleattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::rolesickleMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolesickleMale & msg);
		static ::proto_ff::rolesickleMale* new_pbmsg(){ return new ::proto_ff::rolesickleMale(); }
		static ::proto_ff::rolesickleMale make_pbmsg(){ return ::proto_ff::rolesickleMale(); }
	};
	typedef struct rolesickleMale_s rolesickleMale_t;

	struct Sheet_rolesickleMale_s : public NFDescStoreSeqOP {
		Sheet_rolesickleMale_s();
		virtual ~Sheet_rolesickleMale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct rolesickleMale_s, 2000> rolesickleMale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rolesickleMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rolesickleMale & msg);
		static ::proto_ff::Sheet_rolesickleMale* new_pbmsg(){ return new ::proto_ff::Sheet_rolesickleMale(); }
		static ::proto_ff::Sheet_rolesickleMale make_pbmsg(){ return ::proto_ff::Sheet_rolesickleMale(); }
	};
	typedef struct Sheet_rolesickleMale_s Sheet_rolesickleMale_t;

	struct rolesickleFemaleattributeDesc_s : public NFDescStoreSeqOP {
		rolesickleFemaleattributeDesc_s();
		virtual ~rolesickleFemaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::rolesickleFemaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolesickleFemaleattributeDesc & msg);
		static ::proto_ff::rolesickleFemaleattributeDesc* new_pbmsg(){ return new ::proto_ff::rolesickleFemaleattributeDesc(); }
		static ::proto_ff::rolesickleFemaleattributeDesc make_pbmsg(){ return ::proto_ff::rolesickleFemaleattributeDesc(); }
	};
	typedef struct rolesickleFemaleattributeDesc_s rolesickleFemaleattributeDesc_t;

	struct rolesickleFemale_s : public NFDescStoreSeqOP {
		rolesickleFemale_s();
		virtual ~rolesickleFemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct rolesickleFemaleattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::rolesickleFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rolesickleFemale & msg);
		static ::proto_ff::rolesickleFemale* new_pbmsg(){ return new ::proto_ff::rolesickleFemale(); }
		static ::proto_ff::rolesickleFemale make_pbmsg(){ return ::proto_ff::rolesickleFemale(); }
	};
	typedef struct rolesickleFemale_s rolesickleFemale_t;

	struct Sheet_rolesickleFemale_s : public NFDescStoreSeqOP {
		Sheet_rolesickleFemale_s();
		virtual ~Sheet_rolesickleFemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct rolesickleFemale_s, 2000> rolesickleFemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rolesickleFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rolesickleFemale & msg);
		static ::proto_ff::Sheet_rolesickleFemale* new_pbmsg(){ return new ::proto_ff::Sheet_rolesickleFemale(); }
		static ::proto_ff::Sheet_rolesickleFemale make_pbmsg(){ return ::proto_ff::Sheet_rolesickleFemale(); }
	};
	typedef struct Sheet_rolesickleFemale_s Sheet_rolesickleFemale_t;

	struct roleswordMaleattributeDesc_s : public NFDescStoreSeqOP {
		roleswordMaleattributeDesc_s();
		virtual ~roleswordMaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::roleswordMaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleswordMaleattributeDesc & msg);
		static ::proto_ff::roleswordMaleattributeDesc* new_pbmsg(){ return new ::proto_ff::roleswordMaleattributeDesc(); }
		static ::proto_ff::roleswordMaleattributeDesc make_pbmsg(){ return ::proto_ff::roleswordMaleattributeDesc(); }
	};
	typedef struct roleswordMaleattributeDesc_s roleswordMaleattributeDesc_t;

	struct roleswordMale_s : public NFDescStoreSeqOP {
		roleswordMale_s();
		virtual ~roleswordMale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct roleswordMaleattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::roleswordMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleswordMale & msg);
		static ::proto_ff::roleswordMale* new_pbmsg(){ return new ::proto_ff::roleswordMale(); }
		static ::proto_ff::roleswordMale make_pbmsg(){ return ::proto_ff::roleswordMale(); }
	};
	typedef struct roleswordMale_s roleswordMale_t;

	struct Sheet_roleswordMale_s : public NFDescStoreSeqOP {
		Sheet_roleswordMale_s();
		virtual ~Sheet_roleswordMale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleswordMale_s, 2000> roleswordMale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleswordMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleswordMale & msg);
		static ::proto_ff::Sheet_roleswordMale* new_pbmsg(){ return new ::proto_ff::Sheet_roleswordMale(); }
		static ::proto_ff::Sheet_roleswordMale make_pbmsg(){ return ::proto_ff::Sheet_roleswordMale(); }
	};
	typedef struct Sheet_roleswordMale_s Sheet_roleswordMale_t;

	struct roleswordFemaleattributeDesc_s : public NFDescStoreSeqOP {
		roleswordFemaleattributeDesc_s();
		virtual ~roleswordFemaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::roleswordFemaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleswordFemaleattributeDesc & msg);
		static ::proto_ff::roleswordFemaleattributeDesc* new_pbmsg(){ return new ::proto_ff::roleswordFemaleattributeDesc(); }
		static ::proto_ff::roleswordFemaleattributeDesc make_pbmsg(){ return ::proto_ff::roleswordFemaleattributeDesc(); }
	};
	typedef struct roleswordFemaleattributeDesc_s roleswordFemaleattributeDesc_t;

	struct roleswordFemale_s : public NFDescStoreSeqOP {
		roleswordFemale_s();
		virtual ~roleswordFemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct roleswordFemaleattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::roleswordFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roleswordFemale & msg);
		static ::proto_ff::roleswordFemale* new_pbmsg(){ return new ::proto_ff::roleswordFemale(); }
		static ::proto_ff::roleswordFemale make_pbmsg(){ return ::proto_ff::roleswordFemale(); }
	};
	typedef struct roleswordFemale_s roleswordFemale_t;

	struct Sheet_roleswordFemale_s : public NFDescStoreSeqOP {
		Sheet_roleswordFemale_s();
		virtual ~Sheet_roleswordFemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct roleswordFemale_s, 2000> roleswordFemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roleswordFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roleswordFemale & msg);
		static ::proto_ff::Sheet_roleswordFemale* new_pbmsg(){ return new ::proto_ff::Sheet_roleswordFemale(); }
		static ::proto_ff::Sheet_roleswordFemale make_pbmsg(){ return ::proto_ff::Sheet_roleswordFemale(); }
	};
	typedef struct Sheet_roleswordFemale_s Sheet_roleswordFemale_t;

	struct roletaidaoMaleattributeDesc_s : public NFDescStoreSeqOP {
		roletaidaoMaleattributeDesc_s();
		virtual ~roletaidaoMaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::roletaidaoMaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roletaidaoMaleattributeDesc & msg);
		static ::proto_ff::roletaidaoMaleattributeDesc* new_pbmsg(){ return new ::proto_ff::roletaidaoMaleattributeDesc(); }
		static ::proto_ff::roletaidaoMaleattributeDesc make_pbmsg(){ return ::proto_ff::roletaidaoMaleattributeDesc(); }
	};
	typedef struct roletaidaoMaleattributeDesc_s roletaidaoMaleattributeDesc_t;

	struct roletaidaoMale_s : public NFDescStoreSeqOP {
		roletaidaoMale_s();
		virtual ~roletaidaoMale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct roletaidaoMaleattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::roletaidaoMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roletaidaoMale & msg);
		static ::proto_ff::roletaidaoMale* new_pbmsg(){ return new ::proto_ff::roletaidaoMale(); }
		static ::proto_ff::roletaidaoMale make_pbmsg(){ return ::proto_ff::roletaidaoMale(); }
	};
	typedef struct roletaidaoMale_s roletaidaoMale_t;

	struct Sheet_roletaidaoMale_s : public NFDescStoreSeqOP {
		Sheet_roletaidaoMale_s();
		virtual ~Sheet_roletaidaoMale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct roletaidaoMale_s, 2000> roletaidaoMale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roletaidaoMale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roletaidaoMale & msg);
		static ::proto_ff::Sheet_roletaidaoMale* new_pbmsg(){ return new ::proto_ff::Sheet_roletaidaoMale(); }
		static ::proto_ff::Sheet_roletaidaoMale make_pbmsg(){ return ::proto_ff::Sheet_roletaidaoMale(); }
	};
	typedef struct Sheet_roletaidaoMale_s Sheet_roletaidaoMale_t;

	struct roletaidaoFemaleattributeDesc_s : public NFDescStoreSeqOP {
		roletaidaoFemaleattributeDesc_s();
		virtual ~roletaidaoFemaleattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::roletaidaoFemaleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roletaidaoFemaleattributeDesc & msg);
		static ::proto_ff::roletaidaoFemaleattributeDesc* new_pbmsg(){ return new ::proto_ff::roletaidaoFemaleattributeDesc(); }
		static ::proto_ff::roletaidaoFemaleattributeDesc make_pbmsg(){ return ::proto_ff::roletaidaoFemaleattributeDesc(); }
	};
	typedef struct roletaidaoFemaleattributeDesc_s roletaidaoFemaleattributeDesc_t;

	struct roletaidaoFemale_s : public NFDescStoreSeqOP {
		roletaidaoFemale_s();
		virtual ~roletaidaoFemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t upgradePoint;
		NFArray<struct roletaidaoFemaleattributeDesc_s, 22> attribute;

		virtual void write_to_pbmsg(::proto_ff::roletaidaoFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::roletaidaoFemale & msg);
		static ::proto_ff::roletaidaoFemale* new_pbmsg(){ return new ::proto_ff::roletaidaoFemale(); }
		static ::proto_ff::roletaidaoFemale make_pbmsg(){ return ::proto_ff::roletaidaoFemale(); }
	};
	typedef struct roletaidaoFemale_s roletaidaoFemale_t;

	struct Sheet_roletaidaoFemale_s : public NFDescStoreSeqOP {
		Sheet_roletaidaoFemale_s();
		virtual ~Sheet_roletaidaoFemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct roletaidaoFemale_s, 2000> roletaidaoFemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_roletaidaoFemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_roletaidaoFemale & msg);
		static ::proto_ff::Sheet_roletaidaoFemale* new_pbmsg(){ return new ::proto_ff::Sheet_roletaidaoFemale(); }
		static ::proto_ff::Sheet_roletaidaoFemale make_pbmsg(){ return ::proto_ff::Sheet_roletaidaoFemale(); }
	};
	typedef struct Sheet_roletaidaoFemale_s Sheet_roletaidaoFemale_t;

	struct roleexp_s : public NFDescStoreSeqOP {
		roleexp_s();
		virtual ~roleexp_s(){}
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
		virtual ~Sheet_roleexp_s(){}
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
		virtual ~roleskillType_s(){}
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
		virtual ~Sheet_roleskillType_s(){}
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
		virtual ~roleaddSkill_s(){}
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
		virtual ~Sheet_roleaddSkill_s(){}
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
		virtual ~roleworldexp_s(){}
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
		virtual ~Sheet_roleworldexp_s(){}
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

