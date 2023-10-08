cd /d %~dp0
cd Debug

echo Starting AllServer...
start "AllServer" "NFFishLoader.exe" "--Server=AllServer" "--ID=1.13.1.1" "--Config=../../Config/Fish" "--Plugin=../../FishBusPlugin" "--restart"






