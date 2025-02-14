def shuanshuan(n, k):
    for _ in range(k):
        if n == 1:
            return False
        if n % 2 == 0:
            n //= 2
        else:
            n = 3 * n + 1
    return n == 1

# Mảng yi cho trước
yi = [27, 38, 87, 95, 118, 9]

# Duyệt qua tất cả các ký tự printable từ 0x20 đến 0x7f
valid_chars = []
for i in range(0x20, 0x7f):
    if all(shuanshuan(i, yi[j]) for j in range(6)):
        valid_chars.append(chr(i))

# In ra tất cả các ký tự hợp lệ
print("Valid characters: ", valid_chars)
