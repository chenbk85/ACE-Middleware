# Microsoft Developer Studio Project File - Name="ACE_SSL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ACE_SSL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ACE_SSL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ACE_SSL.mak" CFG="ACE_SSL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ACE_SSL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ACE_SSL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ACE_SSL - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ".\DLL\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ACE_SSL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\ACE_wrappers" /I "..\..\OpenSSL\openssl-0.9.5\inc32" /D "NDEBUG" /D "_WINDOWS" /D "WIN32" /D "ACE_HAS_SSL" /D "ACE_SSL_BUILD_DLL" /FD /c
# SUBTRACT CPP /X /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 ace.lib libeay32.lib ssleay32.lib /nologo /dll /pdb:none /machine:I386 /libpath:"..\..\ACE_wrappers\ace" /libpath:"..\..\ACE_wrappers\TAO\tao" /libpath:"..\..\OpenSSL\openssl-0.9.5\out32dll"

!ELSEIF  "$(CFG)" == "ACE_SSL - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ".\DLL\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ACE_SSL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /Gy /I "..\..\ACE_wrappers" /I "..\..\OpenSSL\openssl-0.9.5\inc32" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "ACE_HAS_SSL" /D "ACE_SSL_BUILD_DLL" /FD /GZ /c
# SUBTRACT CPP /Fr /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 aced.lib libeay32.lib ssleay32.lib /nologo /dll /debug /machine:I386 /out:"ACE_SSLd.dll" /libpath:"..\..\ACE_wrappers\ace" /libpath:"..\..\ACE_wrappers\TAO\tao" /libpath:"..\..\OpenSSL\openssl-0.9.5\out32dll"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "ACE_SSL - Win32 Release"
# Name "ACE_SSL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\SSL_Context.cpp
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK.cpp
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Acceptor.cpp
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Connector.cpp
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Stream.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\SSL_Context.h
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK.h
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Acceptor.h
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Connector.h
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Stream.h
# End Source File
# Begin Source File

SOURCE=.\sslconf.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "i"
# Begin Source File

SOURCE=.\SSL_Context.i
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Acceptor.i
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Connector.i
# End Source File
# Begin Source File

SOURCE=.\SSL_SOCK_Stream.i
# End Source File
# End Group
# End Target
# End Project
