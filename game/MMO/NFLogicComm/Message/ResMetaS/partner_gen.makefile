include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/partnerpartner.bin ${PROTOCGEN_FILE_PATH}/PartnerPartnerDesc.h ${PROTOCGEN_FILE_PATH}/PartnerPartnerDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerchange.bin ${PROTOCGEN_FILE_PATH}/PartnerChangeDesc.h ${PROTOCGEN_FILE_PATH}/PartnerChangeDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerstarUp.bin ${PROTOCGEN_FILE_PATH}/PartnerStarupDesc.h ${PROTOCGEN_FILE_PATH}/PartnerStarupDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerfragment.bin ${PROTOCGEN_FILE_PATH}/PartnerFragmentDesc.h ${PROTOCGEN_FILE_PATH}/PartnerFragmentDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerattribute.bin ${PROTOCGEN_FILE_PATH}/PartnerAttributeDesc.h ${PROTOCGEN_FILE_PATH}/PartnerAttributeDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerexp.bin ${PROTOCGEN_FILE_PATH}/PartnerExpDesc.h ${PROTOCGEN_FILE_PATH}/PartnerExpDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerequip.bin ${PROTOCGEN_FILE_PATH}/PartnerEquipDesc.h ${PROTOCGEN_FILE_PATH}/PartnerEquipDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerrefine.bin ${PROTOCGEN_FILE_PATH}/PartnerRefineDesc.h ${PROTOCGEN_FILE_PATH}/PartnerRefineDesc.cpp ${PROTOCGEN_FILE_PATH}/partnerslot.bin ${PROTOCGEN_FILE_PATH}/PartnerSlotDesc.h ${PROTOCGEN_FILE_PATH}/PartnerSlotDesc.cpp 

${PROTOCGEN_FILE_PATH}/partnerpartner.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerpartner  --excel_sheetname=partner  --proto_msgname=partnerpartner  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerpartner.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerPartnerDesc.h ${PROTOCGEN_FILE_PATH}/PartnerPartnerDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerPartnerDesc.h ${PROTOCGEN_FILE_PATH}/PartnerPartnerDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerchange.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerchange  --excel_sheetname=change  --proto_msgname=partnerchange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerchange.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerChangeDesc.h ${PROTOCGEN_FILE_PATH}/PartnerChangeDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerChangeDesc.h ${PROTOCGEN_FILE_PATH}/PartnerChangeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerstarUp.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerstarUp  --excel_sheetname=starUp  --proto_msgname=partnerstarUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerstarUp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerStarupDesc.h ${PROTOCGEN_FILE_PATH}/PartnerStarupDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerStarupDesc.h ${PROTOCGEN_FILE_PATH}/PartnerStarupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerfragment.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerfragment  --excel_sheetname=fragment  --proto_msgname=partnerfragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerfragment.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerFragmentDesc.h ${PROTOCGEN_FILE_PATH}/PartnerFragmentDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerFragmentDesc.h ${PROTOCGEN_FILE_PATH}/PartnerFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerattribute.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerattribute  --excel_sheetname=attribute  --proto_msgname=partnerattribute  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerattribute.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerAttributeDesc.h ${PROTOCGEN_FILE_PATH}/PartnerAttributeDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerAttributeDesc.h ${PROTOCGEN_FILE_PATH}/PartnerAttributeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerexp.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerexp  --excel_sheetname=exp  --proto_msgname=partnerexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerexp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerExpDesc.h ${PROTOCGEN_FILE_PATH}/PartnerExpDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerExpDesc.h ${PROTOCGEN_FILE_PATH}/PartnerExpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerequip.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerequip  --excel_sheetname=equip  --proto_msgname=partnerequip  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerequip.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerEquipDesc.h ${PROTOCGEN_FILE_PATH}/PartnerEquipDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerEquipDesc.h ${PROTOCGEN_FILE_PATH}/PartnerEquipDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerrefine.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerrefine  --excel_sheetname=refine  --proto_msgname=partnerrefine  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerrefine.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerRefineDesc.h ${PROTOCGEN_FILE_PATH}/PartnerRefineDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerRefineDesc.h ${PROTOCGEN_FILE_PATH}/PartnerRefineDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/partnerslot.bin:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/partner.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_partnerslot  --excel_sheetname=slot  --proto_msgname=partnerslot  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partnerslot.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PartnerSlotDesc.h ${PROTOCGEN_FILE_PATH}/PartnerSlotDesc.cpp:${PROTOCGEN_FILE_PATH}/partner.proto.ds ${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PartnerSlotDesc.h ${PROTOCGEN_FILE_PATH}/PartnerSlotDesc.cpp" --dst=${DESC_STORE_PATH}/

