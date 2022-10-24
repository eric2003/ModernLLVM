define i32 @main() {
    ;Hello
    call i32 @putchar( i32 72  )
    call i32 @putchar( i32 101 )
    call i32 @putchar( i32 108 )
    call i32 @putchar( i32 108 )
    call i32 @putchar( i32 111 )
    
    ; space
    call i32 @putchar( i32 32  )
    
    ; World
    call i32 @putchar( i32 87  )
    call i32 @putchar( i32 111 )
    call i32 @putchar( i32 114 )
    call i32 @putchar( i32 108 )
    call i32 @putchar( i32 100 )
    
    ; newline
    call i32 @putchar( i32 10  )
    
    ret i32 0
}

declare i32 @putchar( i32 )