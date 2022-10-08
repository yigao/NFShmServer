LoadHelper = {}

require("trdlib.Init")  --先加载第三方库
require("conf.serverConf")
require("conf.redisConf")
require("Public.Init")

require("common.define.HumanDefine")
require("common.packet.packet_human")

require("common.define.AgentDefine")
require("common.define.BarccatatDefine")
require("common.define.BcbmDefine")
require("common.define.BrnnDefine")
require("common.define.CaipiaoDefine")
require("common.define.CaipiaoBjscDefine")
require("common.define.CaipiaoLhcDefine")
require("common.define.CaipiaoXyftDefine")
require("common.define.CjmpDefine")
require("common.define.DdzDefine")
require("common.define.DouNiuDefine")
require("common.define.DouNiuTzDefine")
require("common.define.ErnnDefine")
require("common.define.ErshDefine")
require("common.define.FenFenCaiDefine")
require("common.define.ForestDefine")
require("common.define.FqzsDefine")
require("common.define.FruitDefine")
require("common.define.GdmjDefine")
require("common.define.HongHeiDefine")
require("common.define.LhdDefine")
require("common.define.LhdbDefine")
require("common.define.LkpyDefine")
require("common.define.MissionDefine")
require("common.define.PszDefine")
require("common.define.RankDefine")
require("common.define.RateDefine")
require("common.define.ShopDefine")
require("common.define.SlhbDefine")
require("common.define.SicboDefine")
require("common.define.SlotDefine")
require("common.define.SscaiDefine")
require("common.define.TexasDefine")
require("common.define.TgpdDefine")
require("common.define.TtzDefine")
require("common.define.YqsDefine")
require("common.define.ShzBatDefine")

require("common.st_agent_pb")
require("common.st_human_pb")
require("common.st_barccatat_pb")
require("common.st_bcbm_pb")
require("common.st_brnn_pb")
require("common.st_caipiao_pb")
require("common.st_cjmp_pb")
require("common.st_ddz_pb")
require("common.st_douniu_pb")
require("common.st_douniutz_pb")
require("common.st_ernn_pb")
require("common.st_ersh_pb")
require("common.st_fenfencai_pb")
require("common.st_forest_pb")
require("common.st_fqzs_pb")
require("common.st_fruit_pb")
require("common.st_gdmj_pb")
require("common.st_gdmj2_pb")
require("common.st_honghei_pb")
require("common.st_lhd_pb")
require("common.st_lhdb_pb")
require("common.st_lkpy_pb")
require("common.st_mission_pb")
require("common.st_psz_pb")
require("common.st_shop_pb")
require("common.st_sicbo_pb")
require("common.st_slhb_pb")
require("common.st_slot_pb")
require("common.st_texas_pb")
require("common.st_tgpd_pb")
require("common.st_ttz_pb")
require("common.st_user_pb")
require("common.st_yqs_pb")
require("common.st_utils_pond_pb")
require("common.st_shzbat_pb")

require("Human.Model.PlayerModel")
require("Human.Model.GoodsModel")
require("Human.Model.OnlineModel")
require("Human.Model.NoticeModel")
require("Human.Model.BroadCastModel")
require("Human.Model.ChatModel")
require("Human.Model.MailModel")
require("Human.Model.AgencyModel")
require("Human.Model.AwardModel")
require("Human.Model.BankModel")
require("Human.Model.RosterModel")
require("Human.Model.GameModel")
require("Human.Model.PlayerStatsModel")
require("Human.Model.LocationModel")
require("Human.Model.HttpSendModel")
require("Human.Model.ActivityModel")
require("Human.Model.SpecialModel")

