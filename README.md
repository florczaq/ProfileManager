## Profile Manager CLI

### About
Profile Manager is a command line interface.  
Each profile contains list of user's urls, CMD commands and .exe files paths that can be run at the same time.  
> Windows only.
### Instalation
  Download the ProfileManagerCLI folder from this repository.
  
  Place this folder on C:/
  > C:/ProfileManagerCLI

  Add ProfileManagerCLI folder directory to Environment Variables > Path

### Usage

`Backspace` hard quits the application  
Type `pm` and: 
- `--help` - list of options  
- `-a/--add + new profile name` - add new profile
- `-d/--delete + profile name` - delete profile
- `-i/--delete-id + profile index` - delete profiles
- `-e/--edit + profile name` - interactive profile's edition menu 
- `-p/--paths + profile name` - list of paths, links and commands for selected profile
- `-r/--run + profile name` - run profile
- `-m/--menu` - interactive main manu
- `-l/--list` - list of created profiles
