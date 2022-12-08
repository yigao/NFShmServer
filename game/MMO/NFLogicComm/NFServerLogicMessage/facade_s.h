#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "facade.pb.h"
#include "facade_s.h"

namespace proto_ff_s {

	struct facadedisplaymaterialDesc_s : public NFDescStoreSeqOP {
		facadedisplaymaterialDesc_s();
		virtual ~facadedisplaymaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t exp;

		virtual void write_to_pbmsg(::proto_ff::facadedisplaymaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadedisplaymaterialDesc & msg);
		static ::proto_ff::facadedisplaymaterialDesc* new_pbmsg(){ return new ::proto_ff::facadedisplaymaterialDesc(); }
		static ::proto_ff::facadedisplaymaterialDesc make_pbmsg(){ return ::proto_ff::facadedisplaymaterialDesc(); }
	};
	typedef struct facadedisplaymaterialDesc_s facadedisplaymaterialDesc_t;

	struct facadedisplay_s : public NFDescStoreSeqOP {
		facadedisplay_s();
		virtual ~facadedisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t type;
		NFShmString<60> resource;
		NFShmString<60> name;
		NFShmString<100> activeDesc;
		NFShmString<60> professionID;
		NFShmString<80> skillID;
		int32_t soulItemID;
		NFArray<struct facadedisplaymaterialDesc_s, 3> material;
		NFArray<int64_t, 3> fragmentID;

		virtual void write_to_pbmsg(::proto_ff::facadedisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadedisplay & msg);
		static ::proto_ff::facadedisplay* new_pbmsg(){ return new ::proto_ff::facadedisplay(); }
		static ::proto_ff::facadedisplay make_pbmsg(){ return ::proto_ff::facadedisplay(); }
	};
	typedef struct facadedisplay_s facadedisplay_t;

