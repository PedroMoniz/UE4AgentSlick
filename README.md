# Agent Slick

An Unreal Engine 4 2D project about an special agent that is stuck in his enemy's lair.

## Prerequisites

This project requires some steps before you can build and run it.

- Install Unreal Engine 4.10.1 or higher (http://unrealengine.com/)
- Install a C++ IDE compatible with Unreal Engine
  - For Windows we suggest Visual Studio 2015 Community Edition (https://www.visualstudio.com/)
    - Beware this IDE doesn't install C++ environment and compiler by default, to install them visit http://blogs.msdn.com/b/vcblog/archive/2015/07/24/setup-changes-in-visual-studio-2015-affecting-c-developers.aspx
  - For Mac we suggest Xcode (https://developer.apple.com/xcode/)
  - For Linux we suggest KDevelop (https://www.kdevelop.org/)
    - Unreal Engine for Linux is still in early development (unfortunantly) therefore many things, including the IDE, may change.
- [Optional] Install Git

## Instructions

These instructions will allow you to build the project and play the game from within the editor.

1. If you don't already have the project, either download the zip and unzip or git clone the project from our page https://github.com/PedroMoniz/UE4AgentSlick
2. Inside the folder you'll find a file with the name MobileAgentSlick.uproject, double click it.
3. A message should pop up asking for a rebuild of the project, allow the project to be rebuilt.
4. The editor should now be open, allowing you to see one of the levels. To play it, press the arrow pointing down on the right side of the play button, and select "New Editor Window (PIE)".

#### NOTES:

- In step 3, the engine generates the project files, so that IDE can edit the game files. If something goes wrong during this step consider the following errors:
  1. You don't have a C++ environment installed.
  2. Your binaries folder don't have the same C++ files has the source folder.
    - Solution: Delete the Binaries folder, and generate project files.
      - To generate files in windows right-click the .uproject file and select Generate Visual Studio Project Files
      - To generate files in Mac see https://answers.unrealengine.com/questions/22749/cant-generate-xcode-files.html
      - To generate files in Linux see https://wiki.unrealengine.com/Building_On_Linux#Generating_project_files_for_your_project
- In step 4, to choose other levels open folders Levels->LevelX->LevelX where X is the number of a level.

## Credits

Nuno Baptista
Miguel Neves
Pedro Moniz
Ricardo Rodrigues
