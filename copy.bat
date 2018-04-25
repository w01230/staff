@echo off
 
for /f "delims=" %%i in ('dir /s/b "*.vib"') do ( 
echo %%~ni 
pushd %%~dpi  
copy %%i ..

popd
)
pause