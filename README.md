# UE4-MySQL-via-PHP-and-Cpp
Using C++ exposed to UE4's blueprints you can query a MySQL database via PHP and return data wrapped in JSON

# Setup:
1) Inside of your *projectName*.Build.cs add ` , "Http", "Json", "JsonUtilities", "Sockets", "Networking" ` to the line
`PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Http", "Json", "JsonUtilities", "Sockets", "Networking" });`

2) Merget the *Source* folder into your project's *Source* folder

3) Right click your *projectName*.uproject file and select *Generate Visual Studion project files*

# Inside of Unreal Engine:
1) In your actor blueprint click *Add Component* select *My Actor Compoent*
2) Call the C++ code via blueprints
3) Pass as inputs the URL and parameter to query (in this example it's the userID)
4) The code will call a PHP script hosted locally to query the MySQL database for all entries with the userID
5) The PHP script then returns all data as a string wrapped in JSON
