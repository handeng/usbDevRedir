@echo off
echo ����usb �ض��򼰸�����Ŀ......
echo ...
call "..\build.bat"

cd /d %~dp0
cd udr-stable
set dirname=udr-stable-%date:~0,4%%date:~5,2%%date:~8,2%
md "%dirname%"
cd "%dirname%"
md "udr-windows"
md "udr-linux"
set filename=%date:~0,4%%date:~5,2%%date:~8,2%-%time:~0,2%%time:~3,2%-setup.exe
echo "%filename%"

copy "..\..\..\udrInstall\��װ������\Express\SingleImage\DiskImages\DISK1\setup.exe" "udr-windows\%filename%"
copy "..\..\linux-udr\udr-linux.tar" "udr-linux\."
copy "..\..\Readme.txt" .
echo ...
echo ��ɣ�
pause