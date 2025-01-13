# CPL

This is an attempt at the Command Procedure Language first available on the
Prime Computer in 1981.

## Concept

This language was one of the first scripting languages I learned around the
same time I started to learn AUTOEXEC.BAT and CONFIG.SYS on DOS.

This language is clumsy, to be sure. It was intended to be fast and I think it
was intended to be scanned quickly for rapid substitutions in the text of a
command line "program".

## Implementation

Remember that this was a very new thing at the time. I'm attempting to do this
in C because I need to refine my C chops. Writing Java for so long has made my
C skills suffer, so I want to fix that. Also writing a C programming book for
my students, so I was to relive learning the language all over again.

Everything in this design is C11/C17 compatible.

## The Language

This project attempts to implement CPL as it was available on Primos 21.x.

[CPL Prime Brochure](https://sysovl.info/pages/blobs/prime/brochures/jim/PrimeCPL.pdf)

[CPL User Guide](https://sysovl.info/pages/blobs/prime/devel/CPL%20Users%20Guide%20Rev%2021%20DOC4302-3LA%201987.pdf)

The language looks like this:

&if %severity$% = 1 &then &call error_routine

&if (expression) &then &goto label
&else &do
&end

&if [exists %filename%|
&then [open_file %filename% -mode status]
