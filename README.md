![Gordon Logo](dist/logo.png)

# Gordon

*If I'm writing bloatware, might as well be in C*

The whole point of Gordon is a learning exercise...
Overall, this library will serve to first reimplement certain parts of the C Standard Library such as **malloc** and **free** and then move onto other parts, working my way down to the Syscall interface

### Planned Features
-   "Fat" pointers
-   Multi-tiered heap management
-   Aim for C99 compat with unistd.h and signal.h
-   Parts of POSIX (Semaphores, pthreads)
-   The kitchen sink
-   Reinvent the wheel as a 10999 sided polygon chiseled from bedrock
-   **gord.h** will be a rolling component where I add things like general purpose data structures and pointer chunks

## Headers
#### Done
-   stdbool.h <May 24, 2017>
-   Not a header, but syscall interface implemented for x86_64 and ARM <June 15, 2017>

#### Partially Done
-   unistd.h
-   stddef.h
-   stdio.h
-   stdlib.h
-   syscall.h
-   semaphore.h

#### TODO
-   assert.h
-   ctype.h
-   errno.h
-   float.h
-   limits.h
-   locale.h
-   math.h
-   setjmp.h
-   signal.h
-   stdarg.h
-   string.h
-   time.h
-   complex.h
-   fenv.h
-   inttypes.h
-   stdint.h
-   tgmath.h 
