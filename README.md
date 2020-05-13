# School 42 UNIX project: ft_ls

This project is basically a re-coding in C of the well-known UNIX command: **ls**.

## How it works

* The **-l, -a, -r, -R, -t, -c, -u** options are implemented in my ls.

* The output display is smilar to a **ls -1** as I didn't implement the normal ls column display.

* A design mistake on my part makes my **ft_ls** store all the file data it needs in memory before printing everything -
i.e if I do a **ft_ls -lR /** it will parse and store the data of every file inside a gigantic structure before printing everything and freeing the memory.

* A more intelligent approach would have been to print the files and free the memory progressively as the parsing goes.
I might correct that in the future.
