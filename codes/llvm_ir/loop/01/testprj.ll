define i32 @main() {
    br label %loop

loop:
    call i32 @putchar( i32 48 )
    br label %loop 

    ret i32 0
}

declare i32 @putchar( i32 )