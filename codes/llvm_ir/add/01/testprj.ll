define i32 @main() {
    %x = add i32 37, 43
    call i32 @putchar( i32 %x )

    %y = sub i32 %x, 5
    call i32 @putchar( i32 %y )

    call i32 @putchar( i32 10 )
    ret i32 0
}

declare i32 @putchar( i32 )