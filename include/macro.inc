# Label macros for splat/spimdisasm output.
.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro endlabel label
    .size \label, . - \label
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro enddlabel label
    .size \label, . - \label
.endm

.macro jlabel label
    \label:
.endm

.macro alabel label
    .global \label
    \label:
.endm

.macro nonmatching label, size=1
.endm
