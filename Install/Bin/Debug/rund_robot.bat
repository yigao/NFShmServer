cd /d %~dp0
cd Debug

echo Starting Robot...
start "Robot" "NFPluginLoader.exe" "--Server=RobotServer" "--ID=1.1.1.1" "--Config=../../Config" "--Plugin=../../TcpPlugin" "--Param=33,1,127.0.0.1,7051"






