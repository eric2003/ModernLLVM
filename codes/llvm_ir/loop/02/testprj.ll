define i32 @main() {
entry:
    br label %outer_loop

outer_loop:
    %i = phi i32 [0, %entry], [%ii, %end_inner_loop]
    br label %inner_loop

inner_loop:
    %j = phi i32 [0, %outer_loop], [%jj, %inner_loop]
    call i32 @putchar( i32 42 )
    %jj = add i32 %j, 1
    %inner_cmp_result = icmp sge i32 %jj, 10
    br i1 %inner_cmp_result, label %end_inner_loop, label %inner_loop
end_inner_loop:
    call i32 @putchar( i32 10 )
    %ii = add i32 %i, 1
    %outer_cmp_result = icmp sge i32 %ii, 10
    br i1 %outer_cmp_result, label %end_outer_loop, label %outer_loop

end_outer_loop:

    ret i32 0
}

declare i32 @putchar( i32 )