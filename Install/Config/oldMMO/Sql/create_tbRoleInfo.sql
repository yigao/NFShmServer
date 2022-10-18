CREATE TABLE IF NOT EXISTS tbRoleInfo (
 charId BIGINT UNSIGNED NOT NULL ,
 playerId BIGINT UNSIGNED ,
 bornZoneId BIGINT UNSIGNED ,
 charName VARCHAR(128) ,
 platId VARCHAR(128) ,
 deletechartime BIGINT UNSIGNED ,
 dirty INT ,
 baseData BLOB /*!99104 COMPRESSED */ ,
 itemData BLOB /*!99104 COMPRESSED */ ,
 taskData BLOB /*!99104 COMPRESSED */ ,
 skillData BLOB /*!99104 COMPRESSED */ ,
 extendData BLOB /*!99104 COMPRESSED */ ,
 equipData BLOB /*!99104 COMPRESSED */ ,
 duplicateData BLOB /*!99104 COMPRESSED */ ,
 achievementData BLOB /*!99104 COMPRESSED */ ,
 buffData BLOB /*!99104 COMPRESSED */ ,
 arenaData BLOB /*!99104 COMPRESSED */ ,
 titleData BLOB /*!99104 COMPRESSED */ ,
 operateLimitData BLOB /*!99104 COMPRESSED */ ,
 huoYueDuData BLOB /*!99104 COMPRESSED */ ,
 operateData BLOB /*!99104 COMPRESSED */ ,
 playerActiveInfo BLOB /*!99104 COMPRESSED */ ,
 cPayData BLOB /*!99104 COMPRESSED */ ,
 unlockInfo BLOB /*!99104 COMPRESSED */ ,
 emblemData BLOB /*!99104 COMPRESSED */ ,
 identifyData BLOB /*!99104 COMPRESSED */ ,
 elementData BLOB /*!99104 COMPRESSED */ ,
 fashionData BLOB /*!99104 COMPRESSED */ ,
 wingData BLOB /*!99104 COMPRESSED */ ,
 mountData BLOB /*!99104 COMPRESSED */ ,
 bossData BLOB /*!99104 COMPRESSED */ ,
 pvpData BLOB /*!99104 COMPRESSED */ ,
 treasure_data BLOB /*!99104 COMPRESSED */ ,
 artifact_data BLOB /*!99104 COMPRESSED */ ,
 fateStarData BLOB /*!99104 COMPRESSED */ ,
 convoyData BLOB /*!99104 COMPRESSED */ ,
 daily_data BLOB /*!99104 COMPRESSED */ ,
 field_data BLOB /*!99104 COMPRESSED */ ,
 vipData BLOB /*!99104 COMPRESSED */ ,
 partnerData BLOB /*!99104 COMPRESSED */ ,
 mallData BLOB /*!99104 COMPRESSED */ ,
 godhoodData BLOB /*!99104 COMPRESSED */ ,
 recoveryData BLOB /*!99104 COMPRESSED */ ,
 activityData BLOB /*!99104 COMPRESSED */ ,
 soActivityData BLOB /*!99104 COMPRESSED */ ,
 useitemData BLOB /*!99104 COMPRESSED */ ,
 dayUseItemData BLOB /*!99104 COMPRESSED */ ,
 mysteryshop_data BLOB /*!99104 COMPRESSED */ ,
 packagetestrebate_data BLOB /*!99104 COMPRESSED */ ,
 fight_data BLOB /*!99104 COMPRESSED */ ,
 power_data BLOB /*!99104 COMPRESSED */ ,
 occupation_data BLOB /*!99104 COMPRESSED */ ,
 headset_data BLOB /*!99104 COMPRESSED */ ,
 online_gift_data BLOB /*!99104 COMPRESSED */ ,
 droplimit_data BLOB /*!99104 COMPRESSED */ ,
 gmhelp_data BLOB /*!99104 COMPRESSED */ ,
 godgm_data BLOB /*!99104 COMPRESSED */ ,
 bowl_data BLOB /*!99104 COMPRESSED */ ,
 bagitemData BLOB /*!99104 COMPRESSED */ ,
 hide_data BLOB /*!99104 COMPRESSED */ ,
 INDEX(playerId),
 INDEX(bornZoneId),
 PRIMARY KEY(charId))  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table tbRoleInfo add column charId BIGINT UNSIGNED NOT NULL;
