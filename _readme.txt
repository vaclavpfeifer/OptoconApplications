In order to sucesfully build and run the project following must be SET:

a) In user csproj file change QTDIR location for each of the configuration - see example bellow:

  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <QTDIR>C:\Qt\Qt5.7.0X32\5.7\msvc2015</QTDIR>
    <LocalDebuggerEnvironment>PATH=$(QTDIR)\bin%3b$(PATH)</LocalDebuggerEnvironment>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <QTDIR>C:\Qt\Qt5.7.0X32\5.7\msvc2015</QTDIR>
    <LocalDebuggerEnvironment>PATH=$(QTDIR)\bin%3b$(PATH)</LocalDebuggerEnvironment>
  </PropertyGroup>

b) You can set global PATH variable to your QT bin location

  C:\Qt\Qt5.7.0X32\5.7\msvc2015\bin\


~ Note that option b) is less flexible when working with different QT versions...


