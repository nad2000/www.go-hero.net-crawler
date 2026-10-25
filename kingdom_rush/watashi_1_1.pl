#!/usr/bin/perl

use strict;
use warnings;
use Data::Dumper;
use List::MoreUtils 'first_index';

$| = 1;
chomp(my $re = <STDIN>);
for my $ri (1 .. $re) {
    chomp(my $n = <STDIN>);
    my @a = ();
    for (1 .. $n) {
        $_ = <STDIN>;
        @_ = split;
        push @_, 0;
        push @a, [@_];
    }
    @a = sort { $b->[1] <=> $a->[1] } @a;

    my $m = 0;
    my $ans = 0;
    while (@a > 0) {
        my $i = first_index { $_->[1] <= $m } @a;
        if ($i != -1) {
            $m += 2 - $a[$i][2];
            splice @a, $i, 1;
            ++$ans;
            next;
        }
        my $j = first_index { $_->[0] != -1 && $_->[0] <= $m } @a;
        if ($j != -1) {
            $m += 1;
            $a[$j][0] = -1;
            $a[$j][2] = 1;
            ++$ans;
            next;
        }
        last;
    }

    $ans = 'Too Bad' if @a > 0;
    print "Case #$ri: $ans\n";
}
