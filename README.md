## Profile Manager CLI

### About
Profile Manager is a command line interface.  
Each profile contains list of user's urls, CMD commands and .exe files paths that can be run at the same time.  
> Windows only.
### Instalation
  Download the folder from this repository.
  
### Usage
`Backspace` hard quits the application  
Add profileManager folder to enviroment variables.   
Type `pm` and: 
- `--help` - list of options  
- `-a/--add + new profile name` - Adds new profile
- `-d/--delete + profile name` - deletes profile
- `-i/--delete-id + profile index` - deletes profiles
- `-e/--edit + profile name` - opens profile's interactive edition menu 
- `-p/--paths + profile name` - show list of paths, links and commands for selected profile
- `-r/--run + profile name` - runs profile by name
- `-m/--menu` - opens interactive main manu, where you can use all of above options
- `-l/--list` - shows list of created profiles
