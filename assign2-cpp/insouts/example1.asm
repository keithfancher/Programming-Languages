label  load   one
       add    two
       store  three
       beq    3   end
       bne    3   label 
end    halt
one    .fill  1
two    .fill  2
three  .fill  0
