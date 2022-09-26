include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/operateoperate.bin ${GAME_DATA_PATH}/operatetutor.bin ${GAME_DATA_PATH}/operatejiangli.bin ${GAME_DATA_PATH}/operatehoroscope.bin ${GAME_DATA_PATH}/operatehoroscopePool.bin ${GAME_DATA_PATH}/operatehoroscopeExchange.bin ${GAME_DATA_PATH}/operateconst.bin ${GAME_DATA_PATH}/operateunlimited.bin ${GAME_DATA_PATH}/operaterand.bin ${GAME_DATA_PATH}/operatemooncard.bin ${GAME_DATA_PATH}/operatefund.bin ${GAME_DATA_PATH}/operatetask.bin ${GAME_DATA_PATH}/operateshop.bin ${GAME_DATA_PATH}/operatewish.bin ${GAME_DATA_PATH}/operateturntable.bin ${GAME_DATA_PATH}/operateturntableTask.bin 

${GAME_DATA_PATH}/operateoperate.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateoperate  --excel_sheetname=operate  --proto_msgname=operateoperate  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatetutor.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatetutor  --excel_sheetname=tutor  --proto_msgname=operatetutor  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatejiangli.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatejiangli  --excel_sheetname=jiangli  --proto_msgname=operatejiangli  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatehoroscope.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatehoroscope  --excel_sheetname=horoscope  --proto_msgname=operatehoroscope  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatehoroscopePool.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatehoroscopePool  --excel_sheetname=horoscopePool  --proto_msgname=operatehoroscopePool  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatehoroscopeExchange.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatehoroscopeExchange  --excel_sheetname=horoscopeExchange  --proto_msgname=operatehoroscopeExchange  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operateconst.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateconst  --excel_sheetname=const  --proto_msgname=operateconst  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operateunlimited.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateunlimited  --excel_sheetname=unlimited  --proto_msgname=operateunlimited  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operaterand.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operaterand  --excel_sheetname=rand  --proto_msgname=operaterand  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatemooncard.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatemooncard  --excel_sheetname=mooncard  --proto_msgname=operatemooncard  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatefund.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatefund  --excel_sheetname=fund  --proto_msgname=operatefund  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatetask.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatetask  --excel_sheetname=task  --proto_msgname=operatetask  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operateshop.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateshop  --excel_sheetname=shop  --proto_msgname=operateshop  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operatewish.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatewish  --excel_sheetname=wish  --proto_msgname=operatewish  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operateturntable.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateturntable  --excel_sheetname=turntable  --proto_msgname=operateturntable  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/operateturntableTask.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/operate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateturntableTask  --excel_sheetname=turntableTask  --proto_msgname=operateturntableTask  --start_row=4 --out_path=${GAME_DATA_PATH}/

