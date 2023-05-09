# pipex_42

Pipex is a project that re-creates in C the way two commands are piped together via | in the shell

`# ./pipex infile cmd1 cmd2 outfile
pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)
 
# pipe() sends the output of the first execve() as input to the second execve()
# fork() runs two processes (i.e. two commands) in one single program
# dup2() swaps our files with stdin and stdout`
