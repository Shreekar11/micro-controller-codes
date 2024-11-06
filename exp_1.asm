// non-overlapping memory 

ORG 00H
MOV R2, #0AH
MOV R0, #20H
MOV R1, #40H
label: MOV A,@R0
MOV @R1,A
INC R0
INC R1
DJNZ R2, label 
END

// overlapping memory 
ORG 00H
MOV R2, #0AH
MOV R0, #29H
MOV R1, #2EH
label: MOV A,@R0
MOV @R1,A
DEC R0
DEC R1
DJNZ R2, label 
END