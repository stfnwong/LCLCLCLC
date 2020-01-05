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


// zip version
fn is_palindrome_zip(s: &[u8]) -> bool {
    if s.len() < 2 {
        return true;
    }
    let (left, right) = s.split_at(s.len() / 2);
    left.iter()
        .copied()
        .zip(right.iter().copied().rev())
        .all(|(l,r)| l == r)
}


// Version with unicode support
fn is_palindrome_unicode(s: &str) -> bool {
    let len = s.chars().count();
    s.chars().take(len / 2).eq(input.chars().rev().take(len / 2));
}
