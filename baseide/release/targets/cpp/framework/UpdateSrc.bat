if not exist ..\..\..\..\..\cppengine goto error
del *.cpp
del *.h
del *.o
copy ..\..\..\..\..\cppengine\*.cpp .
copy ..\..\..\..\..\cppengine\*.h .
del main.cpp
goto success
:error
echo msgbox "cppengine folder in the source root does not exist",0,"ERROR" >> m.vbs
wscript m.vbs
del m.vbs
goto fail
:success
echo Update successfull
exit
:fail
echo Update FAILED