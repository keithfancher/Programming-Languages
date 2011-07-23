label  load   one
       add    two
       store  three
       beq    3   1
       bne    3   -5 
end    halt
one    .fill  1
two    .fill  2
three  .fill  0
