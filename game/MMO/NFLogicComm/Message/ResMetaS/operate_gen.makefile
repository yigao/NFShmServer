include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/operateoperate.bin ${PROTOCGEN_FILE_PATH}/operatetutor.bin ${PROTOCGEN_FILE_PATH}/operatejiangli.bin ${PROTOCGEN_FILE_PATH}/operatehoroscope.bin ${PROTOCGEN_FILE_PATH}/operatehoroscopePool.bin ${PROTOCGEN_FILE_PATH}/operatehoroscopeExchange.bin ${PROTOCGEN_FILE_PATH}/operateconst.bin ${PROTOCGEN_FILE_PATH}/operateunlimited.bin ${PROTOCGEN_FILE_PATH}/operaterand.bin ${PROTOCGEN_FILE_PATH}/operatemooncard.bin ${PROTOCGEN_FILE_PATH}/operatefund.bin ${PROTOCGEN_FILE_PATH}/operatetask.bin ${PROTOCGEN_FILE_PATH}/operateshop.bin ${PROTOCGEN_FILE_PATH}/operatewish.bin ${PROTOCGEN_FILE_PATH}/operateturntable.bin ${PROTOCGEN_FILE_PATH}/operateturntableTask.bin 

${PROTOCGEN_FILE_PATH}/operateoperate.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateoperate  --excel_sheetname=operate  --proto_msgname=operateoperate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operateoperate.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatetutor.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatetutor  --excel_sheetname=tutor  --proto_msgname=operatetutor  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatetutor.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatejiangli.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatejiangli  --excel_sheetname=jiangli  --proto_msgname=operatejiangli  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatejiangli.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatehoroscope.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatehoroscope  --excel_sheetname=horoscope  --proto_msgname=operatehoroscope  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatehoroscope.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatehoroscopePool.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatehoroscopePool  --excel_sheetname=horoscopePool  --proto_msgname=operatehoroscopePool  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatehoroscopePool.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatehoroscopeExchange.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatehoroscopeExchange  --excel_sheetname=horoscopeExchange  --proto_msgname=operatehoroscopeExchange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatehoroscopeExchange.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operateconst.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateconst  --excel_sheetname=const  --proto_msgname=operateconst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operateconst.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operateunlimited.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateunlimited  --excel_sheetname=unlimited  --proto_msgname=operateunlimited  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operateunlimited.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operaterand.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operaterand  --excel_sheetname=rand  --proto_msgname=operaterand  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operaterand.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatemooncard.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatemooncard  --excel_sheetname=mooncard  --proto_msgname=operatemooncard  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatemooncard.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatefund.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatefund  --excel_sheetname=fund  --proto_msgname=operatefund  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatefund.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatetask.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatetask  --excel_sheetname=task  --proto_msgname=operatetask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatetask.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operateshop.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateshop  --excel_sheetname=shop  --proto_msgname=operateshop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operateshop.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operatewish.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operatewish  --excel_sheetname=wish  --proto_msgname=operatewish  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operatewish.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operateturntable.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateturntable  --excel_sheetname=turntable  --proto_msgname=operateturntable  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operateturntable.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/operateturntableTask.bin:${PROTOCGEN_FILE_PATH}/operate.proto.ds ${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/operate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_operateturntableTask  --excel_sheetname=turntableTask  --proto_msgname=operateturntableTask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operateturntableTask.bin" --dst=${GAME_DATA_PATH}/
