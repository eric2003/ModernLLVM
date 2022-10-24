define i32 @main() {
    call i32 @putchar( i32 65 )
    call i32 @putchar( i32 10 )
    ret i32 0
}

declare i32 @putchar( i32 )