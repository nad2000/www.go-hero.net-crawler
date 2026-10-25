S = 'ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyeq'
T = 'ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupaoz'
H = {}
S.chars.zip(T.chars){|i, j|
    H[i] = j
}
k = ([*'a'..'z'] - H.keys)[0]
v = ([*'a'..'z'] - H.values)[0]
H[k] = v

re = gets.to_i
(1..re).each do |ri|
    s = gets.chop.gsub(/./){H[$&] || $&}
    puts "Case ##{ri}: #{s}"
end

