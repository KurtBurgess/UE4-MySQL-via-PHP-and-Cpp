# UE4-MySQL-via-PHP-and-Cpp
Using C++ exposed to UE4's blueprints you can query a MySQL database via PHP and return data wrapped in JSON

# Setup
1) Inside of your *projectName*.Build.cs add ` , "Http", "Json", "JsonUtilities", "Sockets", "Networking" ` to the line
`PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Http", "Json", "JsonUtilities", "Sockets", "Networking" });`

2) Modify the `MyActorComponent.cpp and .h` files to have your project name instead of *MarsBridge* then add to your `Source\`*projectName* folder

3) Compile your project

4) Right click your *projectName*.uproject file and select *Generate Visual Studio project files*

5) Move *getUserMissionNotes.php* to your localhost PHP server (This is just a sample to give you a starting point, not the best but useable).

# Inside of Unreal Engine
1) In your actor blueprint click *Add Component* select *My Actor Componet*
2) Call the *MyActorComponent* blueprint from your actor's blueprint editor
3) Pass as inputs the path to the PHP script from localhost and the parameter to query (in this example it's the userID)
4) The code will call a PHP script hosted locally to query the MySQL database for all entries with the userID
5) The PHP script then returns all data as a string wrapped in JSON
