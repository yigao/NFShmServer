include ./define.makefile
.PHONY:all clean

all:
	@echo ${GAME_SRC_PATH}
	@chmod +x ${PROTOC}
	make -f ${MAKE_PROTOC_GEN} 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_EXCEL_GEN} -j${MAKE_SINGLE_JOB_NUM} 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;

clean:
	rm ${ALL_PROTOCGEN_FILE} ${ALL_PROTOCGEN_PY}  ${ALL_PROTOC_DESCRIPTOR_FILE} -rf




