/*
 * Determine if a string is a palindrome
 */


// tail recursive palindrome
fn is_palindrome(bytes: &[u8]) -> bool {
    if bytes.len() <= 1 {
        true
    }
    else if bytes.len() == 2 {
        bytes[0] == bytes[1]
    }
    else if bytes[0] == bytes[bytes.len() - 1]{
        is_palindrome(&bytes[1..bytes.len() - 1])
    }
    else {
        false
    }
}
