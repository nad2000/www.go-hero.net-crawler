re = gets.to_i
1.upto(re) do |ri|
    n, m = gets.split.map(&:to_i)
    a = gets.split.map(&:to_f)
    tmp = 1.0
    rem = n
    ans = 1 + (m + 1)
    a.each do |i|
        rem -= 1
        tmp *= i
        ans = [ans, rem * 2 + (m - n) + 1 + (1 - tmp) * (m + 1)].min
    end
    puts 'Case #%d: %.6f' % [ri, ans]
end
