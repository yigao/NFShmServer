main()
{
	LOG=logs/AllServer_1.1.1.1/AllServer.log
		        
	tail --follow=name --retry $LOG --max-unchanged-stats=3 -n 5 -q | awk '/INFO/ {print "\033[32m" $0 "\033[39m"} /DEBUG/ {print  $0 }  /WARNING/ {print "\033[33m" $0 "\033[39m"} /TRACE/ {print "\033[33m" $0 "\033[39m"} /ERROR/ {print "\033[31m" $0 "\033[39m"} '
}

main

