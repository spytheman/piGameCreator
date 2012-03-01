@echo off
choice /C YN /M "Backup ALL files? This keeps ONLY ONE old backup so be CAREFUL!"

if errorlevel 2 goto NOtarget
if errorlevel 1 goto YEStarget

:YEStarget
echo Backing up....
rmdir /s /q oldBACKUP
ren BACKUP oldBACKUP 
mkdir BACKUP
echo Copying files....
copy *.cpp BACKUP
copy *.h BACKUP
copy *.hpp BACKUP
copy *.c BACKUP
copy *.inl BACKUP
goto :END

:NOtarget
echo Have a nice day

:END
