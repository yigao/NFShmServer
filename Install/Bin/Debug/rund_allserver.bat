cd /d %~dp0
cd Debug

echo Starting AllServer...
start "AllServer" "NFPluginLoader.exe" "--Server=AllServer" "--ID=1.1.1.1" "--Config=../../Config" "--Plugin=../../TcpPlugin"






