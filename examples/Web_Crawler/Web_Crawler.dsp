# Microsoft Developer Studio Project File - Name="Web_Crawler" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Web_Crawler - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Web_Crawler.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Web_Crawler.mak" CFG="Web_Crawler - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Web_Crawler - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Web_Crawler - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Web_Crawler - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 ace.lib /nologo /subsystem:console /machine:I386 /libpath:"..\..\\"

!ELSEIF  "$(CFG)" == "Web_Crawler - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Web_Craw"
# PROP BASE Intermediate_Dir "Web_Craw"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "..\..\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 aced.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\ace"

!ENDIF 

# Begin Target

# Name "Web_Crawler - Win32 Release"
# Name "Web_Crawler - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=.\Command_Processor.cpp
# End Source File
# Begin Source File

SOURCE=.\HTTP_URL.cpp
# End Source File
# Begin Source File

SOURCE=.\Iterators.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\Mem_Map_Stream.cpp
# End Source File
# Begin Source File

SOURCE=.\Options.cpp
# End Source File
# Begin Source File

SOURCE=.\URL.cpp
# End Source File
# Begin Source File

SOURCE=.\URL_Addr.cpp
# End Source File
# Begin Source File

SOURCE=.\URL_Status.cpp
# End Source File
# Begin Source File

SOURCE=.\URL_Visitor.cpp
# End Source File
# Begin Source File

SOURCE=.\URL_Visitor_Factory.cpp
# End Source File
# Begin Source File

SOURCE=.\Web_Crawler.cpp
# End Source File
# End Group
# Begin Group "Include Files"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=.\Cached_Connect_Strategy_T.h
# End Source File
# Begin Source File

SOURCE=.\Caching_Strategies_T.h
# End Source File
# Begin Source File

SOURCE=.\Command_Processor.h
# End Source File
# Begin Source File

SOURCE=.\HTTP_URL.h
# End Source File
# Begin Source File

SOURCE=.\Iterators.h
# End Source File
# Begin Source File

SOURCE=.\Mem_Map_Stream.h
# End Source File
# Begin Source File

SOURCE=.\Optimal_Cache_Map_Manager_T.h
# End Source File
# Begin Source File

SOURCE=.\Options.h
# End Source File
# Begin Source File

SOURCE=.\URL.h
# End Source File
# Begin Source File

SOURCE=.\URL_Addr.h
# End Source File
# Begin Source File

SOURCE=.\URL_Status.h
# End Source File
# Begin Source File

SOURCE=.\URL_Visitor.h
# End Source File
# Begin Source File

SOURCE=.\URL_Visitor_Factory.h
# End Source File
# Begin Source File

SOURCE=.\Web_Crawler.h
# End Source File
# End Group
# Begin Group "Template Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Cached_Connect_Strategy_T.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Caching_Strategies_T.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Optimal_Cache_Map_Manager_T.cpp
# PROP Exclude_From_Build 1
# End Source File
# End Group
# End Target
# End Project
