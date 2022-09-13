BASEPATH=$(cd `dirname $0`; pwd)

log_count=0
log_str=""

do_work()
{
	echo $1 $2 $3 $4
	ln -sdf $BASEPATH/NFPluginLoader $BASEPATH/$1_$2_bin
	#$cp NFPluginLoader $1 -rf
	#chmod a+x $1
	cp AllServer.sh $1_$2_run.sh -rf
	chmod a+x $1_$2_run.sh 
	cp AllServer_log.sh $1_$2_log.sh -rf
	chmod a+x $1_$2_log.sh
	sed -i "s/servername=NFPluginLoader/servername=$1_$2_bin/g" ./$1_$2_run.sh
	sed -i "s/servertype=AllServer/servertype=$1/g" ./$1_$2_run.sh
	#sed -i "s/serverId=.*.1/serverId=$2/g" ./$1_$2_run.sh
	sed -i 's#'''serverId=1.1.1.1'''#'''serverId=$2'''#g' ./$1_$2_run.sh
	sed -i 's#'''serverConfig=../../Config'''#'''serverConfig=$3'''#g' ./$1_$2_run.sh
	sed -i 's#'''serverPlugin=../../Plugin'''#'''serverPlugin=$4'''#g' ./$1_$2_run.sh

	sed -i "s/AllServer_1.1.1.1/AllServer_$2/g" ./$1_$2_log.sh
	sed -i "s/AllServer/$1/g" ./$1_$2_log.sh

	touch Stop.sh
	chmod a+x Stop.sh
	echo "./$1_$2_run.sh stop" >> Stop.sh

	touch ReStart.sh
	chmod a+x ReStart.sh
	echo "./$1_$2_run.sh restart" >> ReStart.sh

	touch Start.sh
	chmod a+x Start.sh
	echo "./$1_$2_run.sh start" >> Start.sh

	touch Clear.sh
	chmod a+x Clear.sh
	echo "rm $1_$2_bin -rf" >> Clear.sh
	echo "rm $1_$2_log.sh -rf" >> Clear.sh
	echo "rm $1_$2_run.sh -rf" >> Clear.sh

	touch Monitor.sh
	chmod a+x Monitor.sh
	echo  "$PWD/$1_$2_bin -d --Server=$1 --ID=$2 --Config=$3 --Plugin=$4 --start" >> Monitor.sh

	let log_count=log_count+1
  touch Alllog.sh
  chmod a+x Alllog.sh

  echo "LOG$log_count=logs/$1_$2/$1.log" >> Alllog.sh
  log_str=$log_str' $'"LOG$log_count "
}

rm Clear.sh
rm Start.sh
rm Stop.sh
rm ReStart.sh
rm Monitor.sh
rm Alllog.sh

echo "main()" >> Alllog.sh
echo "{" >> Alllog.sh

do_work MasterServer 1.1.1.1 ../../Config ../../TcpPlugin
do_work RouteServer 15.100.7.1 ../../Config ../../TcpPlugin
do_work RouteAgentServer 15.100.6.1 ../../Config ../../TcpPlugin
do_work StoreServer 15.100.8.1 ../../Config ../../TcpPlugin
do_work LoginServer 15.100.2.1 ../../Config ../../TcpPlugin
do_work WorldServer 15.100.3.1 ../../Config ../../TcpPlugin
do_work LogicServer 15.100.10.1 ../../Config ../../TcpPlugin
do_work ProxyServer 15.100.5.1 ../../Config ../../TcpPlugin
do_work ProxyAgentServer 15.100.13.1 ../../Config ../../TcpPlugin

echo	"tail --follow=name --retry $log_str --max-unchanged-stats=4 -n 5 -q | awk '"'/INFO/ {print "\033[32m" $0 "\033[39m"} /DEBUG/ {print  $0 }  /WARNING/ {print "\033[33m" $0 "\033[39m"} /TRACE/ {print "\033[33m" $0 "\033[39m"} /ERROR/ {print "\033[31m" $0 "\033[39m"} '"'" >> Alllog.sh

echo "}" >> Alllog.sh
echo "main" >> Alllog.sh

echo "./shm_rm.sh" >> Stop.sh

echo "rm Stop.sh -rf" >> Clear.sh
echo "rm Start.sh -rf" >> Clear.sh
echo "rm ReStart.sh -rf" >> Clear.sh
echo "rm Clear.sh -rf" >> Clear.sh
echo "rm Alllog.sh -rf" >> Clear.sh
echo "rm *_globalid -rf" >> Clear.sh
echo "rm *.pid -rf" >> Clear.sh
echo "rm *.uid -rf" >> Clear.sh
echo "rm *_dump.log -rf" >> Clear.sh
echo "rm shmnframe_lib.bin" >> Clear.sh
