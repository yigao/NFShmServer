include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/partnerpartner.bin ${GAME_DATA_PATH}/partnerchange.bin ${GAME_DATA_PATH}/partnerstarUp.bin ${GAME_DATA_PATH}/partnerfragment.bin ${GAME_DATA_PATH}/partnerattribute.bin ${GAME_DATA_PATH}/partnerexp.bin ${GAME_DATA_PATH}/partnerequip.bin ${GAME_DATA_PATH}/partnerrefine.bin ${GAME_DATA_PATH}/partnerslot.bin 

${GAME_DATA_PATH}/partnerpartner.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerpartner  --excel_sheetname=partner  --proto_msgname=partnerpartner  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerchange.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerchange  --excel_sheetname=change  --proto_msgname=partnerchange  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerstarUp.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerstarUp  --excel_sheetname=starUp  --proto_msgname=partnerstarUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerfragment.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerfragment  --excel_sheetname=fragment  --proto_msgname=partnerfragment  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerattribute.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerattribute  --excel_sheetname=attribute  --proto_msgname=partnerattribute  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerexp.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerexp  --excel_sheetname=exp  --proto_msgname=partnerexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerequip.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerequip  --excel_sheetname=equip  --proto_msgname=partnerequip  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerrefine.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerrefine  --excel_sheetname=refine  --proto_msgname=partnerrefine  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/partnerslot.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerslot  --excel_sheetname=slot  --proto_msgname=partnerslot  --start_row=4 --out_path=${GAME_DATA_PATH}/