require("Agent.Model.AgentModel")
require("Agent.Model.UnlimitedModel")
require("Agent.Model.TaxModel")
require("Agent.Model.BonusModule")
require("Agent.Model.CostModel")
require("Barccatat.Model.BarccatatModel")
require("Barccatat.Model.BarccatatStatsModel")
require("Bcbm.Model.BcbmModel")
require("Brnn.Model.BrnnModel")
require("Brnn.Model.BrnnStatsModel")
require("CaiPiao.Model.CaiPiaoModel")
require("CaiPiao.Model.CaiPiaoXyftModel")
require("CaiPiao.Model.CaiPiaoLhcModel")
require("CaiPiao.Model.CaiPiaoBjscModel")
require("Cjmp.Model.CjmpModel")
require("Cjmp.Model.CjmpStatsModel")
require("Ddz.Model.DdzHistoryModel")
require("Ddz.Model.DdzModel")
require("DouNiu.Model.DouNiuModel")
require("DouNiu.Model.DouNiuHistoryModel")
require("DouNiuTz.Model.DouNiuTzModel")
require("DouNiuTz.Model.DouNiuTzHistoryModel")
require("Ernn.Model.ErnnModel")
require("Ernn.Model.ErnnHistoryModel")
require("Ersh.Model.ErshModel")
require("Forest.Model.ForestModel")
require("Fqzs.Model.FqzsModel")
require("Fruit.Model.FruitModel")
require("Gdmj.Model.GdmjModel")
require("HongHei.Model.HongHeiModel")
require("HongHei.Model.HongHeiStatsModel")
require("Legal.Model.LegalModel")
require("FenFenCai.Model.FenFenCaiModel")
require("Lhdb.Model.LhdbModel")
require("Lhd.Model.LhdModel")
require("Lhd.Model.LhdStatsModel")
require("Lkpy.Model.LkpyModel")
require("Lkpy.Model.LkpyPond")
require("LogServer.Model.LogServer")
require("LogServer.Model.LogBehavior")
require("LogServer.Services.LogService")
require("LogServer.Model.LogConstantly")
require("LogServer.Model.LogModel")
require("Mission.Model.MissionModel")
require("peiwang.Services.peiwangService")
require("PSZ.Model.PszModel")
require("Rank.Model.RankModel")
require("Rank.Model.PopularModel")
require("Rank.Model.JettonModel")
require("Rank.Model.Flowingwater")
require("Robot.Model.RobotModel")
require("Shop.Model.ShopModel")
require("Sicbo.Model.SicboModel")
require("Sicbo.Model.SicboStatsModel")
require("Slhb.Model.SlhbModel") 
require("Slot.Model.SlotModel")
require("Sscai.Model.SscaiModel")
require("Texas.Model.TexasModel")
require("Tgpd.Model.TgpdModel")
require("Yqs.Model.YqsModel")
require("Yqs.Model.YqsPond")
require("Ttz.Model.TtzModel")
require("Ttz.Model.TtzStatsModel")
require("ShzBat.Model.ShzBatModel")

