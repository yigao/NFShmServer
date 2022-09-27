include ./define.makefile
.PHONY:all clean

all:
	@chmod +x ${PROTOC}
	make -f ${MAKE_EXCELMAKEFILE_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_EXCELMMO_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_RESMETAS_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_PROTOC_GEN} 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	for mk_file in $(RESDB_DESC_MAKEFILE);do\
		make -f $$mk_file 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;\
		echo $$mk_file;\
	done

clean:
	rm ${GAME_BUILD_PATH}/* -rf




