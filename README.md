# How to create a Shell Script?
<h1 align ="center"> <img src="https://ml.globenewswire.com/Resource/Download/a08e6c28-55be-44c8-8461-03544f094b38" height="40%" width="30%"> <img src="https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/i/fdb7246b-92e5-4075-a409-7bf063232e08/dasmbdb-b75a3bb1-b481-41a2-9cb1-1ddc06ef5be4.png" height="90%" width="70%"></h1>

## Description
A simple UNIX command interpreter. mini_shell is the user interface to communicate with the operative system services.

This project consists in the creation of a simple shell that will allow the user to interact with the system using commands.

It handles the PATH to find the programs it will execute. It will use the execve() system call to perform the commands. The execution of the programs will be done under children processes using fork(). 

## Requeriments
Compiled with Ubuntu 14.04 LTS using flags `-Wall -Werror -Wextra and -pedantic.`

## Use of functions
|**Functions**|Concepts|
|--|--|
|**environ**|points to an array of pointers to strings called the "environment". |
|**putchar**| put a byte on a stdout stream.|
|**env**| run a program in a modified environment.|
|**split**| split a file into pieces. |
|**execute**|run an application inside a container. |
|**error**| general error-reporting function.|
|**path**|format of the /usr/local/etc/man_db.conf file. |
|**splitPath**|breaks a path into its constituent elements.|
|**run**|executes the specified command in the environment described by the list of options and exits with the command's exit value |
| | |

## Learning objectives
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?



## Pseudocódigo
1. Print a character :
    ```c 
	    while(1){
	    print_prompt();
	    get_input();
	    parse_input();
	    if("logout" || "exit")
	    break;
	    do_cmd(); 
	    }

## *Recommendation*
+ Be calm.
+ Ask your peers (friends).
+ Read the resources.
+ Find additional sources.
+ Assemble your flowchart.
+ Review your flowchart.
+ Ask your peers.
+ Review past projects to be clear about what you will do.
+ Organize your ideas to create the functions.
+ Important: Pass Betty, Gdb / Valgrint.
+ 

## References when creating a Shell Script
1. https://man7.org/linux/man-pages/man1/sh.1p.html

## References when creating a man Shell
1. https://linux.die.net/man/1/bash

## Authors
| [<img src="https://avatars.githubusercontent.com/u/100174476?v=4" width=130><br><sub> WilsonValer </sub>](https://github.com/DaisyGeraldine)   | [<img src="https://avatars.githubusercontent.com/u/104711420?v=4" width=130><br><sub> Iver Sutizal </sub>](https://github.com/IverSutizal)   |
|--|--|
| <div align="center"> <a href="mailto:nederig21@gmail.com" target="_blank"> <img height="32" src="https://www.pngall.com/wp-content/uploads/12/Gmail-Email-PNG-Pic.png" target="_blank">  <a href="https://www.instagram.com/zion_capricornio/" target="_blank"> <img height="32" src="http://assets.stickpng.com/images/580b57fcd9996e24bc43c521.png" target="_blank"> </a>  </div>| <div align="center" > <a href="mailto:nederig21@gmail.com" target="_blank"> <img height="32" src="https://www.pngall.com/wp-content/uploads/12/Gmail-Email-PNG-Pic.png" target="_blank"> <a href="https://twitter.com/IverSutizal" target="_blank"> <img height="32" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/4f/Twitter-logo.svg/2491px-Twitter-logo.svg.png"> </a> <a href="https://www.instagram.com/iversutizal/" target="_blank"> <img height="32" src="http://assets.stickpng.com/images/580b57fcd9996e24bc43c521.png" target="_blank"> </a> </div> |
| <div align="center"><a href="https://www.linkedin.com/in/wilson-valer-ayme-479267180/" target="_blank"> <img height="32" src="https://www.marcoszuniga.com/wp-content/uploads/2020/05/Linkedin-Logo.png" target="_blank"> </a> <a href="https://medium.com/@nederig21" target="_blank"> <img height="32" src="https://img.shields.io/badge/Medium-12100E?style=for-the-badge&logo=medium&logoColor=white" target="_blank"> </a> <a href="https://www.youtube.com/channel/UCgvWWcdYyVxHqpZxI6nuXJA" target="_blank"><img height="32" src="http://assets.stickpng.com/thumbs/580b57fcd9996e24bc43c545.png" target="_blank"> </a></div> |   <div align="center"> <a href="https://www.linkedin.com/in/iver-sutizal-3aa913197/" target="_blank"> <img height="32" src="https://www.marcoszuniga.com/wp-content/uploads/2020/05/Linkedin-Logo.png" target="_blank"> </a> <a href="https://medium.com/@iversutizal" target="_blank"> <img height="32" src="https://img.shields.io/badge/Medium-12100E?style=for-the-badge&logo=medium&logoColor=white" target="_blank"> </a> <a href="https://www.youtube.com/channel/UCaFAl3KzbcNQl29MG5PAxqA" target="_blank"><img height="32" src="http://assets.stickpng.com/thumbs/580b57fcd9996e24bc43c545.png" target="_blank"> </a> </div>|