alter table tbRoleInfo add column playerId BIGINT UNSIGNED;
alter table tbRoleInfo add column bornZoneId BIGINT UNSIGNED;
alter table tbRoleInfo add column charName VARCHAR(128);
alter table tbRoleInfo add column platId VARCHAR(128);
alter table tbRoleInfo add column deletechartime BIGINT UNSIGNED;
alter table tbRoleInfo add column dirty INT;
alter table tbRoleInfo add column baseData BLOB ;
alter table tbRoleInfo add column itemData BLOB ;
alter table tbRoleInfo add column taskData BLOB ;
alter table tbRoleInfo add column skillData BLOB ;
alter table tbRoleInfo add column extendData BLOB ;
alter table tbRoleInfo add column equipData BLOB ;
alter table tbRoleInfo add column duplicateData BLOB ;
alter table tbRoleInfo add column achievementData BLOB ;
alter table tbRoleInfo add column buffData BLOB ;
alter table tbRoleInfo add column arenaData BLOB ;
alter table tbRoleInfo add column titleData BLOB ;
alter table tbRoleInfo add column operateLimitData BLOB ;
alter table tbRoleInfo add column huoYueDuData BLOB ;
alter table tbRoleInfo add column operateData BLOB ;
alter table tbRoleInfo add column playerActiveInfo BLOB ;
alter table tbRoleInfo add column cPayData BLOB ;
alter table tbRoleInfo add column unlockInfo BLOB ;
alter table tbRoleInfo add column emblemData BLOB ;
alter table tbRoleInfo add column identifyData BLOB ;
alter table tbRoleInfo add column elementData BLOB ;
alter table tbRoleInfo add column fashionData BLOB ;
alter table tbRoleInfo add column wingData BLOB ;
alter table tbRoleInfo add column mountData BLOB ;
alter table tbRoleInfo add column bossData BLOB ;
alter table tbRoleInfo add column pvpData BLOB ;
alter table tbRoleInfo add column treasure_data BLOB ;
alter table tbRoleInfo add column artifact_data BLOB ;
alter table tbRoleInfo add column fateStarData BLOB ;
alter table tbRoleInfo add column convoyData BLOB ;
alter table tbRoleInfo add column daily_data BLOB ;
alter table tbRoleInfo add column field_data BLOB ;
alter table tbRoleInfo add column vipData BLOB ;
alter table tbRoleInfo add column partnerData BLOB ;
alter table tbRoleInfo add column mallData BLOB ;
alter table tbRoleInfo add column godhoodData BLOB ;
alter table tbRoleInfo add column recoveryData BLOB ;
alter table tbRoleInfo add column activityData BLOB ;
alter table tbRoleInfo add column soActivityData BLOB ;
alter table tbRoleInfo add column useitemData BLOB ;
alter table tbRoleInfo add column dayUseItemData BLOB ;
alter table tbRoleInfo add column mysteryshop_data BLOB ;
alter table tbRoleInfo add column packagetestrebate_data BLOB ;
alter table tbRoleInfo add column fight_data BLOB ;
alter table tbRoleInfo add column power_data BLOB ;
alter table tbRoleInfo add column occupation_data BLOB ;
alter table tbRoleInfo add column headset_data BLOB ;
alter table tbRoleInfo add column online_gift_data BLOB ;
alter table tbRoleInfo add column droplimit_data BLOB ;
alter table tbRoleInfo add column gmhelp_data BLOB ;
alter table tbRoleInfo add column godgm_data BLOB ;
alter table tbRoleInfo add column bowl_data BLOB ;
alter table tbRoleInfo add column bagitemData BLOB ;
alter table tbRoleInfo add column hide_data BLOB ;
*/