g_redisIndex[NoticeModel.redis_index] = {index = g_redisInfo.redis_one, des="notice"}     --系统唯一的邮件
g_redisIndex[OnlineModel.redis_index] = {index = g_redisInfo.redis_one, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[GoodsModel.redis_index] = {index = g_redisInfo.redis_one, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[BroadCastModel.redis_index] = {index = g_redisInfo.redis_one, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[ChatModel.redis_index] = {index = g_redisInfo.redis_one, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[MailModel.redis_index] = {index = g_redisInfo.redis_one, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[PlayerModel.redis_index] = {index = g_redisInfo.redis_one, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[AgencyModel.redis_index] = {index = g_redisInfo.redis_one, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[RosterModel.redis_index] = {index = g_redisInfo.redis_three, key = MailModel.mail_list, link = 1}  --每个玩家自己的邮件
g_redisIndex[LocationModel.redis_index] = {index = g_redisInfo.redis_one, key = LocationModel.redis_index, link = 1}  --
g_redisIndex[HttpSendModel.redis_index] = {index = g_redisInfo.redis_one, key = HttpSendModel.redis_index, link = 1}  --
g_redisIndex[ActivityModel.redis_index] = {index = g_redisInfo.redis_three, key = HttpSendModel.redis_index, link = 1}  --

g_redisIndex[AgentModel.redis_index] = {index = g_redisInfo.redis_two, key = AgentModel.redis_index, link = 1}
g_redisIndex[BarccatatModel.redis_index] = {index = g_redisInfo.redis_four, des = "barccatat_info"}
g_redisIndex[BarccatatModel.redis_index] = {index = g_redisInfo.redis_four, des = "barccatat_info"}
g_redisIndex[BcbmModel.redis_index] = {index = g_redisInfo.redis_three, key = BcbmModel.redis_index, link = 1}
g_redisIndex[BrnnModel.redis_index] = {index = g_redisInfo.redis_four, des = "brnn_info"}
g_redisIndex[BrnnModel.redis_index] = {index = g_redisInfo.redis_four, des = "brnn_info"}
g_redisIndex[CaiPiaoModel.redis_index] = {index = g_redisInfo.redis_four, des = "caipiao_info"}
g_redisIndex[CaiPiaoModel.redis_index] = {index = g_redisInfo.redis_four, des = "caipiao_info"}
g_redisIndex[CjmpModel.redis_index] = {index = g_redisInfo.redis_four, des = "cjmp_info"}
g_redisIndex[g_ddzRedis.redis_index] = {index = g_redisInfo.redis_three, des = "ddz_info"}
g_redisIndex[g_douniuRedis.redis_index] = {index = g_redisInfo.redis_three, des = "douniu_info"}
g_redisIndex[g_douniuTzRedis.redis_index] = {index = g_redisInfo.redis_three, des = "douniuTz_info"}
g_redisIndex[g_ernnRedis.redis_index] = {index = g_redisInfo.redis_three, des = "ernn_info"}
g_redisIndex[g_ershRedis.redis_index] = {index = g_redisInfo.redis_three, des = "ersh_info"}
g_redisIndex[FenFenCaiModel.redis_index] = {index = g_redisInfo.redis_four, des = "fenfencai_info"}
g_redisIndex[ForestModel.redis_index] = {index = g_redisInfo.redis_three, key = ForestModel.redis_index, link = 1}
g_redisIndex[FqzsModel.redis_index] = {index = g_redisInfo.redis_three, key = FqzsModel.redis_index, link = 1}
g_redisIndex[FruitModel.redis_index] = {index = g_redisInfo.redis_three, key = FruitModel.redis_index, link = 1}
g_redisIndex[g_gdmjRedis.redis_index] = {index = g_redisInfo.redis_four, des = "gdmj"}  --一定要记得在这里设置
g_redisIndex[HongHeiModel.redis_index] = {index = g_redisInfo.redis_four, des = "honghei_info"}
g_redisIndex[LegalModel.redis_index] = {index = g_redisInfo.redis_three, des = "legal_info"}
g_redisIndex[LhdModel.redis_index] = {index = g_redisInfo.redis_four, des = "lhd_info"}
g_redisIndex[LhdbModel.redis_index] = {index = g_redisInfo.redis_three, key = LhdbModel.redis_index, link = 1}
g_redisIndex[LkpyModel.redis_index] = {index = g_redisInfo.redis_three, key = LkpyModel.redis_index, link = 1}
g_redisIndex[MissionModel.redis_index] = {index = g_redisInfo.redis_two, des="MissionModel"}  --每个玩家自己的邮件
g_redisIndex[g_peiwangRedis.redis_index] = {index = g_redisInfo.redis_three, des = "peiwang", link = 0}
g_redisIndex[g_pszRedis.redis_index] = {index = g_redisInfo.redis_three, key = g_pszRedis.redis_index, link = 1}
g_redisIndex[PopularModel.popular_all] = {index = g_redisInfo.redis_three, key = PopularModel.popular_all, link = 0}
g_redisIndex[RankModel.redis_index] = {index = g_redisInfo.redis_three, des = "RankModel", link = 0}
g_redisIndex[JettonModel.redis_index] = {index = g_redisInfo.redis_three, des = "RankModel", link = 0}
g_redisIndex[PopularModel.redis_index] = {index = g_redisInfo.redis_three, des = "RankModel", link = 0}
g_redisIndex[Flowingwater.redis_index] = {index = g_redisInfo.redis_three, des = "RankModel", link = 0}
g_redisIndex[RobotModel.redis_index] = {index = g_redisInfo.redis_three, des = "robot", link = 0}
g_redisIndex[ShopModel.buy_money] = {index = g_redisInfo.redis_two, key = ShopModel.buy_money, link = 1}
g_redisIndex[ShopModel.redis_index] = {index = g_redisInfo.redis_two, key = ShopModel.buy_money, link = 1}
g_redisIndex[SicboModel.redis_index] = {index = g_redisInfo.redis_four, des = "sicbo_info"}
g_redisIndex[SlhbModel.redis_index] = {index = g_redisInfo.redis_four, des = "slhb_info"}
g_redisIndex[SscaiModel.redis_index] = {index = g_redisInfo.redis_three, key = SscaiModel.redis_index, link = 1}
g_redisIndex[g_texasRedis.redis_index] = {index = g_redisInfo.redis_four, key = g_texasRedis.redis_index, link = 1}
g_redisIndex[TgpdModel.redis_index] = {index = g_redisInfo.redis_three, key = TgpdModel.redis_index, link = 1}
g_redisIndex[TtzModel.redis_index] = {index = g_redisInfo.redis_four, des = "Ttz_info"}
g_redisIndex[TtzModel.redis_index] = {index = g_redisInfo.redis_four, des = "Ttz_info"}
g_redisIndex[YqsModel.redis_index] = {index = g_redisInfo.redis_three, key = YqsModel.redis_index, link = 1}
g_redisIndex[ShzBatModel.redis_index] = {index = g_redisInfo.redis_four, des = "shz_info"}

require("Human.Init")
require("Agent.Init")
require("LogServer.Init")
require("Event.Init")
require("Legal.Init")
require("Mission.Init")
require("peiwang.Init")
require("Rank.Init")
require("Robot.Init")
require("Shop.Init")

require("common.packet.packet_lhd")
require("common.packet.packet_douniuTz")

