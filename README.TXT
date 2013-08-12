ALLOCMEM

I originally grabbed this file out of curiosity, as I am a budding C
programmer and thought this was a code snippet.

Much to my surprise, it's a funtional utility that I am quite happy to
have found.

When you execute ALLOCMEM.EXE in an os2 session, it will cause all loaded
Dynamic Linked Libraries to be swapped from memory to the hard drive.

Resulting in a completely empty memory map. (complete as possible, the
os2 kernel and support drivers have to stay in memory)

What effect does this have?

The best! As all of those unused .dll's are now swapped out of memory,
making more room for "your" programs. Whether you know it or not, when you
boot os2, the system will load in every possible .dll that you may or may
not need during your "compute sessions". To my amazment, a lot of the
"default" loading of .dll's is never used during my work. I based this
"discovery" on my use of ALLOCMEM and a resource manager and how my system
behaves during use. Since I am able to clear out a large portion of memory,
I have opted to boost my hpfs386 cache from 4meg to 6meg, and still have
almost 6meg free on my 20meg machine...

Also, since I run a bbs, I added two new events into the bbs schedule.
At 12:00 noon and midnight, I have the bbs run ALLOCMEM, making sure the
memory map stays vacated...

Works great...


REQUIREMENTS
- EMX.DLL
- EMXLIBC.DLL
- EMXWRAP.DLL


