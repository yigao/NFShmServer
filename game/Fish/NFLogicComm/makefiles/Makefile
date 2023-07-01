include ./define.makefile
.PHONY:all clean

all:
	make -f ${MAKE_EXCELMAKEFILE_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_EXCELMMO_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_RESMETAS_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_PROTOC_GEN} 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	for mk_file in $(wildcard ${RESDB_META_PATH}/*.makefile);do\
		make -f $$mk_file 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;\
		echo $$mk_file;\
	done

clean:
	rm ${GAME_BUILD_PATH}/* -rf




