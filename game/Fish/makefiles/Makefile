include ./define.makefile
.PHONY:all clean

START_TIME = $(shell cat /proc/uptime | awk -F "." '{print $$1}')

all:
	make -f ${MAKE_EXCELMAKEFILE_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_EXCELMMO_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	make -f ${MAKE_RESMETAS_GEN}  2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	mk_list=`ls ${RESDB_META_PATH}/*.makefile`;\
	for mk_file in $${mk_list};do\
		make -f $$mk_file 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;\
		echo $$mk_file;\
	done
	make -f ${MAKE_PROTOC_GEN} 2>&1 | tee -a ${MAKE_COMPILE_LOG} 2>&1; if [ $${PIPESTATUS[0]} -ne 0 ]; then exit 1;fi;
	@current_time=`cat /proc/uptime | awk -F "." '{print $$1}'`; \
	time_interval=`expr $${current_time} - $(START_TIME)`; \
	runtime=`date -u -d @$${time_interval} +%Hh:%Mm:%Ss`; \
	echo "######## runtime: $${runtime} ########"
clean:
	rm ${GAME_BUILD_PATH}/* -rf




