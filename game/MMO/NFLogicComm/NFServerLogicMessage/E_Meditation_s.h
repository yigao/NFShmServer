#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Meditation.pb.h"
#include "E_Meditation_s.h"

#define DEFINE_E_MEDITATIONMEDITATION_M_ATTRIBUTE_MAX_NUM 8
#define DEFINE_E_MEDITATIONMEDITATION_M_ACTIVEATTRIBUTE_MAX_NUM 8
#define DEFINE_SHEET_MEDITATIONMEDITATION_E_MEDITATIONMEDITATION_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_MeditationMeditationAttributeDesc_s : public NFDescStoreSeqOP {
		E_MeditationMeditationAttributeDesc_s();
		virtual ~E_MeditationMeditationAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MeditationMeditationAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MeditationMeditationAttributeDesc & msg);
		static ::proto_ff::E_MeditationMeditationAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MeditationMeditationAttributeDesc(); }
		static ::proto_ff::E_MeditationMeditationAttributeDesc make_pbmsg(){ return ::proto_ff::E_MeditationMeditationAttributeDesc(); }
	};
	typedef struct E_MeditationMeditationAttributeDesc_s E_MeditationMeditationAttributeDesc_t;

	struct E_MeditationMeditationActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_MeditationMeditationActiveattributeDesc_s();
		virtual ~E_MeditationMeditationActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MeditationMeditationActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MeditationMeditationActiveattributeDesc & msg);
		static ::proto_ff::E_MeditationMeditationActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_MeditationMeditationActiveattributeDesc(); }
		static ::proto_ff::E_MeditationMeditationActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_MeditationMeditationActiveattributeDesc(); }
	};
	typedef struct E_MeditationMeditationActiveattributeDesc_s E_MeditationMeditationActiveattributeDesc_t;

	struct E_MeditationMeditation_s : public NFDescStoreSeqOP {
		E_MeditationMeditation_s();
		virtual ~E_MeditationMeditation_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//打坐ID
		NFShmString<64> m_name;//打坐名称
		int32_t m_type;//外观类型
		int32_t m_quality;//打坐品质
		NFShmString<64> m_professionLimit;//职业限制
		int64_t m_activationItem;//激活道具ID
		int32_t m_activationNum;//激活道具数量
		int64_t m_starId;//升星道具id
		NFShmString<256> m_starNum;//升星道具数量
		int32_t m_starUp;//升星等级上限
		int32_t m_starBer;//每次升星属性增加的百分比值
		NFShmVector<struct E_MeditationMeditationAttributeDesc_s, DEFINE_E_MEDITATIONMEDITATION_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_MeditationMeditationActiveattributeDesc_s, DEFINE_E_MEDITATIONMEDITATION_M_ACTIVEATTRIBUTE_MAX_NUM> m_ActiveAttribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MeditationMeditation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MeditationMeditation & msg);
		static ::proto_ff::E_MeditationMeditation* new_pbmsg(){ return new ::proto_ff::E_MeditationMeditation(); }
		static ::proto_ff::E_MeditationMeditation make_pbmsg(){ return ::proto_ff::E_MeditationMeditation(); }
	};
	typedef struct E_MeditationMeditation_s E_MeditationMeditation_t;

	struct Sheet_MeditationMeditation_s : public NFDescStoreSeqOP {
		Sheet_MeditationMeditation_s();
		virtual ~Sheet_MeditationMeditation_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MeditationMeditation_s, DEFINE_SHEET_MEDITATIONMEDITATION_E_MEDITATIONMEDITATION_LIST_MAX_NUM> E_MeditationMeditation_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MeditationMeditation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MeditationMeditation & msg);
		static ::proto_ff::Sheet_MeditationMeditation* new_pbmsg(){ return new ::proto_ff::Sheet_MeditationMeditation(); }
		static ::proto_ff::Sheet_MeditationMeditation make_pbmsg(){ return ::proto_ff::Sheet_MeditationMeditation(); }
	};
	typedef struct Sheet_MeditationMeditation_s Sheet_MeditationMeditation_t;

}

