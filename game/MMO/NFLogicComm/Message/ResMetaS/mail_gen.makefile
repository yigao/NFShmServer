include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_mail_bin

${PROTOCGEN_FILE_PATH}/module_mail_bin:${PROTOCGEN_FILE_PATH}/mail.proto.ds ${RESDB_EXCELMMO_PATH}/mail.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_mail_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/mail.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mail.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/MailDescEx.h ${PROTOCGEN_FILE_PATH}/MailDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_mail_bin