	struct Sheet_facadedisplay_s : public NFDescStoreSeqOP {
		Sheet_facadedisplay_s();
		virtual ~Sheet_facadedisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadedisplay_s, 20> facadedisplay_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadedisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadedisplay & msg);
		static ::proto_ff::Sheet_facadedisplay* new_pbmsg(){ return new ::proto_ff::Sheet_facadedisplay(); }
		static ::proto_ff::Sheet_facadedisplay make_pbmsg(){ return ::proto_ff::Sheet_facadedisplay(); }
	};
	typedef struct Sheet_facadedisplay_s Sheet_facadedisplay_t;

	struct facadevaluetreasureAttributeDesc_s : public NFDescStoreSeqOP {
		facadevaluetreasureAttributeDesc_s();
		virtual ~facadevaluetreasureAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadevaluetreasureAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadevaluetreasureAttributeDesc & msg);
		static ::proto_ff::facadevaluetreasureAttributeDesc* new_pbmsg(){ return new ::proto_ff::facadevaluetreasureAttributeDesc(); }
		static ::proto_ff::facadevaluetreasureAttributeDesc make_pbmsg(){ return ::proto_ff::facadevaluetreasureAttributeDesc(); }
	};
	typedef struct facadevaluetreasureAttributeDesc_s facadevaluetreasureAttributeDesc_t;

	struct facadevalueArtifactAttributeDesc_s : public NFDescStoreSeqOP {
		facadevalueArtifactAttributeDesc_s();
		virtual ~facadevalueArtifactAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadevalueArtifactAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadevalueArtifactAttributeDesc & msg);
		static ::proto_ff::facadevalueArtifactAttributeDesc* new_pbmsg(){ return new ::proto_ff::facadevalueArtifactAttributeDesc(); }
		static ::proto_ff::facadevalueArtifactAttributeDesc make_pbmsg(){ return ::proto_ff::facadevalueArtifactAttributeDesc(); }
	};
	typedef struct facadevalueArtifactAttributeDesc_s facadevalueArtifactAttributeDesc_t;

	struct facadevalueBladeAttributeDesc_s : public NFDescStoreSeqOP {
		facadevalueBladeAttributeDesc_s();
		virtual ~facadevalueBladeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadevalueBladeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadevalueBladeAttributeDesc & msg);
		static ::proto_ff::facadevalueBladeAttributeDesc* new_pbmsg(){ return new ::proto_ff::facadevalueBladeAttributeDesc(); }
		static ::proto_ff::facadevalueBladeAttributeDesc make_pbmsg(){ return ::proto_ff::facadevalueBladeAttributeDesc(); }
	};
	typedef struct facadevalueBladeAttributeDesc_s facadevalueBladeAttributeDesc_t;

	struct facadevaluewingAttributeDesc_s : public NFDescStoreSeqOP {
		facadevaluewingAttributeDesc_s();
		virtual ~facadevaluewingAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadevaluewingAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadevaluewingAttributeDesc & msg);
		static ::proto_ff::facadevaluewingAttributeDesc* new_pbmsg(){ return new ::proto_ff::facadevaluewingAttributeDesc(); }
		static ::proto_ff::facadevaluewingAttributeDesc make_pbmsg(){ return ::proto_ff::facadevaluewingAttributeDesc(); }
	};
	typedef struct facadevaluewingAttributeDesc_s facadevaluewingAttributeDesc_t;

	struct facadevalue_s : public NFDescStoreSeqOP {
		facadevalue_s();
		virtual ~facadevalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int64_t wingExp;
		int64_t treasureExp;
		int64_t ArtifactExp;
		int64_t BladeExp;
		NFArray<struct facadevaluetreasureAttributeDesc_s, 5> treasureAttribute;
		NFArray<struct facadevalueArtifactAttributeDesc_s, 6> ArtifactAttribute;
		NFArray<struct facadevalueBladeAttributeDesc_s, 6> BladeAttribute;
		NFArray<struct facadevaluewingAttributeDesc_s, 4> wingAttribute;

		virtual void write_to_pbmsg(::proto_ff::facadevalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadevalue & msg);
		static ::proto_ff::facadevalue* new_pbmsg(){ return new ::proto_ff::facadevalue(); }
		static ::proto_ff::facadevalue make_pbmsg(){ return ::proto_ff::facadevalue(); }
	};
	typedef struct facadevalue_s facadevalue_t;

	struct Sheet_facadevalue_s : public NFDescStoreSeqOP {
		Sheet_facadevalue_s();
		virtual ~Sheet_facadevalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadevalue_s, 500> facadevalue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadevalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadevalue & msg);
		static ::proto_ff::Sheet_facadevalue* new_pbmsg(){ return new ::proto_ff::Sheet_facadevalue(); }
		static ::proto_ff::Sheet_facadevalue make_pbmsg(){ return ::proto_ff::Sheet_facadevalue(); }
	};
	typedef struct Sheet_facadevalue_s Sheet_facadevalue_t;

	struct facadetype_s : public NFDescStoreSeqOP {
		facadetype_s();
		virtual ~facadetype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFShmString<60> souceName;

		virtual void write_to_pbmsg(::proto_ff::facadetype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadetype & msg);
		static ::proto_ff::facadetype* new_pbmsg(){ return new ::proto_ff::facadetype(); }
		static ::proto_ff::facadetype make_pbmsg(){ return ::proto_ff::facadetype(); }
	};
	typedef struct facadetype_s facadetype_t;

	struct Sheet_facadetype_s : public NFDescStoreSeqOP {
		Sheet_facadetype_s();
		virtual ~Sheet_facadetype_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadetype_s, 20> facadetype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadetype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadetype & msg);
		static ::proto_ff::Sheet_facadetype* new_pbmsg(){ return new ::proto_ff::Sheet_facadetype(); }
		static ::proto_ff::Sheet_facadetype make_pbmsg(){ return ::proto_ff::Sheet_facadetype(); }
	};
	typedef struct Sheet_facadetype_s Sheet_facadetype_t;

	struct facadefragmentattributeDesc_s : public NFDescStoreSeqOP {
		facadefragmentattributeDesc_s();
		virtual ~facadefragmentattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadefragmentattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadefragmentattributeDesc & msg);
		static ::proto_ff::facadefragmentattributeDesc* new_pbmsg(){ return new ::proto_ff::facadefragmentattributeDesc(); }
		static ::proto_ff::facadefragmentattributeDesc make_pbmsg(){ return ::proto_ff::facadefragmentattributeDesc(); }
	};
	typedef struct facadefragmentattributeDesc_s facadefragmentattributeDesc_t;

	struct facadefragment_s : public NFDescStoreSeqOP {
		facadefragment_s();
		virtual ~facadefragment_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t fragmentID;
		int64_t item;
		int32_t itemNum;
		NFArray<struct facadefragmentattributeDesc_s, 3> attribute;

		virtual void write_to_pbmsg(::proto_ff::facadefragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadefragment & msg);
		static ::proto_ff::facadefragment* new_pbmsg(){ return new ::proto_ff::facadefragment(); }
		static ::proto_ff::facadefragment make_pbmsg(){ return ::proto_ff::facadefragment(); }
	};
	typedef struct facadefragment_s facadefragment_t;

	struct Sheet_facadefragment_s : public NFDescStoreSeqOP {
		Sheet_facadefragment_s();
		virtual ~Sheet_facadefragment_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadefragment_s, 20> facadefragment_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadefragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadefragment & msg);
		static ::proto_ff::Sheet_facadefragment* new_pbmsg(){ return new ::proto_ff::Sheet_facadefragment(); }
		static ::proto_ff::Sheet_facadefragment make_pbmsg(){ return ::proto_ff::Sheet_facadefragment(); }
	};
	typedef struct Sheet_facadefragment_s Sheet_facadefragment_t;

	struct facadechangeattributeDesc_s : public NFDescStoreSeqOP {
		facadechangeattributeDesc_s();
		virtual ~facadechangeattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadechangeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadechangeattributeDesc & msg);
		static ::proto_ff::facadechangeattributeDesc* new_pbmsg(){ return new ::proto_ff::facadechangeattributeDesc(); }
		static ::proto_ff::facadechangeattributeDesc make_pbmsg(){ return ::proto_ff::facadechangeattributeDesc(); }
	};
	typedef struct facadechangeattributeDesc_s facadechangeattributeDesc_t;

	struct facadechangeActiveAttributeDesc_s : public NFDescStoreSeqOP {
		facadechangeActiveAttributeDesc_s();
		virtual ~facadechangeActiveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadechangeActiveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadechangeActiveAttributeDesc & msg);
		static ::proto_ff::facadechangeActiveAttributeDesc* new_pbmsg(){ return new ::proto_ff::facadechangeActiveAttributeDesc(); }
		static ::proto_ff::facadechangeActiveAttributeDesc make_pbmsg(){ return ::proto_ff::facadechangeActiveAttributeDesc(); }
	};
	typedef struct facadechangeActiveAttributeDesc_s facadechangeActiveAttributeDesc_t;

	struct facadechange_s : public NFDescStoreSeqOP {
		facadechange_s();
		virtual ~facadechange_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t type;
		NFShmString<60> resource;
		NFShmString<60> professionID;
		NFShmString<60> name;
		NFShmString<160> activeDesc;
		int32_t quality;
		int64_t activationItem;
		int32_t activationNum;
		int64_t starId;
		NFShmString<300> starNum;
		int32_t starUp;
		int32_t starBer;
		int64_t upAttributeId;
		int32_t activeSkill;
		NFArray<struct facadechangeattributeDesc_s, 5> attribute;
		NFArray<struct facadechangeActiveAttributeDesc_s, 6> ActiveAttribute;

		virtual void write_to_pbmsg(::proto_ff::facadechange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadechange & msg);
		static ::proto_ff::facadechange* new_pbmsg(){ return new ::proto_ff::facadechange(); }
		static ::proto_ff::facadechange make_pbmsg(){ return ::proto_ff::facadechange(); }
	};
	typedef struct facadechange_s facadechange_t;

	struct Sheet_facadechange_s : public NFDescStoreSeqOP {
		Sheet_facadechange_s();
		virtual ~Sheet_facadechange_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadechange_s, 60> facadechange_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadechange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadechange & msg);
		static ::proto_ff::Sheet_facadechange* new_pbmsg(){ return new ::proto_ff::Sheet_facadechange(); }
		static ::proto_ff::Sheet_facadechange make_pbmsg(){ return ::proto_ff::Sheet_facadechange(); }
	};
	typedef struct Sheet_facadechange_s Sheet_facadechange_t;

	struct facadestarUpupAttributeDesc_s : public NFDescStoreSeqOP {
		facadestarUpupAttributeDesc_s();
		virtual ~facadestarUpupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadestarUpupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadestarUpupAttributeDesc & msg);
		static ::proto_ff::facadestarUpupAttributeDesc* new_pbmsg(){ return new ::proto_ff::facadestarUpupAttributeDesc(); }
		static ::proto_ff::facadestarUpupAttributeDesc make_pbmsg(){ return ::proto_ff::facadestarUpupAttributeDesc(); }
	};
	typedef struct facadestarUpupAttributeDesc_s facadestarUpupAttributeDesc_t;

	struct facadestarUp_s : public NFDescStoreSeqOP {
		facadestarUp_s();
		virtual ~facadestarUp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t upAttributeId;
		int32_t starID;
		int32_t skillID;
		NFArray<struct facadestarUpupAttributeDesc_s, 3> upAttribute;

		virtual void write_to_pbmsg(::proto_ff::facadestarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadestarUp & msg);
		static ::proto_ff::facadestarUp* new_pbmsg(){ return new ::proto_ff::facadestarUp(); }
		static ::proto_ff::facadestarUp make_pbmsg(){ return ::proto_ff::facadestarUp(); }
	};
	typedef struct facadestarUp_s facadestarUp_t;

	struct Sheet_facadestarUp_s : public NFDescStoreSeqOP {
		Sheet_facadestarUp_s();
		virtual ~Sheet_facadestarUp_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadestarUp_s, 40> facadestarUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadestarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadestarUp & msg);
		static ::proto_ff::Sheet_facadestarUp* new_pbmsg(){ return new ::proto_ff::Sheet_facadestarUp(); }
		static ::proto_ff::Sheet_facadestarUp make_pbmsg(){ return ::proto_ff::Sheet_facadestarUp(); }
	};
	typedef struct Sheet_facadestarUp_s Sheet_facadestarUp_t;

	struct facadesoulattributeDesc_s : public NFDescStoreSeqOP {
		facadesoulattributeDesc_s();
		virtual ~facadesoulattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadesoulattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadesoulattributeDesc & msg);
		static ::proto_ff::facadesoulattributeDesc* new_pbmsg(){ return new ::proto_ff::facadesoulattributeDesc(); }
		static ::proto_ff::facadesoulattributeDesc make_pbmsg(){ return ::proto_ff::facadesoulattributeDesc(); }
	};
	typedef struct facadesoulattributeDesc_s facadesoulattributeDesc_t;

	struct facadesoul_s : public NFDescStoreSeqOP {
		facadesoul_s();
		virtual ~facadesoul_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t rechargeID;
		int32_t mainSkill;
		NFArray<struct facadesoulattributeDesc_s, 4> attribute;
		NFArray<int32_t, 8> minorSkill;

		virtual void write_to_pbmsg(::proto_ff::facadesoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadesoul & msg);
		static ::proto_ff::facadesoul* new_pbmsg(){ return new ::proto_ff::facadesoul(); }
		static ::proto_ff::facadesoul make_pbmsg(){ return ::proto_ff::facadesoul(); }
	};
	typedef struct facadesoul_s facadesoul_t;

	struct Sheet_facadesoul_s : public NFDescStoreSeqOP {
		Sheet_facadesoul_s();
		virtual ~Sheet_facadesoul_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadesoul_s, 20> facadesoul_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadesoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadesoul & msg);
		static ::proto_ff::Sheet_facadesoul* new_pbmsg(){ return new ::proto_ff::Sheet_facadesoul(); }
		static ::proto_ff::Sheet_facadesoul make_pbmsg(){ return ::proto_ff::Sheet_facadesoul(); }
	};
	typedef struct Sheet_facadesoul_s Sheet_facadesoul_t;

	struct facadesoulActive_s : public NFDescStoreSeqOP {
		facadesoulActive_s();
		virtual ~facadesoulActive_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFArray<NFShmString<60>, 2> parama;
		NFArray<int32_t, 2> condition;

		virtual void write_to_pbmsg(::proto_ff::facadesoulActive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadesoulActive & msg);
		static ::proto_ff::facadesoulActive* new_pbmsg(){ return new ::proto_ff::facadesoulActive(); }
		static ::proto_ff::facadesoulActive make_pbmsg(){ return ::proto_ff::facadesoulActive(); }
	};
	typedef struct facadesoulActive_s facadesoulActive_t;

	struct Sheet_facadesoulActive_s : public NFDescStoreSeqOP {
		Sheet_facadesoulActive_s();
		virtual ~Sheet_facadesoulActive_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadesoulActive_s, 40> facadesoulActive_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadesoulActive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadesoulActive & msg);
		static ::proto_ff::Sheet_facadesoulActive* new_pbmsg(){ return new ::proto_ff::Sheet_facadesoulActive(); }
		static ::proto_ff::Sheet_facadesoulActive make_pbmsg(){ return ::proto_ff::Sheet_facadesoulActive(); }
	};
	typedef struct Sheet_facadesoulActive_s Sheet_facadesoulActive_t;

	struct facadesoulLvattributeDesc_s : public NFDescStoreSeqOP {
		facadesoulLvattributeDesc_s();
		virtual ~facadesoulLvattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::facadesoulLvattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadesoulLvattributeDesc & msg);
		static ::proto_ff::facadesoulLvattributeDesc* new_pbmsg(){ return new ::proto_ff::facadesoulLvattributeDesc(); }
		static ::proto_ff::facadesoulLvattributeDesc make_pbmsg(){ return ::proto_ff::facadesoulLvattributeDesc(); }
	};
	typedef struct facadesoulLvattributeDesc_s facadesoulLvattributeDesc_t;

	struct facadesoulLv_s : public NFDescStoreSeqOP {
		facadesoulLv_s();
		virtual ~facadesoulLv_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t soulID;
		int32_t itemID;
		int32_t num;
		int32_t successRate;
		int32_t downLv;
		NFArray<struct facadesoulLvattributeDesc_s, 7> attribute;

		virtual void write_to_pbmsg(::proto_ff::facadesoulLv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadesoulLv & msg);
		static ::proto_ff::facadesoulLv* new_pbmsg(){ return new ::proto_ff::facadesoulLv(); }
		static ::proto_ff::facadesoulLv make_pbmsg(){ return ::proto_ff::facadesoulLv(); }
	};
	typedef struct facadesoulLv_s facadesoulLv_t;

	struct Sheet_facadesoulLv_s : public NFDescStoreSeqOP {
		Sheet_facadesoulLv_s();
		virtual ~Sheet_facadesoulLv_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadesoulLv_s, 140> facadesoulLv_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadesoulLv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadesoulLv & msg);
		static ::proto_ff::Sheet_facadesoulLv* new_pbmsg(){ return new ::proto_ff::Sheet_facadesoulLv(); }
		static ::proto_ff::Sheet_facadesoulLv make_pbmsg(){ return ::proto_ff::Sheet_facadesoulLv(); }
	};
	typedef struct Sheet_facadesoulLv_s Sheet_facadesoulLv_t;

	struct facadesoulAchievement_s : public NFDescStoreSeqOP {
		facadesoulAchievement_s();
		virtual ~facadesoulAchievement_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t soulID;
		int32_t type;
		int32_t parama;
		int32_t itemID;
		int32_t num;

		virtual void write_to_pbmsg(::proto_ff::facadesoulAchievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::facadesoulAchievement & msg);
		static ::proto_ff::facadesoulAchievement* new_pbmsg(){ return new ::proto_ff::facadesoulAchievement(); }
		static ::proto_ff::facadesoulAchievement make_pbmsg(){ return ::proto_ff::facadesoulAchievement(); }
	};
	typedef struct facadesoulAchievement_s facadesoulAchievement_t;

	struct Sheet_facadesoulAchievement_s : public NFDescStoreSeqOP {
		Sheet_facadesoulAchievement_s();
		virtual ~Sheet_facadesoulAchievement_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct facadesoulAchievement_s, 160> facadesoulAchievement_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_facadesoulAchievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_facadesoulAchievement & msg);
		static ::proto_ff::Sheet_facadesoulAchievement* new_pbmsg(){ return new ::proto_ff::Sheet_facadesoulAchievement(); }
		static ::proto_ff::Sheet_facadesoulAchievement make_pbmsg(){ return ::proto_ff::Sheet_facadesoulAchievement(); }
	};
	typedef struct Sheet_facadesoulAchievement_s Sheet_facadesoulAchievement_t;

}

