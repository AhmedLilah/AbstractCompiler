package tokenizer

import "core:fmt"

helloFromTokenizer :: proc () {
        fmt.println("Hello from tokenizer.")
}

TokenType :: enum i64 {
}

Token :: struct {
        type : TokenType,
        tokenString : string
}
