include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/festivalmuban_JFduihuan.bin ${GAME_DATA_PATH}/festivalmuban_dingzhi.bin ${GAME_DATA_PATH}/festivalmuban_CZfanzuan.bin ${GAME_DATA_PATH}/festivalmuban_lianxuCZ.bin ${GAME_DATA_PATH}/festivalmuban_prerecharge.bin ${GAME_DATA_PATH}/festivalmuban_doubleGift.bin ${GAME_DATA_PATH}/festivalbigyanhuarecharge.bin ${GAME_DATA_PATH}/festivalbigyanhuacost.bin ${GAME_DATA_PATH}/festivalmuban_bigyanhua.bin ${GAME_DATA_PATH}/festivalfestival.bin ${GAME_DATA_PATH}/festivaltemplate.bin ${GAME_DATA_PATH}/festivalmuban_worldboss.bin ${GAME_DATA_PATH}/festivalmuban_libao.bin ${GAME_DATA_PATH}/festivalmuban_double.bin ${GAME_DATA_PATH}/festivalmiaoshu.bin ${GAME_DATA_PATH}/festivalmuban_denglu.bin ${GAME_DATA_PATH}/festivalmuban_touzi.bin ${GAME_DATA_PATH}/festivalmuban_zhichong.bin ${GAME_DATA_PATH}/festivalmuban_leichong.bin ${GAME_DATA_PATH}/festivalmuban_duihuan.bin ${GAME_DATA_PATH}/festivald_diaoluo.bin ${GAME_DATA_PATH}/festivalmuban_leixiao.bin ${GAME_DATA_PATH}/festivalmuban_shouchong.bin ${GAME_DATA_PATH}/festivalmuban_yanhua.bin ${GAME_DATA_PATH}/festivalyanhuaConstant.bin ${GAME_DATA_PATH}/festivalmuban_shop.bin ${GAME_DATA_PATH}/festivalmuban_czjb.bin ${GAME_DATA_PATH}/festivalmuban_scsb.bin ${GAME_DATA_PATH}/festivalmuban_eggs.bin ${GAME_DATA_PATH}/festivaleggConstant.bin ${GAME_DATA_PATH}/festivalconstant.bin ${GAME_DATA_PATH}/festivalmuban_shousha.bin ${GAME_DATA_PATH}/festivalmuban_huoyue.bin 

${GAME_DATA_PATH}/festivalmuban_JFduihuan.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_JFduihuan  --excel_sheetname=muban_JFduihuan  --proto_msgname=festivalmuban_JFduihuan  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_dingzhi.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_dingzhi  --excel_sheetname=muban_dingzhi  --proto_msgname=festivalmuban_dingzhi  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_CZfanzuan.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_CZfanzuan  --excel_sheetname=muban_CZfanzuan  --proto_msgname=festivalmuban_CZfanzuan  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_lianxuCZ.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_lianxuCZ  --excel_sheetname=muban_lianxuCZ  --proto_msgname=festivalmuban_lianxuCZ  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_prerecharge.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_prerecharge  --excel_sheetname=muban_prerecharge  --proto_msgname=festivalmuban_prerecharge  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_doubleGift.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_doubleGift  --excel_sheetname=muban_doubleGift  --proto_msgname=festivalmuban_doubleGift  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalbigyanhuarecharge.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalbigyanhuarecharge  --excel_sheetname=bigyanhuarecharge  --proto_msgname=festivalbigyanhuarecharge  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalbigyanhuacost.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalbigyanhuacost  --excel_sheetname=bigyanhuacost  --proto_msgname=festivalbigyanhuacost  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_bigyanhua.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_bigyanhua  --excel_sheetname=muban_bigyanhua  --proto_msgname=festivalmuban_bigyanhua  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalfestival.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalfestival  --excel_sheetname=festival  --proto_msgname=festivalfestival  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivaltemplate.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivaltemplate  --excel_sheetname=template  --proto_msgname=festivaltemplate  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_worldboss.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_worldboss  --excel_sheetname=muban_worldboss  --proto_msgname=festivalmuban_worldboss  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_libao.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_libao  --excel_sheetname=muban_libao  --proto_msgname=festivalmuban_libao  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_double.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_double  --excel_sheetname=muban_double  --proto_msgname=festivalmuban_double  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmiaoshu.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmiaoshu  --excel_sheetname=miaoshu  --proto_msgname=festivalmiaoshu  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_denglu.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_denglu  --excel_sheetname=muban_denglu  --proto_msgname=festivalmuban_denglu  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_touzi.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_touzi  --excel_sheetname=muban_touzi  --proto_msgname=festivalmuban_touzi  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_zhichong.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_zhichong  --excel_sheetname=muban_zhichong  --proto_msgname=festivalmuban_zhichong  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_leichong.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_leichong  --excel_sheetname=muban_leichong  --proto_msgname=festivalmuban_leichong  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_duihuan.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_duihuan  --excel_sheetname=muban_duihuan  --proto_msgname=festivalmuban_duihuan  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivald_diaoluo.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivald_diaoluo  --excel_sheetname=d_diaoluo  --proto_msgname=festivald_diaoluo  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_leixiao.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_leixiao  --excel_sheetname=muban_leixiao  --proto_msgname=festivalmuban_leixiao  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_shouchong.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_shouchong  --excel_sheetname=muban_shouchong  --proto_msgname=festivalmuban_shouchong  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_yanhua.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_yanhua  --excel_sheetname=muban_yanhua  --proto_msgname=festivalmuban_yanhua  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalyanhuaConstant.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalyanhuaConstant  --excel_sheetname=yanhuaConstant  --proto_msgname=festivalyanhuaConstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_shop.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_shop  --excel_sheetname=muban_shop  --proto_msgname=festivalmuban_shop  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_czjb.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_czjb  --excel_sheetname=muban_czjb  --proto_msgname=festivalmuban_czjb  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_scsb.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_scsb  --excel_sheetname=muban_scsb  --proto_msgname=festivalmuban_scsb  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_eggs.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_eggs  --excel_sheetname=muban_eggs  --proto_msgname=festivalmuban_eggs  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivaleggConstant.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivaleggConstant  --excel_sheetname=eggConstant  --proto_msgname=festivaleggConstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalconstant.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalconstant  --excel_sheetname=constant  --proto_msgname=festivalconstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_shousha.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_shousha  --excel_sheetname=muban_shousha  --proto_msgname=festivalmuban_shousha  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/festivalmuban_huoyue.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/festival.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_festivalmuban_huoyue  --excel_sheetname=muban_huoyue  --proto_msgname=festivalmuban_huoyue  --start_row=4 --out_path=${GAME_DATA_PATH}/

