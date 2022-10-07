servername=NFPluginLoader
servertype=AllServer
serverId=1.1.1.1
serverConfig=../../Config
serverPlugin=../../Plugin

dowork()
{
	restartss	
}

restartss()
{
	echo "starting $servername"
	$PWD/$servername -d --Server=$servertype --ID=$serverId --Config=$serverConfig --Plugin=$serverPlugin --Restart
	sleep 1
	ps x|grep "$servername"|sed -e '/grep/d'
}

startss()
{
	echo "starting $servername"
	$PWD/$servername -d --Server=$servertype --ID=$serverId --Config=$serverConfig --Plugin=$serverPlugin --start
	sleep 1
	ps x|grep "$servername"|sed -e '/grep/d'
}

reloadss()
{
	echo "starting $servername"
	$PWD/$servername -d --Server=$servertype --ID=$serverId --Config=$serverConfig --Plugin=$serverPlugin --reload
	sleep 1
	ps x|grep "$servername"|sed -e '/grep/d'
}

check_stop_over()
{
	while [ 1 ]
	do
		sleep 1
		pid=`ps x |grep $PWD/$servername | sed -e '/grep/d' | gawk '{print $1}'`
		if [ -z "$pid" ]
		then
			echo "$PWD/$servername Stop Over"
			break
		else
			echo "$PWD/$servername Still Runing, Please Wait..."
		fi
	done
}

stopss()
{
	pid=`ps x |grep $PWD/$servername | sed -e '/grep/d' | gawk '{print $1}'`
	if [ -z "$pid" ]
	then
		return
	fi
	echo "$PWD/$servername Exist.........Stop .............."
	$PWD/$servername  -d --Server=$servertype --ID=$serverId --Config=$serverConfig --Plugin=$serverPlugin --Stop
	check_stop_over
	echo "stop $servername"
}

case $1 in
	restart)
	echo "--------------------------------------------------"
	echo "--------------------RESTART-------------------------"
	echo "--------------------------------------------------"
	restartss
	;;
	start)
	echo "--------------------------------------------------"
	echo "--------------------START-------------------------"
	echo "--------------------------------------------------"
	startss
	;;
	stop)
	echo "--------------------------------------------------"
	echo "--------------------STOP-------------------------"
	echo "--------------------------------------------------"
	stopss
	;;
	reload)
	echo "--------------------------------------------------"
	echo "--------------------RELOAD-------------------------"
	echo "--------------------------------------------------"
	reloadss
	;;
esac
echo "--------------------------------------------------"
echo "----------------------DONE------------------------"
echo "--------------------------------------------------"

