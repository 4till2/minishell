# minishell
A mini UNIX command interpreter implemented in C.

## Description
The goal of this project is to understand the core of the Unix system and explore
an important part of this system’s API: process creation and synchronisation.

The implemented functionality closely mocks the behavior found in zsh shell.

For a more thorough description and list of requirements (such as allowed functions) look at `minishell.en.pdf`.

### Functionality
The interpreter displays a prompt (a simple "$>") and waits for input from the command line, validated by pressing enter.
The prompt is shown again only once the commands have been fully executed. 

- This version does not support pipes, redirections, or other advanced functionality.
- The executables are those that can be found in the PATH variable.
- `;` seperates multiple commands.

#### Supported Expansions:
`$` : Expands to description found for following string in environment variables.

`~` : Expands to path found at HOME in environment variables.

#### Supported Built-ins:
`echo` : Writes to output.

`cd`   : Changes directory.

`setenv` : Changes environment variable.

`unsetenv` : Removes environment variable.

`env`      : Lists all environment variables.

`exit`     : Closes shell.

#### Supported Ctrls:
`CTRL-D` : Reprompts input.

### Usage
```
$ make
```

```
$ ./minishell command [command flags] [command args]
```
