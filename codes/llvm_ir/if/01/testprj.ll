define i32 @main() {
    %n = call i32 @getchar()
    %cmp_result = icmp sge i32 %n, 50
    br i1 %cmp_result, label %if_true, label %if_false

if_true:
    call i32 @putchar( i32 65 )
    br label %if_exit

if_false:
    call i32 @putchar( i32 66 )
    br label %if_exit

if_exit:
    call i32 @putchar( i32 10 )
    ret i32 0
}

declare i32 @getchar()
declare i32 @putchar( i32 )